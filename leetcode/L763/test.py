"""
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

"""


class Solution(object):
	def partitionLabels(self, S):
		"""
		:type S: str
		:rtype: List[int]
		"""
		index  = 0
		sIndex = {}
		for s in S:
			sIndex[s] = index
			index += 1
		res = []

		imax = sIndex[S[0]]
		index = 1
		start = 0
		for s in S[1:]:
			if imax < index:
				res.append(index - start)
				start = index
			imax = max(imax, sIndex[s])
			index +=1
		res.append(sIndex[S[-1]] - start + 1)
		return res
				
			


s = Solution() 
#arr = "ababcbacadefegdehijhklij"
arr = "131124001156"
print s.partitionLabels(arr)

