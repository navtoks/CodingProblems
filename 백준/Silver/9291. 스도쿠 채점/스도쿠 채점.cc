#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;

#define FOR(i, n) for (int i = 0; i < n; ++i)

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        vector<vi> arr(9, vi(9));
        FOR(i, 9) FOR(j, 9) cin >> arr[i][j];

        bool is_valid = true;
        FOR(i, 9) {
            vi checker(10, 0);
            FOR(j, 9) checker[arr[i][j]] = 1;
            FOR(j, 9) if (!checker[j + 1]) is_valid = false;
        }

        FOR(i, 9) {
            vi checker(10, 0);
            FOR(j, 9) checker[arr[j][i]] = 1;
            FOR(j, 9) if (!checker[j + 1]) is_valid = false;
        }

        FOR(y, 3) FOR(x, 3) {
            vi checker(10, 0);
            FOR(i, 3) FOR(j, 3) checker[arr[y * 3 + i][x * 3 + j]] = 1;
            FOR(j, 9) if (!checker[j + 1]) is_valid = false;
        }

        cout << "Case " << t << ": ";
        if (!is_valid) cout << "IN";
        cout << "CORRECT\n";
    }

    return 0;
}