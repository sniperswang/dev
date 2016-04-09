#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*

* Complete the function below.

*/

bool isSubStr(string &str1, string &str2) 
{
	return true;
}


bool isSubSequence(string str1, string str2)
{
	int j = 0; // For index of str1 (or subsequence

	// Traverse str2 and str1, and compare current character 
	// of str2 with first unmatched char of str1, if matched 
	// then move ahead in str1
	for (int i=0; i<str2.size() && j<str1.size(); i++)
	{
		if (str1[j] == str2[i])
			j++;
	}

	// If all characters of str1 were found in str2
	return (j==str1.size());
}

int longest_chain(vector < string > w) 
{
	int len = w.size();
	sort(w.begin(), w.end());
	int arr[50000][50000];
	return 0;
}


/*
int longest_chain(vector < string > w) 
{
	int len = w.size();
	sort(w.begin(), w.end());

	for(int i = len - 1; i >= 0; i --  )
	{
		int count = 1;
		cout << w[i] << endl;
		int strLen = w[i].size();
		for (int j = 0; j < strLen; j++)
		{
			string strClone = w[i];
			strClone.erase(strClone.begin()+j);
			//if ( longest_chain_matcher(strClone,i+1) ) 
			{
				count ++ ;
			}
		}
	}
	
	return 0;
}
*/

int main()
{
	vector <string> v_s;

	string s1 = "6";
	string s2 = "a";
	string s3 = "b";
	string s7 = "ba";
	string s5 = "bca";
	string s6 = "bda";
	string s4 = "bdca";

	v_s.push_back(s1);
	v_s.push_back(s2);
	v_s.push_back(s3);
	v_s.push_back(s4);
	v_s.push_back(s5);
	v_s.push_back(s6);
	v_s.push_back(s7);

	cout<< isSubSequence (s6,s4) << endl;
	return 0;
}
