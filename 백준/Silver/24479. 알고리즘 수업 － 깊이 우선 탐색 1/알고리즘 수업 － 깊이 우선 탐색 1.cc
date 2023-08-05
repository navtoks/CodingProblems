#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
using vi = vector<int>;
using mi = vector<vi>;

int n, m, r;
mi graph;
vi visited;

void SetGraph() {
    cin >> n >> m >> r;
    graph = mi(n + 1);
    visited = vi(n + 1, 0);
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        sort(begin(graph[i]), end(graph[i]), greater<int>());
    }
}

void Dfs() {
    stack<int> temp;
    int u = r;
    int order = 1;
    temp.push(u);
    while (!temp.empty()) {
        u = temp.top();
        temp.pop();
        if (!visited[u]) visited[u] = order++;
        for (const auto& v : graph[u]) {
            if (visited[v]) continue;
            temp.push(v);
        }
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    SetGraph();
    Dfs();

    for (int i = 1; i <= n; ++i) {
        cout << visited[i] << '\n';
    }

    return 0;
}