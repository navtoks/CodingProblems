#include <iostream>
#include <vector>
using namespace std;

bool IsEndNumber(int n) {
    while (n > 100) {
        if (n % 1000 == 666) return true;
        n /= 10;
    }
    return false;
}

int NextNumber(int n) {
    while (!IsEndNumber(n)) {
        ++n;
    }
    return n;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int number = 666;
    for (int i = 1; i < n; ++i) {
        number = NextNumber(number + 1);
    }
    cout << number;

    return 0;
}