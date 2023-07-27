#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 100'000;
vector<int> arr(MAXN + 1, -1);

void NextMove(int u, int v, queue<int>& checker) {
    if (v > MAXN || v < 0) return;
    if (arr[v] != -1) return;
    arr[v] = arr[u] + 1;
    checker.push(v);
}

void Bfs(int start) {
    queue<int> temp;
    int u = start;
    temp.push(u);
    arr[u] = 0;
    while (!temp.empty()) {
        u = temp.front();
        temp.pop();
        NextMove(u, u + 1, temp);
        NextMove(u, u - 1, temp);
        NextMove(u, 2 * u, temp);
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    Bfs(n);
    cout << arr[k];

    return 0;
}