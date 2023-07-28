#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;
using mi = vector<vi>;

struct Paper {
    int w, b;
    bool IsWhite() const { return b == 0; }
    bool IsBlue() const { return w == 0; }
    Paper operator+(const Paper& other) { return Paper{w + other.w, b + other.b}; }
};

Paper BaseCondition(const mi& arr, int x, int y) {
    Paper now{0, 0};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (arr[y + i][x + j]) ++now.b;
            else ++now.w;
        }
    }
    if (now.IsWhite()) now.w = 1;
    if (now.IsBlue()) now.b = 1;
    return now;
}

Paper Recursion(const mi& arr, int n, int x, int y) {
    if (n == 2) {
        return BaseCondition(arr, x, y);
    }
    n /= 2;
    Paper result{0, 0};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            Paper now = Recursion(arr, n, x + i * n, y + j * n);
            result = result + now;
        }
    }
    if (result.IsWhite()) result.w = 1;
    if (result.IsBlue()) result.b = 1;
    return result;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    mi arr(n, vi(n));
    for (auto& row : arr) {
        for (auto& elt : row) cin >> elt;
    }
    Paper result = Recursion(arr, n, 0, 0);
    cout << result.w << '\n' << result.b;

    return 0;
}