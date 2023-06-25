#include <iostream>
#include <string>
#include <vector>
using namespace std;

double ComputeScore(const string& s) {
    if (s == "F") return 0.0;

    double score = 'D' - s[0] + 1;
    if (s[1] == '+') score += 0.5;
    return score;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    double mean = 0;
    double total = 0;
    for (int i = 0; i < 20; ++i) {
        double credit;
        string s, score;
        cin >> s >> credit >> score;

        if (score == "P") continue;

        total += credit;
        mean += credit * ComputeScore(score);
    }

    cout.precision(4);
    cout << fixed << mean / total;
}