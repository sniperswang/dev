
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
		string res ="/";
		vector<string> stack;
		string curStr = "";

		for (int index = 0;index < path.size(); index ++ )
		{
		 	switch (path[index])
			{
				case '/':
				{
					if ( curStr == ".." ) 
					{
						if (stack.size() != 0)
						{
							stack.pop_back();
						}
					} 
					else if(curStr != "" && curStr != ".")
					{
						stack.push_back(curStr);
					}
					curStr = "";
				}
				break;
				default:
				{
					curStr += path[index];
				}
				break;
			}
		}

		if ( curStr == ".." ) 
		{
			if (stack.size() != 0)
			{
				stack.pop_back();
			}
		} 
		else if(curStr != "" && curStr != ".")
		{
			stack.push_back(curStr);
		}

		for( int i = 0; i < stack.size(); i++)
		{
			if (i == stack.size() -1)
			{
				res = res + stack[i];
			}
			else 
			{
				res = res + stack[i] + "/";
			}
		}

		return res; 
    }
};
  
int main() 
{
	//string path = "/a/./b/../../c/";
	//string path = "/home//foo/";
//	string path = "/../";
	string path = "/home/";
	//string path = "/...";
	Solution s;
	cout << s.simplifyPath(path) << endl;
    return 0;
}

