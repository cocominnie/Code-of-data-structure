#include "dulist.hpp"

Status ListInsert_DuL(DuLinkList &L, int i, int e)
{
    if (i < 1)
        return ERROR;
    DuLinkList p = L->next;
    int j = 1;
    while (p != L && j < i)
    {
        p = p->next;
        ++j;
    }
    if (j > i || (p == L && j < i))
        return ERROR;
    DuLinkList s = new DuLNode;
    s->data = e;
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    return OK;
}

Status ListDelete_DuL(DuLinkList &L, int i, int &e)
{
    if (i < 1)
        return ERROR;
    DuLinkList p = L->next;
    int j = 1;
    while (p != L && j < i)
    {
        p = p->next;
        ++j;
    }
    if (p == L || j > i)
        return ERROR;
    e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    delete p;
    return OK;
}
