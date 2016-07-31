
#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>

using namespace std;


long stringSimilarity(string value)
{
	// build fast refermap
	int len = value.size();
	vector<int> row(len,0);
	vector<vector<int> >referMap(len,row);

	for(int i = 0; i < len; i ++)
	{
		for (int j = 0; j < len; j++ )
		{
			if ( i > 0 && j > 0)
			{
				if (value[i] == value[j])
				{
					if (referMap[i-1][j-1]  > 0 )
						referMap[i][j] = referMap[i-1][j-1] + 1;
					else 
						referMap[i][j] = referMap[i-1][j-1];
				}
				else 
				{
					if (referMap[i-1][j-1] >= 0)
					{
						referMap[i][j] = referMap[i-1][j-1]*(-1);
					}
					else
					{
						referMap[i][j] = referMap[i-1][j-1];
					}
				}
			}
			else
			{
				if (value[i] == value[j])
				{
					referMap[i][j] = 1;
				}
				else
				{
					referMap[i][j] = 0;
				}
			}
			cout << "i:" << i << " j:" << j << " res:" << referMap[i][j] << endl; ;
		}
	}
	
	int res = 0;
	for (int i = 0; i< len; i++)
	{
		res += abs(referMap[len-1][len-i-1]);
		cout << referMap[len-1][len-i-1] << " ";
	}
	cout << endl;
	return res;
}

int main() 
{
	cout << stringSimilarity("cccccccccccccccccccccccccccaaaaaabbbbbbbbbb") << endl;
    return 0;
}
