#include <iostream>
#include <vector>
using namespace std;

struct Size {
    int w, h;
    bool operator<(const Size& other) {
        return w < other.w && h < other.h;
    }
};

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<Size> arr(n);
    for (auto& elt : arr) cin >> elt.w >> elt.h;

    vector<int> ranks(n, 1);
    for (int i = 0; i < n; ++i) {
        auto& now = ranks[i];
        for (int j = 0; j < n; ++j) {
            if (arr[i] < arr[j]) ++now;
        }
    }

    for (const auto& elt : ranks) cout << elt << ' ';

    return 0;
}