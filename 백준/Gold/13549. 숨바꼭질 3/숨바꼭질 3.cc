#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 100'000;
vector<int> arr(N + 1, N);
queue<int> temp;

bool IsValid(int v) {
    return v >= 0 && v <= N;
}

void NextMove(int u, int v) {
    if (!IsValid(v)) return;
    int dist = arr[u] + 1;
    if (dist < arr[v]) {
        temp.push(v);
        arr[v] = dist;
    }
}

void Warp(int u) {
    int v = 2 * u;
    if (!IsValid(v)) return;
    int dist = arr[u];
    if (dist < arr[v]) {
        temp.push(v);
        arr[v] = dist;
    }
}

void Bfs(int n, int k) {
    temp.push(n);
    arr[n] = 0;
    while (!temp.empty()) {
        int u = temp.front();
        temp.pop();

        int v = u;
        while (v != 0 && v <= N) {
            Warp(v);
            v *= 2;
        }
        NextMove(u, u + 1);
        NextMove(u, u - 1);
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    Bfs(n, k);
    cout << arr[k];

    return 0;
}