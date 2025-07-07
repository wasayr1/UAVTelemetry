#include <iostream>
#include "Drone.h"

Drone::Drone(double start_lat, double start_lon) {
    latitude = start_lat;
    longitude = start_lon;
    altitude = 0.0;
    speed = 0.0;
    std::cout << "Drone object created at Lat/Lon: " << latitude << "/" << longitude << std::endl;
}

void Drone::updatePosition() {
    latitude += 0.0001; // Simulate moving north
    longitude += 0.0001; // Simulate moving east
    if (altitude < 1000.0) {
        altitude += 15.5; // Simulate climbing
    }
}

void Drone::printStatus() {
    std::cout << "--- Telemetry Update ---\n";
    std::cout << "  Latitude:  " << latitude << "\n";
    std::cout << "  Longitude: " << longitude << "\n";
    std::cout << "  Altitude:  " << altitude << " ft\n";
    std::cout << "------------------------\n\n";
}