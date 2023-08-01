#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using vi = vector<int>;
using mi = vector<vi>;

int n, m, start, order = 1;
mi graph;
vi visited;
queue<int> temp;

void SetGraph() {
    cin >> n >> m >> start;
    graph = mi(n + 1);
    visited = vi(n + 1, 0);
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (auto& nodes : graph) {
        sort(begin(nodes), end(nodes), greater<int>());
    }
}

void Visit(int u) {
    if (visited[u]) return;
    temp.push(u);
    visited[u] = order++;
}

void Bfs() {
    int u = start;
    Visit(u);
    while (!temp.empty()) {
        u = temp.front();
        temp.pop();
        for (const auto& v : graph[u]) {
            Visit(v);
        }
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    SetGraph();
    Bfs();
    for (int i = 1; i <= n; ++i) {
        cout << visited[i] << '\n';
    }

    return 0;
}