#ifndef COORDINATES_HPP
#define COORDINATES_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Coordinates
{
public:
	struct Coordinate {
		double latitude;
		double longitude;
	};
	static Coordinate calculate_center(const std::vector<std::string>& latitudes, const std::vector<std::string>& longitudes);
	static string dms_to_decimal(string dms);
	static double stringToDouble(const std::string& str);
};

#endif // !COORDINATES_HPP
