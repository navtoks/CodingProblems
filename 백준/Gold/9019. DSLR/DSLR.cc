#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int a, b;
const int M = 10000;
vector<string> arr(M);
vector<bool> visited;
queue<int> temp;

int D(int n) {
    n *= 2;
    return n >= M ? n - M : n;
}

int S(int n) {
    if (n == 0) return M - 1;
    return n - 1;
}

int L(int n) {
    n *= 10;
    return n / M + n % M;
}

int R(int n) {
    return n / 10 + (n % 10) * 1000;
}

void NextMove(int u, int v, char c) {
    if (visited[v]) return;
    temp.push(v);
    visited[v] = true;
    arr[v] = arr[u] + c;
}

void Bfs(int a, int b) {
    temp = queue<int>();
    temp.push(a);
    visited[a] = true;
    while (!temp.empty()) {
        int u = temp.front();
        temp.pop();
        if (u == b) {
            cout << arr[u] << '\n';
            break;
        }

        NextMove(u, D(u), 'D');
        NextMove(u, S(u), 'S');
        NextMove(u, L(u), 'L');
        NextMove(u, R(u), 'R');
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        visited = vector<bool>(M, false);
        arr = vector<string>(M);
        Bfs(a, b);
    }

    return 0;
}