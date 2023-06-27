#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int a, b, v;
    cin >> a >> b >> v;

    v -= a;
    int n = v / (a - b);
    if (v % (a - b)) ++n;
    cout << n + 1;

    return 0;
}