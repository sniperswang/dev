
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


//global map for fast-reference;

vector<vector<int> > referMap;

map<char,vector<char> >buildKnighMap(int boardRow, int boardCol, vector<vector<char> >& rows)
{
	// build map value -> path
	// vector<vector<int> > 
	// for example 8 -> 1 ,3 
	//			   1 -> 6, 8
	// for example vector[8] = { [1], [3] }
	//             vector[1] = { [6], [8] }
	map<char,vector<char> > charMap;

	for(int i = 0; i < boardRow; i++ )
	{
		for (int j = 0; j < boardCol; j++)
		{
			if (rows[i][j] < '0' || rows[i][j] > '9' )
				continue;
			vector<int> rowp;
			vector<int> colp;
			vector<char> path;

			rowp.push_back(i-2);colp.push_back(j-1);
			rowp.push_back(i-2);colp.push_back(j+1);
			rowp.push_back(i+2);colp.push_back(j-1);
			rowp.push_back(i+2);colp.push_back(j+1);
			rowp.push_back(i-1);colp.push_back(j-2);
			rowp.push_back(i-1);colp.push_back(j+2);
			rowp.push_back(i+1);colp.push_back(j-2);
			rowp.push_back(i+1);colp.push_back(j+2);

			int len = rowp.size();
			for (int k = 0; k < len; k++)
			{
				int row = rowp[k];
				int col = colp[k];
				if ( row >= 0 && col >= 0 && row < boardRow && col < boardCol )
				{
					char e = rows[row][col];
					if (e >= '0' && e <= '9')
						path.push_back(e); 
				}
			}

			charMap[rows[i][j]] = path;
		}
	}

	map<char,vector<char> >::iterator iter;

	for(iter = charMap.begin(); iter != charMap.end(); iter++)
	{
		cout << iter->first << " ==> ";
		vector<char> path = iter->second;
		int len = path.size();
		for (int i = 0; i < len; i++)
		{
			cout << path[i] << ' ';
		}
		cout << endl;
	}
	return charMap;
}

map<char,vector<char> >buildBishopMap(int boardRow, int boardCol, vector<vector<char> >& rows)
{
	// build map value -> path
	// vector<vector<int> > 
	// for example 8 -> 1 ,3 
	//			   1 -> 6, 8
	// for example vector[8] = { [1], [3] }
	//             vector[1] = { [6], [8] }
	map<char,vector<char> > charMap;
	for(int i = 0; i < boardRow; i++ )
	{
		for (int j = 0; j < boardCol; j++)
		{
			if (rows[i][j] < '0' || rows[i][j] > '9' )
				continue;
			vector<int> rowp;
			vector<int> colp;
			vector<char> path;
			
			rowp.push_back(-1);colp.push_back(-1);
			rowp.push_back(-1);colp.push_back(1);
			rowp.push_back(1);colp.push_back(-1);
			rowp.push_back(1);colp.push_back(1);
			
			int len = rowp.size();
			for (int k = 0; k < len; k++)
			{
				int row = i;
				int col = j;

				while(true)
				{
					row += rowp[k];
					col += colp[k];
					if ( row >= 0 && col >= 0 && row < boardRow && col < boardCol )
					{
						char e = rows[row][col];
						if (e >= '0' && e <= '9')
							path.push_back(e); 
					}
					else
					{
						break;
					}
				}

			}

			charMap[rows[i][j]] = path;
		}
	}
	
	/*
	map<char,vector<char> >::iterator iter;

	for(iter = charMap.begin(); iter != charMap.end(); iter++)
	{
		cout << iter->first << " ==> ";
		vector<char> path = iter->second;
		int len = path.size();
		for (int i = 0; i < len; i++)
		{
			cout << path[i] << ' ';
		}
		cout << endl;
	}
	*/
	return charMap;
}

int getNumforDigit(int level, map<char,vector<char> > &charMap, char key)
{
	if (level == 0)
	{
//		cout << "key -48 " << key - 48 << " level:" << level << endl;
		referMap[int(key-48)][level] = 1;
		return 1;
	}
	
	map<char,vector<char> >::iterator iter = charMap.find(key);
	if (iter == charMap.end())
		return 0;
	vector<char> path = iter->second;
	int len = path.size();

	if (len == 0)
		return 0;

	int sum = 0;
	for(int i = 0 ; i < len; i++ )
	{

		if (referMap[path[i] - 48][level-1] != -1)
		{
			sum += referMap[path[i] -48][level-1];
		}
		else 
		{
			referMap[path[i]-48][level-1] = getNumforDigit(level-1, charMap, path[i]);
			sum += referMap[path[i]-48][level-1];
		}
		//sum += getNumforDigit(level-1, charMap, path[i]);
	}
	return sum;

}



int getBishopPhoneNum(int numOfLen, vector<char>& validStartDigits, int boardRow, int boardCol, vector<vector<char> >& rows)
{
	map<char,vector<char> > charMap = buildBishopMap(boardRow, boardCol, rows);
	int sum = 0;
	int len = validStartDigits.size();
	for (int i =0; i < len; i++)
	{
		sum += getNumforDigit(numOfLen-1,charMap,validStartDigits[i]);
	}
	return sum;
}

int getKnightPhoneNum(int numOfLen, vector<char>& validStartDigits, int boardRow, int boardCol, vector<vector<char> >& rows)
{
	map<char,vector<char> > charMap = buildKnighMap(boardRow, boardCol, rows);

	int sum = 0;
	int len = validStartDigits.size();
	for (int i =0; i < len; i++)
	{
		sum += getNumforDigit(numOfLen-1,charMap,validStartDigits[i]);
	}
	return sum;
}

int main() 
{
	string piece;
	int numOfLen;
	vector<char> validStartDigits;
	int boardRow;
	int boardCol;
	vector<vector<char> > rows;

	cin >> piece;
	cin >> numOfLen;

	// ingore cin ignore leading whitespace 
	cin.ignore();
	// 
	int c;
	do {
		c=getchar();
		if( c != ' ' && c != '\n')
		{
			validStartDigits.push_back(c);
		}
	} while (c != '\n');
	cin >> boardRow;
	cin >> boardCol;

	// ingore cin ignore leading whitespace 
	cin.ignore();
	for (int i = 0; i < boardRow; i ++)
	{
		vector<char> row;
		do {
			c=getchar();
			if( c != ' ' && c != '\n')
			{
				row.push_back(c);
			}
		} while (c != '\n');
		rows.push_back(row);
	}

	cout << "piece:" << piece << endl; 
	cout << "numberOfLen:" << numOfLen << endl;
	vector<char>::iterator mySetIter;
	for (mySetIter = validStartDigits.begin(); mySetIter != validStartDigits.end(); mySetIter++)
	{
		cout << *mySetIter <<",";
	}
	cout << endl;	
	cout << "boardRow:"<< boardRow << endl;
	cout << "boardCol:"<< boardCol << endl;

	for (int i = 0; i < boardRow;i++)
	{
		for (int j = 0;j < boardCol; j++ )
		{
			cout << rows[i][j] << " ";
		}
		cout << endl;
	}

	// init referencMap;
	int default_value = -1;
	vector<int> vec(numOfLen, default_value);
	for (int i =  0; i < 10; i++)
	{
		referMap.push_back(vec);
	}

	int sum = 0;
	
	if ( piece == "knight" ) 
		sum = getKnightPhoneNum(numOfLen, validStartDigits, boardRow, boardCol, rows);
	else if (piece == "bishop")
		sum = getBishopPhoneNum(numOfLen, validStartDigits, boardRow, boardCol, rows);
	cout << sum  << endl;
	return 0;
}
