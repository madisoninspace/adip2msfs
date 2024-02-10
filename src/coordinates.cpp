#include "../include/coordinates.hpp"

Coordinates::Coordinate Coordinates::calculate_center(const std::vector<std::string>& latitudes, const std::vector<std::string>& longitudes)
{
    double sumLat = 0.0;
    double sumLon = 0.0;

    // Convert string latitudes to doubles and calculate sum
    for (const auto& lat : latitudes) {
        sumLat += stringToDouble(lat);
    }

    // Convert string longitudes to doubles and calculate sum
    for (const auto& lon : longitudes) {
        sumLon += stringToDouble(lon);
    }

    // Calculate average latitude and longitude
    double avgLat = sumLat / latitudes.size();
    double avgLon = sumLon / longitudes.size();

    return { avgLat, avgLon };
}

string Coordinates::dms_to_decimal(string dms)
{
    string degrees = dms.substr(0, 3);
    string minutes = dms.substr(4, 2);
    string seconds = dms.substr(7, 2);

    float fDegrees = stof(degrees);
    float fMinutes = stof(minutes);
    float fSeconds = stof(seconds);

    float fDecimal = fDegrees + (fMinutes / 60) + (fSeconds / 3600);
    if (dms[dms.length() - 1] == 'S' || dms[dms.length() - 1] == 'W')
    {
        fDecimal *= -1;
    };

    return to_string(fDecimal);
}

double Coordinates::stringToDouble(const string& str) {
    std::istringstream iss(str);
    double result;
    iss >> result;
    return result;
}