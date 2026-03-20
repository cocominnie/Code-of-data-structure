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

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

Status GetElem_L(LinkList L, int i, int &e);

Status ListInsert_L(LinkList &L, int i, int e);

Status ListDelete_L(LinkList &L, int i, int &e);

void CreateList_L(LinkList &L, int n);

void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc);