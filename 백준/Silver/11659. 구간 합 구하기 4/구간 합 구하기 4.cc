#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<int> arr(N);
    for (auto& elt : arr) cin >> elt;

    vector<int> sums(N);
    sums[0] = arr[0];
    for (int i = 1; i <= N; ++i) {
        sums[i] = arr[i] + sums[i - 1];
    }

    for (int m = 0; m < M; ++m) {
        int i, j;
        cin >> i >> j;
        if (i == 1) {
            cout << sums[j - 1] << '\n';
        }
        else {
            cout << sums[j - 1] - sums[i - 2] << '\n';
        }
    }

    return 0;
}