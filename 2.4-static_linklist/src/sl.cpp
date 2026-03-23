#include "sl.hpp"

int LocateElem_SL(SLinkList S, int e)
{
    int i = S[0].cur;
    while (i && S[i].data != e)
        i = S[i].cur;
    return i;
}

void InitSpace_SL(SLinkList &space)
{
    int i;
    for (i = 0; i < MaxSize - 1; ++i)
        space[i].cur = i + 1;
    space[MaxSize - 1].cur = 0;
}

int Malloc_SL(SLinkList &space)
{
    int i = space[0].cur;
    if (space[0].cur)
        space[0].cur = space[i].cur;
    return i;
}

void Free_SL(SLinkList &space, int k)
{
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

void difference(SLinkList &space, int &S)
{
    int i, j;
    InitSpace_SL(space);
    S = Malloc_SL(space);
    int r = S;
    int m, n;
    cout << "please input the number of elements in set A: ";
    scanf("%d", &m);
    cout << "please input the number of elements in set B: ";
    scanf("%d", &n);
    for (j = 1; j <= m; ++j)
    {
        i = Malloc_SL(space);
        cout << "please input the " << j << "th element of set A: ";
        scanf("%d", &space[i].data);
        space[r].cur = i;
        r = i;
    }
    space[r].cur = 0;
    int b, p, k;
    for (j = 1; j <= n; ++j)
    {
        cout << "please input the " << j << "th element of set B: ";
        scanf("%d", &b);
        p = S;
        k = space[S].cur;
        while (k != space[r].cur && space[k].data != b)
        {
            p = k;
            k = space[k].cur;
        }
        if (k == space[r].cur)
        {
            i = Malloc_SL(space);
            space[i].data = b;
            space[i].cur = space[r].cur;
            space[r].cur = i;
            r = i;
        }
        else
        {
            space[p].cur = space[k].cur;
            Free_SL(space, k);
            if (k == r)
                r = p;
        }
    }
}