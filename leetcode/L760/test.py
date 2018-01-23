class Solution:
	def nextClosestTime(self, time):
		"""
		:type time: str
		:rtype: str
		"""


class Solution(object):
	def anagramMappings(self, A, B):
		"""
		:type A: List[int]
		:type B: List[int]
		:rtype: List[int]
		"""
		res = []
		indexB = {}
		index = 0
		for i in B:
			indexB[i] = index
			index += 1

		for i in A:
			res.append(indexB[i])
		return res
			


s = Solution()
time = ""
A = [12, 28, 46, 32, 50]
B = [50, 12, 32, 46, 28]
print s.anagramMappings(A,B)

