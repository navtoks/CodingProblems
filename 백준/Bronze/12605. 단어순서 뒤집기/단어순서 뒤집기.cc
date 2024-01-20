#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void Solve(string& s) {
    stringstream ss(s);
    string buffer;
    vector<string> result;
    while (ss >> buffer) {
        result.push_back(buffer);
    }

    for (auto i = rbegin(result); i != rend(result); ++i) {
        cout << *i << ' ';
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cin.ignore();
    
    for (int i = 1; i <= n; ++i) {
        string s;
        getline(cin, s);
        cout << "Case #" << i << ": ";
        Solve(s);
        cout << '\n';
    }

    return 0;
}