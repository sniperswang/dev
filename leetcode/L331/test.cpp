
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
	public:
	bool isValidSerialization(string preorder) {
		int len = preorder.size();
		if (preorder[0] == '#' && len == 1)
		{
			return true;
		}

		vector<string> checker;
		for ( int i = 0; i < len; i++)
		{
			if(preorder[i] == ',')
			{
				continue;
			}

			string eStr="";
			while(preorder[i] != ',' && i < len)
			{
				eStr = eStr + preorder[i];
				i++; 
			}
			checker.push_back(eStr);
			int currentSz = checker.size(); 
			while ( currentSz > 2 ) 
			{
				if( checker[currentSz-1] == "#" && checker[currentSz-2] == "#" &&  checker[currentSz-3] != "#")
				{
					checker.pop_back();
					checker.pop_back();
					checker.pop_back();
					checker.push_back("#");
					currentSz = checker.size();
				}
				else 
				{
					currentSz = checker.size();
					break;
				}
			}
		}
		if ( checker.size() == 1 && checker[0] == "#")
		{
			return true;
		}

		return false;

	}
};


int main() 
{
	//string str = "9,#,82,#,#";

	string str = "9,3,4,#,#,1,#,#,2,#,6,#,#";
	Solution s;
	cout << s.isValidSerialization(str) << endl;
    return 0;
}
