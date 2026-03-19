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

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int Status;

typedef struct
{
    int *elem;
    int length;
    int listsize;
} SqList;

Status InitList_Sq(SqList &L);

Status ListInsert_Sq(SqList &L, int i, int e);

Status ListDelete_Sq(SqList &L, int i, int &e);

Status compare(int a, int b);

int LocateElem_Sq(SqList L, int e, Status (*compare)(int, int));

void MergeList_Sq(SqList La, SqList Lb, SqList &Lc);