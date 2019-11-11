#include<stdio.h>
#include<vector.h>

class Solution {
public:
    

    /* compare condition for stl sort. it compares the first
     and second element and based on the condition provided.
     if condition is false it swaps or else keeps the same order */
    static bool compare(vector<int>& a,vector<int>& b){    
        return (a.front() < b.front());
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(),compare);
        int length = intervals.size();
        vector<vector<int>>::iterator it; // iterator to the input vector
        vector<vector<int>> merged;
        

        
         for(it=intervals.begin();it < intervals.end();++it){  // iterator is a pointer pointed to the address of first element of the vector
            // if merge is empty or if last element of intervel vector inside merged is less than new iterator 
            //elements start number add a new interval element from the interval

            if (merged.empty() || (merged.back().back() < it->front()))                
                merged.push_back(*it);
            else
                merged.back().back() = max(merged.back().back(), it->back());
        }
        

        return merged;

    }
};