#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<int> arr(N + 1);
    for (int i = 1; i <= N; ++i) arr[i] = i;

    for (int m = 0; m < M; ++m) {
        int i, j;
        cin >> i >> j;

        auto b = begin(arr);
        reverse(b + i, b + j + 1);
    }

    for (int i = 1; i <= N; ++i) cout << arr[i] << ' ';

    return 0;
}