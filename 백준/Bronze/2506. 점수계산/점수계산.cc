#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, sum = 0, cnt = 0;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        if (x) sum += ++cnt;
        else cnt = 0;
    }
    cout << sum;

    return 0;
}