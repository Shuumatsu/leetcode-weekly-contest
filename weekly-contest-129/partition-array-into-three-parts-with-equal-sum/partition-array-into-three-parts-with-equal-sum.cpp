#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    bool canThreePartsEqualSum(vector<int> &A) {
        auto sum = 0;
        for (auto x : A) {
            sum += x;
        }
        if (sum % 3 != 0) {
            return false;
        }
        auto target = sum / 3;

        auto first_part = A[0];
        auto third_part = A[(A.size() - 1)];
        // i and j mean the gaps are before the index i/j
        function<bool(int, int)> sliding_window = [&](auto i, auto j) {
            // cout << i << " " << first_part << "---" << j << " " << third_part
            //      << endl;
            if (i == j) {
                return false;
            }
            if (first_part != target) {
                first_part += A[i];
                return sliding_window(i + 1, j);
            }
            if (third_part != target) {
                third_part += A[j - 1];
                return sliding_window(i, j - 1);
            }
            if (sum - first_part - third_part == target) {
                return true;
            }
            first_part += A[i];
            return sliding_window(i + 1, A.size() - 1);
        };

        return sliding_window(1, A.size() - 1);
    }
};

int main() {
    vector<int> a = {3, 3, 6, 5, -2, 2, 5, 1, -9, 4};
    cout << a.size() << endl;
    auto s = new Solution();
    auto r = s->canThreePartsEqualSum(a);
    if (r) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    return 0;
}