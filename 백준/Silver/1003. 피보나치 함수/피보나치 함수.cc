#include <iostream>
#include <vector>
using namespace std;

struct FiboVector {
    int e0{0};
    int e1{0};
    FiboVector operator+(const FiboVector& other) {
        return FiboVector{e0 + other.e0, e1 + other.e1};
    }
};

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    vector<FiboVector> arr(41);
    arr[0].e0 = 1;
    arr[1].e1 = 1;
    for (int i = 2; i <= 40; ++i) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;
        cout << arr[n].e0 << ' ' << arr[n].e1 << '\n';
    }

    return 0;
}