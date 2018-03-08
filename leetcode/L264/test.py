"""
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number, and n does not exceed 1690.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

"""

class Solution:
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
  
        if n < 0:
          return 0
        if n == 1:
          return 1

        array = [0]*n
        t1 = 0;
        t2 = 0;
        t3 = 0;
        array[0] = 1

        for i in xrange(1,n):
          array[i] = min(array[t1]*2, array[t2]*3, array[t3]*5)
          if array[i] == array[t1]*2:
              t1 +=1
          if array[i] ==  array[t2]*3:
              t2 +=1
          if array[i] == array[t3]*5:
              t3 +=1
        return array[n-1]



s = Solution()
print s.nthUglyNumber(10)

