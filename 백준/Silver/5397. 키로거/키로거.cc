#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        list<char> lst;
        auto iter = begin(lst);
        for (const auto& c : s) {
            switch (c) {
            case '<':
                if (iter != begin(lst)) --iter;
                break;
            case '>':
                if (iter != end(lst)) ++iter;
                break;
            case '-':
                if (iter != begin(lst)) iter = lst.erase(--iter);
                break;
            default:
                iter = lst.insert(iter, c);
                ++iter;
                break;
            }
        }

        for (iter = begin(lst); iter != end(lst); ++iter) cout << *iter;
        cout << '\n';
    }

    return 0;
}