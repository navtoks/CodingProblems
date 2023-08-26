#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";

        vector<int> arr(3);
        for (auto& elt : arr) cin >> elt;
        sort(begin(arr), end(arr));

        if (arr[0] + arr[1] <= arr[2]) {
            cout << "invalid!\n";
            continue;
        }

        if (arr[0] == arr[2]) cout << "equilateral\n";
        else if (arr[0] == arr[1] || arr[1] == arr[2]) cout << "isosceles\n";
        else cout << "scalene\n";
    }

    return 0;
}