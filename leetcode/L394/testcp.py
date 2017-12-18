class Solution:
	def decodeString(self, s):
		"""
		:type s: str
		:rtype: str
		"""
		stack = [];
		stack.append(["",1])
		num = ""
		for c in s:
			if c.isdigit():
				num += c;
			elif c == '[':
				stack.append(["",int(num)])
				num = ""
			elif c == "]":
				st,k = stack.pop()
				stack[-1][0] += st*k
			else:
				stack[-1][0] += c

		return stack[0][0]


		

s = Solution()
print s.decodeString("3[a2[c]]")
print s.decodeString("2[abc]3[cd]ef")
print s.decodeString("100[leetcode]")
