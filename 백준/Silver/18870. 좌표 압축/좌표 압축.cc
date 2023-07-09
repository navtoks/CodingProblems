#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct X {
    int idx, x;
    bool operator<(const X& other) {
        return x < other.x;
    }
};

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<X> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i].idx = i;
        cin >> arr[i].x;
    }
    sort(begin(arr), end(arr));

    vector<int> compressed(n);
    int now = 0;
    compressed[arr[0].idx] = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i].x != arr[i - 1].x) ++now;
        compressed[arr[i].idx] = now;
    }

    for (const auto& elt : compressed) cout << elt << ' ';

    return 0;
}