#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int i = 1;
    while (i * i <= n) {
        ++i;
    }
    cout << i - 1;

    return 0;
}