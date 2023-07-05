#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll Gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return Gcd(b, a % b);
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<ll> arr(n);
    for (auto& elt : arr) cin >> elt;

    vector<ll> diff(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        diff[i] = arr[i + 1] - arr[i];
    }

    ll gcd = diff[0];
    for (const auto& elt : diff) {
        gcd = Gcd(gcd, elt);
    }

    ll cnt = 0;
    for (const auto& elt : diff) {
        cnt += (elt / gcd - 1);
    }
    cout << cnt;

    return 0;
}