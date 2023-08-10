#include <iostream>
#include <vector>
using namespace std;

struct X {
    int cnt, from;
};

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<X> arr(n + 1);
    arr[1] = X{0, 0};
    for (int i = 2; i <= n; ++i) {
        int prev = arr[i - 1].cnt;
        arr[i] = X{prev + 1, i - 1};
        if (i % 3 == 0) {
            int now = arr[i / 3].cnt;
            if (now < prev) {
                arr[i] = X{now + 1, i / 3};
                prev = now;
            }
        }
        if (i % 2 == 0) {
            int now = arr[i / 2].cnt;
            if (now < prev) arr[i] = X{now + 1, i / 2};
        }
    }

    cout << arr[n].cnt << '\n';
    int idx = n;
    while (idx) {
        cout << idx << ' ';
        idx = arr[idx].from;
    }

    return 0;
}