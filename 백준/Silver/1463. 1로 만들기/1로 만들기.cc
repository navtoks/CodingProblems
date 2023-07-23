#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> arr(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        int now = arr[i - 1];
        if (i % 3 == 0) now = min(arr[i / 3], now);
        if (i % 2 == 0) now = min(arr[i / 2], now);
        arr[i] = now + 1;
    }
    cout << arr[n];

    return 0;
}