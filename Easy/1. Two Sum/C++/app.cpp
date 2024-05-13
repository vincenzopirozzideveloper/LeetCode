#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }
        return {};  // This line is unlikely to be reached
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> indices1 = solution.twoSum(nums1, target1);
    cout << "Test case 1: [" << indices1[0] << ", " << indices1[1] << "]" << endl;

    // Test case 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> indices2 = solution.twoSum(nums2, target2);
    cout << "Test case 2: [" << indices2[0] << ", " << indices2[1] << "]" << endl;

    // Test case 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> indices3 = solution.twoSum(nums3, target3);
    cout << "Test case 3: [" << indices3[0] << ", " << indices3[1] << "]" << endl;

    return 0;
}
