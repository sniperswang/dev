
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
	public:
	bool isPowerOfTwo(int n) {
		while ( ((n&1) == 0) && (n > 1))
		{
			n>>=1;
		}
		return (n==1);
	}
};

int main() 
{
	unsigned int i = 5;
	Solution s;
	cout << s.isPowerOfTwo(5) << endl;
    return 0;
}
