#include <iostream>
#include <string>
#include <vector>
using namespace std;
using S = string;

vector<S> ms{
    "January", "February", "March", "April", "May", "June", "July", "August",
    "September", "October", "November", "December"
};

vector<int> mi{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool IsLeap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int ComputeDays(int y, int m, int d) {
    int days = d;
    for (int i = 0; i < m; ++i) days += mi[i];
    return days;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    S s;
    cin >> s;
    int month;
    for (int i = 0; i < 12; ++i) {
        if (s == ms[i]) month = i;
    }

    cin >> s;
    int d = stoi(s.substr(0, 2)) - 1;

    cin >> s;
    int y = stoi(s);
    if (IsLeap(y)) ++mi[1];

    cin >> s;
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));

    int total = ComputeDays(y, 11, 31);
    int days = ComputeDays(y, month, d);

    double now = (days * 24 + h) * 60 + m;

    cout.precision(10);
    cout << fixed << 100 * now / double(total * 24 * 60);

    return 0;
}