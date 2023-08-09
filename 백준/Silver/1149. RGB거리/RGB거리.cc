#include <iostream>
#include <vector>
using namespace std;

struct C {
    int r, g, b;
};

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<C> arr(n);
    for (auto& elt : arr) cin >> elt.r >> elt.g >> elt.b;

    for (int i = 1; i < n; ++i) {
        const auto& prev = arr[i - 1];
        arr[i].r += min(prev.g, prev.b);
        arr[i].g += min(prev.r, prev.b);
        arr[i].b += min(prev.r, prev.g);
    }

    const auto& result = arr.back();
    cout << min(result.r, min(result.g, result.b));

    return 0;
}