#include <iostream>
#include <set>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    set<int> a, b;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        b.insert(x);
    }

    int cnt = 0;
    for (const auto& elt : a) {
        if (b.find(elt) != end(b)) ++cnt;
    }
    cout << n + m - cnt * 2;

    return 0;
}