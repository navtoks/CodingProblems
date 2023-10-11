#include <iostream>
#include <vector>
using namespace std;
using ll = unsigned long long;

const ll MAX = (1ULL << 63);

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;

    if (n == 0) {
        cout << "NO";
        return 0;
    }

    vector<ll> arr;
    ll now = 1;
    while (now < MAX) {
        arr.push_back(now);
        now *= 3;
    }

    for (int i = arr.size() - 1; i >= 0; --i) {
        if (arr[i] <= n) n -= arr[i];
    }

    if (n) cout << "NO";
    else cout << "YES";

    return 0;
}