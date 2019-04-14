#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxScoreSightseeingPair(vector<int> &arr) {
        auto max_score = INT32_MIN;
        auto curr_a = INT32_MIN;
        for (auto i = 0; i < arr.size(); i++) {
            auto a = arr[i] + i;
            auto b = arr[i] - i;

            max_score = max(max_score, curr_a + b);
            curr_a = max(curr_a, a);
        }

        return max_score;
    }
};