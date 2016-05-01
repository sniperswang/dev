
#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
	public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t one = 1;
		uint32_t num = 0;
		for ( int i = 0; i < 32; i++) 
		{
			num = num << 1;
			if( (n&one) != 0)
			{
				num = num|1; 
			}
			one = one << 1;
		}
		return num;
	}
};

int main() 
{
	Solution s;
	cout << s.reverseBits(43261596) << endl;
    return 0;
}
