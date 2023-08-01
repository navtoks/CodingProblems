#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
using vs = vector<string>;
using vb = vector<bool>;
using mb = vector<vb>;

int n;
vs graph;

struct X {
    int x, y;
    X operator+(const X& o) { return {x + o.x, y + o.y}; }
    bool IsValid() { return x >= 0 && x < n && y >= 0 && y < n; }
};
vector<X> dX{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void SetArr() {
    cin >> n;
    graph = vs(n);
    for (auto& elt : graph) cin >> elt;
}

void Bfs(mb& visited, const X& start, bool is_rgb) {
    const char color = graph[start.y][start.x];

    queue<X> temp;
    visited[start.y][start.x] = true;
    temp.push(start);

    X u = start;
    while (!temp.empty()) {
        u = temp.front();
        temp.pop();
        for (const auto& dx : dX) {
            X v = u + dx;
            if (!v.IsValid() || visited[v.y][v.x]) continue;
            char now = graph[v.y][v.x];
            if (is_rgb && now != color) continue;
            if (!is_rgb) {
                if (color == 'B') {
                    if (now != 'B') continue;
                }
                else if (now == 'B') continue;
            }
            visited[v.y][v.x] = true;
            temp.push(v);
        }
    }
}

int Count(bool is_rgb) {
    int cnt = 0;
    mb visited(n, vb(n, false));
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            X now{x, y};
            if (visited[now.y][now.x]) continue;
            Bfs(visited, now, is_rgb);
            ++cnt;
        }
    }
    return cnt;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    SetArr();
    cout << Count(true) << ' ' << Count(false);

    return 0;
}