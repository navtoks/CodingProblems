#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int cnt = 0;
    while (n > 4) {
        cnt += n / 5;
        n /= 5;
    }
    cout << cnt;

    return 0;
}