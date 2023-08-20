#include <iostream>
#include <vector>
using namespace std;

int d(int n) {
    int result = n;
    while (n != 0) {
        result += n % 10;
        n /= 10;
    }
    return result;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    const int M = 10000;

    vector<bool> arr(M + 1, true);
    for (int i = 1; i <= M; ++i) {
        int now = d(i);
        if (now <= M) arr[now] = false;
    }

    for (int i = 1; i <= M; ++i) {
        if (arr[i]) cout << i << '\n';
    }

    return 0;
}