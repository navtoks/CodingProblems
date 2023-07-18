#include <iostream>
#include <vector>
using namespace std;

vector<int> arr(8001, 0);  // -4000 ~ 4000

int Rounding(int numerator, int denominator) {
    int div = numerator / denominator;
    int rem = numerator % denominator;
    if (rem > denominator / 2) ++div;
    return div;
}

int ComputeMean(int n) {
    int sum = 0;
    for (int i = 0; i <= 8000; ++i) {
        sum += (i - 4000) * arr[i];
    }

    if (sum > 0) return Rounding(sum, n);
    return -Rounding(-sum, n);
}

int ComputeMedian(int n) {
    int mid = n / 2 + 1;
    int cnt = 0;
    for (int i = 0; i <= 8000; ++i) {
        if (mid - cnt <= arr[i]) return i - 4000;
        cnt += arr[i];
    }
}

int ComputeMode() {
    int m = 0;
    for (int i = 0; i <= 8000; ++i) {
        if (arr[i] > arr[m]) m = i;
    }

    for (int i = m + 1; i <= 8000; ++i) {
        if (arr[i] == arr[m]) return i - 4000;
    }
    return m - 4000;
}

int ComputeRange() {
    int m = 0, M = 0;
    for (int i = 0; i <= 8000; ++i) {
        if (arr[i]) {
            m = i;
            break;
        }
    }
    for (int i = 8000; i >= 0; --i) {
        if (arr[i]) {
            M = i;
            break;
        }
    }
    return M - m;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++arr[x + 4000];
    }

    cout << ComputeMean(n) << '\n' << ComputeMedian(n) << '\n' << ComputeMode() << '\n' << ComputeRange();

    return 0;
}