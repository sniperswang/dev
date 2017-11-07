
#include <iostream>
#include <vector>
#include <map>
#include <ctype.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
			
		string res = "";
		for(int i = S.size()-1; i>=0 ; i--)
		{
			if (S[i] == '-')
				continue;
			if (res.size() % (K+1) == K)
         {
            res += '-';
         }
			res += char(toupper(S[i]));
		} 
      std::reverse(res.begin(), res.end());
		return res;
    }
};
  
int main() 
{
	string ss = "D--2-4A0r7-4k";
	Solution s;
	cout << s.licenseKeyFormatting(ss,4) << endl;
    return 0;
}
