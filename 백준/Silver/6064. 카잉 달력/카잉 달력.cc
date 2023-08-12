#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        
        int year = -1;
        for (int i = 0; i < N; ++i) {
            int candidate = x + M * i;
            if ((candidate - y) % N == 0) {
                year = candidate;
                break;
            }
        }
        cout << year << '\n';
    }

    return 0;
}