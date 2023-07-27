#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using vi = vector<int>;
using mi = vector<vi>;

int n, m;
mi graph;

struct X {
    int x, y;
    X operator+(const X& other) { return X{x + other.x, y + other.y}; }
    bool IsValid() {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};
vector<X> dX{X{-1, 0}, X{+1, 0}, X{0, -1}, X{0, +1}};

void SetGraph() {
    cin >> m >> n;
    graph = mi(n, vi(m));
    for (auto& row : graph) {
        for (auto& elt : row) cin >> elt;
    }
}

void FindStarts(queue<X>& temp) {
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            if (graph[y][x] == 1) temp.push(X{x, y});
        }
    }
}

void Bfs() {
    queue<X> temp;
    FindStarts(temp);
    X u;
    while (!temp.empty()) {
        u = temp.front();
        temp.pop();
        for (const auto& dx : dX) {
            X v = u + dx;
            if (!v.IsValid()) continue;
            if (graph[v.y][v.x] != 0) continue;
            graph[v.y][v.x] = graph[u.y][u.x] + 1;
            temp.push(v);
        }
    }
}

int FindMax() {
    int max_value = 0;
    for (const auto& row : graph) {
        for (const auto& elt : row) {
            if (elt == 0) return -1;
            if (elt > max_value) max_value = elt;
        }
    }
    return max_value - 1;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    SetGraph();
    Bfs();
    cout << FindMax();

    return 0;
}