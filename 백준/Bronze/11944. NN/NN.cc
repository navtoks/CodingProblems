#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);
    
    int m;
    string s;
    cin >> s >> m;
    int d = s.size();

    int n = stoi(s) * d;
    n = n > m ? m : n;
    for (int i = 0; i < n; ++i) {
        cout << s[i % d];
    }

    return 0;
}