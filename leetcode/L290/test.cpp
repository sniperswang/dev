
#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
	
		stringstream ss(str);	
		string tok;	
		int index = 0;
		int len = pattern.size();
		map<char,string> cstrMap;
		map<string,char> strcMap;
		while(getline(ss, tok, ' ')) {
			if( index >= len)
			{
				return false;
			}
			cout << tok << endl;
			if ( cstrMap.find(pattern[index]) == cstrMap.end())
			{
				cstrMap[pattern[index]] = tok;
			}
			else if ( cstrMap[pattern[index]] != tok )
			{
				return false;
			}
			
			if( strcMap.find(tok) == strcMap.end())
			{
				strcMap[tok] = pattern[index];
			}
			else if ( strcMap[tok] != pattern[index] )
			{
				return false;
			}
			index++;
		}
		if(index != len ) 
		{
			return false;
		}
		/*
		istringstream iss(str);

		while(iss)
		{
			string sub;
			iss >> sub;
			cout << "Substring: " << sub << endl;
		} 
		*/
		return true;
	}
};


int main() 
{
	Solution s;
	cout << s.wordPattern("abba","abcd") << endl;
    return 0;
}
