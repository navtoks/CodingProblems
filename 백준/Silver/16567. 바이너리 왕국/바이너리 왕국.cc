#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, m, x;
    cin >> n >> m;

    int cnt = 0;
    bool cont = false;
    vector<int> arr(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        if (arr[i]) {
            if (!cont) {
                cont = true;
                ++cnt;
            }
        }
        else cont = false;
    }

    while (m--) {
        cin >> x;
        if (x) {
            cin >> x;
            if (arr[x]) continue;
            cnt += (1 - arr[x - 1] - arr[x + 1]);
            arr[x] = 1;
        }
        else cout << cnt << '\n';
    }

    return 0;
}