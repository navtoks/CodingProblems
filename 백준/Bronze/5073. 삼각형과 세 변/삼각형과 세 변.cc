#include <iostream>
using namespace std;



int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0) break;

        int m = max(a, max(b, c));
        if (2 * m >= a + b + c) cout << "Invalid";
        else if (a == b) {
            if (a == c) cout << "Equilateral";
            else cout << "Isosceles";
        }
        else if (a == c) cout << "Isosceles";
        else if (b == c) cout << "Isosceles";
        else cout << "Scalene";
        cout << '\n';
    }

    return 0;
}