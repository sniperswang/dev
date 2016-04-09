#include<iostream>
#include<string>
#include<vector>

using namespace std;


int friendCircles(vector < string > friends) 
{
	int count = friends.size();
	int arrLen = friends.size();
	for ( int i = 0; i < arrLen; i ++ ) 
	{
		for (int j = i+1; j < arrLen; j++)
		{
			if (friends[i][j] == 'Y') 
			{
				count--;
				continue;
			}
		}
	}
	return count;
}

int main()
{
	vector <string> v_s;
/*
	string s1="YYNN";
	string s2="YYYN";
	string s3="NYYN";
	string s4="NNNY";
*/
/*
	string s1="YNNNN";
	string s2="NYNNN";
	string s3="NNYNN";
	string s4="NNNYN";
	string s5="NNNNY";
*/
	string s1="YNNN";
	string s2="NYYN";
	string s3="NYYN";
	string s4="NNNY";

	v_s.push_back(s1);
	v_s.push_back(s2);
	v_s.push_back(s3);
	v_s.push_back(s4);

	int count = friendCircles(v_s);
	cout << count << endl;

	return 0;
}
