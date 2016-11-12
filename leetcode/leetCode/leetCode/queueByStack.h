//
//  queueByStack.h
//  leetCode
//
//  Created by Yao Wang on 7/10/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <stack>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;

#ifndef leetCode_queueByStack_h
#define leetCode_queueByStack_h


template <typename T> class myQueue 
{
public:
    myQueue(){};
    ~myQueue(){};
    
    void enqueue(const T&);
    T    dequeue(void);
    
private:
    stack<T> enqStack;
    stack<T> deqStack;
    
};

template <typename T> void myQueue<T>::enqueue(const T& e) {
    enqStack.push(e);
}

template <typename T> T myQueue<T>::dequeue(){
    if(deqStack.size() == 0) {
        while(enqStack.size() != 0) {
            T& e = enqStack.top();
            deqStack.push(e);
            enqStack.pop();
        }
    }
              
    if(deqStack.size()==0){
        runtime_error e("run_time error");
        throw e;
    }
    
    T head = deqStack.top();
    deqStack.pop();
    return head;
} 

#endif
