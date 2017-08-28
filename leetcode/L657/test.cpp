
#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    bool judgeCircle(string moves) {
        int vert=0;
        int horz=0;
        
        for (int i = 0; i < moves.size(); i++)
        {
            switch(moves[i])
            {
                case 'U':vert++;break;
                case 'D':vert--;break;
                case 'L':horz++;break;
                case 'R':horz--;break;
                default:break;
            }
            
        }
        return (vert==0) && (horz ==0);
    }
};
  
int main() 
{
    return 0;
}
