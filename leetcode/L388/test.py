class Solution(object):
	def lengthLongestPath(self, input):
		"""
		:type input: str
		:rtype: int
		"""
		levelLen = {0:0}
		maxLen = 0
		for line in input.splitlines():
			name = line.lstrip('\t')
			level = len(line) - len(name)
			if "." in name: 
				maxLen = max(levelLen[level] + len(name), maxLen)
			else:
				levelLen[level+1] = levelLen[level] + len(name) + 1

		return maxLen
s = Solution()
input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
print s.lengthLongestPath(input)



		
        
