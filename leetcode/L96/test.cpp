
#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    int numTrees(int n) {

		int* res = new int[n+1];
		res[0] = 1;
		res[1] = 1;
		
		for (int i = 2; i < n+1; i++)
		{
			int sum = 0;
			for (int j = 0; j < i; j++)
			{
				sum += res[j]*res[i-j-1];
			}
			res[i] = sum;
		}
	
		int val = res[n];
		delete [] res;	
 		return val;       
    }
};
  
int main() 
{
	Solution s;
	cout << s.numTrees(3) << endl;
    return 0;
}
