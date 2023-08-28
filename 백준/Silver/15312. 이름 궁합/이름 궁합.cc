#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> cnts{3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;

    int n = a.size() * 2;
    vector<int> arr(n);
    for (int i = 0; i < n / 2; ++i) {
        arr[2 * i] = cnts[a[i] - 'A'];
        arr[2 * i + 1] = cnts[b[i] - 'A'];
    }

    for (int i = n - 1; i > 1; --i) {
        for (int j = 0; j < i; ++j) {
            arr[j] = (arr[j] + arr[j + 1]) % 10;
        }
    }
    cout << arr[0] << arr[1];

    return 0;
}