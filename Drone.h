#ifndef DRONE_H
#define DRONE_H

#include <string>
#include <vector>

class Drone {
public:

    struct Waypoint {
        double latitude;
        double longitude;
    };

    // Constructor
    Drone(double start_lat, double start_lon);

    // Public variables to hold telemetry data
    double latitude;
    double longitude;
    double altitude;
    double speed;

    double fuelLevel;
    double windSpeed;
    double windDirection; // In degrees
    bool isGPSError;

    void loadFlightPlan(const std::string& filename);

    // Public funcs
    void updatePosition();
    void printStatus();

private:
    // ---Private variables for navigation ---
    std::vector<Waypoint> flightPlan;
    size_t currentWaypointIndex;


};

#endif // DRONE_H