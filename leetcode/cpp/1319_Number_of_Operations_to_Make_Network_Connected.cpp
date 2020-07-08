
// DSU: naive method implemented. Use rank for better O(..) complexity
class Solution {
    
    int redundancy_edge = 0;
     vector<int> parent;
        
        int find(int x){
            while(parent[x] != x)
                x = parent[x];
            return x;
        }
        
        void union_find(int x, int y){
            int x_par = find(x);
            int y_par = find(y);
            // std::cout << "x: " << x << ", x_par " << x_par << ",  y " << y << ",  y_par " << y_par << std::endl;
            if(x_par == y_par){
                redundancy_edge++;
            }
            else{
                parent[y_par] = x_par;
            }
        }
            
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int unconnected_nodes = 0;
        
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0); // ivec will become: [0..99]
        
        for(auto& edge : connections){
            union_find(edge[0], edge[1]);
        }
        
        for(int i = 0; i < n; ++i){
            // cout << i << "parent" << parent[i] << endl;
            if(parent[i] == i){
                unconnected_nodes++;
            }
        }
        unconnected_nodes--;
        std::cout << unconnected_nodes << " " << redundancy_edge << endl;
        if(unconnected_nodes > redundancy_edge) return -1;
        else if(redundancy_edge > unconnected_nodes) return unconnected_nodes;
        else return redundancy_edge;
        
    }
};