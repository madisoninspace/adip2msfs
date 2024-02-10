// adip2msfs.cpp : Defines the entry point for the application.
//

#include "../include/adip2msfs.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	cout << "adip2fs v0.2.0\n(C) 2024 Madison L.H. Wass <github.com/madisoninspace>\n" << endl;
	if (argc != 3) {
		cout << "USAGE: adip2fs {Airport Code} {XML File}" << endl;
		return 1;
	}

	if (strlen(argv[1]) < 3 || strlen(argv[1]) > 4) {
		cout << "Invalid airport code." << endl;
		return 1;
	}

	// Data checks
	if (!filesystem::exists("data/airports.csv")) {
		cout << "ERROR: Airports CSV is missing." << endl;
		return 1;
	}
	if (!filesystem::exists("data/runways.csv")) {
		cout << "ERROR: Runways CSV is missing." << endl;
		return 1;
	}

	// Load files
	Airport* airport = new Airport();
	Runway* runway = new Runway();
	airport->load_file();
	runway->load_file();

	//
	optional<Airport::AirportItem> apt = airport->single_by_loc_id(string(argv[1]));
	if (!apt.has_value()) {
		cout << "ERROR: No matching airport found." << endl;
		return 1;
	}
	optional<vector<Runway::RunwayItem>> runways = runway->runways_by_id(apt.value().locId);
	if (!runways.has_value()) {
		cout << "ERROR: This airport did not have any suitable runways or helipads" << endl;
		return 1;
	}

	FSData* fsd = new FSData();
	fsd->new_document();
	fsd->new_airport_element(apt.value());
	for (auto& rwy : runways.value()) {
		if (rwy.runwayId.substr(0, 1) == "H") {
			fsd->new_helipad_element(rwy);
		}
		else {
			fsd->new_runway_element(rwy);
		}
	}
	fsd->save(string(argv[2]));

	cout << "Complete." << endl;

	return 0;
}
