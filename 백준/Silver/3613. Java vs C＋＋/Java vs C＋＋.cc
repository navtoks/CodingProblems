#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);
    
    string s;
    cin >> s;

    bool is_snake = false;
    bool is_mixed = false;
    for (const auto& c : s) {
        if (isupper(c)) is_mixed = true;
        if (c == '_') is_snake = true;
    }
    
    bool has_first_error = isupper(s[0]) || (s[0] == '_');
    bool has_last_error = (s.back() == '_');
    bool has_cont_underscroe = false;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == '_' && s[i - 1] == '_') has_cont_underscroe = true;
    }

    string result;
    if (has_first_error ||
        has_last_error ||
        has_cont_underscroe ||
        (is_snake && is_mixed)) result = "Error!";
    else if (is_snake) {
        bool underscore = false;
        for (const auto& c : s) {
            if (underscore) {
                result += toupper(c);
                underscore = false;
            }
            else if (c == '_') underscore = true;
            else result += c;            
        }
    }
    else {
        for (const auto& c : s) {
            if (isupper(c)) result += '_';
            result += tolower(c);
        }
    }

    cout << result;

    return 0;
}