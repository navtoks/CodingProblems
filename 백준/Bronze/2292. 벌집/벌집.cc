#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    --n;

    int rooms = 0;
    while (3 * rooms * (rooms + 1) < n) {
        ++rooms;
    }
    cout << rooms + 1;

    return 0;
}