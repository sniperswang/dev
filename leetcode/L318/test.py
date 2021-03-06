"""
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) 
where the two words do not share common letters. You may assume that each word will contain only lower case letters. 
If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.

"""

class Solution(object):
    def maxProduct(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        mask = {}
        res = 0
        for i in range(0, len(words)):
          local_mask = 0
          for c in words[i]:
              local_mask |= 1 << (ord(c) - ord('a'))
          mask[words[i]] = local_mask

          for j in range(0,i):
            if mask[words[i]] & mask[words[j]] == 0:
              res = max(res, len(words[j])*len(words[i]))

        return res
            

s = Solution()
#words = ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
words = ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
print s.maxProduct(words)

