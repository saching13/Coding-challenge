class Solution {
    
    int find(int x, vector<int>& parent){
        while(x != parent[x]){
            x = parent[x];
        }
        
        return x;
    }
    
    bool union_find(int x, int y, vector<int>& parent, vector<int>& rank){
        int x_par = find(x, parent);
        int y_par = find(y, parent);
        
        if(x_par == y_par){
            return true;
        }
        else if(rank[x_par] < rank[y_par]){
            parent[x_par] = y_par;
        }
        else if(rank[y_par] < rank[x_par]){
            parent[y_par] = x_par;
        }
        else{
            rank[x_par]++;
            parent[y_par] = x_par;
        }
        
        return false;
    }
    
    
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        if(edges.size() < 3) return {};
        
        int N = 0;
        for(vector<int>& edg : edges){
            N = max(N, edg[0]);
            N = max(N, edg[1]);
        }
        
        vector<int> parent(N + 1);
        vector<int> rank(N + 1, 0);
        std::iota(parent.begin(), parent.end(), 0);

        
        for(vector<int>& edg : edges){
        
            if(union_find(edg[0], edg[1], parent, rank)) return edg;        
        }
        
        return {};
    }
};