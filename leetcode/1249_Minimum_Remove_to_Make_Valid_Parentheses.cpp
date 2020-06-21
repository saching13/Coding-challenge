#include <deque>

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int idx = 0;
        if(s.size() == 0)
            return s;
        int open = 0;
        int close = 0;
        std::deque<int> rem_index;
        while(idx < s.size()){
            
            if((s[idx] == '(') || (s[idx] == ')')){
                if(s[idx] == '('){
                    
                 rem_index.push_back(idx);
                    open += 1;
                }
                else if(s[idx] == ')'){
                    open -=1;
                    if(open >= 0){
                        rem_index.pop_back();
                    }
                }
                if(open < 0){
                    open++;
                    rem_index.push_back(idx);
                }
            }

            idx++;
        }
        int offset = 0;
        for(int i : rem_index){
            cout << i + offset<< " ";
            s.erase(s.begin() + i + offset);    
            offset--;
        }
        return s;
    }
};