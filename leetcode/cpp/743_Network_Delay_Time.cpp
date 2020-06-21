// Method 1: DFS slower. doesnt take advantage of weights.


class Solution {
    
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        unordered_map<int, vector<pair<int, int>>> adj_list; 
        vector<int> delay(N + 1, INT_MAX);
        
        for(int i = 0; i < times.size(); ++i){
            if(adj_list.find(times[i][0]) == adj_list.end()){
                adj_list[times[i][0]] = {{times[i][1], times[i][2]}};
            }
            else{
                adj_list[times[i][0]].push_back({times[i][1], times[i][2]});
            }
        }
        
        delay[K] = 0;
        delay[0] = 0;
        dfs(K, delay, adj_list, 0);
        
        int max_val = *max_element(delay.begin(), delay.end());

        if(max_val == INT_MAX) return -1;
        else return max_val;
    }
    
    void dfs(int node, vector<int>& delay, unordered_map<int, vector<pair<int, int>>>& adj_list, int curr_time){
        
        for(pair<int, int>& sub_node : adj_list[node]){
            if(delay[sub_node.first] > curr_time + sub_node.second){
                delay[sub_node.first] = curr_time + sub_node.second;
                if(adj_list.find(sub_node.first) != adj_list.end())
                    dfs(sub_node.first, delay, adj_list, delay[sub_node.first]);
            }
            
        }
        return;
    }
};


// Method 2: DIjkastra

class Solution {
    
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        unordered_map<int, vector<pair<int, int>>> adj_list; 
        vector<int> delay(N + 1, INT_MAX);
        
        for(int i = 0; i < times.size(); ++i){
            if(adj_list.find(times[i][0]) == adj_list.end()){
                adj_list[times[i][0]] = {make_pair(times[i][1], times[i][2])};
            }
            else{
                adj_list[times[i][0]].push_back({times[i][1], times[i][2]});
            }
        }
        
        delay[K] = 0;
        delay[0] = 0;
            
        priority_queue<int, vector<pair<int, int>>, std::greater<pair<int, int>>> node_que;
        
        node_que.push(make_pair(0,K));
                      
        while(!node_que.empty()){
            
            pair<int, int> curr_node = node_que.top(); 
            node_que.pop();
            int u = curr_node.second;
            
            for(const auto& sub : adj_list[u]){
                
                if(delay[sub.first] > curr_node.first + sub.second){
                    delay[sub.first] = curr_node.first + sub.second;
                    if(adj_list.find(sub.first) != adj_list.end())
                        node_que.push(make_pair(delay[sub.first], sub.first));
                }
            }
        }
        
        int max_val = *max_element(delay.begin(), delay.end());

        if(max_val == INT_MAX) return -1;
        else return max_val;
    }
    

};