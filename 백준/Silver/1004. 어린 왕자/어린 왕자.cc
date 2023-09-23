#include <iostream>
#include <vector>
using namespace std;

struct X {
    int x, y;
    X() { cin >> x >> y; }
};

struct C {
    X p;
    int r;
    C() { cin >> r; }
    bool Contains(const X& o) {
        int dx = p.x - o.x, dy = p.y - o.y;
        int d = dx * dx + dy * dy;
        return d <= r * r;
    }
};

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        X x1, x2;

        int n, cnt = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            C c;

            bool c1 = c.Contains(x1), c2 = c.Contains(x2);
            if (c1 && c2) continue;
            if (c1) ++cnt;
            if (c2) ++cnt;
        }
        cout << cnt << '\n';
    }

    return 0;
}