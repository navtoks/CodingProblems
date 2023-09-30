#include <iostream>
#include <string>
#include <vector>
using namespace std;
using V = vector<int>;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    string s;
    int q;
    cin >> s >> q;

    int n = s.size();
    vector<V> arr(n, V(26, 0));
    arr[0][s[0] - 'a'] = 1;
    for (int i = 1; i < n; ++i) {
        arr[i] = arr[i - 1];
        ++arr[i][s[i] - 'a'];
    }

    while (q--) {
        char c;
        int l, r;
        cin >> c >> l >> r;

        int i = c - 'a';
        if (l == 0) cout << arr[r][i] << '\n';
        else cout << arr[r][i] - arr[l - 1][i] << '\n';
    }

    return 0;
}