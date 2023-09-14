#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);
    
    int a, b, m;
    cin >> a >> b >> m;

    vector<ll> arr(m);
    for (auto& elt : arr) cin >> elt;

    ll mult = 1;
    ll result = 0;
    for (int i = m - 1; i >= 0; --i) {
        result += arr[i] * mult;
        mult *= a;
    }

    vector<ll> results;
    while (result != 0) {
        results.push_back(result % b);
        result /= b;
    }

    for (auto iter = rbegin(results); iter != rend(results); ++iter) {
        cout << *iter << ' ';
    }

    return 0;
}