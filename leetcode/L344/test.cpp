
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
	public:
	string reverseString(string s) {
		std::reverse(s.begin(),s.end());
		return s;
	}
};


int main() 
{
	Solution s;
	string str = "12345";
	cout << s.reverseString(str) << endl;
    return 0;
}
