#include <iostream>
#include <fstream>   
#include <sstream>   
#include <cmath>     
#include <random>    
#include "Drone.h"

Drone::Drone(double start_lat, double start_lon) {
    latitude = start_lat;
    longitude = start_lon;
    altitude = 0.0;
    speed = 50.0;

    fuelLevel = 100.0;
    windSpeed = 0.0;
    windDirection = 0.0;
    isGPSError = false;
    currentWaypointIndex = 0;
    std::cout << "Drone object created at Lat/Lon: " << latitude << "/" << longitude << std::endl;
}

void Drone::loadFlightPlan(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open flight plan file: " << filename << std::endl;
        return;
    }

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string lat_str, lon_str;

        if (std::getline(ss, lat_str, ',') && std::getline(ss, lon_str)) {
            Waypoint wp = {std::stod(lat_str), std::stod(lon_str)};
            flightPlan.push_back(wp);
        }
    }
    std::cout << "Flight plan loaded with " << flightPlan.size() << " waypoints." << std::endl;
}

void Drone::updatePosition() {
    // 1. Check for mission-ending conditions
    if (currentWaypointIndex >= flightPlan.size()) {
        std::cout << "Mission Complete: All waypoints reached." << std::endl;
        // Optional: Make the drone loiter or land
        speed = 0;
        return;
    }
    if (fuelLevel <= 0) {
        std::cout << "CRITICAL: Out of fuel!" << std::endl;
        speed = 0;
        // Optional: Simulate a crash
        altitude = 0;
        return;
    }

    // 2. Get current target waypoint
    Waypoint target = flightPlan[currentWaypointIndex];

    // 3. Calculate vector to target
    double deltaLat = target.latitude - latitude;
    double deltaLon = target.longitude - longitude;
    double distance = std::sqrt(deltaLat * deltaLat + deltaLon * deltaLon);

    // 4. Check if we have reached the waypoint
    // (Using a small threshold, since floating point numbers are imprecise)
    if (distance < 0.0001) {
        std::cout << "Waypoint " << currentWaypointIndex + 1 << " reached!" << std::endl;
        currentWaypointIndex++;
        return;
    }

    // 5. Move towards the target
    double moveLat = (deltaLat / distance) * (speed / 50000.0); // Scaled for simulation
    double moveLon = (deltaLon / distance) * (speed / 50000.0);

    latitude += moveLat;
    longitude += moveLon;

    // a. Add wind effect (a small random push)
    latitude += (rand() % 10 - 5) / 100000.0 * (windSpeed / 50.0);
    longitude += (rand() % 10 - 5) / 100000.0 * (windSpeed / 50.0);

    // b. Consume fuel
    fuelLevel -= 0.1; // Constant consumption rate

    // c. Simulate a random GPS error (1% chance each update)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 100);
    if (distrib(gen) == 1) {
        isGPSError = !isGPSError; // Toggle the error state
    }
}

void Drone::printStatus() {
    std::cout << "--- Telemetry Update ---\n";

    if (isGPSError) {
        std::cout << "  GPS STATUS:  SIGNAL LOST!\n";
    } else {
        std::cout << "  Latitude:    " << latitude << "\n";
        std::cout << "  Longitude:   " << longitude << "\n";
    }

    std::cout << "  Altitude:    " << altitude << " ft\n";
    std::cout << "  Speed:       " << speed << " knots\n";
    std::cout << "  Fuel:        " << fuelLevel << "%\n";
    std::cout << "  Wind Speed:  " << windSpeed << " knots\n";

    if (currentWaypointIndex < flightPlan.size()) {
        std::cout << "  Heading to WP " << currentWaypointIndex + 1 << " ["
                  << flightPlan[currentWaypointIndex].latitude << ", "
                  << flightPlan[currentWaypointIndex].longitude << "]\n";
    } else {
        std::cout << "  Mission Status: COMPLETE\n";
    }

    std::cout << "------------------------\n\n";
}