#include "SqList.hpp"

int main()
{
    SqList L;
    // Inittialize the list
    if (InitList_Sq(L) == OK)
    {
        cout << "InitList_Sq OK" << endl;
    }
    else
    {
        cout << "InitList_Sq ERROR" << endl;
    }

    // Insert elements into the list
    if (ListInsert_Sq(L, 1, 1) == OK)
    {
        cout << "ListInsert_Sq OK" << endl;
        cout << "L.elem[0] = " << L.elem[0] << endl;
    }
    else
    {
        cout << "ListInsert_Sq ERROR" << endl;
    }

    if (ListInsert_Sq(L, 2, 2) == OK)
    {
        cout << "ListInsert_Sq OK" << endl;
        cout << "L.elem[1] = " << L.elem[1] << endl;
    }
    else
    {
        cout << "ListInsert_Sq ERROR" << endl;
    }

    if (ListInsert_Sq(L, 3, 3) == OK)
    {
        cout << "ListInsert_Sq OK" << endl;
        cout << "L.elem[2] = " << L.elem[2] << endl;
    }
    else
    {
        cout << "ListInsert_Sq ERROR" << endl;
    }

    if (ListInsert_Sq(L, 4, 4) == OK)
    {
        cout << "ListInsert_Sq OK" << endl;
        cout << "L.elem[3] = " << L.elem[3] << endl;
    }
    else
    {
        cout << "ListInsert_Sq ERROR" << endl;
    }

    if (ListInsert_Sq(L, 5, 5) == OK)
    {
        cout << "ListInsert_Sq OK" << endl;
        cout << "L.elem[4] = " << L.elem[4] << endl;
    }
    else
    {
        cout << "ListInsert_Sq ERROR" << endl;
    }
    // Delete an element from the list
    int e;
    if (ListDelete_Sq(L, 3, e) == OK)
    {
        cout << "ListDelete_Sq OK" << endl;
        cout << "Deleted element = " << e << endl;
    }
    else
    {
        cout << "ListDelete_Sq ERROR" << endl;
    }
    // Locate an element in the list
    int index = LocateElem_Sq(L, 4, compare);
    if (index != 0)
    {
        cout << "LocateElem_Sq OK" << endl;
        cout << "index = " << index << endl;
    }
    else
    {
        cout << "LocateElem_Sq ERROR" << endl;
    }

    SqList L1;
    if (InitList_Sq(L1) == OK)
    {
        cout << "InitList_Sq OK" << endl;
    }
    else
    {
        cout << "InitList_Sq ERROR" << endl;
    }
    if (ListInsert_Sq(L1, 1, 1) == OK)
    {
        cout << "ListInsert_Sq OK" << endl;
        cout << "L1.elem[0] = " << L1.elem[0] << endl;
    }
    else
    {
        cout << "ListInsert_Sq ERROR" << endl;
    }
    if (ListInsert_Sq(L1, 2, 3) == OK)
    {
        cout << "ListInsert_Sq OK" << endl;
        cout << "L1.elem[1] = " << L1.elem[1] << endl;
    }
    else
    {
        cout << "ListInsert_Sq ERROR" << endl;
    }
    if (ListInsert_Sq(L1, 3, 5) == OK)
    {
        cout << "ListInsert_Sq OK" << endl;
        cout << "L1.elem[2] = " << L1.elem[2] << endl;
    }
    else
    {
        cout << "ListInsert_Sq ERROR" << endl;
    }

    SqList L2;
    MergeList_Sq(L, L1, L2);
    int *p = L2.elem;
    while (p < L2.elem + L2.length)
    {
        cout << *p++ << " ";
    }
    cout << endl;
    return 0;
}
