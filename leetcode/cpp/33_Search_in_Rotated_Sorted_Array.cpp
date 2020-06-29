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


// Approach 2

class Solution {
    
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
        
        return nums.size();
    }
    
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        if(nums.size() == 1) {
            if(nums[0] == target) return 0;
            else return -1;
        }
        int start_index = nums.size();
        std::vector<int>::iterator low;
        // method one linear to find the startIndex
        for(int i = 1; i < nums.size(); ++i){
            if(!(nums[i-1] < nums[i])) start_index = i;
        }
        
        //start_index = rotation_search(nums) // method2 to find the start_index with binary search
        
        if(target >= nums[0] && target <= nums[start_index - 1]) 
            low=std::lower_bound (nums.begin(), nums.begin() + start_index - 1, target);
        else if(start_index < nums.size() && target <= nums[nums.size() - 1] && target >= nums[start_index]) 
            low=std::lower_bound (nums.begin() + start_index, nums.end(), target);
        else
            return -1;
        
        if(nums[low - nums.begin()] == target) return low - nums.begin();
        else return -1;
        
        
    }
};