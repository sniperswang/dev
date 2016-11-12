//
//  interview.h
//  leetCode
//
//  Created by Yao Wang on 8/4/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef leetCode_interview_h
#define leetCode_interview_h
// Question A:
/*
 1.	Write a program that takes a list of strings containing integers and words and returns a sorted version of this list (words are alphabetical order and integers are numerical order. If nth element is an integer it must remain an integer and vice versa)
 a.	Car truck bus -> bus car truck
 b.	8 4 6 1 -> 1 4 6 8
 c.	Car truck 8 4 bus 6 1 -> bus car 1 4 truck 6 8
 d.	Answer: intvec[], intpos, stringvec[], stringpos, isInt[]
 
*/

/*
 Code A:
 
 int isInteger(string s){
 string::iterator it;
 it = s.begin();
 while(it != s.end()){
 if( !isdigit(*it) ) {
 return false;
 }
 it++;
 }
 return true;
 }
 
 { // main body
 
 //string s("Somewhere down the road");
 string s("car truck 8 4 bus 6 1 ");
 char *pch;
 char *str = new char[s.size()];
 memcpy(str,s.c_str(),s.size());
 //str[s.size()] = '\n';
 pch = strtok (str," ");
 
 vector<int> strPos;
 vector<int> intPos;
 set<string> strSet;
 set<int> intSet;
 int i =0;
 while (pch != NULL)
 {//
 
 if( isInteger(pch) ){
 intPos.push_back(i);
 intSet.insert(atoi(pch));
 } else {
 strPos.push_back(i);
 strSet.insert(pch);
 }
 // printf ("%s\n",pch);
 pch = strtok (NULL, " ");
 i++;
 }
 
 vector<string> strVec(i);
 set<int>::iterator i_it = intSet.begin();
 set<string>::iterator s_it = strSet.begin();
 
 // assign sorted integers;
 i = 0;
 for(;i_it != intSet.end(); i_it++){
 stringstream ss;
 ss << *i_it;
 string temp = ss.str();
 strVec[ intPos[i] ] = temp;
 i++;
 }
 
 i = 0;
 for(;s_it !=strSet.end(); s_it++){
 strVec[ strPos[i] ] = *s_it;
 i++;
 }
 
 for(i=0; i < strVec.size(); ++i)
 {
 std::cout << strVec[i] << "\n";
 }
 
 } // main body
 
 */

#endif
