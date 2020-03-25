//leetcode: 96. Unique Binary Search Trees

class Solution {
public:
    int numTrees(int n) {
        // Hint: at each number i in n as node [0 : i-1] will be left sub tree 
        // and [i+1]:n will ne right sub tree and both will always be sorted.
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; ++i){
            for(int j = 1; j <= i; ++j){
            dp[i] += dp[j - 1] * dp[i - j];    
            }
        }
        
        return dp[n];
    }
};