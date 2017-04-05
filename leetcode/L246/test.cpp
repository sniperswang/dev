
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:

    bool isMatch(char a, char b)
    {
        if ( a == b && ( (a == '1') || (a == '8') || (a == '0') ) )
		{
	        return true;
		}
        else if ( (a =='6' && b =='9') || (a == '9' && b == '6') ) 
            return true;
            
        return false;
    }

    bool isStrobogrammatic(string num) {
        int size = num.size();
        
        if (size == 0)
            return true;
            
        int i = 0;
        int j = size - 1;
        
        while (i <= j)
        {
            if (!isMatch(num[i], num[j]))
                return false;
                
            i++; 
            j--;
        }
        return true;
    }
};
 
int main() 
{

 	string num = "2";
	Solution s;
	cout << s.isStrobogrammatic(num) << endl;
    return 0;
}
