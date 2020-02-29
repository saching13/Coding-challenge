class Solution {
public:
    
    unordered_map <char,vector<string>> phone_match = {{'2',{"a", "b", "c"}},
                                                       {'3',{"d", "e", "f"}},
                                                       {'4',{"g", "h", "i"}},
                                                       {'5',{"j", "k", "l"}},
                                                       {'6',{"m", "n", "o"}},
                                                       {'7',{"p", "q", "r", "s"}},
                                                       {'8',{"t", "u", "v"}},
                                                       {'9',{"w", "x", "y", "z"}}};
     
    
    vector<string> letterCombinations(string digits) {
       deque<string> result;
        
        for(char num : digits){
            int result_len = result.size();
            int i = 0;
            if(result_len == 0){
                for (string c : phone_match[num]){
                    result.push_back(c);
                    }
           }
            
            while(i < result_len){
                for(string c : phone_match[num]){
                    result.push_back(result[0] + c);
                }
                i++;
                result.pop_front();
            }
        }
        
        
        return {result.begin(), result.end()};
        
    }
};