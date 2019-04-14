#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    string removeOuterParentheses(string str) {
        vector<char> removed;
        auto left = 0;
        for (auto x : str) {
            if (x == '(') {
                left += 1;
                if (left == 1) {
                    continue;
                }
                removed.push_back('(');
                continue;
            }
            left -= 1;
            if (left == 0) {
                continue;
            }
            removed.push_back(')');
        }

        std::ostringstream oss;
        copy(removed.begin(), removed.end(), ostream_iterator<char>(oss));
        return oss.str();
    }
};

int main() {
    auto s = new Solution();
    auto a = "(()())(())";
    auto r = s->removeOuterParentheses(a);
    cout << r << endl;
    a = "(()())(())(()(()))";
    r = s->removeOuterParentheses(a);
    cout << r << endl;
    a = "()()";
    r = s->removeOuterParentheses(a);
    cout << r << endl;
}