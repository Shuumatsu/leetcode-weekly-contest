#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

auto to_binary = [&](auto n) {
    vector<char> b;
    while (n != 0) {
        b.push_back(n & 1 == 1 ? '1' : '0');
        n /= 2;
    }
    reverse(b.begin(), b.end());

    ostringstream bss;
    std::copy(b.begin(), b.end(), ostream_iterator<char>(bss));

    return bss.str();
};

class Solution {
  public:
    bool queryString(string str, int N) {
        for (auto i = 0; i <= N; i++) {
            if (str.find(to_binary(i)) == string::npos) {
                return false;
            }
        }

        return true;
    }
};