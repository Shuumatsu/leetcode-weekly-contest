#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    vector<int> nextLargerNodes(ListNode *head) {
        vector<int> arr;
        vector<int> r;
        stack<int> s;
        for (auto curr = head; curr; curr = curr->next) {
            while (s.size() && arr[s.top()] < curr->val) {
                r[s.top()] = curr->val;
                s.pop();
            }
            s.push(arr.size());
            arr.push_back(curr->val);
            r.push_back(0);
        }

        return r;
    }
};