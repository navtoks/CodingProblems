#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int x;
    cin >> x;

    int n = 0;
    int sum = 0;
    while (x > sum) {
        sum += n++;
    }
    sum -= n;

    int denominator = x - sum - 1;
    int numerator = n - denominator;
    if (n % 2) cout << denominator << '/' << numerator;
    else cout << numerator << '/' << denominator;

    return 0;
}