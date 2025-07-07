#ifndef DRONE_H
#define DRONE_H

class Drone {
public:
    // Constructor
    Drone(double start_lat, double start_lon);

    // Public variables to hold telemetry data
    double latitude;
    double longitude;
    double altitude;
    double speed;

    // Public funcs
    void updatePosition();
    void printStatus();
};

#endif // DRONE_H