#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using vi = vector<int>;
using mi = vector<vi>;

int n, m, start;
mi graph;
vi visited;
queue<int> temp;

void SetGraph() {
    cin >> n >> m >> start;
    graph = mi(n + 1);
    visited = vi(n + 1, -1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void Visit(int u, int v) {
    if (visited[v] != -1) return;
    temp.push(v);
    visited[v] = visited[u] + 1;
}

void Bfs() {
    int u = start;
    Visit(u, u);
    while (!temp.empty()) {
        u = temp.front();
        temp.pop();
        for (const auto& v : graph[u]) {
            Visit(u, v);
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