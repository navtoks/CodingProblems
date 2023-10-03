#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (i) arr[i] += arr[i - 1];
    }

    int max_sum = arr[k - 1];
    for (int i = 0; i < n - k; ++i) {
        int now = arr[i + k] - arr[i];
        max_sum = max(max_sum, now);
    }
    cout << max_sum;

    return 0;
}