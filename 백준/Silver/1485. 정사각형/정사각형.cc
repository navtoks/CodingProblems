#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

#define FOR(i) for (int i = 0; i < 4; ++i)

struct X {
    ll x, y;
    bool operator<(X o) { return x < o.x || (x == o.x && y < o.y); }
    bool operator>(X o) { return x > o.x || (x == o.x && y > o.y); }
    X operator-(X o) { return X{x - o.x, y - o.y}; }
    ll Dot(X o) { return x * o.x + y * o.y; }
};

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) {
        vector<X> p(4);
        FOR(i) cin >> p[i].x >> p[i].y;

        int imin = 0, imax = 0;
        FOR(i) imin = (p[i] < p[imin] ? i : imin);
        FOR(i) imax = (p[i] > p[imax] ? i : imax);

        int i1 = imin, i2;
        FOR(i) {
            if (i != imin && i != imax) {
                if (i1 != imin) i2 = i;
                else i1 = i;
            }
        }

        vector<X> d(4);
        d[0] = p[i1] - p[imin];
        d[1] = p[i2] - p[imin];
        d[2] = p[imax] - p[i1];
        d[3] = p[imax] - p[i2];

        bool flag = true;
        ll dist = d[0].Dot(d[0]);
        FOR(i) if (dist != d[i].Dot(d[i])) flag = false;
        FOR(i) if (d[i].Dot(d[i]) == 0) flag = false;
        if (d[0].Dot(d[1]) != 0) flag = false;
        cout << flag << '\n';
    }

    return 0;
}