#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void SetArr(vector<int>& arr) {
    for (auto& elt : arr) cin >> elt;
    sort(begin(arr), end(arr));
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> as(n), bs(m);
        SetArr(as);
        SetArr(bs);

        int cnt = 0, j = 0;
        for (int i = 0; i < n; ++i) {
            while (as[i] > bs[j] && j < m) ++j;
            cnt += j;
        }

        cout << cnt << '\n';
    }

    return 0;
}