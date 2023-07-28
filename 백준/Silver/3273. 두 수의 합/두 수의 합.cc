#include <iostream>
#include <vector>
using namespace std;

const int MAXA = 1'000'000;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, x;
    cin >> n;

    vector<int> arr(n);
    vector<bool> appeared(MAXA + 1, false);
    for (auto& elt : arr) {
        cin >> elt;
        appeared[elt] = true;
    }

    cin >> x;

    int cnt = 0;
    for (const auto& elt : arr) {
        int other = x - elt;
        if (other < 0 || other > MAXA || elt == other) continue;
        if (appeared[elt] && appeared[other]) ++cnt;
    }
    cout << cnt / 2;

    return 0;
}