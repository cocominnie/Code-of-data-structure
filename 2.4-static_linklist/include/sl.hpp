#pragma once
#define SqList_h

#include <iostream>

using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

#define MaxSize 1000

typedef struct
{
    int data;
    int cur;
} component, SLinkList[MaxSize];

int LocateElem_SL(SLinkList S, int e);

void InitSpace_SL(SLinkList &space);

int Malloc_SL(SLinkList &space);

void Free_SL(SLinkList &space, int k);

void difference(SLinkList &space, int &S);