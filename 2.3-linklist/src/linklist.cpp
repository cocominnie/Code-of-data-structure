#include "linklist.hpp"

Status GetElem_L(LinkList L, int i, int &e)
{
    int j = 1;
    LinkList p = L->next;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return ERROR;
    e = p->data;
    return OK;
}

Status ListInsert_L(LinkList &L, int i, int e)
{
    LinkList p = L;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return ERROR;
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete_L(LinkList &L, int i, int &e)
{
    LinkList p = L;
    int j = 0;
    while (p->next && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (!p->next || j > i)
        return ERROR;
    LinkList q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return OK;
}

void CreateList_L(LinkList &L, int n)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    for (int i = n; i > 0; --i)
    {
        LinkList p = (LinkList)malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }
}

void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc)
{
    LinkList pa = La->next, pb = Lb->next, pc = Lc = La;
    while (pa && pb)
    {
        if (pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    free(Lb);
}