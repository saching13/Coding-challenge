//44. Wildcard Matching

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1,false));
        dp[0][0] = true;
        
        //if (p.size() == 0 || s.size() == 0) return true;
        
        for(int j = 0; j < p.size(); j++){
            //cout << j << endl;
            if(p[j] == '*') dp[0][j+1] = dp[0][j];
            //else dp[0][j+1] = false;
        }
        //cout << "end" << endl;
        //for(int i = 1; i <= s.size(); i++) dp[i][0] = false;
        
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < p.size(); j++){
                //cout <<
                if(p[j] == '*') dp[i + 1][j + 1] = dp[i + 1][j] | dp[i][j + 1] | dp[i][j];
                else if(p[j] == '?' || p[j] == s[i]) dp[i + 1][j + 1] = dp[i ][j];
                else dp[i + 1][j + 1] = false;
            }
        }
        
        return dp[s.size()][p.size()];
    }
};