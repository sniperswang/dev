"""

Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.

Input: arr = [1,0,2,3,4]
Output: 4
Explanation:
We can split into two chunks, such as [1, 0], [2, 3, 4].
However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.


"""
	
class Solution(object):
	def maxChunksToSorted(self, arr):
		"""
		:type arr: List[int]
		:rtype: int
		"""
		ct = 0
		imax = 0;
		for i in arr:
			imax = max(imax,i)
			if (imax == i):
				ct += 1
		return ct

s = Solution()
#arr = [1,0,2,3,4]
arr = [4,3,2,1,0]
print s.maxChunksToSorted(arr)

