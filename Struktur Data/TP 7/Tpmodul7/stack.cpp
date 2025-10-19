#include "stack.h"

void createStack103032300013(stack &s){
    top(s) = 0;

}

bool isEmpty103032300013(stack s){
    if (top(s) == 0){
        return true;
    } else {
        return false;
    }
}

bool isFull103032300013(stack s){
    if (top(s) == 15){
        return true;
    } else {
        return false;
    }
}

void push103032300013(stack &s, infotype x){
    if (isFull103032300013(s) == false){
        top(s) = top(s) + 1;
        info(s)[top(s)] = x;
    }
}

infotype pop103032300013(stack &s){
    infotype x;
    x = info(s)[top(s)];
    top(s) = top(s)-1;
    return x;
}

void printInfo103032300013(stack s){
    int i;
    for (i = top(s); i > 0; i--){
        cout << info(s)[i];
    }
}
