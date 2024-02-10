#ifndef AIRPORT_HPP
#define AIRPORT_HPP

#include <future>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <format>

#include "../csv.hpp"

using namespace std;

class Airport
{
public:
    struct AirportItem {
        string siteId;
        string facilityType;
        string locId;
        string effectiveDate;
        string region;
        string ado;
        string stateId;
        string stateName;
        string county;
        string countyState;
        string city;
        string name;
        string ownership;
        string use;
        string owner;
        string ownerAddress;
        string ownerCityStateZip;
        string ownerPhone;
        string manager;
        string managerAddress;
        string managerCityStateZip;
        string managerPhone;
        string arpLatitude;
        string arpLatitudeSec;
        string arpLongitude;
        string arpLongitudeSec;
        string arpMethod;
        string elevation;
        string elevationMethod;
        string magneticVariation;
        string magneticVariationYear;
        string trafficPatternAltitude;
        string sectional;
        string distanceFromCBD;
        string directionFromCBD;
        string landArea;
        string artccId;
        string artccComputerId;
        string artccName;
        string responsibleArtccId;
        string responsibleArtccComputerId;
        string responsibleArtccName;
        string tieInFSS;
        string tieInFSSId;
        string tieInFSSName;
        string fssPhoneNumber;
        string fssTollFreeNumber;
        string alternateFSSId;
        string alternateFSSName;
        string alternateFSSTollFreeNumber;
        string notamFacilityId;
        string notamService;
        string activationDate;
        string airportStatusCode;
        string certificationTypeDate;
        string federalAgreements;
        string airspaceDetermination;
        string customsAirportOfEntry;
        string customsLandingRights;
        string militaryJointUse;
        string militaryLandingRights;
        string inspectionMethod;
        string inspectionGroup;
        string lastInspectionDate;
        string lastOwnerInformationDate;
        string fuelTypes;
        string airframeRepair;
        string powerPlantRepair;
        string bottledOxygenType;
        string bulkOxygenType;
        string lightingSchedule;
        string beaconSchedule;
        string atct;
        string unicom;
        string ctaf;
        string segmentedCircle;
        string beaconColor;
        string nonCommercialLandingFee;
        string medicalUse;
        string singleEngineAircraft;
        string multiEngineAircraft;
        string jetEngineAircraft;
        string helicopters;
        string glidersOperational;
        string militaryOperational;
        string ultralights;
        string commercialOperations;
        string commuterOperations;
        string airTaxiOperations;
        string gaLocalOperations;
        string gaItinOperations;
        string militaryOperations;
        string operationsDate;
        string airportPositionSource;
        string airportPositionSourceDate;
        string airportElevationSource;
        string airportElevationSourceDate;
        string fuelAvailable;
        string transientStorage;
        string otherServices;
        string windIndicator;
        string icaoId;
        string npiaHub;
        string npiaRole;
        string arpLatitudeDD;
        string arpLongitudeDD;
    };

    vector<AirportItem> get_all();
    void load_file();
    static string parse_magnetic_variation(string magvar);
    optional<AirportItem> single_by_loc_id(string id);
    optional<AirportItem> single_by_icao_id(string id);
private:
    vector<AirportItem> airports;
};

#endif // !AIRPORT_HPP
