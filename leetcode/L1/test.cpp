
#include <iostream>
#include <vector>

using namespace std;
				
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) 
    {
    // Start t
    // DO NOT write int main() function
        vector<int> res;
        for (int i=0; i < numbers.size();i++)
        {
            for(int j=i+1; j < numbers.size();j++)
            {
                if((numbers[i]+numbers[j]) == target)
                {
                    res.push_back(i+1);
                    res.push_back(j+1);
                }
            }
        }
        return res;
    }
};

int main() 
{
    return 0;
}
