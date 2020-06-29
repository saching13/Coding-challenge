class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return {};
        
        vector<int> result;
        int r_min = 0,r_max = matrix.size() - 1;
        int c_min = 0,c_max = matrix[0].size() - 1;

        while(r_min <= r_max && c_min <= c_max){
            
            for(int c = c_min; c <= c_max; ++c){
                result.push_back(matrix[r_min][c]);
            }
            r_min++;
            
            for(int r = r_min; r <= r_max; ++r){
                result.push_back(matrix[r][c_max]);
            }
            c_max--;                
            
            if(!(r_min <= r_max && c_min <= c_max)) break;
            
            for(int c = c_max; c >= c_min; --c){
                result.push_back(matrix[r_max][c]);
            }
            r_max--;
            
            
            for(int r = r_max; r >= r_min; --r){
                result.push_back(matrix[r][c_min]);
            }
            c_min++;
            
        }
        return result;
    }
};