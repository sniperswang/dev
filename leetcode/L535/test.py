import string
import random
"""
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl 
and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. 
You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.


"""

class Codec:

    def __init__(self):
      self.shortToLong = {}
      self.longtoShort = {}
    
    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """

        if longUrl not in self.longtoShort:
          newStr = ""
          while ( newStr == "" or newStr in self.shortToLong ):
            for i in range(6):
              newStr = newStr+random.choice(string.ascii_letters + '0123456789')

          self.shortToLong[newStr] = longUrl
          self.longtoShort[longUrl] = newStr
          return "http://tinyurl.com/"+newStr

        else:
          return "http://tinyurl.com/"+self.longtoShort[longUrl]

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        :type shortUrl: str
        :rtype: str
        """
        shortStr = shortUrl[-6:]
        return self.shortToLong[shortStr]
        
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))



codec = Codec()
longURl = "https://leetcode.com/problems/design-tinyurl"
newStr = codec.encode(longURl)
print newStr

oldStr = codec.decode(newStr)
print oldStr


