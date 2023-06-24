#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    vector<bool> arr(42, false);
    for (int i = 0; i < 10; ++i) {
        int x;
        cin >> x;
        arr[x % 42] = true;
    }

    int cnt = 0;
    for (const auto& elt : arr) {
        if (elt) ++cnt;
    }
    cout << cnt;
}