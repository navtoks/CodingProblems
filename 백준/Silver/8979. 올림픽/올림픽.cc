#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct X {
    int i, g, s, b;
    bool operator<(X o) {
        if (g == o.g) {
            if (s == o.s) return b < o.b;
            return s < o.s;
        }
        return g < o.g;
    }
    bool operator==(X o) {
        return g == o.g && s == o.s && b == o.b;
    }
};

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<X> arr(n);
    for (auto& elt : arr) cin >> elt.i >> elt.g >> elt.s >> elt.b;
    sort(begin(arr), end(arr));

    int rank = 1;
    vector<int> ranks(n + 1);
    ranks[arr.back().i] = rank;
    for (int i = n - 2; i >= 0; --i) {
        ++rank;
        if (arr[i] == arr[i + 1]) ranks[arr[i].i] = ranks[arr[i + 1].i];
        else ranks[arr[i].i] = rank;
    }

    cout << ranks[k];

    return 0;
}