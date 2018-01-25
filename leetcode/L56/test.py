"""
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
"""

# Definition for an interval.
 class Interval(object):
	 def __init__(self, s=0, e=0):
		 self.start = s
				self.end = e




class Solution(object):
  def merge(self, intervals):
    """
    :type intervals: List[Interval]
    :rtype: List[Interval]
    """
    intervals.sort(key = lambda x: x.start)
    res = []
    if (len(intervals) == 0):
      return res

    lower = intervals[0].start
    upper = intervals[0].end
    for subarr in intervals[1:]:
      if subarr.start <= upper:
        if subarr.end > upper:
          upper = subarr.end
      else:
        e = Interval(lower,upper)
        res.append(e)
        lower = subarr.start
        upper = subarr.end

    e = Interval(lower,upper)
    res.append(e)
    return res

s = Solution()
print s.merge(arr)

