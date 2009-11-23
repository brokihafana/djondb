-- MySQL Administrator dump 1.4
--
-- ------------------------------------------------------
-- Server version	5.1.37-1ubuntu5


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;


--
-- Create schema jaguarmd
--

CREATE DATABASE IF NOT EXISTS jaguarmd;
USE jaguarmd;

--
-- Definition of table `jaguarmd`.`activities`
--

DROP TABLE IF EXISTS `jaguarmd`.`activities`;
CREATE TABLE  `jaguarmd`.`activities` (
  `id` int(11) NOT NULL DEFAULT '0',
  `activitytype` int(11) DEFAULT NULL,
  `startquantity` int(11) NOT NULL DEFAULT '1',
  `looptype` int(11) NOT NULL,
  `idprocessdef` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `jaguarmd`.`activities`
--

/*!40000 ALTER TABLE `activities` DISABLE KEYS */;
LOCK TABLES `activities` WRITE;
INSERT INTO `jaguarmd`.`activities` VALUES  (1,0,1,0,1);
UNLOCK TABLES;
/*!40000 ALTER TABLE `activities` ENABLE KEYS */;


--
-- Definition of table `jaguarmd`.`processdef`
--

DROP TABLE IF EXISTS `jaguarmd`.`processdef`;
CREATE TABLE  `jaguarmd`.`processdef` (
  `id` int(11) NOT NULL,
  `defname` varchar(100) NOT NULL,
  `processType` smallint(6) NOT NULL,
  `masterent` varchar(100) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Process Definition';

--
-- Dumping data for table `jaguarmd`.`processdef`
--

/*!40000 ALTER TABLE `processdef` DISABLE KEYS */;
LOCK TABLES `processdef` WRITE;
INSERT INTO `jaguarmd`.`processdef` VALUES  (1,'def1',1,'temp'),
 (2,'def2',1,'temp'),
 (3,'def3',1,'temp'),
 (4,'def4',1,'temp'),
 (5,'def5',1,'temp'),
 (6,'def6',1,'temp');
UNLOCK TABLES;
/*!40000 ALTER TABLE `processdef` ENABLE KEYS */;


--
-- Definition of table `jaguarmd`.`task`
--

DROP TABLE IF EXISTS `jaguarmd`.`task`;
CREATE TABLE  `jaguarmd`.`task` (
  `id` int(11) NOT NULL DEFAULT '0',
  `idactivity` int(11) DEFAULT NULL,
  `taskname` varchar(20) DEFAULT NULL,
  `tasktype` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `jaguarmd`.`task`
--

/*!40000 ALTER TABLE `task` DISABLE KEYS */;
LOCK TABLES `task` WRITE;
INSERT INTO `jaguarmd`.`task` VALUES  (1,1,'test',0);
UNLOCK TABLES;
/*!40000 ALTER TABLE `task` ENABLE KEYS */;




/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
