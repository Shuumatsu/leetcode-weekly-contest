
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
        if (s.size() <= 1) {
            return new TreeNode(s[0] - '0');
        }

        stack<tuple<int, TreeNode *>> stack;
        auto h = [&](auto depth, auto val) {
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
        };

        auto val = -1;
        auto depth = 0;
        TreeNode *root;
        for (auto x : s) {
            if (x == '-') {
                if (val != -1) {
                    if (depth == 0) {
                        root = new TreeNode(val);
                        stack.push({depth, root});
                    } else {
                        h(depth, val);
                    }
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
        h(depth, val);

        return root;
    }
};

int main() {
    auto s = new Solution();
    auto a = "1-2--3--4-5--6--7";
    auto r = s->recoverFromPreorder("3");
}
