//
//  aoti_sample.h
//  leetCode
//
//  Created by Yao Wang on 8/24/13.
//
//

#ifndef leetCode_aoti_sample_h
#define leetCode_aoti_sample_h

int myatoi(const char *str) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int str_len = sizeof(str);
    char cpy_str[str_len+1];
    
    memcpy(cpy_str,str,str_len+1);
    cpy_str[str_len+1] = '\0';
    char *pch;
    pch = strtok (cpy_str," ");
    
    if (pch == NULL)
        return 0;
    
    int subStrLen = sizeof(pch);
    
    if(!isdigit(pch[0]) && pch[0] != '+' && pch[0] != '-' ) {
        return 0;
    }
    
    bool isPos = true;
    
    long res=0;
    for (int i = 0; i < subStrLen + 1; i ++) {
        if (pch[i] == '+') {
            isPos=true;
            i++;
        } else if(pch[i] == '-'){
            isPos=false;
            i++;
        }
        if(isdigit(pch[i]) ) {
            res = res*10 + (int(pch[i]) - 48);
        }else {
            break;
        }
    }
    
    if(!isPos)
        res = res * (-1);
    
    if (res > INT_MAX || res < INT_MIN) {
        return 0;
    } else {
        return int(res);
    }
    
    return 0;
}

/* test
 
 string str = "+00131204";
 const char s[] = "hell0";
 const char *p = s;
 cout << "size of s:" << p <<" "<< sizeof(s) << "\n";
 char ch = '0';
 // cout << " ch :" << int(ch) << "\n";
 int i = atoi(str.c_str());
 cout << "i:" << i << "\n";
 i = myatoi(str.c_str());
 cout <<" myAtoi:" << i << "\n";
 
 */

#endif
