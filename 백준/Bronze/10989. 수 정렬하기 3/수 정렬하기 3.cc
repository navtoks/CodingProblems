#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> arr(10001, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++arr[x];
    }

    for (int i = 1; i <= 10000; ++i) {
        for (int j = 0; j < arr[i]; ++j) {
            cout << i << '\n';
        }
    }
    
    return 0;
}