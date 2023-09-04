#include <iostream>
using namespace std;
using ll = long long;

struct Vector {
    ll x, y;
    void Input() { cin >> x >> y; }
    Vector operator-(Vector o) const { return {x - o.x, y - o.y}; }
};

struct Line {
    // x = x1 + (x2 - x1) * t   ->  X = Base + t * dV where scalar t in [0, 1]
    // y = y1 + (y2 - y1) * t       with Base = [x1, y1], dV = [x2 - x1, y2 - y1]
    Vector base, dv;
    Line() {
        base.Input();
        dv.Input();
        dv = dv - base;
    }
};

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    Line l1, l2;
    // |dx1 -dx2| |t1| = |x2 - x1|
    // |dy1 -dy2| |t2| = |y2 - y1|

    auto [a11, a21] = l1.dv;  // column vector
    auto [a12, a22] = Vector{-l2.dv.x, -l2.dv.y};
    auto [b1, b2] = (l2.base - l1.base);
    ll det = a11 * a22 - a12 * a21;
    bool result = false;
    if (det) {
        if (det < 0) {
            det *= -1;  // set determinants to be positive
            a21 *= -1, a22 *= -1, b2 *= -1;  // second row
        }
        ll x = a22 * b1 - a12 * b2;
        ll y = -a21 * b1 + a11 * b2;
        bool x_valid = (x >= 0 && x <= det);
        bool y_valid = (y >= 0 && y <= det);
        result = x_valid && y_valid;
    }
    else {  // two lines have the sample slope -> parallel or lie on a same line
        if (b1 == 0 && b2 == 0) result = true;  // trivial solution
        else {
            if (a11) {
                // [a b b1; c d b2] -> [a b b1; ac ad ab2] -> [ac bc cb1; ac bc ab2]
                if (a21 * b1 != a11 * b2) result = false;  // parallel
                else {
                    ll xl1 = l1.base.x, xr1 = l1.dv.x + xl1;
                    if (xr1 < xl1) swap(xl1, xr1);

                    ll xl2 = l2.base.x, xr2 = l2.dv.x + xl2;
                    if (xr2 < xr2) swap(xl2, xr2);

                    bool valid1 = (xl2 >= xl1 && xl2 <= xr1) || (xr2 >= xl1 && xr2 <= xr1);
                    bool valid2 = (xl1 >= xl2 && xl1 <= xr2) || (xr1 >= xl2 && xr1 <= xr2);
                    result = (valid1 || valid2);
                }
            }
            else {
                // [0 b b1; c d b2] -> [0 b b1; bc bd bb2] -> [0 bd db1; 0 bd bb2]
                if (a22 * b1 != a12 * b2) result = false;  // parallel
                else {
                    ll xl1 = l1.base.y, xr1 = l1.dv.y + xl1;
                    if (xr1 < xl1) swap(xl1, xr1);

                    ll xl2 = l2.base.y, xr2 = l2.dv.y + xl2;
                    if (xr2 < xr2) swap(xl2, xr2);

                    bool valid1 = (xl2 >= xl1 && xl2 <= xr1) || (xr2 >= xl1 && xr2 <= xr1);
                    bool valid2 = (xl1 >= xl2 && xl1 <= xr2) || (xr1 >= xl2 && xr1 <= xr2);
                    result = (valid1 || valid2);
                }
            }
        }
    }
    cout << result;

    return 0;
}