#include <iostream>
#include <vector>
using namespace std;

struct X {
    int x, y;
};

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<X> arr(n);
    for (auto& elt : arr) cin >> elt.x >> elt.y;

    int minx = 10000, miny = 10000;
    int maxx = -10000, maxy = -10000;
    for (const auto& elt : arr) {
        if (elt.x > maxx) maxx = elt.x;
        if (elt.x < minx) minx = elt.x;
        if (elt.y > maxy) maxy = elt.y;
        if (elt.y < miny) miny = elt.y;
    }
    cout << (maxx - minx) * (maxy - miny);

    return 0;
}