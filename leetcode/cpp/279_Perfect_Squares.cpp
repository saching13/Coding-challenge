class Solution {
public:
    int numSquares(int n) {
        
        vector<int> dp(n+1,INT_MAX);
        vector<int> sqNum;
        dp[0] = 0;
        
        for(int i = 1; i <= n; i++){
            
            int s = sqrt(i);
            if(s*s == i){
                
                dp[i] = 1;
                sqNum.push_back(i);
            }
            else{
                
                for(int j = 0; j < sqNum.size(); j++){
                     dp[i]= min(dp[i],dp[i-sqNum[j]] + 1);
                
                }
            }
            
        }
        
        return dp[n];
        
    }
};