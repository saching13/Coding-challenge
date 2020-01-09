class Solution {
public:
    
    int rotation_search(vector<int>& nums){
        int left = 0;
        int right = nums.size()-1;
        int mid;
        while(left <= right){
            mid = (left + right+1) / 2; // (a+b-1)/b ceiling method
            if ((mid != nums.size()-1) && (nums[mid] > nums[mid + 1]))
                return mid + 1;
            if (nums[left] < nums[mid])
                left = mid + 1; 
            else
                right = mid - 1; 

        }
        
        return 0;
    }
    
    int binary_search(int left, int right,vector<int>& nums,int target){
        int mid;
        while(left <= right){
            mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        int index = rotation_search(nums);
            if (index == 0)
                return binary_search(index,nums.size()-1,nums,target);
            if (target >= nums[0]){
                return binary_search(0,index-1,nums,target);
            }
            else
                return binary_search(index,nums.size()-1,nums,target);
    }
};