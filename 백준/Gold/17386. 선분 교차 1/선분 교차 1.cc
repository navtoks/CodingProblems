#include <iostream>
using namespace std;
using ll = long long;

struct Vector {
    ll x, y;
    void Input() { cin >> x >> y; }
    Vector operator-(Vector o) { return {x - o.x, y - o.y}; }
};

struct Line {
    // x = x1 + (x2 - x1) * t   -> X = P + dP * t where scalar t in [0, 1]
    // y = y1 + (y2 - y1) * t
    Vector p, dp;
    void Set() {
        p.Input();   dp.Input();
        dp = dp - p;
    }
};

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);
    
    Line l1, l2;
    l1.Set();   l2.Set();
    // l1 : X1 = P1 + dP1 * t1  &  l2 : X2 = P2 + dP2 * t2
    // [dx1 -dx2] [t1] = [x2 - x1]
    // [dy1 -dy2] [t2] = [y2 - y1]

    ll a = l1.dp.x, c = l1.dp.y;
    ll b = -l2.dp.x, d = -l2.dp.y;
    ll b1 = l2.p.x - l1.p.x, b2 = l2.p.y - l1.p.y;
    ll det = a * d - b * c;
    bool result = false;
    if (det != 0) {
        ll t1 = d * b1 - b * b2;
        ll t2 = -c * b1 + a * b2;

        if (det > 0) result = (det >= t1 && t1 >= 0 && det >= t2 && t2 >= 0);
        else result = (det <= t1 && t1 <= 0 && det <= t2 && t2 <= 0);
    }
    cout << result;
    
    return 0;
}