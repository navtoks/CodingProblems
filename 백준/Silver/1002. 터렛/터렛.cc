#include <iostream>
using namespace std;

struct C {
    int x, y, r;
    int dist(const C& other) {
        int dx = x - other.x;
        int dy = y - other.y;
        return dx * dx + dy * dy;
    }
};

istream& operator>>(istream& in, C& c) {
    in >> c.x >> c.y >> c.r;
    return in;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        C c1, c2;
        cin >> c1 >> c2;

        int d = c1.dist(c2);
        int dr = (c1.r - c2.r) * (c1.r - c2.r);
        int ar = (c1.r + c2.r) * (c1.r + c2.r);
        if (d == 0) {
            if (dr == 0) cout << -1;
            else cout << 0;
        }
        else if (d > ar) cout << 0;
        else if (d == ar) cout << 1;
        else if (d > dr) cout << 2;
        else if (d == dr) cout << 1;
        else cout << 0;
        cout << '\n';
    }

    return 0;
}