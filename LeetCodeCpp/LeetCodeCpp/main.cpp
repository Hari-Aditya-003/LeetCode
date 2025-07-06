#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        for (int& num : arr) {
            int val = (num & 65535);
            if (val <= n) {
                arr[val - 1] += (1 << 16);
            }
        }
        for (int val = n; val >= 1; val--) {
            if ((arr[val - 1] >> 16) == val) {
                return val;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> input = {2, 2, 3, 4}; // example input
    cout << "Lucky Integer: " << sol.findLucky(input) << endl;
    return 0;
}
