#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int h, w, n;
        cin >> h >> w >> n;

        int x = n / h;
        int y = n % h;

        if (y == 0) y = h;
        else ++x;

        cout << y;
        cout.width(2);
        cout.fill('0');
        cout << x << '\n';
    }

    return 0;
}