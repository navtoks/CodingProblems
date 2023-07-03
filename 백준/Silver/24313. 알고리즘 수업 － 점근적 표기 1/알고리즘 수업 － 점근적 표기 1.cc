#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int a1, a0, c, n0;
    cin >> a1 >> a0 >> c >> n0;
    c -= a1;

    bool satisfied = (c * n0 >= a0) && (c >= 0);
    cout << satisfied;

    return 0;
}