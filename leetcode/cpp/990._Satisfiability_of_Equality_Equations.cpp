#include <algorithm>
class Solution {
    
    unordered_map<char,char> equal_parents;
    
    char find(char curr_node){
            if(equal_parents.find(curr_node) == equal_parents.end()){
                return curr_node;
            }
            else{
                if(equal_parents[curr_node] == curr_node)
                    return curr_node;
                else
                    return find(equal_parents[curr_node]);
            }

    }
    
    void union_find(char x, char y){
        char par_x = find(x);
        char par_y = find(y);
        
        if(par_x != par_y){
                equal_parents[par_y]  = par_x;


        }
    }
    
public:
    bool equationsPossible(vector<string>& equations) {
        
        for(string edge : equations){
            if(edge[1] == '='){
                union_find(edge[0], edge[3]);
            }
        }
        
        
        for(string edge : equations){
            
            if(edge[1] == '!'){
                if(find(edge[0]) == find(edge[3]))
                    return false;
            }
        }
        return true;
        
    }
};