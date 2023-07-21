#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using vi = vector<int>;
using mi = vector<vi>;

int n, m;
mi graph, dist;

struct X {
    int x, y;
    X operator+(const X& other) { return X{x + other.x, y + other.y}; }
    int& Get(mi& arr) { return arr[y][x]; }
    bool IsValid() { return x >= 0 && x < m && y >= 0 && y < n; }
};
vector<X> dX{X{-1, 0}, X{+1, 0}, X{0, -1}, X{0, +1}};

X FindStart() {
    X start;
    bool flag = false;
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            start = X{x, y};
            if (start.Get(graph) == 2) {
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    return start;
}

void ExcludeZeroZones() {
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            X now{x, y};
            if (now.Get(graph) == 0) {
                now.Get(dist) = 0;
            }
        }
    }
}

void Bfs(X start) {
    queue<X> temp;
    X u = start;
    temp.push(u);
    u.Get(dist) = 0;
    while (!temp.empty()) {
        u = temp.front();
        temp.pop();
        for (const auto& dx : dX) {
            X v = u + dx;
            if (!v.IsValid() || v.Get(dist) != -1) continue;
            temp.push(v);
            v.Get(dist) = u.Get(dist) + 1;
        }
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    cin >> n >> m;

    graph = mi(n, vi(m));
    dist = mi(n, vi(m, -1));

    for (auto& row : graph) {
        for (auto& elt : row) {
            cin >> elt;
        }
    }

    X start = FindStart();
    ExcludeZeroZones();
    Bfs(start);

    for (const auto& row : dist) {
        for (const auto& elt : row) cout << elt << ' ';
        cout << '\n';
    }

    return 0;
}