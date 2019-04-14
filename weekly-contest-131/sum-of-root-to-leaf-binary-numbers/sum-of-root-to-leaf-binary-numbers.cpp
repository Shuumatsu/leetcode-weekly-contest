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
    int calc(int p, TreeNode *node) {
        auto n = p * 2 + node->val;

        if (node->left == NULL) {
            if (node->right == NULL) {
                return n;
            }
            return calc(n, node->right);
        }
        if (node->right == NULL) {
            return calc(n, node->left);
        }
        return calc(n, node->left) + calc(n, node->right);
    }

    int sumRootToLeaf(TreeNode *root) { return calc(0, root); };
};
