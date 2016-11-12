//
//  vitrualExample.h
//  leetCode
//
//  Created by Yao Wang on 8/25/13.
//
//

#ifndef leetCode_vitrualExample_h
#define leetCode_vitrualExample_h

class A {
public:
    virtual void print() = 0;
};

class B: public A {
public:
    void print(){
        cout << "print B\n";
    }
};

class C: public B {
public:
    virtual void print(){
        cout << "print C\n";
    }
};

void test(A* a){
    a->print();
}

/*
 
 B b;
 C c;
 
 A* bb = &b;
 A* cc = &c;
 
 test(bb);
 test(cc);
 
 */

#endif
