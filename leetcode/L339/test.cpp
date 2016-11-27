
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:

    int depthSumLevel(vector<NestedInteger>& nestedList, int level)
    {
        int sum = 0;
        vector<NestedInteger>::iterator iter =  nestedList.begin();
        for (;iter != nestedList.end();iter++)
        {
            sum += (iter->isInteger() == true) ? level*iter->getInteger():depthSumLevel(iter->getList(),level+1);
        }
        return sum;
    }
    
    int depthSum(vector<NestedInteger>& nestedList) {
       return depthSumLevel(nestedList, 1);
    }
}; 

  
int main() 
{
    return 0;
}
