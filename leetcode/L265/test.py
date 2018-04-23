"""
There are a row of n houses, each house can be painted with one of the k colors. 
The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. 
For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?

"""

class Solution(object):
  def minCostII(self, costs):
      """
      :type costs: List[List[int]]
      :rtype: int
      """
      if len(costs) == 0:
        return 0

      m = len(costs)
      n = len(costs[0])

      for i in range (1, m):
        preMin = {}
        preMin[0] = min(costs[i-1][1:])
        costs[i][0] = costs[i][0] + preMin[0] 

        if ( n > 1):
          preMin[n-1] = min(costs[i-1][:n-1])
          costs[i][n-1] = costs[i][n-1] + preMin[n-1] 

        for j in range (1, n-1):
          preMin[j] = min( min(costs[i-1][:j]), min(costs[i-1][j+1:]) )
          costs[i][j] = costs[i][j] + preMin[j] 


      return min(costs[len(costs)-1])

costa = [1,2,4]
costb = [3,1,0]
costc = [1,2,1]

costs = []
costs.append(costa)
costs.append(costb)
costs.append(costc)


s = Solution()

print s.minCostII(costs)



