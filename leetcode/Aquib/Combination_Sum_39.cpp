// Question : https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> result;   
    void calculate_sum(vector<int>& candidates, int target,vector<int> prefix,int index)
    {
        if(target == 0) {result.push_back(prefix); }
        if(target <= 0) {return;}
        for(int i =index; i < candidates.size();i++)
        {
           prefix.push_back(candidates[i]);
           calculate_sum(candidates, target -candidates[i], prefix,i);
            prefix.pop_back();
            
        }
        
        
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int> prefix;
        sort(candidates.begin(),candidates.end());
        calculate_sum(candidates,target, prefix, 0);
        
        return result;
        
        
    }
};