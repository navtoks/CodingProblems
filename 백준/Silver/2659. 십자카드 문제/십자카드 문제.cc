#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using V = vector<int>;

int TimeNumber(V& num) {
    int m = 10000;
    for (int i = 0; i < 4; ++i) {
        int now = num[i] * 1000 + num[(i + 1) % 4] * 100 + num[(i + 2) % 4] * 10 + num[(i + 3) % 4];
        if (now < m) m = now;
    }
    return m;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    V arr(10000, 0);
    for (int n = 1111; n < 10000; ++n) {
        V num(4);
        int now = n;
        bool flag = false;
        for (int i = 0; i < 4; ++i) {
            int r = now % 10;
            if (r == 0) {
                flag = true;
                break;
            }
            num[3 - i] = r;
            now /= 10;
        }
        int t = TimeNumber(num);
        arr[t] = 1;
    }

    V num(4);
    for (auto& n : num) cin >> n;
    int t = TimeNumber(num);

    int cnt = 0;
    for (int i = 1111; i <= t; ++i) {
        if (arr[i]) ++cnt;
    }

    cout << cnt;

    return 0;
}