#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<string> arr(n);
    for (auto& elt : arr) cin >> elt;

    int x_cnt = 0;
    for (int i = 0; i < n; ++i) {
        bool cont = false;
        const auto& now = arr[i];
        for (int j = 0; j < n - 1; ++j) {
            if (now[j] == '.' && now[j + 1] == '.') {
                if (!cont) ++x_cnt;
                cont = true;
            }
            else cont = false;
        }
    }

    int y_cnt = 0;
    for (int i = 0; i < n; ++i) {
        bool cont = false;
        for (int j = 0; j < n - 1; ++j) {
            if (arr[j][i] == '.' && arr[j + 1][i] == '.') {
                if (!cont) ++y_cnt;
                cont = true;
            }
            else cont = false;
        }
    }
    cout << x_cnt << ' ' << y_cnt;
    
    return 0;
}