//
//  jump.h
//  leetCode
//
//  Created by Yao Wang on 2/18/14.
//
//

#ifndef leetCode_jump_h
#define leetCode_jump_h

// Jump Game II

class Solution {
public:
    int jump(int A[], int n) {
        
        if( n == 0 || n == 1) {
            return 0;
        }
        
        int start=0, end=0, max=0, count=0;
        
        while( end < n) {
            
            count++;
            
            for(int i = start; i <= end; i++) {
                if (A[i] +i >= n-1) {
                    return count;
                }
                
                if(A[i] +i > max) {
                    max = A[i] +i;
                }
            }
            
            start = end + 1;
            end   = max;
        }
        
        return 0;
    }
};

/*
 
 int A[] = {1,2,0,1,1};
 // int A[] = {2,3,1,1,4};
 Solution s;
 
 int min_step = s.jump(A, 5);
 
 cout << "min_step:" << min_step << endl;
 
 */

/* shit solution
class Solution {
public:
    int jump(int A[], int n) {
        
        if( n == 0 || n == 1) {
            return 1;
        }
        
        vector< vector <int> > path;
        vector< vector <int> > value;
        
        init_array(path, A, n);
        init_array(value, A, n);
        
        
        findMinStep(path,value,0,n-1,n);
        print_array(value);
        
        return value[0][n-1];
        
    }
    
private:
    
    int findMinStep(vector< vector <int> > &path, vector< vector <int> > &value, int start, int end, int n) {
        int minStep = n;
        
        if( path[start][end] == 1) {
            return 1;
        } else if ( value[start][end] != 0)  {
            return value[start][end];
        }
        
        for(int i = start+1; i < end; i++) {
            int local_step  = n;
            if(path[i][end] == 1){
                local_step = findMinStep(path, value, start, i, n) + 1;
            } else {
                local_step = findMinStep(path, value, start, i, n) + findMinStep(path, value, i, end, n) ;
            }
            
            if (local_step < minStep) {
                minStep = local_step;
            }
        }
        
        value[start][end] = minStep;
        return minStep;
    }
    
    void init_array(vector< vector <int> > &path, int A[], int n) {
        vector<int> row (n, 0);
        for(int i =  0; i < n; i++) {
            path.push_back(row);
        }
        
        for(int i = 0; i < n; i++) {
            int len = A[i];
            for(int j = 0; j < len; j++) {
                
                int x = i+j+1;
                if( x > n -1) {
                    break;
                }
                path[i][x] = 1;
                
            }
        }
        
    }
    
    void print_array(vector< vector <int> > &path) {
        
        unsigned long long len = path.size();
        
        for(int i =0; i < len; ++i) {
            for(int j = 0; j < len; ++j) {
                cout << " " << path[i][j];
            }
            cout << endl;
        }
    }
};
*/
/* better 2;
 class Solution {
 public:
 int jump(int A[], int n) {
 
 if( n == 0 || n == 1) {
 return 1;
 }
 
 int curr_min_step = n;;
 int most_close_point = n;
 
 for(int i = n -2; i > -1; i--) {
 int dis = n-1 -i;
 
 if (A[i] >= dis) {
 curr_min_step = 1;
 most_close_point = i;
 A[i] = -1;
 } else {
 dis = most_close_point - i;
 if( A[i] >= dis ) {
 int short_step = A[i] - dis;
 int availble_jump = 0;
 
 if( short_step + most_close_point > n -1) {
 short_step = n - 1 - most_close_point;
 }
 
 while(short_step > 0) {
 if(curr_min_step == 1) {
 break;
 }
 if( A[most_close_point+short_step] == -1) {
 availble_jump++;
 }
 short_step--;
 }
 curr_min_step = curr_min_step + 1 - availble_jump;
 most_close_point = i;
 }
 }
 }
 
 
 return curr_min_step;
 }
 };

 
 
 */


#endif
