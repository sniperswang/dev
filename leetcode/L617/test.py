"""
Given two binary trees and imagine that when you put one of them to cover the other, 
some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, 
then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

Example 1:
Input: 
  Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
       3
      / \ 
     4   5
    / \   \ 
   5   4   7
Note: The merging process must start from the root nodes of both trees.

"""

# Definition for a binary tree node.
class TreeNode(object):
   def __init__(self, x):
       self.val = x
       self.left = None
       self.right = None

class Solution(object):
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        if t1 and t2:
            root = TreeNode(t1.val + t2.val)
            root.left = self.mergeTrees(t1.left, t2.left)
            root.right = self.mergeTrees(t1.right, t2.right)
            return root
        else:
            return t1 or t2

    def mergeTrees1(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """

        e = TreeNode(0)
        if (t1 == None and t2 == None):
            return None
        if (t1 == None):
            e.val = t2.val
            e.left = self.mergeTrees(None, t2.left)
            e.right = self.mergeTrees(None, t2.right)
        elif (t2 ==None):
            e.val = t1.val
            e.left = self.mergeTrees(t1.left, None)
            e.right = self.mergeTrees(t1.right, None)
        else:
            e.val = t1.val + t2.val
            e.left = self.mergeTrees(t1.left, t2.left)
            e.right = self.mergeTrees(t1.right, t2.right)
        return e

    def printTree(self, root):
      buf = []
      output = []
      if not root:
          print '$'
      else:
          buf.append(root)
          count = 1
          nextCount = 0
          while count > 0:
              node = buf.pop(0)
              if node:
                  output.append(node.val)
                  count -= 1
              else:
                  output.append('$')
              if node and node.left:
                  buf.append(node.left)
                  nextCount += 1
              else:
                  buf.append(None)
              if node and node.right:
                  buf.append(node.right)
                  nextCount += 1
              else:
                  buf.append(None)
              if count == 0:
                  print output
                  output = []
                  count = nextCount
                  nextCount = 0
          # print the remaining all empty leaf node part
          for i in range(len(buf)):
              output.append('$')
          print output

s = Solution()
a = TreeNode(1)
b = TreeNode(3)
c = TreeNode(2)
d = TreeNode(5)

a.left = b;
a.right = c;
b.left = d

e = TreeNode(2)
f = TreeNode(1)
g = TreeNode(3)
h = TreeNode(4)
i = TreeNode(7)

e.left = f
e.right = g
f.right = h
g.right = i

res = s.mergeTrees(a,e)
s.printTree(res)

