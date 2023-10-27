#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> result;

void Solve(const string& s) {
    result.reserve(3 * s.size());
    for (const auto& c : s) {
        int x = c - '0';
        result.push_back(x / 4);
        result.push_back(x % 4 / 2);
        result.push_back(x % 2);
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    Solve(s);

    if (s == "0") cout << 0;

    bool flag = false;
    for (const auto& elt : result) {
        if (flag) cout << elt;
        else if (elt) {
            cout << elt;
            flag = true;
        }
    }
    
    return 0;
}