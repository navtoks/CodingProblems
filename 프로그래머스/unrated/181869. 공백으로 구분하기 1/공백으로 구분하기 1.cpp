#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    stringstream ss(my_string);
    string buffer;
    while (getline(ss, buffer, ' ')) {
        answer.push_back(buffer);
    }
    return answer;
}