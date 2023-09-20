#include <iostream>
#include <string>
using namespace std;

string inputs{"=-0987654321\\][POIUYTREW\';LKJHGFDS/.,MNBVCX"};
string outputs{"-0987654321`][POIUYTREWQ;LKJHGFDSA.,MNBVCXZ"};
int n = inputs.size();

char Convert(char c) {
    for (int i = 0; i < n; ++i) {
        if (inputs[i] == c) return outputs[i];
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    while (true) {
        string s;
        getline(cin, s);
        if (cin.eof()) break;

        for (auto& c : s) {
            if (c == ' ') continue;
            c = Convert(c);
        }
        cout << s << '\n';
    }

    return 0;
}