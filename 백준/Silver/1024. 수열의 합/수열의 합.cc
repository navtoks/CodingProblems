#include <iostream>
using namespace std;

int FindStartNumber(int n, int l) {
    // sum = l * (2x + l - 1) / 2
    // let l = 2k or l = 2k + 1, then find an integer such that sum = n
    // k * (2x + 2k - 1) = n,  if l = 2k
    // (2k + 1) * (x + k) = n,  if l = 2k + 1
    int k = l / 2, x;
    if (l % 2) {
        if (n % l) return -1;
        x = n / l - k;
    }
    else {
        if (n % k) return -1;
        x = n / k + 1;
        if (x % 2) return -1;
        x = x / 2 - k;
    }
    return x > -1 ? x : -1;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, l;
    cin >> n >> l;

    int x = -1;
    for (; l <= 100; ++l) {
        x = FindStartNumber(n, l);
        if (x != -1) break;
    }

    if (x == -1) cout << -1;
    else for (int i = 0; i < l; ++i) cout << x + i << ' ';

    return 0;
}