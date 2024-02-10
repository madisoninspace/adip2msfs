#include "../../include/models/runway.hpp"

using namespace std;

vector<Runway::RunwayItem> Runway::get_all() 
{
	return runways;
}

void Runway::load_file()
{
    csv::CSVReader reader("data/runways.csv");
    csv::CSVRow row;

    try {
        while (reader.read_row(row)) {
            Runway::RunwayItem runway;
            runway.siteId = row[0].get();
            runway.locId = row[1].get();
            runway.state = row[2].get();
            runway.runwayId = row[3].get();
            runway.length = row[4].get();
            runway.width = row[5].get();
            runway.surfaceTypeCondition = row[6].get();
            runway.surfaceTreatment = row[7].get();
            runway.pcn = row[8].get();
            runway.edgeLightIntensity = row[9].get();
            runway.lengthSource = row[10].get();
            runway.lengthSourceDate = row[11].get();
            runway.wbcSingle = row[12].get();
            runway.wbcDual = row[13].get();
            runway.wbcTwoDual = row[14].get();
            runway.wbcTandemTwoDual = row[15].get();
            runway.baseEndId = row[16].get();
            runway.baseTrueHeading = row[17].get();
            runway.baseILSType = row[18].get();
            runway.baseRightHandTrafficPattern = row[19].get();
            runway.baseMarkingType = row[20].get();
            runway.baseMarkingCondition = row[21].get();
            runway.baseLatitudeDMS = row[22].get();
            runway.baseLatitudeSeconds = row[23].get();
            runway.baseLongitudeDMS = row[24].get();
            runway.baseLongitudeSeconds = row[25].get();
            runway.baseElevation = row[26].get();
            runway.baseThresholdHeight = row[27].get();
            runway.baseVisualGlidePathAngle = row[28].get();
            runway.baseDisplacedLatitudeDMS = row[29].get();
            runway.baseDisplacedLatitudeSeconds = row[30].get();
            runway.baseDisplacedLongitudeDMS = row[31].get();
            runway.baseDisplacedLongitudeSeconds = row[32].get();
            runway.baseDisplacedElevation = row[33].get();
            runway.baseDisplacedThresholdLength = row[34].get();
            runway.baseTDZElevation = row[35].get();
            runway.baseVGSI = row[36].get();
            runway.baseRVR = row[37].get();
            runway.baseRVV = row[38].get();
            runway.baseALS = row[39].get();
            runway.baseREIL = row[40].get();
            runway.baseCenterlineLights = row[41].get();
            runway.baseTouchdownLights = row[42].get();
            runway.baseObstacle = row[43].get();
            runway.baseObstacleMarkingLighting = row[44].get();
            runway.baseObstaclePart77 = row[45].get();
            runway.baseObstacleClearanceSlope = row[46].get();
            runway.baseObstacleHeightAboveRunway = row[47].get();
            runway.baseObstacleDistanceFromRunway = row[48].get();
            runway.baseObstacleCenterlineOffset = row[49].get();
            runway.baseGradient = row[50].get();
            runway.baseGradientDirection = row[51].get();
            runway.basePositionSource = row[52].get();
            runway.basePositionSourceDate = row[53].get();
            runway.baseElevationSource = row[54].get();
            runway.baseElevationSourceDate = row[55].get();
            runway.baseDisplacedPositionSource = row[56].get();
            runway.baseDisplacedPositionSourceDate = row[57].get();
            runway.baseElevationPositionSource = row[58].get();
            runway.baseElevationPositionSourceDate = row[59].get();
            runway.baseTDZElevationSource = row[60].get();
            runway.baseTDZElevationSourceDate = row[61].get();
            runway.baseTORA = row[62].get();
            runway.baseTODA = row[63].get();
            runway.baseASDA = row[64].get();
            runway.baseLDA = row[65].get();
            runway.baseLAHSO = row[66].get();
            runway.baseLAHSOId = row[67].get();
            runway.baseLAHSODesc = row[68].get();
            runway.baseLAHSOLatitudeDMS = row[69].get();
            runway.baseLAHSOLatitudeSeconds = row[70].get();
            runway.baseLAHSOLongitudeDMS = row[71].get();
            runway.baseLAHSOLongitudeSeconds = row[72].get();
            runway.baseLAHSOSource = row[73].get();
            runway.baseLAHSOSourceDate = row[74].get();
            runway.reciprocalEndId = row[75].get();
            runway.reciprocalTrueHeading = row[76].get();
            runway.reciprocalILSType = row[77].get();
            runway.reciprocalRightHandTrafficPattern = row[78].get();
            runway.reciprocalMarkingType = row[79].get();
            runway.reciprocalMarkingCondition = row[80].get();
            runway.reciprocalLatitudeDMS = row[81].get();
            runway.reciprocalLatitudeSeconds = row[82].get();
            runway.reciprocalLongitudeDMS = row[83].get();
            runway.reciprocalLongitudeSeconds = row[84].get();
            runway.reciprocalElevation = row[85].get();
            runway.reciprocalThresholdHeight = row[86].get();
            runway.reciprocalVisualGlidePathAngle = row[87].get();
            runway.reciprocalDisplacedLatitudeDMS = row[88].get();
            runway.reciprocalDisplacedLatitudeSeconds = row[89].get();
            runway.reciprocalDisplacedLongitudeDMS = row[90].get();
            runway.reciprocalDisplacedLongitudeSeconds = row[91].get();
            runway.reciprocalDisplacedElevation = row[92].get();
            runway.reciprocalDisplacedThresholdLength = row[93].get();
            runway.reciprocalTDZElevation = row[94].get();
            runway.reciprocalVGSI = row[95].get();
            runway.reciprocalRVR = row[96].get();
            runway.reciprocalRVV = row[97].get();
            runway.reciprocalALS = row[98].get();
            runway.reciprocalREIL = row[99].get();
            runway.reciprocalCenterlineLights = row[100].get();
            runway.reciprocalTouchdownLights = row[101].get();
            runway.reciprocalObstacle = row[102].get();
            runway.reciprocalObstacleMarkingLighting = row[103].get();
            runway.reciprocalObstaclePart77 = row[104].get();
            runway.reciprocalObstacleClearanceSlope = row[105].get();
            runway.reciprocalObstacleHeightAboveRunway = row[106].get();
            runway.reciprocalObstacleDistanceFromRunway = row[107].get();
            runway.reciprocalObstacleCenterlineOffset = row[108].get();
            runway.reciprocalGradient = row[109].get();
            runway.reciprocalGradientDirection = row[110].get();
            runway.reciprocalPositionSource = row[111].get();
            runway.reciprocalPositionSourceDate = row[112].get();
            runway.reciprocalElevationSource = row[113].get();
            runway.reciprocalElevationSourceDate = row[114].get();
            runway.reciprocalDisplacedPositionSource = row[115].get();
            runway.reciprocalDisplacedPositionSourceDate = row[116].get();
            runway.reciprocalElevationPositionSource = row[117].get();
            runway.reciprocalElevationPositionSourceDate = row[118].get();
            runway.reciprocalTDZElevationSource = row[119].get();
            runway.reciprocalTDZElevationSourceDate = row[120].get();
            runway.reciprocalTORA = row[121].get();
            runway.reciprocalTODA = row[122].get();
            runway.reciprocalASDA = row[123].get();
            runway.reciprocalLDA = row[124].get();
            runway.reciprocalLAHSO = row[125].get();
            runway.reciprocalLAHSOId = row[126].get();
            runway.reciprocalLAHSODesc = row[127].get();
            runway.reciprocalLAHSOLatitudeDMS = row[128].get();
            runway.reciprocalLAHSOLatitudeSeconds = row[129].get();
            runway.reciprocalLAHSOLongitudeDMS = row[130].get();
            runway.reciprocalLAHSOLongitudeSeconds = row[131].get();
            runway.reciprocalLAHSOSource = row[132].get();
            runway.reciprocalLAHSOSourceDate = row[133].get();
            runway.icaoId = row[134].get();

            runways.push_back(runway);
        }

        cout << "Runways loaded." << endl;
    }
    catch (const std::exception& ex) {
        std::cout << "Error reading runways file. Exception: " << ex.what() << std::endl;
    }
}

