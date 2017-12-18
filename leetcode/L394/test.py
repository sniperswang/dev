class Solution:
	def nextClosestTime(self, time):
		"""
		:type time: str
		:rtype: str
		"""
		print "hello"

	def decodeString(self, s):
		"""
		:type s: str
		:rtype: str
		"""
		charStack = []
		numStack = []
		currStr = ""
		for c in s:
			if (c >= 'a' and c <= 'z') or c == '[':
				charStack.append(c)
			if c >= '1' and c <= '9':
				numStack.append(c)
			if c == "]":
				_str = ""
				while 1:
					if charStack[-1] != '[':
						_str += charStack.pop()
					else:
						charStack.pop()
						break
				num = numStack.pop()

				_str = _str [::-1]
				allStr =  _str + currStr
				currStr = ""
				for i in range(0,int(num)):
					currStr += allStr
#				print currStr
		for i in range(0, len(charStack)):
			currStr += charStack[i]

		print currStr


class Solution1(object):
	def decodeString(self, s):
		stack = []
		stack.append(["", 1])
		num = ""
		for ch in s:
			if ch.isdigit():
				num += ch
			elif ch == '[':
				stack.append(["", int(num)])
				num = ""
			elif ch == ']':
				st, k = stack.pop()
				stack[-1][0] += st*k
				print "st:"+st+" k:"+str(k)
				print "stack[-1][0]:"+ stack[-1][0]
			else:
				stack[-1][0] += ch
				print "stack[-1][0]:"+ stack[-1][0]
		return stack[0][0]




s = Solution1()
print s.decodeString("3[a2[c]]")
print s.decodeString("2[abc]3[cd]ef")

