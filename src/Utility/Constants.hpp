/*
 * prjsv 2015-21
 * Marco Antognini & Jamila Sam
 */

#ifndef INFOSV_CONSTANTS_HPP
#define INFOSV_CONSTANTS_HPP

#include <string>

// Numerical constants
double const DEG_TO_RAD = 0.0174532925; ///< Degree to Radian conversion constant
double const TAU = 6.283185307;         ///< TAU constant (= 2 * PI)
double const PI = 3.141592654;          ///< PI constant
double const EPSILON = 1e-8;            ///< a small epsilon value
double const DEFAULT_ANT_SIZE = 20.0;   ///< drawing constant for ants
// Define resources location
std::string const RES_LOCATION = "../res/";

// Define the location of the config file
std::string const DEFAULT_CFG = "app.json";

// Define the location of the font file (could be in the config instead of here)
std::string const APP_FONT_LOCATION = RES_LOCATION + "sansation.ttf";

/// Loader parameters
std::string const MAP_NAME = "MAP_NAME";
// Stats titles
namespace s
{

std::string const GENERAL      = "general";
std::string const WORKER_ANTS  = "worker ants";
std::string const SOLDIER_ANTS = "soldier ants";
std::string const TERMITES     = "termites";
std::string const ANTHILLS     = "anthills";
std::string const FOOD         = "food";
std::string const TEMPERATURE  = "temperature";
} // s

#endif // INFOSV_CONSTANTS_HPP
