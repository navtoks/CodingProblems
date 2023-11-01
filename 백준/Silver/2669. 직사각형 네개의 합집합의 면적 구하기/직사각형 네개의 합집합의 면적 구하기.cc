#include <iostream>
#include <vector>
using namespace std;
using V = vector<int>;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    vector<V> arr(101, V(101, 0));
    for (int i = 0; i < 4; ++i) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int y = y1; y < y2; ++y) {
            for (int x = x1; x < x2; ++x) {
                arr[y][x] = 1;
            }
        }
    }

    int sum = 0;
    for (const auto& row : arr) {
        for (const auto& elt : row) if (elt) ++sum;
    }
    cout << sum;

    return 0;
}