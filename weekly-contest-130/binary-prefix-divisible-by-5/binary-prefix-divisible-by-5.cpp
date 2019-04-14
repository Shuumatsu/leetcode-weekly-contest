#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<bool> prefixesDivBy5(vector<int> &A) {
        vector<bool> result;
        auto curr = 0;
        for (auto x : A) {
            curr = curr * 2 + x;
            curr = curr % 5;
            result.push_back(curr == 0);
        }

        return result;
    }
};

int main() {
    auto s = new Solution();
    vector<int> a = {0, 1, 1};
    auto r = s->prefixesDivBy5(a);
    for (auto x : r) {
        cout << x << " ";
    }
    cout << endl;
}