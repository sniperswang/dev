
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
	public:
	void GetNext(string p,vector<int> &next)  
	{
		int k = -1;
		int j = 0;
		next[0] = -1;
		int pLen = p.size();

		while(j < pLen)
		{
			if (k == -1 || p[j] == p[k])
			{
				k++;
				j++;
				if (p[j] != p[k])
					next[j] = k;
				else
					next[j] = next[k];
			}
			else 
			{
				k = next[k];
			}
		}
	}

	int strStr(string haystack, string needle) 
	{
		vector<int> next;
		int i = 0;  
		int j = 0;  
		int sLen = haystack.size();  
		int pLen = needle.size();  
		if (sLen < pLen)
			return -1;
		if ( sLen == 0  && pLen == 0)
			return 0;
		if (pLen > 0)
		{
			next.reserve(needle.size()+1);
			GetNext(needle,next);
		}
		while (i < sLen && j < pLen)  
		{  
			if (j == -1 || haystack[i] == needle[j])  
			{  
				i++;  
				j++;  
			}  
			else  
			{  
				j = next[j];  
			}  
		} 
		if (j == pLen)  
			return i - j;  
		else  
			return -1; 
	}
};



int main() 
{
	string s = "mississippi";
	string p = "issipi";
	Solution ss;
	cout << ss.strStr(s,p) << endl;
    return 0;
}
