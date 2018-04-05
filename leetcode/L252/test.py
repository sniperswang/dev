"""
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
determine if a person could attend all meetings.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return false.

"""

# Definition for an interval.
class Interval(object):
  def __init__(self, s=0, e=0):
    self.start = s
    self.end = e

class Solution(object):
  def canAttendMeetings(self, intervals):
    """
    :type intervals: List[Interval]
    :rtype: bool
    """
    intervals.sort(key = lambda x: x.start)
    if (len(intervals) <= 1 ):
      return True

    upper = intervals[0].end

    for subarr in intervals[1:]:
      if subarr.start < upper:
        return False
      upper = subarr.end

    return True



s = Solution()
time = ""
s.nextClosestTime(time)

