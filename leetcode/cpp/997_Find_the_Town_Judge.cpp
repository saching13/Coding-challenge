class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_set<int> trust_list;
        unordered_set<int> trust_adj_list;
        for(vector<int>& edge : trust){
                trust_adj_list.insert(edge[0]);
        }
        
        if(trust_adj_list.size() != N - 1) return -1;
        
        int judge ;
        int remaining = N * (N + 1) / 2;
        
        for(auto val : trust_adj_list){
            remaining -= val;
            
        }
        // cout << remaining;
        judge = remaining;
        
        for(vector<int>& edge : trust){
            if(judge == edge[1]){
                trust_list.insert(edge[0]);
            }
        }
                
        if(trust_list.size() == N - 1) return judge;
        else return -1;
        
    }
};