class Solution {
    void dfs(int node, vector<vector<int>>& rooms, vector<bool>& visited){
        
            visited[node] = true;

            for(int next_room : rooms[node]){
                if(!visited[next_room]){
                    dfs(next_room, rooms, visited);
                }
            }

            return;
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        
        dfs(0,rooms,visited);
        
        bool is_visited = true;
        
        for(bool v : visited){
            is_visited = is_visited && v;
        }
        return is_visited;
    }
};