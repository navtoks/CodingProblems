#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Round(int n) {
    if (n % 10 < 5) {
        n /= 10;
        cout.precision(2);
        cout << fixed << double(n / 100.0);
    }
    else {
        n = (n / 10) + 1;
        cout.precision(2);
        cout << fixed << double(n / 100.0);
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (auto& elt : arr) {
        double x;
        cin >> x;
        elt = int(x * 1000);
    }
    sort(begin(arr), end(arr));

    int trimmed = 0;
    for (int i = k; i < n - k; ++i) {
        trimmed += arr[i];
    }
    Round(trimmed / (n - 2 * k));
    cout << '\n';

    int corrected = trimmed;
    for (int i = 0; i < k; ++i) {
        corrected += arr[k];
        corrected += arr[n - 1 - k];
    }
    Round(corrected / n);

    return 0;
}