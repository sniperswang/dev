
#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <utility>  
#include <queue> 

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
		queue <std::pair <std::string,int> > myQueue;
	
		myQueue.push(make_pair(beginWord, 1));			

		while(!myQueue.empty())
		{
			std::pair <std::string,int> top = myQueue.front();
			myQueue.pop();
			if ( top.first == endWord )
				return top.second;
			else 
			{
				findNeighoorNodes(top, myQueue, wordList);
			}
		}
  		return 0;      
    }

	void findNeighoorNodes(std::pair <std::string,int> &myPair, queue <std::pair <std::string,int> > &myQueue, unordered_set<string>& wordList)
	{
		string s = myPair.first;
		
		for (int i = 0; i < s.size(); i++)
		{
			char orgCh = s[i];
			for(char ch = 'a'; ch <= 'z'; ch++ )
			{
				if (ch != orgCh)
				{
					s[i] = ch;
					if ( wordList.size() == 0 )
					{
						return;
					}

					if (wordList.count(s) )
					{
						myQueue.push(make_pair( s, myPair.second+1) );
						wordList.erase(s);
					}
				}		
			}
			s = myPair.first;
		}
	}
};

  
int main() 
{
	std::unordered_set<std::string> wordList;
	wordList.insert("hot");
	wordList.insert("dot");
	wordList.insert("dog");
	Solution s;
	cout <<  s.ladderLength("hot", "dog", wordList) << endl;
    return 0;
}
