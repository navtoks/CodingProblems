#include <iostream>
#include <vector>
using namespace std;

vector<bool> buttons(10, true);
int digits = 1;

bool IsMovable(int n) {
    digits = 1;
    while (n > 9) {
        if (!buttons[n % 10]) return false;
        n /= 10;
        ++digits;
    }
    return buttons[n];
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int x;
        cin >> x;
        buttons[x] = false;
    }

    const int MAX = 500'000 * 2;
    int min_moves = abs(n - 100);
    for (int i = 0; i < MAX; ++i) {
        if (IsMovable(i)) {
            int moves = abs(n - i) + digits;
            min_moves = min(min_moves, moves);
        }
    }
    cout << min_moves;
    
    return 0;
}