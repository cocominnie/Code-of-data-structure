#ifndef triplet_h
#define triplet_h

#include <iostream>

using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int * Triplet;

Status InitTriplet(Triplet &T, int v1, int v2, int v3);

Status DestroyTriplet(Triplet &T);

Status Get(Triplet T, int i, int &e);

Status Put(Triplet &T, int i, int e);

Status IsAscending(Triplet T);

Status IsDescending(Triplet T);

Status Max(Triplet T, int &e);

Status Min(Triplet T, int &e);

#endif