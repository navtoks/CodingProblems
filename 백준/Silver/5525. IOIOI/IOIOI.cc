#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsIoi(const string& s, int i) {
    return s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I';
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, m;
    string s;
    cin >> n >> m >> s;

    vector<int> chunks;
    int cnt = 0;
    for (int i = 0; i < m - 2; ++i) {
        if (IsIoi(s, i)) {
            ++cnt;
            ++i;
        }
        else if (cnt) {
            chunks.push_back(cnt);
            cnt = 0;
        }
    }
    if (cnt) chunks.push_back(cnt);

    cnt = 0;
    for (const auto& elt : chunks) {
        int now = elt - n + 1;
        if (now > 0) cnt += now;
    }
    cout << cnt;

    return 0;
}