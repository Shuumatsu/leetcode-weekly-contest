#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
  public:
    string baseNeg2(int n) {
        string r = "";
        auto curr = n;
        do {
            auto x = curr & 1;
            r = to_string((curr & 1)) + r;
            curr = -(curr >> 1);
        } while (curr != 0);
        return r;
    }
};

int main() {
    auto s = new Solution();
    for (auto a = 0; a < 5; a++) {
        auto r = s->baseNeg2(a);
        cout << r << endl;
    }
}