// Time complexity O(n^2) SPace complexity O(n)

// Clue: Use Binary trees to reduce the complexity to O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int length = nums.size();
        if (length == 0) return 0;
        
        vector<int> dp(nums.size(), 1);
        
        for(int i = 0; i < length - 1; ++i){
            for(int j = i + 1; j < length; j++){
                if(nums[i] < nums[j]){
                    dp[j] = max(dp[i] + 1, dp[j]);
                }
            }
        }
        
        return *max_element(dp.begin(),dp.end());
        
        
    }
};