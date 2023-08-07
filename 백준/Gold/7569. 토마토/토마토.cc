#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using vi = vector<int>;
using mi = vector<vi>;
using ti = vector<mi>;

int n, m, h;
ti graph;

struct X {
    int x, y, z;
    X operator+(const X& o) { return {x + o.x, y + o.y, z + o.z}; }
    bool IsValid() const {
        return x >= 0 && x < m && y >= 0 && y < n && z >= 0 && z < h;
    }
    int& Get() const {
        return graph[z][y][x];
    }
};
vector<X> dX{{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

void SetGraph() {
    cin >> m >> n >> h;
    graph = ti(h, mi(n, vi(m)));
    for (auto& mat : graph) {
        for (auto& row : mat) {
            for (auto& elt : row) cin >> elt;
        }
    }
}

void FindStarts(queue<X>& temp) {
    for (int z = 0; z < h; ++z) {
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < m; ++x) {
                X start{x, y, z};
                if (start.Get() == 1) temp.push(start);
            }
        }
    }
}

void Bfs() {
    queue<X> temp;
    FindStarts(temp);
    while (!temp.empty()) {
        X u = temp.front();
        temp.pop();
        for (const auto& dx : dX) {
            X v = u + dx;
            if (!v.IsValid() || v.Get() != 0) continue;
            v.Get() = u.Get() + 1;
            temp.push(v);
        }
    }
}

int FindMaxDay() {
    int max_day = 0;
    for (int z = 0; z < h; ++z) {
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < m; ++x) {
                X now{x, y, z};
                if (now.Get() == 0) return -1;
                max_day = now.Get() > max_day ? now.Get() : max_day;
            }
        }
    }
    return max_day - 1;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    SetGraph();
    Bfs();
    cout << FindMaxDay();
}