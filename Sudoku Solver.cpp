class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>> board){
        for(int i =0;i<board.size();i++){
            for(int j =0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char c = '1' ; c<='9';c++){
                        if(check(board , i , j , c)){
                            board[i][j]=c;
                            if(solve(board))return true;
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
                
            }
        }
        return true ;
    }
    bool check(vector<vector<char>> board, int i , int j , char c ){
        board[i][j]=c;
        
        int m1[9][9]={0},m2[9][9]={0},m3[9][9]={0};
        for(int i =0;i<board.size();i++){
            for(int j =0;j<board[0].size();j++){
                if(board[i][j]!='.'){
                    int n = board[i][j]-'0' -1;
                    int k = (i/3)*3 + (j/3);
                    if(m1[n][i] || m2[n][j] || m3[n][k])return false;
                    m1[n][i] = m2[n][j] = m3[n][k] =1;
                }
            }
        }
        return true ;
    }
};
