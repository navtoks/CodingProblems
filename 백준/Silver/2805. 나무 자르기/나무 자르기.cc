#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using vl = vector<ll>;

ll n, m;
vl arr;

ll Count(ll height) {
    ll cnt = 0;
    for (const auto& elt : arr) {
        ll now = elt - height;
        if (now > 0) cnt += now;
    }
    return cnt;
}

ll BinarySearch() {
    ll lbd = 0, ubd = 2'000'000'000LL;
    while (lbd <= ubd) {
        ll mid = (lbd + ubd) / 2;
        ll now = Count(mid);
        if (m > now) ubd = mid - 1;
        else lbd = mid + 1;
    }
    return (lbd + ubd) / 2;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    cin >> n >> m;
    arr = vl(n);
    for (auto& elt : arr) cin >> elt;
    cout << BinarySearch();
    
    return 0;
}