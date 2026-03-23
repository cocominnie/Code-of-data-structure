#include "dulist.hpp"

int main()
{
    DuLinkList L = new DuLNode;
    L->prior = L->next = L;
    for (int i = 1; i <= 5; ++i)
        ListInsert_DuL(L, i, i);
    int e;
    ListDelete_DuL(L, 3, e);
    cout << "Deleted element: " << e << endl;
    DuLinkList p = L->next;
    while (p != L)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    return 0;
}
