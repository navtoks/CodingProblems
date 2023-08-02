#include <iostream>
#include <vector>
using namespace std;

struct X {
    int jump, cont;
    // jump = from 2 step before
    // cont = from 1 step before, then this can not be used for the next step.
    int Max() const { return jump > cont ? jump : cont; }
};

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto& elt : arr) cin >> elt;

    if (n == 1) {
        cout << arr[0];
        return 0;
    }

    vector<X> table(n);
    table[0] = {arr[0], 0};
    table[1] = {arr[1], arr[1] + table[0].jump};
    for (int i = 2; i < n; ++i) {
        int from_jump = table[i - 2].Max();
        int from_cont = table[i - 1].jump;
        table[i] = {arr[i] + from_jump, arr[i] + from_cont};
    }
    cout << table.back().Max();

    return 0;
}