class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> duplicate;
        
        
        for(string& files : paths){
            istringstream iss(files);
            vector<string> split_files{ istream_iterator<string>{iss}, istream_iterator<string>{} };
            
            string root_folder = split_files[0] + "/";
            
            for(int i = 1; i < split_files.size(); ++i){
                int open = split_files[i].find("(");
                int close = split_files[i].find(")");
                string file_content = split_files[i].substr(open + 1, close - open - 1);
                duplicate[file_content].push_back(root_folder + split_files[i].substr(0,open));
            }
            
        }
        vector<vector<string>> res;
        unordered_map<string, vector<string>>::iterator t = duplicate.begin();
        for(unordered_map<string, vector<string>>::iterator it = duplicate.begin(); it != duplicate.end(); it++ ){
            if(it->second.size() > 1)
            res.push_back(it->second);
        }
        
        return res;
    }
};