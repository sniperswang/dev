
#include <iostream>
#include <vector>
#include <map>

using namespace std;
class Solution {
public:
    bool isValidSudoku(vector< vector<char> >& board) {
        int xLen = board.size();
        int yLen = board[0].size();

        for (int i =0; i < xLen; i++)
        {
            vector<int> myXMap(yLen, 0);
            vector<int> myYMap(xLen, 0);

            for (int j = 0; j < yLen; j++)
            {
                if(board[i][j] != '.')
                {
                    int val = board[i][j] - '0' - 1;
                    if ( myXMap[val] == 0)
                    {
                        myXMap[val] = 1;
                    }
                    else
                    {
                        return false;
                    }
                }
                
                if(board[j][i] != '.')
                {
                    int val = board[j][i] - '0' - 1;
                    if ( myYMap[val] == 0)
                    {
                        myYMap[val] = 1;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        int row[9];
        for(int i =0; i< 9; i+=3)  
        {  
            for(int j =0; j<9; j+=3)  
            {  
                memset(row, 0, 9*sizeof(int));  
                for(int m=0; m<3; m++)  
                {  
                    for(int n =0; n<3; n++)  
                    {  
                        if(board[m+i][n+j] == '.')  
                            continue;  
                        if(row[board[m+i][n+j]-49] ==1)  
                            return false;  
                        row[board[m+i][n+j]-49]++;  
                    }  
                }  
            }  
        }  
        return true;
    }
};

int main() 
{
return 0;
}
