
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <utility>

using namespace std;
 

class WordDistance {

private:
	unordered_map<string, vector<int> >myMap;
public:
    WordDistance(vector<string>& words) 
	{
	 	for(int i = 0; i < words.size(); i++)
		{
			if ( myMap.find(words[i]) == myMap.end() )
			{
				vector<int> vec;
				vec.push_back(i);
				myMap[words[i]] = vec;
			}
			else 
			{
				myMap[words[i]].push_back(i);
			}
		}	
		
    }

    int shortest(string word1, string word2) {

		int i = 0;
		int j = 0;
		int des = INT_MAX;
		int len1 = myMap[word1].size();
		int len2 = myMap[word2].size();

		while( i != len1 && j != len2)
		{
			des = min(des, abs( myMap[word1][i] - myMap[word2][j] ) );

			if ( myMap[word1][i] < myMap[word2][j] )
			{
				i++;
			}
			else 
			{
				j++;
			}
		}	
	
        return des;
    }
};
 
int main() 
{
    return 0;
}
