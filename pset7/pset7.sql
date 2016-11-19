-- MySQL dump 10.13  Distrib 5.5.50, for debian-linux-gnu (x86_64)
--
-- Host: 0.0.0.0    Database: pset7
-- ------------------------------------------------------
-- Server version	5.5.50-0ubuntu0.14.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `history`
--

DROP TABLE IF EXISTS `history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `history` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `user_id` int(10) unsigned NOT NULL,
  `transaction` varchar(10) NOT NULL,
  `datetime` datetime NOT NULL,
  `symbol` varchar(255) NOT NULL,
  `shares` int(10) unsigned NOT NULL,
  `price` decimal(20,4) unsigned NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `history`
--

LOCK TABLES `history` WRITE;
/*!40000 ALTER TABLE `history` DISABLE KEYS */;
INSERT INTO `history` VALUES (8,11,'BUY','2016-11-04 10:06:20','fb',3,120.0000),(9,11,'SELL','2016-11-04 10:07:56','fb',0,120.0000),(10,11,'BUY','2016-11-04 10:08:20','AAPL',50,109.8300),(11,13,'BUY','2016-11-04 12:38:09','fb',50,120.0000),(12,13,'BUY','2016-11-04 12:38:26','aapl',10,109.8300),(13,13,'SELL','2016-11-04 12:38:59','aapl',0,109.8300);
/*!40000 ALTER TABLE `history` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `portfolio`
--

DROP TABLE IF EXISTS `portfolio`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `portfolio` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `user_id` int(10) unsigned NOT NULL,
  `symbol` varchar(255) NOT NULL,
  `shares` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `portfolio_unique` (`user_id`,`symbol`)
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `portfolio`
--

LOCK TABLES `portfolio` WRITE;
/*!40000 ALTER TABLE `portfolio` DISABLE KEYS */;
INSERT INTO `portfolio` VALUES (16,11,'AAPL',50),(17,13,'fb',50);
/*!40000 ALTER TABLE `portfolio` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(255) NOT NULL,
  `hash` varchar(255) NOT NULL,
  `cash` decimal(65,4) unsigned NOT NULL DEFAULT '0.0000',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'andi','$2y$10$PPoDpX7njg55j8/iNMCKieO..JzNqzrkZjZQuGlV/HC4er0CdnqNm',10000.0000),(2,'caesar','$2y$10$PPoDpX7njg55j8/iNMCKieO..JzNqzrkZjZQuGlV/HC4er0CdnqNm',10000.0000),(3,'eli','$2y$10$PPoDpX7njg55j8/iNMCKieO..JzNqzrkZjZQuGlV/HC4er0CdnqNm',10000.0000),(4,'hdan','$2y$10$PPoDpX7njg55j8/iNMCKieO..JzNqzrkZjZQuGlV/HC4er0CdnqNm',10000.0000),(5,'jason','$2y$10$PPoDpX7njg55j8/iNMCKieO..JzNqzrkZjZQuGlV/HC4er0CdnqNm',10000.0000),(6,'john','$2y$10$PPoDpX7njg55j8/iNMCKieO..JzNqzrkZjZQuGlV/HC4er0CdnqNm',10000.0000),(7,'levatich','$2y$10$PPoDpX7njg55j8/iNMCKieO..JzNqzrkZjZQuGlV/HC4er0CdnqNm',10000.0000),(8,'rob','$2y$10$PPoDpX7njg55j8/iNMCKieO..JzNqzrkZjZQuGlV/HC4er0CdnqNm',10000.0000),(9,'skroob','$2y$10$PPoDpX7njg55j8/iNMCKieO..JzNqzrkZjZQuGlV/HC4er0CdnqNm',10000.0000),(10,'zamyla','$2y$10$PPoDpX7njg55j8/iNMCKieO..JzNqzrkZjZQuGlV/HC4er0CdnqNm',10000.0000),(11,'sasharya05','$2y$10$PPoDpX7njg55j8/iNMCKieO..JzNqzrkZjZQuGlV/HC4er0CdnqNm',12200.0000),(12,'abhijeet','$2y$10$PPoDpX7njg55j8/iNMCKieO..JzNqzrkZjZQuGlV/HC4er0CdnqNm',10000.0000),(13,'kedarNath','$2y$10$PPoDpX7njg55j8/iNMCKieO..JzNqzrkZjZQuGlV/HC4er0CdnqNm',24000.0000);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-11-04 12:49:44
