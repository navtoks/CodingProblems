#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr;
const int MAXTIME = 500 * 500 * 256 * 2;

int ComputeTimeToMakeHeight(int h, int b) {
    int time = 0;
    for (const auto& row : arr) {
        for (const auto& elt : row) {
            int diff = h - elt;
            b -= diff;
            if (diff < 0) time -= 2 * diff;  // subtract block (task 1)
            if (diff > 0) time += diff;  // add block (task 2)
        }
    }

    if (b < 0) return MAXTIME;
    return time;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, m, b;
    cin >> n >> m >> b;

    arr = vector<vector<int>>(n, vector<int>(m));
    for (auto& row : arr) {
        for (auto& elt : row) {
            cin >> elt;
        }
    }

    int min_time = MAXTIME;
    vector<int> times(257);
    for (int h = 0; h <= 256; ++h) {
        times[h] = ComputeTimeToMakeHeight(h, b);
        if (times[h] < min_time) min_time = times[h];
    }

    for (int h = 256; h >= 0; --h) {
        if (times[h] == min_time) {
            cout << min_time << ' ' << h;
            break;
        }
    }

    return 0;
}