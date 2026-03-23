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

typedef struct DuLNode
{
    int data;
    struct DuLNode *prior;
    struct DuLNode *next;
} DuLNode, *DuLinkList;

Status ListInsert_DuL(DuLinkList &L, int i, int e);

Status ListDelete_DuL(DuLinkList &L, int i, int &e);