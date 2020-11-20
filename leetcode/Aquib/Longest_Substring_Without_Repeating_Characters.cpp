// Question : https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/


class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int * visited_array = new int[256];
        int current_length =1;
        int max_length = 1;
        int previous_index =0;
        int string_length = s.length();
        if(s == ""){return 0;}
        for(int i =0; i < 256;i++)
        {
            visited_array[i] = -1;
        }
        visited_array[s[0]] = 0;
        for(int i =1; i < string_length;i++)
        {
            previous_index = visited_array[s[i]];
            
            if(previous_index == -1 || i - current_length > previous_index )
            {
                current_length++;
            }
            else
            {
                if(current_length > max_length )
                {
                    max_length = current_length;    
                }
                current_length = i - previous_index;
                
            }
            visited_array[s[i]] = i;
        }
              if(current_length > max_length )
                {
                    max_length = current_length;    
                }
        delete []visited_array;
        return max_length;
    }
};