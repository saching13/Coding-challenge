class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        
        queue<int> pose;
        pose.push(start);
        
        while(!pose.empty()){
            int curr_pose = pose.front();
            pose.pop();
            
            visited[curr_pose] = true;
            if(arr[curr_pose] == 0){
                return true;
            }
            int next_pose = curr_pose + arr[curr_pose];
            
            if(next_pose >= 0 && next_pose < arr.size()){
                if(!visited[next_pose]){
                    pose.push(next_pose);
                }
            }
            next_pose = curr_pose - arr[curr_pose];
            
            if(next_pose >= 0 && next_pose < arr.size()){
                if(!visited[next_pose]){
                    pose.push(next_pose);
                }
            }
            
        }
        
        
        return false;
        
        
        
    }
};