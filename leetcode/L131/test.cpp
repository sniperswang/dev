
#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
	public:
	vector< vector<string> > partition(string s) {
		vector< vector<string> > res;
		vector<string> output;
		DFS(s,0,output,res);
		return res;
	}	

	void DFS(string& s, int start, vector<string> &output, vector< vector<string> > &res)
	{
		if (start == s.size())
		{
			res.push_back(output);
		}

		for(int i = start; i < s.size(); i ++)
		{
			if( isPalindrome(s,start,i) )
			{
				output.push_back(s.substr(start,i-start+1));
				DFS(s,i+1,output,res);
				output.pop_back();
			}
		}
	}

	bool isPalindrome(string&s, int start, int end)
	{
		while(start < end)
		{
			if (s[start] != s[end])
			{
				return false;
			}
			start ++;
			end --;
		}
		return true;
	}
};

  
int main() 
{
	string str = "aabaa";
	Solution s;
	vector < vector <string> > res = s.partition(str);

	for (int i = 0; i < res.size(); i++)
	{
		for(int j =0; j < res[i].size(); j++)
		{
			cout << res[i][j] << ",";
		}
		cout << endl;
	}
    return 0;
}
