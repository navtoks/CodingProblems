#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

map<int, string> nums{
    {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"},
    {7, "seven"}, {8, "eight"}, {9, "nine"}, {10, "ten"}, {11, "eleven"},
    {12, "twelve"}, {13, "thirteen"}, {14, "fourteen"}, {15, "fifteen"},
    {16, "sixteen"}, {17, "seventeen"}, {18, "eighteen"}, {19, "nineteen"},
    {20, "twenty"}, {30, "thirty"}, {40, "forty"}, {50, "fifty"}, {60, "sixty"},
    {70, "seventy"}, {80, "eighty"}, {90, "ninety"}, {100, "hundred"}
};

string ConvertToString(int n) {
    string result;

    int h = n / 100;
    if (h != 0) {
        result += nums[h];
        result += nums[100];
    }

    n %= 100;
    if (n == 0) return result;

    if (n < 20) {
        result += nums[n];
        return result;
    }

    int t = n / 10;
    if (t) result += nums[t * 10];

    int o = n % 10;
    if (o) result += nums[o];

    return result;    
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int cnt = 0, idx = 0;
    vector<string> arr;
    while (n--) {
        string s;
        cin >> s;

        arr.push_back(s);
        if (s == "$") idx = arr.size() - 1;
        else cnt += s.size();
    }

    string now;
    for (int i = 1; i < 1000; ++i) {
        now = ConvertToString(i);
        if (cnt + now.size() == i) break;
    }
    arr[idx] = now;

    for (const auto& s : arr) cout << s << ' ';

    return 0;
}