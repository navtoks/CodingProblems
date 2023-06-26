#include <iostream>
#include <string>
using namespace std;

char ToChar(int n) {
    if (n < 10) return n + '0';
    return n - 10 + 'A';
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, b;
    cin >> n >> b;

    string result;
    while (n) {
        result += ToChar(n % b);
        n /= b;
    }

    for (auto iter = rbegin(result); iter != rend(result); ++iter) {
        cout << *iter;
    }

    return 0;
}