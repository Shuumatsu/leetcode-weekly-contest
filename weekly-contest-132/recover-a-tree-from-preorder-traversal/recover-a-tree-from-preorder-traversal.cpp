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

// "1-2--3--4-5--6--7"
class Solution {
  public:
    TreeNode *recoverFromPreorder(string s) {
        vector<tuple<int, int>> tokens;
        auto val = -1;
        auto depth = 0;
        for (auto x : s) {
            if (x == '-') {
                if (val != -1) {
                    tokens.push_back({depth, val});
                    val = -1;
                    depth = 0;
                }
                depth += 1;
                continue;
            }
            if (val != -1) {
                val = val * 10 + (x - '0');
                continue;
            }
            val = x - '0';
        }
        tokens.push_back({depth, val});

        stack<tuple<int, TreeNode *>> stack;
        function<void(int)> h = [&](auto i) {
            if (i >= tokens.size()) {
                return;
            }
            auto [depth, val] = tokens[i];

            while (get<0>(stack.top()) >= depth) {
                stack.pop();
            }
            auto node = new TreeNode(val);
            auto parent = get<1>(stack.top());
            if (parent->left) {
                parent->right = node;
            } else {
                parent->left = node;
            }

            stack.push({depth, node});
            h(i + 1);
        };

        auto root = new TreeNode(get<1>(tokens[0]));
        stack.push({0, root});
        h(1);

        return root;
    }
};

int main() {
    auto s = new Solution();
    auto a = "1-2--3--4-5--6--7";
    auto r = s->recoverFromPreorder("3");
}