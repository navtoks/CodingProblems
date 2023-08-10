#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int a, b;
const int N = 10000;
string moves{"DSLR"};

struct X {
    int from{-1};
    char movement{'\n'};
};
using vx = vector<X>;

void NextMove(int u, char c, vx& arr, queue<int>& temp) {
    int v;
    if (c == 'D') {
        v = 2 * u;
        if (v >= N) v -= N;
    }
    else if (c == 'S') v = (u == 0 ? N - 1 : u - 1);
    else if (c == 'L') {
        v = 10 * u;
        v = v % N + v / N;
    }
    else v = u / 10 + (u % 10) * 1000;

    if (arr[v].from != -1) return;
    temp.push(v);
    arr[v] = X{u, c};
}

void Bfs(vx& arr) {
    queue<int> temp;
    temp.push(a);
    arr[a].from = N;
    while (!temp.empty()) {
        int u = temp.front();   temp.pop();
        if (u == b) break;

        for (char c : moves) NextMove(u, c, arr, temp);
    }
}

void PrintResult(const vx& arr) {
    string result;
    while (b != a) {
        result += arr[b].movement;
        b = arr[b].from;
    }
    for (auto i = rbegin(result); i != rend(result); ++i) {
        cout << *i;
    }
    cout << '\n';
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        vx arr(N);
        Bfs(arr);
        PrintResult(arr);
    }

    return 0;
}