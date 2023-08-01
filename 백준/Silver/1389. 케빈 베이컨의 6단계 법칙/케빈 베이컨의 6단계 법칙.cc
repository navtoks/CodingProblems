#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using vi = vector<int>;
using mi = vector<vi>;

int n;
mi arr;

void SetArr() {
    int m;
    cin >> n >> m;
    arr = mi(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
}

int Bfs(int start) {
    queue<int> temp;
    vi dist(n + 1, -1);
    int u = start;
    temp.push(u);
    dist[u] = 0;
    while (!temp.empty()) {
        u = temp.front();
        temp.pop();
        for (const auto& v : arr[u]) {
            if (dist[v] != -1) continue;
            temp.push(v);
            dist[v] = dist[u] + 1;
        }
    }

    int sum = 0;
    for (const auto& elt : dist) {
        if (elt != -1) sum += elt;
    }
    return sum;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    SetArr();

    vi nums(n + 1);
    nums[0] = 5000 * 5000;
    int min_idx = 0;
    for (int i = 1; i <= n; ++i) {
        nums[i] = Bfs(i);
        if (nums[i] < nums[min_idx]) min_idx = i;
    }
    cout << min_idx;

    return 0;
}