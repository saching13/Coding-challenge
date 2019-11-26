



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if (matrix.empty())
            return false;
        
        int rows = matrix.size();
        int columns = matrix[0].size();
        int row = 0;
        int column = columns-1;
        
        while(row <rows and column >= 0){
            if (matrix[row][column] == target)
                return true;
            if(target > matrix[row][column])
               row++;
            else
               column--;
            //cout <<row<<column<<endl;
        }
        
        return false;
        
        
    }
    

    
};

// Method 2: Not optimized
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
//         for(int i=0;i<matrix.size();i++){
            
//             if(binary_search(matrix[i], target)==true)
//                 return true;
//         }
        
//         return false;
        
//     }
    
//     bool binary_search(vector<int>& row, int target){
//         int lower_index = 0;
//         int max_index = row.size()-1;
//         int mid = (lower_index+max_index)/2;
        
//         while(lower_index <= max_index){
//             //cout << row[mid] <<"mid_index:"<<mid <<endl;
//             if (row[mid] == target)
//                 return true;
//             else if (target > row[mid])
//                 lower_index = mid+1;
//             else 
//                 max_index = mid-1;
            
//             //mid = 1+((lower_index+max_index-1)/2);
//             mid = ceil(float((lower_index+max_index))/2);
            
//         }
        
//         return false;
        
        
//     }
    
// };