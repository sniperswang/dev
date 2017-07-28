
#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    vector<int> getRow(int rowIndex) {

		vector <int> res;
	
		vector < vector <int> > array;
		for (int i = 0; i < rowIndex + 1 ; i++)
		{
			res.clear();
			for (int j = 0; j < i+1; j++)
			{
				if (j == 0 || j == i )
				{
					res.push_back(1);
				}
				else 
				{
					res.push_back(array[i-1][j-1] + array[i-1][j]);
				}
			}
			array.push_back(res);
		}
        return res;
    }
};
  
int main() 
{
	vector <int> res;
	Solution s;
	res = s.getRow(3);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << ",";
	}
	cout << endl;
    return 0;
}
