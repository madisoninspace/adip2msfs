#include "../../include/models/airport.hpp"

using namespace std;

vector<Airport::AirportItem> Airport::get_all()
{
    return airports;
}

void Airport::load_file()
{
    try {
        csv::CSVReader reader("data/airports.csv");
        csv::CSVRow row;

        while (reader.read_row(row)) {
            Airport::AirportItem airport;
            airport.siteId = row[0].get();
            airport.facilityType = row[1].get();
            airport.locId = row[2].get();
            airport.effectiveDate = row[3].get();
            airport.region = row[4].get();
            airport.ado = row[5].get();
            airport.stateId = row[6].get();
            airport.stateName = row[7].get();
            airport.county = row[8].get();
            airport.countyState = row[9].get();
            airport.city = row[10].get();
            airport.name = row[11].get();
            airport.ownership = row[12].get();
            airport.use = row[13].get();
            airport.owner = row[14].get();
            airport.ownerAddress = row[15].get();
            airport.ownerCityStateZip = row[16].get();
            airport.ownerPhone = row[17].get();
            airport.manager = row[18].get();
            airport.managerAddress = row[19].get();
            airport.managerCityStateZip = row[20].get();
            airport.managerPhone = row[21].get();
            airport.arpLatitude = row[22].get();
            airport.arpLatitudeSec = row[23].get();
            airport.arpLongitude = row[24].get();
            airport.arpLongitudeSec = row[25].get();
            airport.arpMethod = row[26].get();
            airport.elevation = row[27].get();
            airport.elevationMethod = row[28].get();
            airport.magneticVariation = row[29].get();
            airport.magneticVariationYear = row[30].get();
            airport.trafficPatternAltitude = row[31].get();
            airport.sectional = row[32].get();
            airport.distanceFromCBD = row[33].get();
            airport.directionFromCBD = row[34].get();
            airport.landArea = row[35].get();
            airport.artccId = row[36].get();
            airport.artccComputerId = row[37].get();
            airport.artccName = row[38].get();
            airport.responsibleArtccId = row[39].get();
            airport.responsibleArtccComputerId = row[40].get();
            airport.responsibleArtccName = row[41].get();
            airport.tieInFSS = row[42].get();
            airport.tieInFSSId = row[43].get();
            airport.tieInFSSName = row[44].get();
            airport.fssPhoneNumber = row[45].get();
            airport.fssTollFreeNumber = row[46].get();
            airport.alternateFSSId = row[47].get();
            airport.alternateFSSName = row[48].get();
            airport.alternateFSSTollFreeNumber = row[49].get();
            airport.notamFacilityId = row[50].get();
            airport.notamService = row[51].get();
            airport.activationDate = row[52].get();
            airport.airportStatusCode = row[53].get();
            airport.certificationTypeDate = row[54].get();
            airport.federalAgreements = row[55].get();
            airport.airspaceDetermination = row[56].get();
            airport.customsAirportOfEntry = row[57].get();
            airport.customsLandingRights = row[58].get();
            airport.militaryJointUse = row[59].get();
            airport.militaryLandingRights = row[60].get();
            airport.inspectionMethod = row[61].get();
            airport.inspectionGroup = row[62].get();
            airport.lastInspectionDate = row[63].get();
            airport.lastOwnerInformationDate = row[64].get();
            airport.fuelTypes = row[65].get();
            airport.airframeRepair = row[66].get();
            airport.powerPlantRepair = row[67].get();
            airport.bottledOxygenType = row[68].get();
            airport.bulkOxygenType = row[69].get();
            airport.lightingSchedule = row[70].get();
            airport.beaconSchedule = row[71].get();
            airport.atct = row[72].get();
            airport.unicom = row[73].get();
            airport.ctaf = row[74].get();
            airport.segmentedCircle = row[75].get();
            airport.beaconColor = row[76].get();
            airport.nonCommercialLandingFee = row[77].get();
            airport.medicalUse = row[78].get();
            airport.singleEngineAircraft = row[79].get();
            airport.multiEngineAircraft = row[80].get();
            airport.jetEngineAircraft = row[81].get();
            airport.helicopters = row[82].get();
            airport.glidersOperational = row[83].get();
            airport.militaryOperational = row[84].get();
            airport.ultralights = row[85].get();
            airport.commercialOperations = row[86].get();
            airport.commuterOperations = row[87].get();
            airport.airTaxiOperations = row[88].get();
            airport.gaLocalOperations = row[89].get();
            airport.gaItinOperations = row[90].get();
            airport.militaryOperations = row[91].get();
            airport.operationsDate = row[92].get();
            airport.airportPositionSource = row[93].get();
            airport.airportPositionSourceDate = row[94].get();
            airport.airportElevationSource = row[95].get();
            airport.airportElevationSourceDate = row[96].get();
            airport.fuelAvailable = row[97].get();
            airport.transientStorage = row[98].get();
            airport.otherServices = row[99].get();
            airport.windIndicator = row[100].get();
            airport.icaoId = row[101].get();
            airport.npiaHub = row[102].get();
            airport.npiaRole = row[103].get();
            airport.arpLatitudeDD = row[104].get();
            airport.arpLongitudeDD = row[105].get();

            airports.push_back(airport);
        }

        cout << "Airports loaded." << endl;
    }
    catch (const std::exception& ex) {
        cout << "Error reading airports file. " << ". Exception: " << ex.what() << std::endl;
    }
}

string Airport::parse_magnetic_variation(string magvar)
{
    string magvar_number = magvar.substr(0, 2);
    if (magvar_number.substr(0, 1) == "0") {
        magvar_number = magvar.substr(1, 1);
    }

    if (magvar.length() > 0) {
        string magvar_letter = magvar.substr(2, 1);
        if (magvar_letter == "E") {
            return format("{}.0", magvar_number);
        }
        else {
            return format("-{}.0", magvar_number);
        }
    }
    else {
        return "";
    }
}

optional<Airport::AirportItem> Airport::single_by_loc_id(string id)
{
    for (auto& ap : airports) {
        if (ap.locId == id) {
            return ap;
        }
    }

    return {};
}

optional<Airport::AirportItem> Airport::single_by_icao_id(string id)
{
    for (auto& ap : airports) {
        if (ap.icaoId == id) {
            return ap;
        }
    }

    return {};
}
