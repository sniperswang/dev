
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;
 

void splitStrBuildMap(vector < string >& purchases)
{

}


vector < int > determineRecommendation(string itemId, vector < string > purchases) 
{
	vector<int> res;
	int nStrong = 0;
	set<string> strong;

	int len = purchases.size();

	multimap<string,string> prodToCus;
	multimap<string,string> cusToProd;

	for (int i = 0; i < len; i++)
	{
		int pos = purchases[i].find(':');
		string cus= purchases[i].substr(0,pos);
		string prod = purchases[i].substr(pos+1, purchases.size());

		prodToCus.insert(std::pair<string,string>(prod,cus));
		cusToProd.insert(std::pair<string,string>(cus,prod));
	}

	std::multimap<string,string>::iterator it, itlow,itup;

	itlow = prodToCus.lower_bound (itemId);
	itup = prodToCus.upper_bound (itemId);

	for (it=itlow; it!=itup; ++it)
	{
		std::multimap<string,string>::iterator cusIt, cusItlow, cusItup;
		cusItlow = cusToProd.lower_bound(it->second);
		cusItup = cusToProd.upper_bound(it->second);

		for ( cusIt = cusItlow ; cusIt != cusItup; cusIt++)
		{
			strong.insert(cusIt->second);
		}
	}

	nStrong = strong.size() - 1;

	std::set<string>::iterator prodIt;

	for(prodIt=strong.begin(); prodIt != strong.end(); prodIt++) 
	{
		cout << *prodIt << endl;
	}

	return res;
}


int main() 
{
	vector < string > purchases;
	purchases.push_back("first:ABC");
	purchases.push_back("first:HIJ");
	purchases.push_back("sec:HIJ");
	purchases.push_back("sec:KLM");
	purchases.push_back("third:NOP");
	purchases.push_back("fourth:ABC");
	purchases.push_back("fourth:QRS");
	purchases.push_back("first:DEF");
	purchases.push_back("fifth:KLM");
	purchases.push_back("fifth:TUV");

	determineRecommendation("ABC", purchases);
    return 0;
}
