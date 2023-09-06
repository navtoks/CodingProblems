#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll Gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return Gcd(b, a % b);
}

ll Lcm(ll a, ll b) {
    return a / Gcd(a, b) * b;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;

    ll lcm = 1;
    vector<ll> nums(n), dens(n);  // numerator, denominator
    for (int i = 0; i < n; ++i) {
        cin >> nums[i] >> dens[i];
        lcm = Lcm(lcm, dens[i]);
    }

    ll gcd_n = (lcm / dens[0]) * nums[0];
    for (int i = 1; i < n; ++i) gcd_n = Gcd(gcd_n, (lcm / dens[i]) * nums[i]);

    ll gcd = Gcd(lcm, gcd_n);
    cout << gcd_n / gcd << ' ' << lcm / gcd;
    
    return 0;
}