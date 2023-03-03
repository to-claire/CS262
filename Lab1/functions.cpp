// To, Claire

#include "functions.h"

#include <iostream>
#include <iomanip>

using namespace std;

const double INCHES_TO_METERS = 2.5 / 100.0;
const double METERS_PER_SEC_TO_MILES_PER_HOUR = 3600.0 / 1609.0;

// Implement the functions from functions.h here

// Asks user for input using prompt
// until user enters positive number
double getInput(const string& prompt)
{
    double num = 0.0;
    while (num <= 0)
    {
        cout << prompt;
        cin >> num;
    }
    return num;
}

// converts inches to meters
double convertDistance(double inches)
{
    return (inches * INCHES_TO_METERS);
}

// converts meters/second to miles/hour
double convertSpeed(double metersPerSec)
{
    return (metersPerSec * METERS_PER_SEC_TO_MILES_PER_HOUR);
}

// determines velocity (meters/second) using the distance (in meters)
// and time (in seconds)
// velocity assumed to be constant
double getSpeed(double distance, double seconds)
{
    return (distance / seconds);
}