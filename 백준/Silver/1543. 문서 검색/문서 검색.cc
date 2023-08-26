#include <iostream>
#include <string>
using namespace std;
 
int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int n = s1.size();
    int m = s2.size();

    int cnt = 0;
    for (int i = 0; i <= n - m; ++i) {
        bool flag = false;
        for (int j = 0; j < m; ++j) {
            if (s1[i + j] != s2[j]) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            ++cnt;
            i += m - 1;
        }
    }
    cout << cnt;

    return 0;
}