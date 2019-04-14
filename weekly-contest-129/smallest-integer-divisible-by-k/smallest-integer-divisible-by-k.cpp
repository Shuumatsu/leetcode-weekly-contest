#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    int smallestRepunitDivByK(int k) {
        auto length = 1;
        auto n = 1;
        while (length <= k) {
            auto h = n % k;
            if (h == 0) {
                return length;
            }
            length += 1;
            n = 10 * h + 1;
        }

        return -1;
    }
};
