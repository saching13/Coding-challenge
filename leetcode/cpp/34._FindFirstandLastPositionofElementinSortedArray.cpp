class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = INT_MAX, end = INT_MIN;
        if (nums.size() == 0) return {-1,-1};
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                start = std::min(start, i);
                end = std::max(end, i);
            }
            else if(nums[i] > target) break;
        }
        
        if(start == INT_MAX) return {-1,-1};
        return {start,end};
    }
};