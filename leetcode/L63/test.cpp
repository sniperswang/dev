
#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector< vector<int> >& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int a[m][n];

        int block_m = 0;
        int block_n = 0;
        bool isMBlocked = false;
        bool isNBlocked = false;
        for (int i = 0; i< m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    a[i][j] = 0;
                    if (i == 0)
                    {
                        isMBlocked = true;
                    }

                    if (j == 0)
                    {
                        isNBlocked = true;
                    }
                }
                else if ( i == 0 || j == 0)
                {
                    if ( i == 0 && isMBlocked)
                    {
                        a[i][j] = 0;
                    }
                    else if ( j == 0 && isNBlocked)
                    {
                        a[i][j] = 0;
                    }
                    else
                    {
                        a[i][j] = 1;
                    }
                }
                else
                {
                    a[i][j] = a[i-1][j] + a[i][j-1];
                }
            }
        }
        return a[m-1][n-1];
    }
};
  
int main() 
{
    return 0;
}
