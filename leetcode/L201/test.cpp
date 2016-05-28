
#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
using namespace std;


class Solution {
	public:
	int rangeBitwiseAnd(int m, int n) {
		int res = INT_MAX;
		while( (m&res) != (n&res) )
		{
			res = res<<1;
		}
		return res&n;
	}
};


int main() 
{
	Solution s;
	cout << s.rangeBitwiseAnd(5,7) << endl;
    return 0;
}
