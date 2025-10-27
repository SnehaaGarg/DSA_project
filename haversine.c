#include <math.h>
#include "haversine.h"

double degrees_to_radians(double degrees) {
    return degrees * M_PI / 180.0;
}

double haversine_distance(double lat1, double lon1, double lat2, double lon2) {
    double lat1_rad = degrees_to_radians(lat1);
    double lon1_rad = degrees_to_radians(lon1);
    double lat2_rad = degrees_to_radians(lat2);
    double lon2_rad = degrees_to_radians(lon2);
    
    double dlat = lat2_rad - lat1_rad;
    double dlon = lon2_rad - lon1_rad;
    
    double a = sin(dlat/2) * sin(dlat/2) + 
               cos(lat1_rad) * cos(lat2_rad) * 
               sin(dlon/2) * sin(dlon/2);
    
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    
    return EARTH_RADIUS_KM * c;
}
