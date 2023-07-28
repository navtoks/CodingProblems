#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;
using mi = vector<vi>;

mi arr;

struct Paper {
    int w, b;
    Paper operator+(const Paper& other) { return {w + other.w, b + other.b}; }
    void MakeUnified() {
        if (b == 0) w = 1;
        if (w == 0) b = 1;
    }
};

Paper Recursion(int n, int x, int y) {
    if (n == 1) {
        if (arr[y][x]) return {0, 1};
        return {1, 0};
    }

    n /= 2;
    Paper result{0, 0};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            auto now = Recursion(n, x + i * n, y + j * n);
            result = result + now;
        }
    }
    result.MakeUnified();
    return result;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    arr = mi(n, vi(n));
    for (auto& row : arr) {
        for (auto& elt : row) cin >> elt;
    }
    Paper result = Recursion(n, 0, 0);
    cout << result.w << '\n' << result.b;

    return 0;
}