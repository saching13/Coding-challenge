class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> answer(nums.size(), 1);
        
        for(int i = 1; i < length; i++){
            answer[i] = answer[i-1] * nums[i-1]; // Here we calculate only product of previous 
        }
        
        int R = 1;
        for(int j = length-1; j >= 0; j--){
            
            answer[j] = answer[j]*R; // Here we calculate only product of all the next values that come  
            R = R * nums[j];
        }
        
        return answer;
        
    }
};