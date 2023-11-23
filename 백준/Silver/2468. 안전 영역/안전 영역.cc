#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using V = vector<int>;
using M = vector<V>;

int n;
M arr, visited;

struct X {
    int x, y;
    X operator+(X o) { return X{x + o.x, y + o.y}; }
    bool IsValid() { return x >= 0 && y >= 0 && x < n && y < n; }
};
vector<X> dX{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void Bfs(X u, int h) {
    queue<X> temp;
    temp.push(u);
    visited[u.y][u.x] = 1;

    while (!temp.empty()) {
        u = temp.front();   temp.pop();
        for (X dx : dX) {
            X v = u + dx;
            if (!v.IsValid() || visited[v.y][v.x] || arr[v.y][v.x] < h) continue;
            visited[v.y][v.x] = 1;
            temp.push(v);
        }
    }
}

int Count(int h) {
    visited = M(n, V(n, 0));
    int cnt = 0;
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            if (visited[y][x] || arr[y][x] < h) continue;
            Bfs(X{x, y}, h);
            ++cnt;
        }
    }
    return cnt;
}

int Solve() {
    int max_cnt = 0;
    for (int h = 0; h < 100; ++h) {
        int cnt = Count(h);
        if (cnt == 0) break;
        if (cnt > max_cnt) max_cnt = cnt;
    }
    return max_cnt;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    cin >> n;
    arr = M(n, V(n));
    for (auto& row : arr) for (auto& elt : row) cin >> elt;
    cout << Solve();

    return 0;
}