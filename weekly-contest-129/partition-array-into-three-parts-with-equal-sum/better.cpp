#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    bool canThreePartsEqualSum(vector<int> &arr) {
        auto sum = accumulate(arr.begin(), arr.end(), 0,
                              [&](auto accu, auto x) { return accu + x; });
        if (sum % 3 != 0) {
            return false;
        }
        auto target = sum / 3;

        auto times = 0;
        auto curr = 0;
        for (auto x : arr) {
            curr += x;
            if (curr == target) {
                times += 1;
                curr = 0;
            }
        }

        return curr == 0 && times >= 3;
    }
};