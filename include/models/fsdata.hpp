#ifndef FSDATA_HPP
#define FSDATA_HPP

#include <cctype>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "airport.hpp"
#include "runway.hpp"
#include "../coordinates.hpp"
#include "../tinyxml2.h"

using namespace std;

class FSData
{
public:
	const char* format_number(string number, bool add_feet);
	void new_airport_element(Airport::AirportItem airport);
	void new_document();
	void new_helipad_element(Runway::RunwayItem runway);
	void new_runway_element(Runway::RunwayItem runway);
	void print_to_console();
	void save(string file);
private:
	tinyxml2::XMLDocument* doc;
	tinyxml2::XMLElement* root;
};

#endif // !FSDATA_HPP
