#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using vi = vector<int>;
using mi = vector<vi>;

int n, m, k;
mi arr;

struct X {
    int x, y;
    X operator+(const X& other) { return X{x + other.x, y + other.y}; }
    bool IsValid() { return (x >= 0 && x < m && y >= 0 && y < n); }
    int& Get() { return arr[y][x]; }
};
vector<X> dX{X{-1, 0}, X{+1, 0}, X{0, -1}, X{0, +1}};

void SetArr() {
    cin >> m >> n >> k;
    arr = mi(n, vi(m, 0));
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        arr[y][x] = 1;
    }
}

void Bfs(X start) {
    queue<X> temp;
    X u = start;
    temp.push(u);
    u.Get() = 0;
    while (!temp.empty()) {
        u = temp.front();
        temp.pop();
        for (const auto& dx : dX) {
            X v = u + dx;
            if (!v.IsValid()) continue;
            if (v.Get()) {
                v.Get() = 0;
                temp.push(v);
            }
        }
    }
}

int Count() {
    int cnt = 0;
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            X start{x, y};
            if (start.Get()) {
                Bfs(start);
                ++cnt;
            }
        }
    }
    return cnt;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        SetArr();
        cout << Count() << '\n';
    }

    return 0;
}