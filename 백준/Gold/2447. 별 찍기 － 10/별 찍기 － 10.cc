#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> arr;

void WriteBlank(int n, int i_start, int j_start) {
    if (n == 1) return;

    n /= 3;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i_start + n + i][j_start + n + j] = ' ';
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            WriteBlank(n, i_start + i * n, j_start + j * n);
        }
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    arr = vector<string>(n, string(n, '*'));
    WriteBlank(n, 0, 0);

    for (const auto& s : arr) cout << s << '\n';

    return 0;
}