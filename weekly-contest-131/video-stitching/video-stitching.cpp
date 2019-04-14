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
    int videoStitching(vector<vector<int>> &clips, int t) {
        vector<int> max_range;
        for (auto i = 0; i <= t; i++) {
            max_range.push_back(i);
        }

        for (auto clip : clips) {
            auto from = clip[0];
            auto to = clip[1];
            if (from <= t && max_range[from] < to) {
                for (auto i = from; i < to && i <= t; i++) {
                    max_range[i] = max(to, max_range[i]);
                }
            }
        }

        auto to = 0;
        auto count = 0;
        while (to < t) {
            count += 1;
            if (to == max_range[to]) {
                return -1;
            }
            to = max_range[to];
        }

        return count;
    }
};

int main() {
    auto s = new Solution();
    vector<vector<int>> a = {
        {41, 82}, {3, 75},  {15, 90},  {21, 75}, {49, 91}, {46, 59},  {6, 88},
        {13, 16}, {22, 92}, {42, 52},  {29, 45}, {53, 74}, {72, 91},  {62, 76},
        {34, 47}, {16, 29}, {80, 93},  {49, 88}, {2, 9},   {63, 83},  {8, 36},
        {0, 11},  {38, 42}, {13, 70},  {39, 48}, {53, 70}, {26, 100}, {45, 77},
        {12, 93}, {16, 40}, {64, 66},  {56, 66}, {2, 52},  {65, 73},  {36, 50},
        {17, 32}, {10, 84}, {92, 95},  {81, 90}, {45, 87}, {7, 11},   {14, 30},
        {57, 85}, {49, 49}, {56, 100}, {17, 65}, {76, 96}, {41, 91},  {44, 93},
        {9, 85},  {18, 86}, {19, 52},  {7, 16},  {1, 25},  {8, 68},   {35, 91},
        {7, 66},  {70, 75}, {23, 60},  {48, 72}, {8, 9},   {69, 80},  {45, 77},
        {42, 96}, {47, 92}, {32, 49},  {72, 81}, {3, 46},  {29, 92},  {14, 57},
        {39, 66}, {0, 15},  {49, 77},  {37, 60}, {24, 77}, {15, 74},  {36, 64},
        {61, 76}, {10, 96}, {9, 24},   {23, 55}, {35, 72}, {11, 26},  {38, 71},
        {44, 89}, {42, 49}, {49, 52},  {28, 93}, {12, 61}, {7, 69},   {42, 82},
        {4, 66},  {4, 58},  {2, 51},   {1, 44},  {22, 67}, {6, 53},   {37, 46},
        {5, 65},  {10, 33}};
    auto r = s->videoStitching(a, 80);
    cout << r << endl;
}

// .replace(/\[/g,'{').replace(/\]/g, '}')