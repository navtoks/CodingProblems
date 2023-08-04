#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    vector<int> arr(225);
    for (int i = 1; i < 225; ++i) arr[i] = i * i;

    int n;
    cin >> n;

    int m = 1;
    while (arr[m] < n) ++m;
    if (arr[m] == n) {
        cout << 1;
        return 0;
    }

    for (int i = 1; arr[i] < n; ++i) {
        for (int j = 1; arr[j] < n; ++j) {
            if (arr[i] + arr[j] == n) {
                cout << 2;
                return 0;
            }
        }
    }

    for (int i = 1; arr[i] < n; ++i) {
        for (int j = 1; arr[j] < n; ++j) {
            for (int k = 1; arr[k] < n; ++k) {
                if (arr[i] + arr[j] + arr[k] == n) {
                    cout << 3;
                    return 0;
                }
            }
        }
    }

    for (int i = 1; arr[i] < n; ++i) {
        for (int j = 1; arr[j] < n; ++j) {
            for (int k = 1; arr[k] < n; ++k) {
                for (int l = 1; arr[l] < n; ++l) {
                    if (arr[i] + arr[j] + arr[k] + arr[l] == n) {
                        cout << 4;
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}