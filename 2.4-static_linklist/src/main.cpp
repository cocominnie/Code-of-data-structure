#include "sl.hpp"

int main()
{
    SLinkList space;
    int S;
    difference(space, S);
    int p = S;
    cout << "the difference of set A and set B is: ";
    while (space[p].cur)
    {
        p = space[p].cur;
        cout << space[p].data << " ";
    }
    cout << endl;

    return 0;
}
