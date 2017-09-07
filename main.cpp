#include <iostream>

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <chrono>
#include <thread>
#include <boost/asio.hpp>

const char *port = "/dev/ttyACM0";

int main() {
    std::cout << "Hello, World!" << std::endl;

    sql::Driver *driver;
    sql::Connection *con;
    sql::PreparedStatement *pot0;
    sql::PreparedStatement *pot1;
    sql::PreparedStatement *pot2;

    // MySQL initialisation
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "username", "password");
    con->setSchema("grafana");

    // Prepare insertion statements
    pot0 = con->prepareStatement("INSERT INTO pot0(value) VALUES(?)  ON DUPLICATE KEY UPDATE value = ?");
    pot1 = con->prepareStatement("INSERT INTO pot1(value) VALUES(?)  ON DUPLICATE KEY UPDATE value = ?");
    pot2 = con->prepareStatement("INSERT INTO level(value) VALUES(?) ON DUPLICATE KEY UPDATE value = ?");

    try {
        // Serial interface initialisation
        boost::asio::io_service io;
        boost::asio::serial_port serial(io, port);
        serial.set_option(boost::asio::serial_port_base::baud_rate(9600));

        boost::asio::streambuf buf;
        std::istream is(&buf);
        std::istringstream iss;

        std::string line;
        boost::system::error_code ec;

        // Time when the last MySQL data was sent; used to prevent too frequent updates
        std::chrono::steady_clock::time_point last_update = std::chrono::steady_clock::now();
        while (true) {
            try {
                // TODO: Move this into another function
                // TODO: Make this asynchronous
                boost::asio::read_until(serial, buf, '\n', ec);

                if (!ec) {
                    int potv0 = -2, potv1 = -1, potv2 = 0;
                    std::getline(is, line);
                    iss = std::istringstream(line);
                    iss >> potv0 >> potv1 >> potv2;

                    if (std::chrono::steady_clock::now() - last_update > std::chrono::milliseconds(100)) {
                        std::cout << potv0 << '\t' << potv1 << '\t' << potv2 << std::endl;

                        // Perform the update
                        pot0->setInt(1, potv0);
                        pot0->setInt(2, potv0);
                        pot0->execute();
                        pot1->setInt(1, potv1);
                        pot1->setInt(2, potv1);
                        pot1->execute();
                        pot2->setInt(1, potv2);
                        pot2->setInt(2, potv2);
                        pot2->execute();

                        last_update = std::chrono::steady_clock::now();
                    }

                    std::this_thread::sleep_for(std::chrono::milliseconds(5));

                    if (line == "stop") {
                        break;
                    }
                } else {
                    std::this_thread::sleep_for(std::chrono::milliseconds(5));
                }
            } catch (boost::system::system_error &e) {
                std::cerr << "Unable to execute " << e.what();
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
            }
        }

    } catch (boost::system::system_error &e) {
        std::cerr << "Unable to open interface " << port << ": " << e.what();
    }

    delete pot0;
    delete pot1;
    delete pot2;
    delete con;

    return 0;
}
