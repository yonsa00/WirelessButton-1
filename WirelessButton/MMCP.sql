-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Server version:               10.11.0-MariaDB - mariadb.org binary distribution
-- Server OS:                    Win64
-- HeidiSQL Version:             11.3.0.6295
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

-- Dumping structure for table igp_kim.mmcpv1_002
CREATE TABLE IF NOT EXISTS `mmcpv1_002` (
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `Sensor` varchar(50) DEFAULT '0',
  `Stat` varchar(50) DEFAULT '0',
  `Volume` float DEFAULT 0,
  `Temperature_Panel` float DEFAULT 0,
  `Humidity` float DEFAULT 0,
  `Temperature_Motor` float DEFAULT 0,
  `Pressure1` float DEFAULT 0,
  `Pressure2` float DEFAULT 0,
  `Pressure3` float DEFAULT 0,
  PRIMARY KEY (`Id`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=latin1 ROW_FORMAT=DYNAMIC;

-- Dumping data for table igp_kim.mmcpv1_002: ~0 rows (approximately)
/*!40000 ALTER TABLE `mmcpv1_002` DISABLE KEYS */;
/*!40000 ALTER TABLE `mmcpv1_002` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
