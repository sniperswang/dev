
#include <iostream>
#include <vector>
#include <map>
#include <math.h>  

using namespace std;

vector < int > collatz(int B, int k)
{
	vector <int> res;
	map<int,int> referMap;
	int filter = pow(2,k); 

	for (int i = 1; i < B + 1; i++)
	{
		int num = i;
		int step = 0;
		while( true)
		{
			// got the number;
			if (num == 1)
			{
				referMap[i] = step;
				res.push_back(i);
				break;
			}
			else 
			{
				if (num % 2 == 0)
				{
					num = num / 2;
				}
				else 
				{
					num = num*3 + 1;	
				}
				step ++;
				// not able to compelte in step k
				if ( num > filter || step > k)
				{
					// mark refence map value failed; 
					referMap[num] = k + 1;
					break;
				}
				else 
				{
					if (referMap.find(num) != referMap.end() )
					{
						int total_step = step + referMap[num];
						referMap[i] = total_step;
						// meet the rules 
						if (total_step <= k)
						{
							res.push_back(i);
							break;
						}
					}
				}
			}
		}
	}
	return res;
}

int main() 
{
	vector<int> res;
	res = collatz(16,7);
	int len = res.size();
	for (int i = 0; i < len; i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
    return 0;
}
