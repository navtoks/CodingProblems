#include <iostream>
using namespace std;

bool HasContSum(int n, int l) {
    if (l % 2) {
        if (n % l) return false;
        
        n = n / l - (l - 1) / 2;
        return n > 0;
    }
    else {
        n *= 2;
        if (n % l) return false;
        
        n = n / l + 1 - l;
        return n > 0 && n % 2 == 0;
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int cnt = 1;
    for (int l = 2; l < n; ++l) {
        if (HasContSum(n, l)) ++cnt;
    }
    cout << cnt;

    return 0;
}