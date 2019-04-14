#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxScoreSightseeingPair(vector<int> &A) {
        auto sc = INT32_MIN;
        vector<int> processed;
        auto fc = A[0];
        processed.push_back(fc);
        auto push_back_sc = true;
        auto push_back_fc = false;
        for (auto i = 1; i < A.size(); i++) {
            auto a = A[i] + i;
            auto b = A[i] - i;

            if (push_back_sc) {
                sc = b;
                processed.push_back(sc);
                push_back_sc = false;
                push_back_fc = true;
            } else if (b > sc) {
                sc = b;
                processed[processed.size() - 1] = sc;
            }

            if (a > fc) {
                fc = a;
                if (push_back_fc) {
                    processed.push_back(fc);
                } else {
                    processed[processed.size() - 1] = fc;
                }
                push_back_sc = true;
                push_back_fc = false;
            }
        }

        auto m = INT32_MIN;
        for (auto i = 0; i < processed.size() - 1; i += 2) {
            auto x = processed[i] + processed[i + 1];
            if (x > m) {
                m = x;
            }
        }

        return m;
    }
};

int main() {
    // vector<int> a = {8, 1, 5, 2, 6};
    vector<int> a = {1, 2, 2};
    auto s = new Solution();
    auto r = s->maxScoreSightseeingPair(a);
    cout << r << endl;
    return 0;
}