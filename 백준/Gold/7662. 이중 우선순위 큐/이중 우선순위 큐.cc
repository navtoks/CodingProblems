#include <iostream>
#include <set>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int T, k, n;
    cin >> T;
    while (T--) {
        multiset<int> arr;
        cin >> k;
        while (k--) {
            char c;
            cin >> c >> n;

            if (c == 'I') arr.insert(n);
            else {
                if (arr.empty()) continue;
                if (n == -1) arr.erase(begin(arr));
                else arr.erase(--end(arr));
            }
        }

        if (arr.empty()) cout << "EMPTY\n";
        else cout << *rbegin(arr) << ' ' << *begin(arr) << '\n';
    }

    return 0;
}