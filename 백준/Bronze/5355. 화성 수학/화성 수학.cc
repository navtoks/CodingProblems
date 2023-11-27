#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

double Solve(string& s) {
    stringstream ss(s);
    vector<string> results;
    string buffer;
    while (getline(ss, buffer, ' ')) {
        results.push_back(buffer);
    }

    double n = stod(results[0]);
    for (const auto& c : results) {
        if (c[0] == '@') n *= 3;
        if (c[0] == '%') n += 5;
        if (c[0] == '#') n -= 7;
    }
    return n;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s;
        getline(cin, s);
        cout.precision(2);
        cout << fixed << Solve(s) << '\n';
    }

    return 0;
}