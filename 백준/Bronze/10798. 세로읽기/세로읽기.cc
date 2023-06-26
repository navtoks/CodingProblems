#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    vector<string> arr(5);
    for (auto& s : arr) cin >> s;

    int n_max = 0;
    for (const auto& s : arr) {
        if (s.size() > n_max) n_max = s.size();
    }

    for (int j = 0; j < n_max; ++j) {
        for (int i = 0; i < 5; ++i) {
            if (j < arr[i].size()) cout << arr[i][j];
        }
    }

    return 0;
}