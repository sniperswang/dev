class Solution(object):
    def twoSum(self, nums, target):
		"""
		:type nums: List[int]
		:type target: int
		:rtype: List[int]
		"""
		res =[]
		for i, v1 in enumerate(nums):
			for j, v2 in enumerate(nums[i+1:]):
				if (v1 + v2) == target:
					res.append(i)
					res.append(j+i+1)
					break

		return res

def main():
	s = Solution()
	int_list = [8, 23, 45, 12, 78]
	res = s.twoSum(int_list,35)
	print res

if __name__ == "__main__": main()
