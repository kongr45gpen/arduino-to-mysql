-- phpMyAdmin SQL Dump
-- version 4.7.0-dev
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Sep 07, 2017 at 03:32 PM
-- Server version: 10.0.29-MariaDB-0ubuntu0.16.04.1
-- PHP Version: 7.0.18-0ubuntu0.16.04.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

--
-- Database: `grafana`
--

-- --------------------------------------------------------

--
-- Table structure for table `level`
--

CREATE TABLE `level` (
  `ID` int(11) UNSIGNED NOT NULL,
  `value` int(11) NOT NULL,
  `time` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- --------------------------------------------------------

--
-- Table structure for table `pot0`
--

CREATE TABLE `pot0` (
  `ID` int(11) UNSIGNED NOT NULL,
  `value` int(11) NOT NULL,
  `time` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- --------------------------------------------------------

--
-- Table structure for table `pot1`
--

CREATE TABLE `pot1` (
  `ID` int(11) UNSIGNED NOT NULL,
  `value` int(11) NOT NULL,
  `time` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `level`
--
ALTER TABLE `level`
  ADD PRIMARY KEY (`ID`),
  ADD UNIQUE KEY `time` (`time`);

--
-- Indexes for table `pot0`
--
ALTER TABLE `pot0`
  ADD PRIMARY KEY (`ID`),
  ADD UNIQUE KEY `time` (`time`);

--
-- Indexes for table `pot1`
--
ALTER TABLE `pot1`
  ADD PRIMARY KEY (`ID`),
  ADD UNIQUE KEY `time` (`time`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `level`
--
ALTER TABLE `level`
  MODIFY `ID` int(11) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1;
--
-- AUTO_INCREMENT for table `pot0`
--
ALTER TABLE `pot0`
  MODIFY `ID` int(11) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1;
--
-- AUTO_INCREMENT for table `pot1`
--
ALTER TABLE `pot1`
  MODIFY `ID` int(11) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1;
