#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Time {
    int b, e;
    bool operator<(const Time& other) {
        if (e == other.e) return b < other.b;
        return e < other.e;
    }
};

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<Time> arr(n);
    for (auto& elt : arr) cin >> elt.b >> elt.e;
    sort(begin(arr), end(arr));

    int cnt = 1;
    int now = arr[0].e;
    for (int i = 1; i < n; ++i) {
        if (arr[i].b >= now) {
            ++cnt;
            now = arr[i].e;
        }
    }
    cout << cnt;

    return 0;
}