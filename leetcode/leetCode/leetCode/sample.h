//
//  sample.h
//  leetCode
//
//  Created by Yao Wang on 7/21/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef leetCode_sample_h
#define leetCode_sample_h

/* quick sort
 Solution_quick_sort s;
 int numArray [] = {5,4,3,2,1,10,6,7,8,9};
 s.quickSortNum(numArray,10);
 
 for(int i = 0; i < 10; i++){
 std::cout<<numArray[i]<<"\n";
 }
 */
/* reverse 
 char str[] = "hello\n";
 Solution_reverse_str s_str;
 s_str.reverseStr(str);
 std::cout << "Hello, World :"<< str  << "\n";
 
 Solution_reverse_int s_int;
 int res_i = s_int.reverseInt(102);
 std::cout << "Hello, World B :"<< res_i << "\n";
 */

/*  queue test case *?
 myQueue<int> que;
 que.enqueue(1);
 int res = que.dequeue();
 que.enqueue(2);
 que.enqueue(3);
 que.enqueue(4);
 res = que.dequeue();
 std::cout << "res :"<< res << "\n";
 res = que.dequeue();
 std::cout << "res :"<< res << "\n";
 */

/* reverse list 
 ListNode head(0);
 ListNode l1(1);
 ListNode l2(2);
 ListNode l3(3);
 ListNode l4(4);
 
 head.next = &l1;
 l1.next = &l2;
 l2.next = &l3;
 l3.next = &l4;
 
 ListNode *start = &head;
 Solution_reverse_list s;
 s.printList(start);
 cout<<"----------------------\n";
 start = s.reverseList(start);
 s.printList(start);
*/ 

#endif
