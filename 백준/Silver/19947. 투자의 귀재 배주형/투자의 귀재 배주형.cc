#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);
    
    int h, y;
    cin >> h >> y;

    if (y == 0) {
        cout << h;
        return 0;
    }

    vector<int> arr(y + 1);
    arr[0] = h;
    for (int i = 1; i <= y; ++i) {
        arr[i] = arr[i - 1] * 1.05;
        if (i >= 3) arr[i] = max(int(arr[i - 3] * 1.2), arr[i]);
        if (i >= 5) arr[i] = max(int(arr[i - 5] * 1.35), arr[i]);
    }
    cout << arr.back();

    return 0;
}