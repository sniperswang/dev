"""
 Given an array of n integers where n > 1, nums, 
 return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

 Solve it without division and in O(n).

 For example, given [1,2,3,4], return [24,12,8,6].

 Follow up:
 Could you solve it with constant space complexity? 
 (Note: The output array does not count as extra space for the purpose of space complexity analysis.)


"""

from operator import mul

'''
class Solution(object):
  def productExceptSelf(self, nums):
    """
    :type nums: List[int]
    :rtype: List[int]
    """
    res = []
    if any(n == 0 for n in nums):
      res = [0]*len(nums)
      return res

    #head
    tmp = reduce(mul, nums[1:])
    res.append(tmp)

    for i in range(1, len(nums)-1):
      tmp = reduce(mul, nums[:i]) * reduce(mul, nums[i+1:])
      res.append(tmp)


    #end
    tmp = reduce(mul, nums[:len(nums)-1])
    res.append(tmp)

    return res
'''

class Solution:
    # @param {integer[]} nums
    # @return {integer[]}
    def productExceptSelf(self, nums):
        p = 1
        n = len(nums)
        output = []
        for i in range(0,n):
            output.append(p)
            p = p * nums[i]
        p = 1
        for i in range(n-1,-1,-1):
            output[i] = output[i] * p
            p = p * nums[i]
        return output

s = Solution()
array = [1,2,3,4]
print s.productExceptSelf(array)
        
