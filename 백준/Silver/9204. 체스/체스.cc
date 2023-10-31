#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using V = vector<int>;
using M = vector<V>;
M arr;

struct X {
    int x, y;
    X operator+(X o) { return X{x + o.x, y + o.y}; }
};
using VX = vector<X>;
using MX = vector<VX>;
VX dX;  MX pre;

int Bfs(X u, X e) {
    queue<X> temp;
    temp.push(u);
    arr[u.y][u.x] = 0;
    while (!temp.empty()) {
        u = temp.front();   temp.pop();
        for (X dx : dX) {
            X v = u + dx;
            if (v.x < 0 || v.y < 0 || v.x > 7 || v.y > 7 ||
                arr[v.y][v.x] != -1) continue;
            temp.push(v);
            arr[v.y][v.x] = arr[u.y][u.x] + 1;
            pre[v.y][v.x] = X{u.x, u.y};
        }
    }
    return arr[e.y][e.x];
}

void PrintPaths(X u, X e) {
    VX paths;
    paths.push_back(e);
    while (e.x != u.x || e.y != u.y) {
        e = pre[e.y][e.x];
        paths.push_back(e);
    }

    for (int i = paths.size() - 1; i >= 0; --i) {
        X now = paths[i];
        cout << char(now.x + 'A') << ' ' << now.y + 1 << ' ';
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    for (int i = 1; i < 8; ++i) {
        dX.push_back({i, i});   dX.push_back({i, -i});
        dX.push_back({-i, i});  dX.push_back({-i, -i});
    }

    int T;
    cin >> T;
    while (T--) {
        char x; int y;  
        cin >> x >> y;  X u{x - 'A', y - 1};
        cin >> x >> y;  X e{x - 'A', y - 1};

        arr = M(8, V(8, -1));
        pre = MX(8, VX(8));

        int cnt = Bfs(u, e);
        if (cnt == -1) cout << "Impossible\n";
        else {
            cout << cnt << ' ';
            PrintPaths(u, e);
            cout << '\n';
        }
    }

    return 0;
}