#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, z, m;
set<int> arr;

bool IsTraversavel(int k) {
    int i = 1;
    for (int x = 1; x <= n; ++x) {
        if (arr.find(i) != end(arr)) return false;

        i += k;
        if (i > n) i %= n;
        if (i == z) return true;
    }
    return false;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    cin >> n >> z >> m;

    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        arr.insert(x);
    }

    int k;
    for (k = 1; k <= z; ++k) {
        if (IsTraversavel(k)) break;
    }
    cout << k;

    return 0;
}