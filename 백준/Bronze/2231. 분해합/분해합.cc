#include <iostream>
using namespace std;

int ComposedSum(int n) {
    int sum = n;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int generator = 0;
    for (int i = 0; i < n; ++i) {
        if (ComposedSum(i) == n) {
            generator = i;
            break;
        }
    }

    cout << generator;

    return 0;
}