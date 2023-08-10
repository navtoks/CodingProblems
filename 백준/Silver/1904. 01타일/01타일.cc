#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int cur = 1, prev = 1, pprev = 0;
    while (--n) {
        int now = (cur + prev) % 15746;
        pprev = prev;
        prev = cur;
        cur = now;
    }
    cout << cur;

    return 0;
}