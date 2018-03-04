"""
The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function will only be called once for each test case.

"""
# The read4 API is already defined for you.
# @param buf, a list of characters
# @return an integer
# def read4(buf):

class Solution(object):
    def read(self, buf, n):
        """
        :type buf: Destination buffer (List[str])
        :type n: Maximum number of characters to read (int)
        :rtype: The number of characters read (int)
        """
        idx = 0
        while (n > 0):
          tempbuf = [""]*4
          sz = self.read4(tempbuf)
          if (sz == 0):
            return idx
          for i in range(min(sz,n)):
              buf[idx] = tempbuf[i]
              idx +=1
              n -= 1
        
        return idx
          

    def read4(self, buf):
        self.i += 1
        if (self.i > 4):
          del buf[:]
          return 0
        elif ( self.i > 3):
          del buf[:]
          buf.extend(["1","2","3"])
          return 3
        else:
          del buf[:]
          buf.extend(["1","2","3","4"])
          return 4

    i = 0;


s = Solution()
buf = [""]*60
print s.read(buf,60)
print buf

