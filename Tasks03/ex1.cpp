#include <iostream>
#include <format>
#include <print>

using std::cin;
using std::cout;

class Time {
private:
    int hours = 0;
    int minutes = 0;
    int seconds = 0;

public:
    Time() : hours(0), minutes(0), seconds(0) {}

    Time(int h, int m, int s) {
        setTime(h, m, s);
    }

    void setTime(int h, int m, int s) {
        if (h >= 0 && h <= 23
            && m >= 0 && m <= 59
            && s >= 0 && s <= 59) {

            hours = h;
            minutes = m;
            seconds = s;
        }
    }

    int toSeconds() const {
        return seconds + minutes * 60 + hours * 3600;
    }

    Time secondsToTime(int totalSeconds) const {
        int hours = (totalSeconds / 3600) % 24;
        int minutes = (totalSeconds % 3600) / 60;
        int seconds = (totalSeconds % 3600) % 60;

        Time t = { hours, minutes, seconds };
        return t;
    }

    Time timeTillMidnight() const {
        int totalSecondsInDay = 24 * 3600;

        int remainingSeconds = totalSecondsInDay - toSeconds();
        Time remaining = secondsToTime(remainingSeconds);

        return remaining;
    }

    Time addOneSecond() const {
        int totalSeconds = toSeconds() + 1;
        Time t = secondsToTime(totalSeconds);

        return t;
    }

    bool isDinnerTime() const {

        Time start = { 20, 30 , 00 };
        Time end = { 22, 00 , 00 };

        int currentTime = toSeconds();

        return (currentTime >= start.toSeconds() && currentTime <= end.toSeconds());
    }

    bool isPartyTime() const {
        Time start = { 23, 00, 00 };
        Time end = { 06, 00, 00 };

        int currentTime = toSeconds();

        return (currentTime >= start.toSeconds() || currentTime <= end.toSeconds());
    }

    Time diff(const Time& other) const {
        int diffInSeconds = abs(toSeconds() - other.toSeconds());
        Time diff = secondsToTime(diffInSeconds);

        return diff;
    }

    bool isBefore(const Time& other) const {

        return toSeconds() < other.toSeconds();
    }

    bool isAfter(const Time& other) const {

        return toSeconds() > other.toSeconds();
    }

    void printTime() const {
        std::println("{:02}:{:02}:{:02}", hours, minutes, seconds);
    }
};

void sortTimes(Time* times, int size) {
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (times[j].isAfter(times[j + 1])) {
                std::swap(times[j], times[j + 1]);
            }
        }
    }
}

int main()
{
    Time t1 = { 23, 59, 59 };
    Time t2 = { 21, 00, 00 };

    Time t3 = t2.timeTillMidnight();
    cout << "Time to midnight: ";
    t3.printTime();
    
    cout << '\n';

    if (t2.isDinnerTime()) {
        cout << " - Time for dinner - ";
        t2.printTime();
    }
       
    if (t1.isPartyTime()) {
        cout << " - Time for party - ";
        t1.printTime();
    }

    cout << '\n';

    if (t1.isAfter(t2)) {
        t1.printTime();
        cout << "is after ";
        t2.printTime();
    }

    cout << '\n';

    cout << "added 1 sec to time t1: ";
    t1.addOneSecond().printTime();

    cout << '\n';

    Time diff = t1.diff(t2);
    cout << "the difference is ";
    diff.printTime();
}
