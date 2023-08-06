#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using vb = vector<bool>;
using mb = vector<vb>;

int n;
mb graph;
mb visited;

void SetGraph() {
    cin >> n;
    graph = mb(n, vb(n, false));
    visited = mb(n, vb(n, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool x;
            cin >> x;
            graph[i][j] = x;
        }
    }
}

void Bfs(int start) {
    queue<int> temp;
    int u = start;
    temp.push(u);
    while (!temp.empty()) {
        u = temp.front();
        temp.pop();
        for (int v = 0; v < n; ++v) {
            if (!graph[u][v] || visited[start][v]) continue;
            temp.push(v);
            visited[start][v] = true;
        }
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    SetGraph();
    for (int i = 0; i < n; ++i) {
        Bfs(i);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}