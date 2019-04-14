#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

class Solution {
  public:
    int numEnclaves(vector<vector<int>> &A) {
        auto row_size = A.size();
        if (row_size == 0) {
            return 0;
        }
        auto col_size = A[0].size();

        function<void(int, int)> dfs = [&](auto i, auto j) {
            A[i][j] = 0;
            auto verify = [&](auto ni, auto nj) {
                if (ni >= 0 && nj >= 0 && ni < row_size && nj < col_size &&
                    A[ni][nj]) {
                    dfs(ni, nj);
                }
            };
            verify(i + 1, j);
            verify(i - 1, j);
            verify(i, j + 1);
            verify(i, j - 1);
        };

        for (auto i = 0; i < row_size; i++) {
            for (auto j = 0; j < col_size; j++) {
                if ((i * j == 0 || i == row_size - 1 || j == col_size - 1) &&
                    A[i][j]) {
                    dfs(i, j);
                }
            }
        }

        return accumulate(A.begin(), A.end(), 0, [&](auto accu, auto row) {
            return accu +
                   accumulate(row.begin(), row.end(), 0,
                              [&](auto accu, auto x) { return accu + x; });
        });
    }
};