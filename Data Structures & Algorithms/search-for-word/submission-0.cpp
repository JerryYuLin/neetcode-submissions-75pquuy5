class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool result = false;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(wordSearch(board, word, 0, j, i)) return true;
            }
        }

        return false;
    }

    bool wordSearch(vector<vector<char>>& board, const string& word, int index, int x, int y) {
        if(index == word.size()) return false;

        if(word[index] == board[y][x]){
            if(index==word.size()-1) return true;

            char temp = board[y][x];
            board[y][x] = '#';

            if(x > 0 && wordSearch(board, word, index+1, x-1, y) || x < board[0].size()-1 && wordSearch(board, word, index+1, x+1, y) || y < board.size()-1 && wordSearch(board, word, index+1, x, y+1) || y > 0 && wordSearch(board, word, index+1, x, y-1)) {
                board[y][x] = temp; 
                return true;
            }     
            else {
                board[y][x] = temp;
            }       
        }

        return false;
    }
};