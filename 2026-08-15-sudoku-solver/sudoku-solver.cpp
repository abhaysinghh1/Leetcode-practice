class Solution {
    bool isValid(vector<vector<char>>& board,int row,int col, char ch){
        for(int i=0;i<9;i++){
            if(board[i][col]==ch &&(i!=row)) return false;
            if(board[row][i]==ch &&(i!=col)) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch &&(i!=row ||i!=col)) return false;

        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
         for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
            
                    for(char c='1';c<='9';c++){
                        if(isValid(board,i,j,c)){
                            board[i][j]=c;
                            if(solve(board)) return true;
                        
                        else{
                            board[i][j]='.';
                        }
                        }
                    }
                    return false;
                }
            }
            
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {

       solve(board);
        
    }
};