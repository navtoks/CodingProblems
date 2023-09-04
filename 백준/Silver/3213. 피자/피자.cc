#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> cnts(4, 0);
    while (n--) {
        int a, b;
        char c;
        cin >> a >> c >> b;
        if (a == 3) ++cnts[3];
        else if (b == 2) ++cnts[2];
        else ++cnts[1];
    }

    n = cnts[3];
    cnts[1] -= n;

    n += cnts[2] / 2;
    if (cnts[2] % 2) {
        ++n;
        cnts[1] -= 2;
    }

    if (cnts[1] > 0) {
        n += cnts[1] / 4;
        if (cnts[1] % 4 != 0) ++n;
    }
    cout << n;
    
    return 0;
}