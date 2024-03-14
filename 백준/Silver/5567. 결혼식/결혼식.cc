#include <iostream>
#include <vector>
using namespace std;
using V = vector<int>;
using M = vector<V>;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    M arr(n + 1);
    V visited(n + 1, 0);

    while (m--) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    int cnt = arr[1].size();
    visited[1] = 1;
    for (const auto& u : arr[1]) visited[u] = 1;

    for (const auto& u : arr[1]) {
        for (const auto& v : arr[u]) {
            if (visited[v]) continue;
            visited[v] = 1;
            ++cnt;
        }
    }
    cout << cnt;

    return 0;
}