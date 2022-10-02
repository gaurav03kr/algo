/*
Example 1:

Input: nums = [1,2,3,3,2,2]
Output: 2
Explanation:
The maximum possible bitwise AND of a subarray is 3.
The longest subarray with that value is [3,3], so we return 2.
Example 2:

Input: nums = [1,2,3,4]
Output: 1
Explanation:
The maximum possible bitwise AND of a subarray is 4.
The longest subarray with that value is [4], so we return 1.

*/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int maxi = -1;
        for(int i = 0; i<nums.size(); ++i)maxi = max(nums[i], maxi);
        
        int count = 0, ans = 0;
        for(int i = 0; i<nums.size(); ++i){
             if(nums[i] == maxi)++count;
            else count = 0;
            ans = max(ans, count);
        }
        return ans;
    }
};
