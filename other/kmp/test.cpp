
#include <iostream>
#include <vector>
#include <map>

using namespace std;
  

class Solution 
{
public:
	int KMP(const char* text, int text_len, const char* pattern, int pattern_len)
	{
		int* next = new int[pattern_len];
		calcNext(pattern, next, pattern_len);

		int i = 0;
		int j = 0;

		while ( i < text_len && j < pattern_len)
		{
			if (pattern[j] == text[i])
			{
				i++;
				j++;
			}
			else if ( j == 0)
			{
				i++;
			}
			else 
			{
				j = next[j];
			}

			if ( j == pattern_len)
			{
				return i - pattern_len;
			}
		}
		return -1;
	}

	void calcNext(const char* pattern, int* next, int len)
	{
		next[0] = next[1] = 0;

		int j = 0;

		for (int i = 1; i < len; i ++ )
		{
			while ( j > 0 && pattern[i] != pattern[j])
			{
				j = next[j];
			}

			if (pattern[i] == pattern[j])
				j++;

			next[i+1] = j;
		}
			
	}

	/*
	void calcNext(const char* pattern, int* next, int len)
	{
		next[0] = next[i]
		next[0] = 0;
		for (int i = 1; i < len; i++)
		{
			int h = next[i-1];


			while (true)
			{
				if ( pattern[i]  == pattern[h] )
				{  
					next[i] = h + 1;
					break;
				} 
				else if ( h == 0 )
				{ 
					next[i] = 0;
					break;
				}
				else 
				{
					h = next[h-1];
				}
			}	
		}
			
		for (int j = len -1; j > 0; j--)
		{
			next[j] = next[j -1];
		}
	}
	*/
};

int main() 
{

	// test 1
	//string pattern = "abcaa";
	//string text = "abcabcaabcdaab";
	// 3


	// test 2
	//string pattern = "aaaab";
	//string text = "abcabcaaaabcdaab";
	// 6

	// test 3
	string pattern = "abcabcda";
	string text = "abcabcabcabcdaab";
	// 6
	int next[pattern.size()+1]; 

	Solution s;
	s.calcNext(pattern.c_str(), next, pattern.size());

	for (int i = 0; i < pattern.size(); i++)
	{
		cout << next[i] << "," ;
	}
	cout << endl;


	cout << s.KMP(text.c_str(),text.size(), pattern.c_str(), pattern.size()) << endl;
	
    return 0;
}
