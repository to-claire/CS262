// To, Claire

#include <iostream>
#include <string>
#include <iomanip>

#include "functions.h"

using namespace std;

int main(){
    // Implement your main program here using the functions declared in funtions.h
    const int NUM_VEHICLES = 4;
    double distance = convertDistance(
            getInput("Enter the distance between the wires (inches): "));

    double time[NUM_VEHICLES];
    for (int i = 0; i < NUM_VEHICLES; ++i)
    {
        time[i] = getInput(
                "Enter time recorded (seconds): ");
    }

    cout << "Vehicle"
        << setw(20) << "Time (seconds)"
        << setw(20) << "Speed (m/s)"
        << setw(20) << "Speed (mph)" << endl;

    for (int i = 0; i < NUM_VEHICLES; ++i)
    {
        cout << (i + 1);
        cout << right << fixed << setprecision(2)
            << setw(26) << time[i]
            << setw(20) << getSpeed(distance, time[i])
            << setw(20) << convertSpeed(
                    getSpeed(distance, time[i])) << endl;
    }

    return 0;
}
