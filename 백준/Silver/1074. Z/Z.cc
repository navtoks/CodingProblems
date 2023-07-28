#include <iostream>
using namespace std;

int Recursion(int n, int r, int c) {
    if (n == 1) {
        return 2 * r + c;
    }
    int result = 0;
    int offset = 1 << (n - 1);
    if (r >= offset) {
        result += 2 * offset * offset;
        r -= offset;
    }
    if (c >= offset) {
        result += offset * offset;
        c -= offset;
    }
    return result + Recursion(n - 1, r, c);
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, r, c;
    cin >> n >> r >> c;
    cout << Recursion(n, r, c);

    return 0;
}