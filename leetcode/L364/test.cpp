
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:


    void depthSumLevel(vector<NestedInteger>& nestedList, vector< vector<int> >& copy, int index)
    {
        vector<NestedInteger>::iterator iter =  nestedList.begin();
        for (;iter != nestedList.end();iter++)
        {
            
            if (iter->isInteger() == true) 
            {
                if (index > copy.size() )
                {
                    vector<int> v;
                    v.push_back(iter->getInteger());
                    copy.push_back(v);
                }
                else 
                {
                    copy[index-1].push_back(iter->getInteger());
                }
            }
            else 
            {
                int missingLevel = index + 1 - copy.size();
                while (missingLevel - 1 > 0)
                {
                    vector<int> v;
                    copy.push_back(v);
                    missingLevel--;
                }
                depthSumLevel(iter->getList(), copy, index+1);
            }
        }
    }
    
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector< vector<int> > copy;
        depthSumLevel(nestedList, copy, 1);
        
        int level = 1;
        int sum = 0;
        if (copy.size() == 0)
        {
            return 0;
        }
        
        for (int i = copy.size() -1; i >=0; i--)
        {
            int subSum = 0;
            for (int j = 0; j < copy[i].size(); j++)
            {
                subSum += copy[i][j];
            }
            sum += level*subSum;
            level++;
        }
        return sum;
    }
};
  
int main() 
{
    return 0;
}
