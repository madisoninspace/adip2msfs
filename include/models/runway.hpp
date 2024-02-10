#ifndef RUNWAY_HPP
#define RUNWAY_HPP

#include <future>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <format>

#include "../csv.hpp"

using namespace std;

class Runway
{
public:
    struct RunwayItem {
        string siteId;
        string locId;
        string state;
        string runwayId;
        string length;
        string width;
        string surfaceTypeCondition;
        string surfaceTreatment;
        string pcn;
        string edgeLightIntensity;
        string lengthSource;
        string lengthSourceDate;
        string wbcSingle;
        string wbcDual;
        string wbcTwoDual;
        string wbcTandemTwoDual;
        string baseEndId;
        string baseTrueHeading;
        string baseILSType;
        string baseRightHandTrafficPattern;
        string baseMarkingType;
        string baseMarkingCondition;
        string baseLatitudeDMS;
        string baseLatitudeSeconds;
        string baseLongitudeDMS;
        string baseLongitudeSeconds;
        string baseElevation;
        string baseThresholdHeight;
        string baseVisualGlidePathAngle;
        string baseDisplacedLatitudeDMS;
        string baseDisplacedLatitudeSeconds;
        string baseDisplacedLongitudeDMS;
        string baseDisplacedLongitudeSeconds;
        string baseDisplacedElevation;
        string baseDisplacedThresholdLength;
        string baseTDZElevation;
        string baseVGSI;
        string baseRVR;
        string baseRVV;
        string baseALS;
        string baseREIL;
        string baseCenterlineLights;
        string baseTouchdownLights;
        string baseObstacle;
        string baseObstacleMarkingLighting;
        string baseObstaclePart77;
        string baseObstacleClearanceSlope;
        string baseObstacleHeightAboveRunway;
        string baseObstacleDistanceFromRunway;
        string baseObstacleCenterlineOffset;
        string baseGradient;
        string baseGradientDirection;
        string basePositionSource;
        string basePositionSourceDate;
        string baseElevationSource;
        string baseElevationSourceDate;
        string baseDisplacedPositionSource;
        string baseDisplacedPositionSourceDate;
        string baseElevationPositionSource;
        string baseElevationPositionSourceDate;
        string baseTDZElevationSource;
        string baseTDZElevationSourceDate;
        string baseTORA;
        string baseTODA;
        string baseASDA;
        string baseLDA;
        string baseLAHSO;
        string baseLAHSOId;
        string baseLAHSODesc;
        string baseLAHSOLatitudeDMS;
        string baseLAHSOLatitudeSeconds;
        string baseLAHSOLongitudeDMS;
        string baseLAHSOLongitudeSeconds;
        string baseLAHSOSource;
        string baseLAHSOSourceDate;
        string reciprocalEndId;
        string reciprocalTrueHeading;
        string reciprocalILSType;
        string reciprocalRightHandTrafficPattern;
        string reciprocalMarkingType;
        string reciprocalMarkingCondition;
        string reciprocalLatitudeDMS;
        string reciprocalLatitudeSeconds;
        string reciprocalLongitudeDMS;
        string reciprocalLongitudeSeconds;
        string reciprocalElevation;
        string reciprocalThresholdHeight;
        string reciprocalVisualGlidePathAngle;
        string reciprocalDisplacedLatitudeDMS;
        string reciprocalDisplacedLatitudeSeconds;
        string reciprocalDisplacedLongitudeDMS;
        string reciprocalDisplacedLongitudeSeconds;
        string reciprocalDisplacedElevation;
        string reciprocalDisplacedThresholdLength;
        string reciprocalTDZElevation;
        string reciprocalVGSI;
        string reciprocalRVR;
        string reciprocalRVV;
        string reciprocalALS;
        string reciprocalREIL;
        string reciprocalCenterlineLights;
        string reciprocalTouchdownLights;
        string reciprocalObstacle;
        string reciprocalObstacleMarkingLighting;
        string reciprocalObstaclePart77;
        string reciprocalObstacleClearanceSlope;
        string reciprocalObstacleHeightAboveRunway;
        string reciprocalObstacleDistanceFromRunway;
        string reciprocalObstacleCenterlineOffset;
        string reciprocalGradient;
        string reciprocalGradientDirection;
        string reciprocalPositionSource;
        string reciprocalPositionSourceDate;
        string reciprocalElevationSource;
        string reciprocalElevationSourceDate;
        string reciprocalDisplacedPositionSource;
        string reciprocalDisplacedPositionSourceDate;
        string reciprocalElevationPositionSource;
        string reciprocalElevationPositionSourceDate;
        string reciprocalTDZElevationSource;
        string reciprocalTDZElevationSourceDate;
        string reciprocalTORA;
        string reciprocalTODA;
        string reciprocalASDA;
        string reciprocalLDA;
        string reciprocalLAHSO;
        string reciprocalLAHSOId;
        string reciprocalLAHSODesc;
        string reciprocalLAHSOLatitudeDMS;
        string reciprocalLAHSOLatitudeSeconds;
        string reciprocalLAHSOLongitudeDMS;
        string reciprocalLAHSOLongitudeSeconds;
        string reciprocalLAHSOSource;
        string reciprocalLAHSOSourceDate;
        string icaoId;
    };

    enum Surface : int {
        ASPHALT = 0,
        BITUMINOUS = 1,
        BRICK = 2,
        CLAY = 3,
        CEMENT = 4,
        CONCRETE = 5,
        CORAL = 6,
        DIRT = 7,
        GRASS = 8,
        GRAVEL = 9,
        ICE = 10,
        MACADAM = 11,
        OIL_TREATED = 12,
        PLANKS = 13,
        SAND = 14,
        SHALE = 15,
        SNOW = 16,
        STEEL_MATS = 17,
        TARMAC = 18,
        UNKNOWN = 19,
        WATER = 20,
    };

    vector<RunwayItem> get_all();
    void load_file();
    static string parse_surface(string surface);
    optional<vector<RunwayItem>> runways_by_id(string id);
    static string get_surface_type(int type_id);
private:
    vector<RunwayItem> runways;
    static constexpr const char* surface_types[] = {
        "ASPHALT",
        "BITUMINOUS",
        "BRICK",
        "CLAY",
        "CEMENT",
        "CONCRETE",
        "CORAL",
        "DIRT",
        "GRASS",
        "GRAVEL",
        "ICE",
        "MACADAM",
        "OIL_TREATED",
        "PLANKS",
        "SAND",
        "SHALE",
        "SNOW",
        "STEEL_MATS",
        "TARMAC",
        "UNKNOWN",
        "WATER",
    };
};

#endif // !RUNWAY_HPP
