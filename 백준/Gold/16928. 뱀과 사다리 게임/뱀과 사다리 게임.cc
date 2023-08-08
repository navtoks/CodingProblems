#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

unordered_map<int, int> shortcut;
vector<int> dist(101, 0);

int Bfs() {
    queue<int> temp;
    temp.push(1);
    dist[1] = 1;
    while (!temp.empty()) {
        int u = temp.front();
        temp.pop();
        for (int i = 1; i <= 6; ++i) {
            int v = u + i;
            if (v > 100 || dist[v] != 0) continue;
            dist[v] = dist[u] + 1;
            if (shortcut.find(v) != end(shortcut)) {
                v = shortcut[v];
                if (dist[v] != 0) continue;
                dist[v] = dist[u] + 1;
            }
            temp.push(v);
        }
    }

    return dist[100] - 1;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    while (n--) {
        int u, v;
        cin >> u >> v;
        shortcut.insert({u, v});
    }

    while (m--) {
        int u, v;
        cin >> u >> v;
        shortcut.insert({u, v});
    }

    cout << Bfs();

    return 0;
}