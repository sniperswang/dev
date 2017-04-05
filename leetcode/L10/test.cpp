#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// http://xiaohuiliucuriosity.blogspot.com/2014/12/regular-expression-matching.html?view=flipcard


class Solution {
public:
    bool isMatch(string s, string p) {
    	if ( p.empty() )
			return s.empty(); 

		if (p.size() > 1 && p[1] == '*')
			return ( isMatch(s,p.substr(2)) || (!s.empty() && ( s[0] == p[0] || p[0] == '.' )  && isMatch(s.substr(1),p) ) );
		else 
			return ( !s.empty() && (s[0] == p[0] || p[0] == '.'))  && isMatch(s.substr(1), p.substr(1));
    }
};
  
int main() 
{
	string s = "ab";
	string p = ".*";

	Solution ss;
	
	cout << ss.isMatch(s, p) << endl;

    return 0;
}
