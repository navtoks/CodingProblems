#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 1;
        return 0;
    }

    vector<int> arr(n + 1);
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i <= n; ++i) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
    }
    cout << arr[n];

    return 0;
}