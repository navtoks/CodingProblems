#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
using vi = vector<int>;

#define FOR(i) for(int i = 0; i < 16; ++i)

unordered_map<string, int> map_to_num;
unordered_map<int, string> map_to_str;
vector<vi> dists(16, vi(16, 0));
vi arr;

void SetMaps() {
    string s{"0000"};
    FOR(i) {
        s[0] = (i & 1 ? 'E' : 'I');
        s[1] = (i & 2 ? 'S' : 'N');
        s[2] = (i & 4 ? 'T' : 'F');
        s[3] = (i & 8 ? 'J' : 'P');

        map_to_num.insert({s, i});
        map_to_str.insert({i, s});
    }
}

void SetDists() {
    FOR(i) {
        FOR(j) {
            if (i == j) continue;
            if (j < i) dists[i][j] = dists[j][i];
            else {
                const auto& s1 = map_to_str[i];
                const auto& s2 = map_to_str[j];
                for (int k = 0; k < 4; ++k) {
                    if (s1[k] != s2[k]) ++dists[i][j];
                }
            }
        }
    }
}

void Case2(int i, int& result) {
    FOR(j) {
        if (arr[j] == 0 || i == j) continue;
        result = min(result, dists[i][j] * 2);
    }
}

void Case3(int i, int& result) {
    FOR(j) {
        if (arr[j] == 0 || i == j) continue;
        FOR(k) {
            if (arr[k] == 0 || i == k || j == k) continue;
            result = min(result, dists[i][j] + dists[i][k] + dists[j][k]);
        }
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    SetMaps();
    SetDists();

    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;

        arr = vi(16, 0);
        while (n--) {
            string s;
            cin >> s;
            ++arr[map_to_num[s]];
        }

        int result = 12;
        FOR(i) {
            if (arr[i] > 2) {
                result = 0;
                break;
            }
            else if (arr[i] == 2) Case2(i, result);
            else if (arr[i]) Case3(i, result);
        }
        cout << result << '\n';
    }

    return 0;
}