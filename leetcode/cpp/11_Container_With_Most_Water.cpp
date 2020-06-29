class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        int area = 0;
        while(left < right){
            
            if(height[left] > height[right]){
                area = height[right] * (right - left);
                right--;
            }
            else{
                area = height[left] * (right - left);
                left++;
            }
            
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};