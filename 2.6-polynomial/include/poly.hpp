#pragma once
#define Poly_h

#include <iostream>

using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

typedef struct
{
    float coef; // 系数
    int expn;   // 指数
} ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node, *LinkList;

typedef LinkList polynomial;

void InitList(polynomial &L);

LinkList GetHead(polynomial L);

void SetCurElem(LinkList p, ElemType e);

ElemType GetCurElem(LinkList p);

int compare(ElemType a, ElemType b);

Status LocateElem(LinkList L, ElemType e, int (*compare)(ElemType, ElemType));

Status OrderInsert(LinkList &L, ElemType e, int (*compare)(ElemType, ElemType));

void CreatePolyn(polynomial &L, int m);

void CopyPolyn(polynomial src, polynomial &dest);

void DestroyList(polynomial &L);

void PrintPolyn(polynomial L);

void AddPolyn(polynomial &Pa, polynomial &Pb);

void MultiplyPolyn(polynomial &Pa, polynomial &Pb);
