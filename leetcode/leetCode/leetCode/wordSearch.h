//
//  wordSearch.h
//  leetCode
//
//  Created by Yao Wang on 9/4/13.
//
//

#ifndef leetCode_wordSearch_h
#define leetCode_wordSearch_h

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int x_len = board[0].size();
        int y_len = board.size();
        
        if( (x_len * y_len) < word.size() ){
            return false;
        }
        
        for(int j = 0; j < y_len; j++) {
            for(int i = 0; i < x_len; i++){
                if( searchHelper(board, i, j, word, 0, 0)){
                //    cout << "start from : j :" << j << " i: " << i << endl;
                    return true;
                }
            }
        }
        
        return false;
        
        
    }
    
    bool searchHelper(vector<vector<char> > &board, int i, int j, string word, int pos, int where) {
        static int x_len = board[0].size();
        static int y_len = board.size();
        static int word_len = word.size();
        
        if(pos == word_len) {
            return true;
        }
        
        if(i < 0 || j < 0) {
            return false;
        }
        
        if( i >= x_len || j >= y_len ) {
            return false;
        }
        
        if(board[j][i] == word[pos]) {
            if(pos == word_len - 1){ // completed all the match
               // cout << "last last: j :" << j << " i: " << i << " pos: " << pos << endl;
                return true;
            }else { // partical match, keep searching
                if ( where !=2 && searchHelper(board, i - 1, j, word, (pos+1), 1) ){ //search left
                    //cout << "last from : j :" << j << " i: " << i << " pos: " << pos << endl;
                    return true;
                }else if ( where != 1  && searchHelper(board, i + 1, j, word, (pos+1), 2) ) { // search right
                  //  cout << "last from : j :" << j << " i: " << i << " pos: " << pos << endl;
                    return true;
                } else if ( where != 4 && searchHelper(board, i, j - 1, word, (pos+1), 3) ) { // search up
                 //   cout << "last from : j :" << j << " i: " << i << " pos: " << pos << endl;
                    return true;
                } else if ( where != 3 && searchHelper(board, i, j + 1, word, (pos+1), 4) ) { // search down
                  //  cout << "last from : j :" << j << " i: " << i << " pos: " << pos << endl;
                    return true;
                }
            } // partical match, keep searching
        } // if(array[y][x] == word[pos])
        return false;
    }
    
};

/*
 
 
 [
 ["ABCE"],
 ["SFCS"],
 ["ADEE"]
 ]
 word = "ABCCED", -> returns true,
 word = "SEE", -> returns true,
 word = "ABCB", -> returns false.
 
 // char x1[] = "ABCE";
 // char x2[] = "SFCS";
 // char x3[] = "ADEE";
 char x1[] = "a";
 vector<char> v1(x1, x1 + 1);
 //   vector<char> v2(x2, x2 + 4);
 //    vector<char> v3(x3, x3 + 4);
 
 vector< vector<char> > matrix;
 matrix.push_back(v1);
 // matrix.push_back(v2);
 //   matrix.push_back(v3);
 
 // string str = "ABCCED";
 // string str = "SEE";
 //  string str = "ABCB";
 string str = "ab";
 Solution s;
 bool res = s.exist(matrix,str);
 
 cout << " res : " << res << endl;



 */

#endif
