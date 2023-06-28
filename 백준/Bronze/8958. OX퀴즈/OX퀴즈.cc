#include <iostream>
#include <string>
using namespace std;

int ComputeScore(const string& s) {
    int score = 0;
    int cnt = 0;
    for (const auto& c : s) {
        if (c == 'O') ++cnt;
        else cnt = 0;
        score += cnt;
    }
    return score;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        string s;
        cin >> s;
        cout << ComputeScore(s) << '\n';
    }

    return 0;
}