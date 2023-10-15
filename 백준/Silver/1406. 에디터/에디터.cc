#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    list<char> lst;
    auto iter = begin(lst);
    for (const auto& c : s) {
        iter = lst.insert(iter, c);
        ++iter;
    }

    int n;
    cin >> n;
    while (n--) {
        char c;
        cin >> c;
        switch (c) {
        case 'L':
            if (iter != begin(lst)) --iter;
            break;
        case 'D':
            if (iter != end(lst)) ++iter;
            break;
        case 'B':
            if (iter != begin(lst)) iter = lst.erase(--iter);
            break;
        case 'P':
            cin >> c;
            iter = lst.insert(iter, c);
            ++iter;
            break;
        }
    }

    for (iter = begin(lst); iter != end(lst); ++iter) cout << *iter;

    return 0;
}