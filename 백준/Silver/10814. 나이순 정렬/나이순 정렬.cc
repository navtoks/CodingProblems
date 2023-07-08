#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct X {
    int n;
    string s;
    bool operator<(const X& other) const {
        return n < other.n;
    }
};

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<X> arr(n);
    for (auto& elt : arr) cin >> elt.n >> elt.s;
    stable_sort(begin(arr), end(arr));

    for (const auto& elt : arr) cout << elt.n << ' ' << elt.s << '\n';
    
    return 0;
}