string Runway::parse_surface(string surface)
{
    Runway::Surface surfaceType = Runway::Surface::UNKNOWN;

    if (surface == "ICE") {
        surface = Runway::Surface::ICE;
    }
    else {
        string sfc = surface.substr(0, 4);

        if (sfc == "CONC") {
            surfaceType = Runway::Surface::CONCRETE;
        }
        else if (sfc == "ASPH") {
            surfaceType = Runway::Surface::ASPHALT;
        }
        else if (sfc == "SNOW") {
            surfaceType = Runway::Surface::SNOW;
        }
        else if (sfc == "MATS") {
            surfaceType = Runway::Surface::STEEL_MATS;
        }
        else if (sfc == "TREA") {
            surfaceType = Runway::Surface::OIL_TREATED;
        }
        else if (sfc == "GRAV") {
            surfaceType = Runway::Surface::GRAVEL;
        }
        else if (sfc == "TURF") {
            surfaceType = Runway::Surface::GRASS;
        }
        else if (sfc == "DIRT") {
            surfaceType = Runway::Surface::DIRT;
        }
        else if (sfc == "WATE") {
            surfaceType = Runway::Surface::WATER;
        }
    }

    return get_surface_type(surfaceType);
}

optional<vector<Runway::RunwayItem>> Runway::runways_by_id(string id)
{
    vector<Runway::RunwayItem> rwys;

    for (auto& rwy : runways) {
        if (rwy.locId == id)
        {
            rwys.push_back(rwy);
        }
    }

    if (rwys.size() > 0) {
        return rwys;
    }
    else {
        return {};
    }
}

string Runway::get_surface_type(int type_id)
{
    const char* surface = surface_types[type_id];
    return string(surface);
}

