#include <iostream>
#include <string>
#include <set>
using namespace std;

bool HasSameCycle(const string& s1, const string& s2) {
     int n = s1.size();
    if (n != s2.size()) return false;

    for (int i = 0; i < n; ++i) {
        bool flag = false;
        for (int j = 0; j < n; ++j) {
            if (s1[(i + j) % n] != s2[j]) {
                flag = true;
                break;
            }
        }
        if (!flag) return true;
    }
    return false;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;
    
    set<string> arr{s};
    while (--n) {
        cin >> s;

        bool flag = false;
        for (const auto& elt : arr) {
            if (HasSameCycle(s, elt)) {
                flag = true;
                break;
            }
        }
        if (!flag) arr.insert(s);
    }
    
    cout << arr.size();

    return 0;
}