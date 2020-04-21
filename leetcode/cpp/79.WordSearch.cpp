class Solution {
public:
    bool checkNextLetter(string& word,
                         vector<vector<char>>& board,
                         vector<vector<bool>>& visited,
                         int r,
                         int c,
                         int wordIndex){
        
        if(wordIndex < word.size() - 1){
        if(r-1 >= 0 && !visited[r - 1][c] && board[r - 1][c] == word[wordIndex + 1]){
            visited[r - 1][c] = true;
            if(!checkNextLetter(word, board, visited, r - 1, c, wordIndex + 1)) visited[r - 1][c] = false;
            else return true;
        }
        if(c - 1 >= 0 && !visited[r][c - 1] && board[r][c - 1] == word[wordIndex + 1]){
            visited[r][c - 1] = true;

            if(!checkNextLetter(word, board, visited, r, c - 1, wordIndex + 1)) visited[r][c - 1] = false;
            else return true;
        }
        if(r + 1 < board.size() && !visited[r + 1][c] && board[r + 1][c] == word[wordIndex + 1]){
            visited[r + 1][c] = true;

            if(!checkNextLetter(word, board, visited, r + 1, c, wordIndex + 1)) visited[r + 1][c] = false;
            else return true;
        }
        if(c + 1 < board[0].size() && !visited[r][c + 1] && board[r][c + 1] == word[wordIndex + 1]){
            visited[r][c + 1] = true;

            if(!checkNextLetter(word, board, visited, r, c + 1, wordIndex + 1)) visited[r][c + 1] = false;
            else return true;
        }
        }
        else return true;
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0) return false;
        int rows = board.size();
        int columns = board[0].size();
        vector<vector<bool>> visitedChar(board.size(), vector<bool>(board[0].size(), false));
        
        for(int r = 0; r < rows; ++r){
            for(int c = 0; c < columns; ++c){
                if(board[r][c] == word[0]){
                    visitedChar[r][c] = true;
                    if(checkNextLetter(word, board, visitedChar, r, c, 0)) return true;
                    else visitedChar[r][c] = false;
                }
            }
        }
        
        return false;
    }
};