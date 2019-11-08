## leet code 11. Container With Most Water
class Solution:
    def maxArea(self, height: List[int]) -> int:
        l = len(height)
        top_index = l - 1
        min_index = 0
        area = 0   
            
        while (min_index < l) and (top_index >= 0):
            if height[min_index] > height[top_index]:
                a1 = (top_index-min_index) * height[top_index]
                top_index -= 1
            else:
                a1 = (top_index-min_index) * height[min_index]
                min_index += 1
            if a1 > area:
                area = a1
                
        return area

        