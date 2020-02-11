class Solution {
public:
    vector<int> days;
    vector<int> costs;
    vector<int> duration = {1, 7, 30};
    vector<int> min_costs;
    
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
     this->days = days;
     this->costs = costs;
     this->min_costs.resize(days.size(),0);
        
     
    return dp(0);
    }
    
    
    int dp(int i){
        
        if(i >= days.size())
            return 0;
        if(min_costs[i] != 0)
            return min_costs[i];
        
        int ans = INT_MAX;
        int j = i;
        for(int k = 0; k < 3; k++){
            while(j < days.size() && days[j] < days[i]+ duration[k])    j++;
            ans = min(ans,dp(j) + costs[k]);
        }
        
        min_costs[i] = ans;
        return ans;    
    }
    
};