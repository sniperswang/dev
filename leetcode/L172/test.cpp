
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
  
		int numOfFive = 0;
		int x = 5;

		while ( n >= x ) 
		{
			numOfFive += n / x;
			x *= 5;
		}

		return  numOfFive;
    }
};
  
int main() 
{

	Solution s;
	cout << s.trailingZeroes(25) << endl;
    return 0;
}
