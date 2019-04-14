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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    int maxAncestorDiff(TreeNode *root) {
        function<tuple<int, int>(TreeNode *)> h = [&](auto node) {
            int max_negative = 0;
            int max_positive = 0;
            auto calc_from_child = [&](auto child) {
                if (!child) {
                    return;
                }

                auto [a, b] = h(child);
                cout << a << " " << b;
                auto diff = node->val - child->val;

                if (diff == 0) {
                    max_positive = max(max_positive, b);
                    max_negative = min(max_negative, a);
                    return;
                }

                if (diff < 0) {
                    max_negative = min(max_negative, diff + a);
                    max_positive = max(max_positive, b);
                    return;
                }
                max_positive = max(max_positive, diff + b);
                max_negative = min(max_negative, a);
            };

            calc_from_child(node->left);
            calc_from_child(node->right);
            tuple<int, int> t = {max_negative, max_positive};
            return t;
        };

        auto [a, b] = h(root);
        return max(abs(a), abs(b));
    }
};