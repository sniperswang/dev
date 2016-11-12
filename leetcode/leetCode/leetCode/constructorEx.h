//
//  constructorEx.h
//  leetCode
//
//  Created by Yao Wang on 8/26/13.
//
//

#ifndef leetCode_constructorEx_h
#define leetCode_constructorEx_h

class a{
public:
    int var1;
    a(int var)
    {
        var1 = var;
    }
};

class b: public a
{
public:
    int var2;
    b(int d) : var2( d++) , a(var2++)
    {
        cout << this->var1 << "\n";
        cout << this->var2 << "\n";
    }
};


//     b obj1(5); 
#endif
