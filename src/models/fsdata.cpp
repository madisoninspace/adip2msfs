#include "../../include/models/fsdata.hpp"

using namespace std;

const char* FSData::format_number(string number, bool add_feet = true)
{
	string formatted_number = "";
	if (add_feet) {
		formatted_number = format("{}.0F", number);
	}
	else {
		formatted_number = format("{}.0", number);
	}
	return strdup(formatted_number.c_str());
}

void FSData::new_airport_element(Airport::AirportItem airport)
{
	tinyxml2::XMLElement* airportElement = doc->NewElement("Airport");
	airportElement->SetAttribute("lat", airport.arpLatitudeDD.c_str());
	airportElement->SetAttribute("lon", airport.arpLongitudeDD.c_str());
	airportElement->SetAttribute("alt", FSData::format_number(airport.elevation));

	if (airport.icaoId.length() > 0) {
		airportElement->SetAttribute("ident", airport.icaoId.c_str());
	}
	else {
		airportElement->SetAttribute("ident", airport.locId.c_str());
	}

	airportElement->SetAttribute("name", airport.name.c_str());
	airportElement->SetAttribute("city", airport.city.c_str());
	airportElement->SetAttribute("magvar", Airport::parse_magnetic_variation(airport.magneticVariation).c_str());

	if (root) {
		root->InsertEndChild(airportElement);
	}
}

void FSData::new_document()
{
	doc = new tinyxml2::XMLDocument();
	tinyxml2::XMLDeclaration* decl = doc->NewDeclaration();
	doc->InsertFirstChild(decl);

	tinyxml2::XMLElement* fsdata = doc->NewElement("FSData");
	fsdata->SetAttribute("Version", "9.0");
	doc->InsertEndChild(fsdata);

	root = doc->FirstChildElement("FSData");
}

void FSData::new_helipad_element(Runway::RunwayItem runway)
{
	tinyxml2::XMLElement* runwayElement = doc->NewElement("Helipad");
	runwayElement->SetAttribute("lat", Coordinates::dms_to_decimal(runway.baseLatitudeDMS).c_str());
	runwayElement->SetAttribute("lon", Coordinates::dms_to_decimal(runway.baseLongitudeDMS).c_str());
	runwayElement->SetAttribute("alt", FSData::format_number(runway.baseElevation));
	runwayElement->SetAttribute("surface", Runway::parse_surface(runway.surfaceTypeCondition).c_str());
	runwayElement->SetAttribute("heading", FSData::format_number("0", false));
	runwayElement->SetAttribute("length", FSData::format_number(runway.length));
	runwayElement->SetAttribute("width", FSData::format_number(runway.width));
	runwayElement->SetAttribute("type", "H");

	if (root) {
		root->FirstChildElement("Airport")->InsertEndChild(runwayElement);
	}
}

void FSData::new_runway_element(Runway::RunwayItem runway)
{
	tinyxml2::XMLElement* runwayElement = doc->NewElement("Runway");

	vector<string> latitudes;
	vector<string> longitudes;
	string baseLat = Coordinates::dms_to_decimal(runway.baseLatitudeDMS);
	string baseLon = Coordinates::dms_to_decimal(runway.baseLongitudeDMS);
	string recipLat = Coordinates::dms_to_decimal(runway.reciprocalLatitudeDMS);
	string recipLon = Coordinates::dms_to_decimal(runway.reciprocalLongitudeDMS);

	latitudes.push_back(baseLat);
	latitudes.push_back(recipLat);
	longitudes.push_back(baseLon);
	longitudes.push_back(recipLon);

	Coordinates::Coordinate coords = Coordinates::calculate_center(latitudes, longitudes);
	runwayElement->SetAttribute("lat", coords.latitude);
	runwayElement->SetAttribute("lon", coords.longitude);

	string elevation = format("{}F", runway.baseElevation);
	const char* formatted_elevation = elevation.c_str();
	runwayElement->SetAttribute("alt", formatted_elevation);

	runwayElement->SetAttribute("surface", Runway::parse_surface(runway.surfaceTypeCondition).c_str());
	runwayElement->SetAttribute("heading", FSData::format_number(runway.baseTrueHeading, false));
	runwayElement->SetAttribute("length", FSData::format_number(runway.length));
	runwayElement->SetAttribute("width", FSData::format_number(runway.width));

	if (!isalpha(runway.runwayId[0])) {
		runwayElement->SetAttribute("number", runway.runwayId.substr(0, 2).c_str());
		
		if (isalpha(runway.runwayId[2])) {
			runwayElement->SetAttribute("designator", runway.runwayId.substr(2, 1).c_str());
		}
	}

	if (root) {
		root->FirstChildElement("Airport")->InsertEndChild(runwayElement);
	}
}

void FSData::print_to_console()
{
	tinyxml2::XMLPrinter printer;
	doc->Print(&printer);
	cout << printer.CStr() << endl;
}

void FSData::save(string file)
{
	FILE* newFile = fopen(file.c_str(), "w");
	doc->SaveFile(newFile);
}
