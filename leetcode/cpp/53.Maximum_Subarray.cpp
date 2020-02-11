// Kadane's Algo
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev = 0, sum ;
        for(int i = 0; i < nums.size(); i++){
            prev += nums[i];
            if (i == 0) sum = nums[0];
            if(prev < nums[i]) prev = nums[i];
            //cout <<sum << endl;
            sum = max(sum, prev);
        }
        return sum;
        
    }
};