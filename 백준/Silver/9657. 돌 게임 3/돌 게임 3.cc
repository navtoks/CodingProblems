#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    vector<bool> arr(1001, true);  // 1, 3, 4 = true
    arr[2] = false;
    for (int i = 5; i <= 1000; ++i) {
        if (arr[i - 1] && arr[i - 3] && arr[i - 4]) arr[i] = false;
    }

    int n;
    cin >> n;

    if (arr[n]) cout << "SK";
    else cout << "CY";

    return 0;
}