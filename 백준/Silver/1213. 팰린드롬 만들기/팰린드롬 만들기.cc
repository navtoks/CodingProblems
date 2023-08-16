#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Print(int n) {
    cout << static_cast<char>(n + 'A');
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    vector<int> arr(26, 0);
    for (const auto& c : s) ++arr[c - 'A'];

    int odd = -1;
    bool IsPalindrome = true;
    for (int i = 0; i < 26; ++i) {
        if (arr[i] % 2 == 0) continue;

        if (odd == -1) odd = i;
        else IsPalindrome = false;
    }

    if (!IsPalindrome) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }

    for (int i = 0; i < 26; ++i) {
        int n = arr[i] / 2;
        while (n--) Print(i);
    }
    if (odd != -1) Print(odd);
    for (int i = 25; i >= 0; --i) {
        int n = arr[i] / 2;
        while (n--) Print(i);
    }
    
    return 0;
}