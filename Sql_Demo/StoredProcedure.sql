-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Server version:               10.6.5-MariaDB - mariadb.org binary distribution
-- Server OS:                    Win64
-- HeidiSQL Version:             11.3.0.6295
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;


-- Dumping database structure for igp_jakarta
CREATE DATABASE IF NOT EXISTS `igp_jakarta` /*!40100 DEFAULT CHARACTER SET latin1 */;
USE `igp_jakarta`;

-- Dumping structure for procedure igp_jakarta.UPDATEMONITORING
DELIMITER //
CREATE PROCEDURE `UPDATEMONITORING`(
	IN `table_name` VARCHAR(255),
	IN `Departement_Param` VARCHAR(255),
	IN `MachineName_Param` VARCHAR(255),
	IN `State_Param` INT
)
BEGIN
    DECLARE status_result VARCHAR(255);
    DECLARE log_id INT;
    DECLARE status_generate VARCHAR(50);

    SET @query = CONCAT('SELECT Status INTO @status_result FROM ', table_name, ' WHERE Departement = ? AND Machine_Name = ?');
    SET @department_value = Departement_Param;
    SET @machine_name_value = MachineName_Param;
    PREPARE stmt FROM @query;
    EXECUTE stmt USING @department_value, @machine_name_value;
    DEALLOCATE PREPARE stmt;

    IF State_Param = 1 THEN
        SET status_generate = 1;
   ELSE
       SET status_generate = 0;
   END IF;

    IF @status_result <> State_Param THEN
         INSERT INTO monitoring (Line, Machine, Departement, Cond) VALUES (table_name, MachineName_Param, Departement_Param, status_generate);
        SET log_id = LAST_INSERT_ID();
        SELECT log_id;
    ELSE
        SELECT 'Status matches';
    END IF;
END//
DELIMITER ;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
