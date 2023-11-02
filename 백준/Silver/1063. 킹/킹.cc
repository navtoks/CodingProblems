#include <iostream>
#include <string>
#include <map>
using namespace std;

struct X {
    int x, y;
    X operator+(X o) { return {x + o.x, y + o.y}; }
    bool IsValid() { return x >= 0 && x < 8 && y >= 0 && y < 8; }
    bool IsSame(X o) { return x == o.x && y == o.y; }
};

map<string, X> moves{
    {"R", {1, 0}}, {"L", {-1, 0}}, {"B", {0, -1}}, {"T", {0, 1}},
    {"RT", {1, 1}}, {"LT", {-1, 1}}, {"RB", {1, -1}}, {"LB", {-1, -1}}
};

X ToX(string s) {
    char x = s[0], y = s[1];
    return X{x - 'A', y - '1'};
}

void Print(X pos) {
    cout << char(pos.x + 'A') << pos.y + 1;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    string s;
    cin >> s;   X king{s[0] - 'A', s[1] - '1'};
    cin >> s;   X stone{s[0] - 'A', s[1] - '1'};

    int n;
    cin >> n;
    while (n--) {
        cin >> s;
        X dx = moves[s];

        X now = king + dx;
        if (!now.IsValid()) continue;
        if (now.IsSame(stone)) {
            X temp = stone + dx;
            if (!temp.IsValid()) continue;
            stone = temp;
        }
        king = now;
    }

    Print(king);
    cout << '\n';
    Print(stone);

    return 0;
}