#include <iostream>
#include <vector>
using namespace std;

bool IsPrime(int n) {
    if (n < 2) return false;

    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (IsPrime(x)) ++cnt;
    }
    cout << cnt;

    return 0;
}