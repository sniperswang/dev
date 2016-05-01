
#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
	int hammingWeight(uint32_t n) {
		uint32_t one = 1;
		int count = 0;
		for (int i = 0; i < 32; i++ ) 
		{
			if ( (n&one) != 0 )
			{
				count++;
			}
			one=one<<1;
		}
		return count;
	}
};

int main() 
{
	Solution s;
	cout << s.hammingWeight(5) << endl;
    return 0;
}
