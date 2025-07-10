#include <thread>   // For pausing the program
#include <chrono>   // For time durations
#include "Drone.h"  

int main() {
    // Create a Drone object
    Drone myUAV(42.3505, -71.1054); // Starting near BU

    // Load the flight plan ---
    myUAV.loadFlightPlan("waypoints.txt");

    int loop_counter = 0;

    // The main simulation loop
    while (true) {
        // -Periodically change wind conditions ---
        if (loop_counter % 20 == 0) { // Every 20 seconds
            myUAV.windSpeed = rand() % 30; // Wind up to 30 knots
        }
        
        myUAV.updatePosition();
        myUAV.printStatus();

        // Pause for 1 second
        std::this_thread::sleep_for(std::chrono::seconds(1));
        loop_counter++;
    }

    return 0;
}
