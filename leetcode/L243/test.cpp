
#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
		int len = words.size();
        int distance = words.size();
        if (word1 == word2)
        {
            return 0;
        }
        
        int aIndex = -1;
        int bIndex = -1;
        
        for (int i = 0; i < len; i++)
        {
            if(words[i] == word1)
            {
                aIndex = i;
            }
            else if (words[i] == word2)
            {
                bIndex = i;
            }
            
            if ( (words[i] == word1 || words[i] == word2 ) && (aIndex != -1) && (bIndex != -1) )
            {
                distance = (distance > abs(aIndex - bIndex) ) ?  abs(aIndex - bIndex) : distance;
            }
            
        }
        return distance;

    }
};
  
int main() 
{
    return 0;
}
