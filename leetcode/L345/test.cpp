
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


class Solution {
	public:
	string reverseVowels(string s) {
		set<char> Vowels;
		Vowels.insert('a');
		Vowels.insert('e');
		Vowels.insert('i');
		Vowels.insert('o');
		Vowels.insert('u');
		Vowels.insert('A');
		Vowels.insert('E');
		Vowels.insert('I');
		Vowels.insert('O');
		Vowels.insert('U');

		vector<int> index;
		int strSz = s.size();
		for ( int i = 0; i < strSz; i++) 
		{
			if ( Vowels.find(s[i]) != Vowels.end())
			{
				index.push_back(i);
			}
		}

		int i = 0;
		int j = index.size() - 1;
		while(true)
		{
			char temp;
			if( i >= j)
			{
				break;
			}
			temp = s[index[i]];
			s[index[i]] = s[index[j]];
			s[index[j]] = temp;
			i++;
			j--;
		}
		return s;
	}
};

int main() 
{
	string str = "leetcode";
	Solution s;
	cout << s.reverseVowels(str) << endl;
    return 0;
}
