#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
using vi = vector<int>;
using mi = vector<vi>;

int n, m, start;
mi arr;
vi visited;

void SetArr() {
    cin >> n >> m >> start;
    arr = mi(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    for (auto& vec : arr) {
        sort(begin(vec), end(vec));
    }
}

void Visit(int u) {
    cout << u << ' ';
    visited[u] = true;
}

void Dfs(int start) {
    stack<int> temp;
    int u = start;
    temp.push(u);
    while (!temp.empty()) {
        u = temp.top();
        if (!visited[u]) Visit(u);
        temp.pop();
        for (auto iter = rbegin(arr[u]); iter != rend(arr[u]); ++iter) {
            int v = *iter;
            if (visited[v]) continue;
            temp.push(v);
        }
    }
}

void Bfs(int start) {
    queue<int> temp;
    int u = start;
    Visit(u);
    temp.push(u);
    while (!temp.empty()) {
        u = temp.front();
        temp.pop();
        for (const auto& v : arr[u]) {
            if (visited[v]) continue;
            Visit(v);
            temp.push(v);
        }
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    SetArr();

    visited = vi(n + 1, 0);
    Dfs(start);
    cout << '\n';

    visited = vi(n + 1, 0);
    Bfs(start);

    return 0;
}