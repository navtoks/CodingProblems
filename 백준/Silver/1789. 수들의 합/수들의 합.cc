#include <iostream>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    ll s;
    cin >> s;

    ll n = 1;
    while (n * (n + 1) / 2 <= s) ++n;

    if (n * (n + 1) / 2 > s) --n;
    cout << n;

    return 0;
}