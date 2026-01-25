#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include<iostream>
#define top(S) (S).top
#define info(S) (S).info

using namespace std;

typedef char infotype;

struct stack {
    infotype info[15];
    int top;
};

void createStack103032300013(stack &s);
bool isEmpty103032300013(stack s);
bool isFull103032300013(stack s);
void push103032300013(stack &s, infotype x);
infotype pop103032300013(stack &s);
void printInfo103032300013(stack s);

#endif // STACK_H_INCLUDED
