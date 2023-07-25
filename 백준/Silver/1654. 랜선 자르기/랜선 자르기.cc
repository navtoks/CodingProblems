#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using vl = vector<ll>;

vl arr;

ll Count(ll length) {
    ll cnt = 0;
    for (const auto& elt : arr) {
        cnt += elt / length;
    }
    return cnt;
}

ll BinarySearch(ll target) {
    ll lbd = 1;
    ll ubd = (1LL << 31);
    ll result = 0;
    while (lbd <= ubd) {
        ll mid = (lbd + ubd) / 2;
        ll now = Count(mid);
        if (now < target) ubd = mid - 1;
        else {
            lbd = mid + 1;
            if (result < mid) result = mid;
        }
    }
    return result;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    ll k, n;
    cin >> k >> n;

    arr = vl(k);
    for (auto& elt : arr) cin >> elt;
    cout << BinarySearch(n);

    return 0;
}