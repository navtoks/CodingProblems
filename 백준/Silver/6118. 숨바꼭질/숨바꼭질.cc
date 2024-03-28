#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using V = vector<int>;

int n, m;
vector<V> arr;
V dist;

void Bfs() {
    queue<int> temp;
    temp.push(1);
    dist[1] = 0;
    while (!temp.empty()) {
        int u = temp.front();   temp.pop();
        for (const auto& v : arr[u]) {
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            temp.push(v);
        }
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    cin >> n >> m;
    arr = vector<V>(n + 1);
    dist = V(n + 1, -1);

    while (m--) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    Bfs();

    int idx = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] > dist[idx]) idx = i; 
    }

    int cnt = 1;
    for (int i = idx + 1; i <= n; ++i) {
        if (dist[i] == dist[idx]) ++cnt;
    }

    cout << idx << ' ' << dist[idx] << ' ' << cnt;

    return 0;
}