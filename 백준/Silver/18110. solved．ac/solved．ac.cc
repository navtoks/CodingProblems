#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Rounding(int a, int b) {
    int result = a / b;
    if (2 * (a % b) >= b) ++result;
    return result;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    vector<int> arr(n);
    for (auto& elt : arr) cin >> elt;
    sort(begin(arr), end(arr));

    int sum = 0;
    int trimmed = Rounding(n * 15, 100);
    for (int i = trimmed; i < n - trimmed; ++i) {
        sum += arr[i];
    }

    n -= 2 * trimmed;
    cout << Rounding(sum, n);

    return 0;
}