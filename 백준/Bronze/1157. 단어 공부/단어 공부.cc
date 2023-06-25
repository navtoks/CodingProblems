#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    vector<int> cnts(26, 0);
    for (const auto& c : s) {
        int i = tolower(c) - 'a';
        ++cnts[i];
    }

    int m_idx = 0;
    for (int i = 0; i < 26; ++i) {
        if (cnts[m_idx] < cnts[i]) m_idx = i;
    }

    bool repeated = false;
    for (int i = m_idx + 1; i < 26; ++i) {
        if (cnts[m_idx] == cnts[i]) {
            repeated = true;
            break;
        }
    }

    if (repeated) cout << '?';
    else cout << static_cast<char>(m_idx + 'A');
}