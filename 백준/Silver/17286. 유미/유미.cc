#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define FOR(i) for (int i = 0; i < 3; ++i)

struct X {
    int x, y;
    double Dist(X o) {
        int dx = x - o.x, dy = y - o.y;
        return sqrt(dx * dx + dy * dy);
    }
};

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    X base;
    cin >> base.x >> base.y;

    vector<X> arr(3);
    FOR(i) cin >> arr[i].x >> arr[i].y;

    int sum = 1200;
    FOR(i) FOR(j) {
        if (i == j) continue;
        FOR(k) {
            if (i == k || j == k) continue;
            int temp = base.Dist(arr[i]) + arr[i].Dist(arr[j]) + arr[j].Dist(arr[k]);
            if (temp < sum) sum = temp;
        }
    }

    cout << sum;

    return 0;
}