#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    vector<int> arr(11);
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for (int i = 4; i < 11; ++i) {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;
        cout << arr[n] << '\n';
    }

    return 0;
}