#include <iostream>

using namespace std;

class Time {
private:
    int hours, minutes, seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    // Overloaded insertion operator (<<)
    friend ostream& operator<<(ostream& os, const Time& time) {
        os << time.hours << ":" << time.minutes << ":" << time.seconds;
        return os;
    }

    // Overloaded extraction operator (>>)
    friend istream& operator>>(istream& is, Time& time) {
        is >> time.hours >> time.minutes >> time.seconds;
        return is;
    }
    
    Time& operator=(const Time& other) {
        hours = other.hours;
        minutes = other.minutes;
        seconds = other.seconds;
        return *this;  
    }
};

int main() {
    Time time1, time2;

    cout << "Enter time1 (HH:MM:SS): ";
    cin >> time1; 

    cout << "Enter time2 (HH:MM:SS): ";
    cin >> time2;

    cout << "Time 1: " << time1 << endl;
    cout << "Time 2: " << time2 << endl;

    return 0;
}
