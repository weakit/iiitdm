
int mod(int x, int y) {
    // to handle negative values
    int m = x % y;
    return m < 0 ? m + y : m;
}


class Time {
    int hours;
    int minutes;
    int seconds;

public:
    explicit Time(int h = 0, int m = 0, int s = 0) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    void setHours(int h) {
        hours = h;
    }

    void setMinutes(int m) {
        minutes = m;
    }

    void setSeconds(int s) {
        seconds = s;
    }

    int getHours() { return hours; }

    int getMinutes() { return minutes; }

    int getSeconds() { return seconds; }

    Time add(int h = 0, int m = 0, int s = 0) {
        // return a new object with a new time
        h = mod(hours + h + (minutes + m) / 60 + (seconds + s) / 3600, 24);
        m = mod(minutes + m + (seconds + s) / 60, 60);
        s = mod(seconds + s, 60);
        return Time(h, m, s);
    }
};
