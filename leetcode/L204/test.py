"""
Description:

Count the number of prime numbers less than a non-negative number, n.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

"""


class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """ 
        if  n <= 2:
          return 0
        res = [True] * n
        res[0] = False
        res[1] = False

        for i in xrange(2,n):
          if res[i] == True:
            for j in xrange(2, (n-1)//i + 1):
              res[i*j] = False
              print i, j
        return sum(res)

			


s = Solution()
print s.countPrimes(10)


