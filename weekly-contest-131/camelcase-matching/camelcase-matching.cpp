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

class Solution {
  public:
    vector<bool> camelMatch(vector<string> &queries, string pattern) {
        vector<function<char(int)>> transitions;
        bool last_lowercase = false;
        for (auto p : pattern) {
            int current_state = transitions.size();
            if (isupper(p)) {
                if (last_lowercase) {
                    transitions.push_back([=](auto c) {
                        if (c == p) {
                            return current_state + 1;
                        }
                        if (islower(c)) {
                            return current_state;
                        }
                        return -1;
                    });
                    transitions.push_back([=](auto c) {
                        if (c == p) {
                            return current_state + 1;
                        }
                        if (islower(c)) {
                            return current_state;
                        }
                        return -1;
                    });
                    continue;
                }
                transitions.push_back([=](auto c) {
                    if (c == p) {
                        return current_state + 1;
                    }
                    if (islower(c)) {
                        return current_state;
                    }
                    return -1;
                });
                continue;
            }
            last_lowercase = true;
            transitions.push_back([=](auto c) {
                if (c == p) {
                    return current_state + 1;
                }
                if (islower(c)) {
                    return current_state + 2;
                }
                return -1;
            });
        }
    }
};