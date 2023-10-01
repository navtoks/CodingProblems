#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using V = vector<int>;
using M = vector<V>;

int n, m;
M arr, dist;

struct X {
    int x, y;
    X operator+(X o) { return X{x + o.x, y + o.y}; }
    bool IsValid() { return x >= 0 && x < m && y >= 0 && y < n; }
};
vector<X> dX{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void Bfs(X start) {
    M visited(n, V(m, 0));

    queue<X> temp;
    temp.push(start);
    visited[start.y][start.x] = 1;
    dist[start.y][start.x] = 0;
    while (!temp.empty()) {
        X u = temp.front();
        temp.pop();
        for (X dx : dX) {
            X v = u + dx;
            if (!v.IsValid() || arr[v.y][v.x] || visited[v.y][v.x]) continue;
            visited[v.y][v.x] = 1;
            dist[v.y][v.x] = min(dist[v.y][v.x], dist[u.y][u.x] + 1);
            temp.push(v);
        }
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    cin >> n >> m;
    arr = M(n, V(m));
    for (auto& row : arr) {
        for (auto& elt : row) cin >> elt;
    }

    dist = M(n, V(m, 51));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr[i][j]) Bfs(X{j, i});
        }
    }

    int max_dist = 0;
    for (const auto& row : dist) {
        for (const auto& elt : row) {
            if (elt != 51) max_dist = max(max_dist, elt);
        }
    }
    cout << max_dist;

    return 0;
}