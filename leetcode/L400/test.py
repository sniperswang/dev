"""
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.

"""

class Solution(object):
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        for digits in range(1,11):
            first = 10**(digits - 1)
            if ( n <= first*9*digits):
              return int(str( first + (n-1)/digits)[(n-1)%digits])
            else:
              n -= first*9*digits
        

s = Solution()
print s.findNthDigit(9)
"""
for i in range(10):
  print s.findNthDigit(10+i)
"""
