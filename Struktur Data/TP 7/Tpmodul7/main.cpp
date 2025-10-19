#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    stack s;
    createStack103032300013(s);
    push103032300013(s, 'A');
    push103032300013(s, 'T');
    push103032300013(s, 'A');
    push103032300013(s, 'D');
    push103032300013(s, 'R');
    push103032300013(s, 'U');
    push103032300013(s, 'T');
    push103032300013(s, 'K');
    push103032300013(s, 'U');
    push103032300013(s, 'R');
    push103032300013(s, 'T');
    push103032300013(s, 'S');

    cout << "Stack Awal : " << endl;
    printInfo103032300013(s);
    cout << endl;

    pop103032300013(s);
    pop103032300013(s);
    pop103032300013(s);
    pop103032300013(s);
    pop103032300013(s);
    pop103032300013(s);
    pop103032300013(s);
    pop103032300013(s);

    cout << "Stack sesudah pop : " <<endl;
    printInfo103032300013(s);
    cout << endl;
}
