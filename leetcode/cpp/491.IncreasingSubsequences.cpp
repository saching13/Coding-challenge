class Solution {
public:
    
    void helper(vector<int>& nums, int idx, vector<int>& subRes, set<vector<int>>& result){
        if(subRes.size() > 1) result.insert(subRes);
        for(int i = idx; i < nums.size(); ++i){
            if(!subRes.empty() && nums[i] < subRes.back()) continue;
            subRes.push_back(nums[i]);
            helper(nums, i + 1, subRes, result);
            subRes.pop_back();
        }
    }
    
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        set<vector<int>> result;
        vector<int> subRes;
        
        helper(nums, 0, subRes, result);
        
        return vector<vector<int>>(result.begin(), result.end());
    }
};