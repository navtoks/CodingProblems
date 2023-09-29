#include <iostream>
using namespace std;
using ll = unsigned long long;

ll BinarySearch(ll n, ll lbd, ll ubd) {
    while (lbd < ubd) {
        ll mid = (lbd + ubd) / 2ULL;
        if (mid * mid < n) lbd = mid + 1;
        else ubd = mid;
    }
    return (lbd + ubd) / 2ULL;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;

    ll lbd = 0, ubd = (1ULL << 32);
    cout << BinarySearch(n, lbd, ubd);

    return 0;
}