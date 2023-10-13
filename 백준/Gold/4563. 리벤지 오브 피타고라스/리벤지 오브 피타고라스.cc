#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> FindDivs(ll n) {
    vector<ll> divs;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i) continue;
        divs.push_back(i);
        divs.push_back(n / i);
    }
    return divs;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    while (true) {
        ll a;
        cin >> a;
        if (a == 0) break;

        int cnt = 0;
        auto divs = FindDivs(a * a);
        for (int i = 0; i < divs.size(); i += 2) {
            ll c2 = divs[i] + divs[i + 1];
            ll b2 = divs[i + 1] - divs[i];
            if (c2 % 2 == 0 && b2 % 2 == 0 && b2 / 2 > a) ++cnt;
        }

        cout << cnt << '\n';
    }

    return 0;
}