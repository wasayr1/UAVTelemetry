#include <thread>   // For pausing the program
#include <chrono>   // For time durations
#include "Drone.h"  

int main() {
    // Creating a Drone object with a starting location (e.g., BU)
    Drone myUAV(42.3505, -71.1054);

    // The main simulation loop
    while (true) {
        myUAV.updatePosition();
        myUAV.printStatus();

        // Pause the loop for 1 second to simulate a real-time data stream
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}