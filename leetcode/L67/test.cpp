
#include <iostream>
#include <vector>
#include <map>

using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string res ="";
        int aIndex = a.size()-1;
        int bIndex = b.size()-1;

        char chA;
        char chB;
        char addV = 0;
        char curr;
        while(true)
        {
            if (aIndex < 0 && bIndex < 0)
            {
                if ( addV == 1)
                {
                    res += char(addV + '0');
                }
                break;
            }

            (aIndex >= 0) ? chA = a[aIndex] - '0' : chA = 0;
            (bIndex >= 0) ? chB = b[bIndex] - '0' : chB = 0;
            curr = chA + chB + addV;
            res += char(curr % 2 + '0');
            addV = curr / 2;
            aIndex --;
            bIndex --;
        }
        std::reverse(res.begin(),res.end());
        return res;
    }
};
  
int main() 
{
    return 0;
}
