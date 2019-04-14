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
        map<int, map<int, int>> diff_len;

        auto length = 0;
        for (auto j = 1; j < a.size(); j++) {
            for (auto i = 0; i < j; i++) {
                auto diff = a[j] - a[i];
                diff_len[diff][j] = diff_len[diff][i] + 1;
                length = max(length, diff_len[diff][j]);
            }
        }

        return length + 1;
    }
};
