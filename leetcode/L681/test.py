from datetime import *

class Solution:
	def nextClosestTime(self, time):
		digits = set(time)
		print digits
		while True:
			time = (datetime.strptime(time, '%H:%M') + timedelta(minutes=1)).strftime('%H:%M')
			if set(time) <= digits:
				return time



s = Solution()
time = "23:59"
print s.nextClosestTime(time)

