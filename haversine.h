#ifndef HAVERSINE_H
#define HAVERSINE_H

#define EARTH_RADIUS_KM 6371.0

double degrees_to_radians(double degrees);
double haversine_distance(double lat1, double lon1, double lat2, double lon2);

#endif
