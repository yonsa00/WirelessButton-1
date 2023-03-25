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

-- Dumping structure for table andon_plant2.sub_assy
CREATE TABLE IF NOT EXISTS `sub_assy` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `Departement` varchar(50) DEFAULT NULL,
  `status` tinyint(4) DEFAULT NULL,
  `Machine` int(11) DEFAULT NULL,
  `Machine_Name` varchar(50) DEFAULT NULL,
  `Button_active` varchar(50) DEFAULT NULL,
  `Button_deactive` varchar(50) DEFAULT NULL,
  `code_dep` varchar(50) DEFAULT NULL,
  `picture` varchar(50) DEFAULT NULL,
  `RST` int(11) DEFAULT NULL,
  `PS` int(11) DEFAULT NULL,
  `Modified` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp(),
  PRIMARY KEY (`id`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=115 DEFAULT CHARSET=latin1 ROW_FORMAT=DYNAMIC;

-- Dumping data for table andon_plant2.sub_assy: ~21 rows (approximately)
/*!40000 ALTER TABLE `sub_assy` DISABLE KEYS */;
REPLACE INTO `sub_assy` (`id`, `Departement`, `status`, `Machine`, `Machine_Name`, `Button_active`, `Button_deactive`, `code_dep`, `picture`, `RST`, `PS`, `Modified`) VALUES
	(1, 'Maintenance', 0, 1, 'M-1 (D-14)', './assets/img/mtc.png', './assets/img/mtcoff.png', 'MC', './assets/img/M-1 (D-14).png', 0, 20, '2023-03-24 23:50:27'),
	(2, 'QC', 0, 1, 'M-1 (D-14)', './assets/img/qc.png', './assets/img/qcoff.png', 'QC', './assets/img/M-1 (D-14).png', 0, 1726, '2023-03-24 23:50:30'),
	(3, 'Supply', 1, 1, 'M-1 (D-14)', './assets/img/sp.png', './assets/img/spoff.png', 'SP', './assets/img/M-1 (D-14).png', 0, 7, '2023-03-24 23:50:28'),
	(4, 'Maintenance', 1, 2, 'M-3 (D-14)', './assets/img/mtc.png', './assets/img/mtcoff.png', 'MC', './assets/img/M-3 (D-14).png', 1, 0, '2023-03-24 22:59:31'),
	(5, 'QC', 0, 2, 'M-3 (D-14)', './assets/img/qc.png', './assets/img/qcoff.png', 'QC', './assets/img/M-3 (D-14).png', 1, 0, '2023-03-24 22:43:04'),
	(6, 'Supply', 0, 2, 'M-3 (D-14)', './assets/img/sp.png', './assets/img/spoff.png', 'SP', './assets/img/M-3 (D-14).png', 1, 0, '2023-03-24 22:24:45'),
	(7, 'Maintenance', 1, 3, 'M-3-3 (D-14)', './assets/img/mtc.png', './assets/img/mtcoff.png', 'MC', './assets/img/M-3-3 (D-14).png', 1, 0, '2023-03-24 22:59:31'),
	(8, 'QC', 1, 3, 'M-3-3 (D-14)', './assets/img/qc.png', './assets/img/qcoff.png', 'QC', './assets/img/M-3-3 (D-14).png', 1, 0, '2023-03-24 22:59:31'),
	(9, 'Supply', 1, 3, 'M-3-3 (D-14)', './assets/img/sp.png', './assets/img/spoff.png', 'SP', './assets/img/M-3-3 (D-14).png', 1, 0, '2023-03-24 22:59:31'),
	(10, 'Maintenance', 1, 4, 'M-1 (D-40)', './assets/img/mtc.png', './assets/img/mtcoff.png', 'MC', './assets/img/M-1 (D-40).png', 1, 0, '2023-03-24 22:59:31'),
	(11, 'QC', 1, 4, 'M-1 (D-40)', './assets/img/qc.png', './assets/img/qcoff.png', 'QC', './assets/img/M-1 (D-40).png', 1, 0, '2023-03-24 22:59:31'),
	(12, 'Supply', 1, 4, 'M-1 (D-40)', './assets/img/sp.png', './assets/img/spoff.png', 'SP', './assets/img/M-1 (D-40).png', 1, 0, '2023-03-24 22:59:31'),
	(13, 'Maintenance', 1, 5, 'M-3 (D-40)', './assets/img/mtc.png', './assets/img/mtcoff.png', 'MC', './assets/img/M-3 (D-40).png', 0, 0, '2023-03-24 22:59:31'),
	(14, 'QC', 1, 5, 'M-3 (D-40)', './assets/img/qc.png', './assets/img/qcoff.png', 'QC', './assets/img/M-3 (D-40).png', 0, 0, '2023-03-24 22:59:31'),
	(15, 'Supply', 1, 5, 'M-3 (D-40)', './assets/img/sp.png', './assets/img/spoff.png', 'SP', './assets/img/M-3 (D-40).png', 0, 0, '2023-03-24 22:59:31'),
	(16, 'Maintenance', 1, 6, 'M-3-3 (D-40)', './assets/img/mtc.png', './assets/img/mtcoff.png', 'MC', './assets/img/M-3-3 (D-40).png', 0, 0, '2023-03-24 22:59:31'),
	(17, 'QC', 0, 6, 'M-3-3 (D-40)', './assets/img/qc.png', './assets/img/qcoff.png', 'QC', './assets/img/M-3-3 (D-40).png', 0, 0, '2022-09-27 20:25:18'),
	(18, 'Supply', 0, 6, 'M-3-3 (D-40)', './assets/img/sp.png', './assets/img/spoff.png', 'SP', './assets/img/M-3-3 (D-40).png', 0, 0, '2022-09-27 20:25:20'),
	(19, 'Maintenance', 0, 7, 'S-1 (NEW)', './assets/img/mtc.png', './assets/img/mtcoff.png', 'MC', './assets/img/S-1 (NEW).png', 0, 0, '2022-09-27 20:34:19'),
	(20, 'QC', 0, 7, 'S-1 (NEW)', './assets/img/qc.png', './assets/img/qcoff.png', 'QC', './assets/img/S-1 (NEW).png', 0, 0, '2022-09-27 20:34:21'),
	(21, 'Supply', 0, 7, 'S-1 (NEW)', './assets/img/sp.png', './assets/img/spoff.png', 'SP', './assets/img/S-1 (NEW).png', 0, 0, '2022-09-27 20:34:22');
/*!40000 ALTER TABLE `sub_assy` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
