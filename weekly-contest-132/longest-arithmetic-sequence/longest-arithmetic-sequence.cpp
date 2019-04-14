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
    int longestArithSeqLength(vector<int> &a) {
        map<int, int> m;
        for (auto i = 1; i < a.size(); i++) {
            auto diff = a[i] - a[i - 1];
            m[diff] += 1;
        }

        auto length = 0;
        for (auto [_, x] : m) {
            length = max(length, x);
        }

        return length + 1;
    }
};