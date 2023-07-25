#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using vi = vector<int>;
using mi = vector<vi>;

int n, m;
mi graph;
vi visited;

void SetGraph() {
    cin >> n >> m;

    graph = mi(n + 1);
    visited = vi(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void Dfs(int u) {
    visited[u] = 1;
    for (const auto& v : graph[u]) {
        if (visited[v]) continue;
        Dfs(v);
    }
}

int Count() {
    int cnt = 0;
    for (int u = 1; u <= n; ++u) {
        if (visited[u]) continue;
        Dfs(u);
        ++cnt;
    }
    return cnt;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    SetGraph();
    cout << Count();

    return 0;
}