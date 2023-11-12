#include <iostream>
#include <vector>
using namespace std;
using V = vector<int>;

bool IsMonotonic(const V& arr, int i) {
    int a = arr[i], b = arr[i + 1], c = arr[i + 2];
    return (a <= b && b <= c) || (a >= b && b >= c);
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    V arr(n);
    for (auto& elt : arr) cin >> elt;

    int m = 0;
    int cnt = 0;
    for (int i = 0; i < n - 3; ++i) {
        if (IsMonotonic(arr, i)) {
            m = max(m, cnt);
            cnt = 0;
        }
        else ++cnt;
    }

    if (IsMonotonic(arr, n - 3)) m = max(m, cnt);
    else m = max(m, cnt + 1);

    cout << m + 2;

    return 0;
}