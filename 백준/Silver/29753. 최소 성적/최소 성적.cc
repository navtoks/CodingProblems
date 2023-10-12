#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
using S = string;

map<S, int> dict;
vector<S> scores{"F", "D0", "D+", "C0", "C+", "B0", "B+", "A0", "A+"};

void SetDictionary() {
    int score = 50;
    for (const auto& s : scores) {
        dict.insert({s, score});
        score += 50;
    }
    dict["F"] = 0;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    SetDictionary();

    int n;
    S s;
    cin >> n >> s;
    
    int mean = ((s[0] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0'));

    int credit, credits = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> credit;
        credits += credit;
        if (i != n - 1) {
            cin >> s;
            sum += credit * dict[s];
        }
    }

    S result = "impossible";
    for (const auto& s : scores) {
        if ((sum + credit * dict[s]) / credits > mean) {
            result = s;
            break;
        }
    }
    cout << result;

    return 0;
}