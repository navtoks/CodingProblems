#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

ll Parse(const string& s) {
    int result = 0;
    ll n = s.size() - 2;
    for (int i = 0; i < 6; ++i) {
        result *= 10;
        if (i < n) result += (s[i + 2] - '0');
    }
    return result;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);
    
    ll m;
    cin >> m;

    vector<int> cnts(m, 0);
    while (true) {
        string s;
        cin >> s;
        if (cin.eof()) break;

        ll n = Parse(s);
        n = n * m / 1000000;
        ++cnts[n];
    }
    
    for (const auto& cnt : cnts) cout << cnt << ' ';

    return 0;
}