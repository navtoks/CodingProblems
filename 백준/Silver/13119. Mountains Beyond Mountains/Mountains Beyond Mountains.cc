#include <iostream>
#include <vector>
using namespace std;
#define FOR(i, a, b) for (int i = a; i < b; ++i)

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<char>> arr(n, vector<char>(m, '.'));
    FOR(j, 0, m) arr[x - 1][j] = '-';
    FOR(i, 0, x - 1) {
        for (int j = 2; j < m; j += 3) arr[i][j] = '|';
    }

    FOR(j, 0, m) {
        int h;
        cin >> h;
        FOR (i, 0, h) arr[i][j] = '#';
        if (h >= x) arr[x - 1][j] = '*';
    }

    for (int i = n - 1; i >= 0; --i) {
        FOR(j, 0, m) cout << arr[i][j];
        cout << '\n';
    }

    return 0;
}