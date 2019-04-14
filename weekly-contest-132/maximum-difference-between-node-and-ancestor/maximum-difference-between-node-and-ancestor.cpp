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
        auto max_negative = 0;
        auto max_positive = 0;
        function<tuple<int, int>(TreeNode *)> h = [&](auto node) {
            auto cmax_val = node->val;
            auto cmin_val = node->val;

            auto calc = [&](auto child) {
                auto [max_val, min_val] = h(child);
                max_positive = max(node->val - min_val, max_positive);
                max_negative = min(node->val - max_val, max_negative);
                cmax_val = max(cmax_val, max_val);
                cmin_val = min(cmin_val, min_val);
            };
            if (node->left) {
                calc(node->left);
            }
            if (node->right) {
                calc(node->right);
            }

            tuple<int, int> mm = {cmax_val, cmin_val};
            return mm;
        };
        h(root);

        return abs(max_negative) > max_positive ? abs(max_negative)
                                                : max_positive;
    }
};