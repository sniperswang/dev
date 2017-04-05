#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>


using namespace std;

class Solution {
public:
    
    vector<int> findSubstring(string s, vector<string>& words) {
		vector <int> res;
		std::unordered_map<std::string,int> mymap;
		int totalLen = 0;
		int strLen = 0;

		if (words.size() != 0)
		{
			totalLen = words.size()*words[0].size();
			strLen = words[0].size();
		}
		else 
		{
			return res;
		}
			
		for (int i = 0; i < words.size(); i++)
		{
			mymap[words[i]]++;
		}

		if (s.size() < totalLen)
		{
			return res;
		}

		for (int i = 0; i < s.size(); i++)
		{
			int currLen = 0;
			int pos = 0;
			std::unordered_map<std::string,int> innermap;

			if (s.size() - i < totalLen)
				break;
			
			while(true)
			{
				string subString = s.substr(i+pos,strLen);
				if ( mymap.count (subString) != 0)
				{
					innermap[subString] ++;
					if ( innermap[subString] > mymap[subString] ) 
					{
						break;
					}
					currLen += strLen;
			
					if (currLen == totalLen) 
					{
						res.push_back(i);
						break;
					}
					pos += strLen;
				}
				else 
				{
					break;
				}
			}
		}
		
      	return res;
    }

};
  
int main() 
{
	//string s = "barfoothefoobarman";
	string s = "barfoofoobarthefoobarman";
	vector<string> words;
	words.push_back("foo");
	words.push_back("bar");
	words.push_back("the");

	Solution ss;
	vector<int> res;
	res = ss.findSubstring(s, words);

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}
		
    return 0;
}
