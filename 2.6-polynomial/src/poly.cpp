#include "poly.hpp"

static void AppendNode(LinkList tail, ElemType e, LinkList &newTail)
{
    LinkList node = new Node;
    node->data = e;
    node->next = nullptr;
    tail->next = node;
    newTail = node;
}

void InitList(polynomial &L)
{
    L = new Node;
    L->next = nullptr;
}

LinkList GetHead(polynomial L)
{
    return L;
}

void SetCurElem(LinkList p, ElemType e)
{
    p->data = e;
}

ElemType GetCurElem(LinkList p)
{
    return p->data;
}

LinkList NextPos(LinkList h, LinkList p)
{
    return p->next;
}

int compare(ElemType a, ElemType b)
{
    if (a.expn > b.expn)
        return 1;
    else if (a.expn < b.expn)
        return -1;
    else
        return 0;
}

Status LocateElem(LinkList L, ElemType e, int (*compare)(ElemType, ElemType))
{
    LinkList p = L->next;
    while (p)
    {
        if (compare(p->data, e) == 0)
            return OK;
        p = p->next;
    }
    return ERROR;
}

Status OrderInsert(LinkList &L, ElemType e, int (*compare)(ElemType, ElemType))
{
    LinkList p = L;
    while (p->next && compare(p->next->data, e) < 0)
        p = p->next;
    if (p->next && compare(p->next->data, e) == 0)
    {
        p->next->data.coef += e.coef;
        if (p->next->data.coef == 0)
        {
            LinkList temp = p->next;
            p->next = temp->next;
            delete temp;
        }
    }
    else
    {
        LinkList newNode = new Node;
        newNode->data = e;
        newNode->next = p->next;
        p->next = newNode;
    }
    return OK;
}

void CreatePolyn(polynomial &L, int m)
{
    if (!L)
        InitList(L);
    LinkList h = GetHead(L);
    int i;
    for (i = 1; i <= m; ++i)
    {
        ElemType e;
        printf("Please enter the coefficient and exponent of term %d: ", i);
        scanf("%f %d", &e.coef, &e.expn);
        OrderInsert(h, e, compare);
    }
}

void CopyPolyn(polynomial src, polynomial &dest)
{
    InitList(dest);
    LinkList tail = dest;
    LinkList p = src->next;
    while (p)
    {
        AppendNode(tail, p->data, tail);
        p = p->next;
    }
}

void DestroyList(polynomial &L)
{
    LinkList p = L;
    while (p)
    {
        LinkList temp = p;
        p = p->next;
        delete temp;
    }
    L = nullptr;
}

void PrintPolyn(polynomial L)
{
    LinkList p = L->next;
    while (p)
    {
        if (p->data.coef > 0 && p != L->next)
            cout << "+";
        cout << p->data.coef << "x^" << p->data.expn << " ";
        p = p->next;
    }
    cout << endl;
}

void AddPolyn(polynomial &Pa, polynomial &Pb)
{
    LinkList pa = Pa->next;
    LinkList pb = Pb->next;
    polynomial result;
    InitList(result);
    LinkList tail = result;

    while (pa && pb)
    {
        int cmp = compare(pa->data, pb->data);
        if (cmp < 0)
        {
            AppendNode(tail, pa->data, tail);
            pa = pa->next;
        }
        else if (cmp > 0)
        {
            AppendNode(tail, pb->data, tail);
            pb = pb->next;
        }
        else
        {
            ElemType e;
            e.coef = pa->data.coef + pb->data.coef;
            e.expn = pa->data.expn;
            if (e.coef != 0)
                AppendNode(tail, e, tail);
            pa = pa->next;
            pb = pb->next;
        }
    }
    while (pa)
    {
        AppendNode(tail, pa->data, tail);
        pa = pa->next;
    }
    while (pb)
    {
        AppendNode(tail, pb->data, tail);
        pb = pb->next;
    }

    DestroyList(Pa);
    Pa = result;
}

void MultiplyPolyn(polynomial &Pa, polynomial &Pb)
{
    polynomial result;
    InitList(result);

    LinkList pa = Pa->next;
    while (pa)
    {
        LinkList pb = Pb->next;
        while (pb)
        {
            ElemType e;
            e.coef = pa->data.coef * pb->data.coef;
            e.expn = pa->data.expn + pb->data.expn;
            OrderInsert(result, e, compare);
            pb = pb->next;
        }
        pa = pa->next;
    }

    DestroyList(Pa);
    Pa = result;
}
