#include <iostream>
#include <vector>
using namespace std;

void MoveHanoi(int n, int from, int to) {
    if (n == 0) return;
    
    int temp = 6 - from - to;
    MoveHanoi(n - 1, from, temp);
    cout << from << ' ' << to << '\n';
    MoveHanoi(n - 1, temp, to);
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    cout << (1 << n) - 1 << '\n';
    MoveHanoi(n, 1, 3);

    return 0;
}