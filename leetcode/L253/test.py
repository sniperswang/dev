
"""
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
"""

# Definition for an interval.
class Interval(object):
   def __init__(self, s=0, e=0):
       self.start = s
       self.end = e



class Solution(object):
    def minMeetingRooms(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        intervals.sort(key = lambda x: x.start)
        if (len(intervals) <= 1 ):
            return len(intervals)
        
        upper = intervals[0].end
        rooms = []
        room = []
        room.append(intervals[0])
        rooms.append(room)
        
        for subarr in intervals[1:]:
            print subarr.start, ",", subarr.end
            done = False 
            for room in rooms:
              if subarr.start >= room[-1].end:
                room.append(subarr)
                done = True
                break
            if done == False:
              room = []
              room.append(subarr)
              rooms.append(room)
        return len(rooms)
              
 

s = Solution()
arr = [] 
arr.append(Interval(2,11))
arr.append(Interval(6,16))
arr.append(Interval(11,16))
arr.append(Interval(15,17))
print s.minMeetingRooms(arr)

