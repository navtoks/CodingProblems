#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
using vi = vector<int>;
using dict1 = unordered_map<string, int>;
using dict2 = unordered_map<int, string>;

dict1 map_to_num;
dict2 map_to_str;
vector<vi> dists(16, vi(16, 0));
vi arr;

void SetMaps() {
    string s{"0000"};
    for (int i = 0; i < 16; ++i) {
        s[0] = (i & 1 ? 'E' : 'I');
        s[1] = (i & 2 ? 'S' : 'N');
        s[2] = (i & 4 ? 'T' : 'F');
        s[3] = (i & 8 ? 'J' : 'P');

        map_to_num.insert({s, i});
        map_to_str.insert({i, s});
    }
}

void SetDists() {
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            const auto& s1 = map_to_str[i];
            const auto& s2 = map_to_str[j];
            for (int k = 0; k < 4; ++k) {
                if (s1[k] != s2[k]) ++dists[i][j];
            }
        }
    }
}

void Case2(int i, int& result) {
    for (int j = 0; j < 16; ++j) {
        if (arr[j] == 0 || i == j) continue;
        int dist = dists[i][j] * 2;
        if (dist < result) result = dist;
    }
}

void Case3(int i, int& result) {
    for (int j = 0; j < 16; ++j) {
        if (arr[j] == 0 || i == j) continue;

        for (int k = 0; k < 16; ++k) {
            if (arr[k] == 0 || i == k || j == k) continue;
            int dist = dists[i][j] + dists[i][k] + dists[j][k];
            if (dist < result) result = dist;
        }
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    SetMaps();
    SetDists();

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        arr = vi(16, 0);
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            ++arr[map_to_num[s]];
        }

        int result = 12;
        for (int i = 0; i < 16; ++i) {
            if (arr[i] == 0) continue;
            if (arr[i] > 2) result = 0;
            else if (arr[i] == 2) Case2(i, result);
            else Case3(i, result);
        }
        cout << result << '\n';
    }

    return 0;
}