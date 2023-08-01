#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using ml = vector<vl>;

int n, m, r, order = 1;
ml graph;
vl depth, visited;
queue<int> temp;

void SetGraph() {
    cin >> n >> m >> r;

    graph = ml(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (auto& nodes : graph) {
        sort(begin(nodes), end(nodes));
    }

    depth = vl(n + 1, -1);
    visited = vl(n + 1, 0);
}

void Visit(int u, int v) {
    if (visited[v]) return;
    temp.push(v);
    depth[v] = depth[u] + 1;
    visited[v] = order++;
}

void Bfs() {
    int u = r;
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

    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += depth[i] * visited[i];
    }
    cout << sum;

    return 0;
}