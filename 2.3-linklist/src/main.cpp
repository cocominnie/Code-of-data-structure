#include "linklist.hpp"

int main()
{
    LinkList L;
    CreateList_L(L, 5);
    LinkList p = L->next;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    int e;
    if (GetElem_L(L, 3, e) == OK)
    {
        cout << "The 3rd element is: " << e << endl;
    }
    if (ListInsert_L(L, 3, 10) == OK)
    {
        cout << "Successfully inserted 10 at position 3." << endl;
    }
    if (GetElem_L(L, 3, e) == OK)
    {
        cout << "After inserting 10 at position 3, the 3rd element is: " << e << endl;
    }
    if (ListDelete_L(L, 3, e) == OK)
    {
        cout << "After deleting the 3rd element, the deleted element is: " << e << endl;
    }
    LinkList L1, L2;
    CreateList_L(L1, 3);
    MergeList_L(L, L1, L2);
    LinkList p1 = L2->next;
    while (p1)
    {
        cout << p1->data << " ";
        p1 = p1->next;
    }
    cout << endl;

    return 0;
}
