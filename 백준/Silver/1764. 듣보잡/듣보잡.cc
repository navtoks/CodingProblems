#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    set<string> unlistened, unwatched;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        unlistened.insert(s);
    }
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        unwatched.insert(s);
    }

    set<string> arr;
    for (const auto& elt : unlistened) {
        if (unwatched.find(elt) != end(unwatched)) arr.insert(elt);
    }

    cout << arr.size() << '\n';
    for (const auto& elt : arr) cout << elt << '\n';

    return 0;
}