#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<int> arr(N + 1, 0);
    for (int m = 0; m < M; ++m) {
        int i, j, k;
        cin >> i >> j >> k;

        for (int x = i; x <= j; ++x) arr[x] = k;
    }

    for (int i = 1; i <= N; ++i) cout << arr[i] << ' ';
}