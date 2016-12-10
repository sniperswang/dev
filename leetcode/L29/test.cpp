
#include <iostream>
#include <vector>
#include <map>
#include <climits> 

using namespace std;

/*
class Solution {
public:
    int divide(int dividend, int divisor) {
 		if (divisor == 0)
		{
			return INT_MAX;
		}

		bool positive = false;
		if ( (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0) )
		{
			positive = true;
		}

		dividend = abs(dividend);
		divisor = abs(divisor);
	
		int quotient = 0;
		while ( (dividend -= divisor) >= 0 )
		{
			quotient++;
		}

		quotient = positive ? quotient: (0-quotient);
		return quotient;
    }
};
*/


class Solution {
public:
    int divide(int dividend, int divisor) {
        if ( dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }
        
        if ( divisor == 1)
        {
            return dividend;
        }
        
        long long a = ( dividend >= 0 ) ? dividend: -(long long)dividend;
        long long b = ( divisor >= 0 ) ? divisor: -(long long)divisor;

        long long result = 0;

        while (a >= b)
        {
            long long c = b;
			long long x = 1;
            for(int i = 0; a >= c; c<<=1 , i++ )
            {
                a -= c;
                result += (x << i);
            }
        }
        return ( (dividend ^ divisor) >> 31) ? -result : result;
	}

};
  
int main() 
{
	Solution s;
	cout << s.divide(INT_MIN, 2) << endl;
	cout << INT_MIN << endl;
	cout << INT_MAX << endl;
    return 0;
}
