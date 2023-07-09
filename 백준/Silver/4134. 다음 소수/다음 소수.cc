#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

bool IsPrime(ll n) {
    if (n < 2) return false;

    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        ll n;
        cin >> n;
        while (!IsPrime(n)) {
            ++n;
        }
        cout << n << '\n';
    }

    return 0;
}