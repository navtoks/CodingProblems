#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n == 4 || n == 7) cout << -1;
    else {
        int cnt = n / 5;
        int rem = n % 5;

        switch (rem)
        {
        case 1:
        case 3:
            ++cnt;
            break;
        case 2:
        case 4:
            cnt += 2;
            break;
        }
        cout << cnt;
    }

    return 0;
}