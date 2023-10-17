#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void Solve(string& s) {
    stringstream ss(s);
    string buffer;
    while (getline(ss, buffer, ' ')) {
        int n = buffer.size();
        for (int i = 0; i < n; ++i) cout << buffer[n - i - 1];
        cout << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string s;
        getline(cin, s);
        Solve(s);
    }

    return 0;
}