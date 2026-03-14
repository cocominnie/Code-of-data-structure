#include "triplet.hpp"

Status InitTriplet(Triplet &T, int v1, int v2, int v3){
    T = (int*)malloc(3 * sizeof(int));
    if(!T) {
        exit(-2);
    }
    T[0] = v1;
    T[1] = v2;
    T[2] = v3;
    return OK;
}

Status DestroyTriplet(Triplet &T){
    free(T);
    T = NULL;
    return OK;
}

Status Get(Triplet T, int i, int &e){
    if(i < 1 || i > 3) {
        return ERROR;
    }
    e = T[i - 1];
    return OK;
}

Status Put(Triplet &T, int i, int e){
    if(i<1 || i>3){
        return ERROR;
    }
    T[i-1] = e;
    return OK;
}

Status IsAscending(Triplet T){
    return(T[0]<=T[1] && T[1]<=T[2]);
}

Status IsDescending(Triplet T){
    return(T[0]>=T[1] && T[1]>=T[2]);
}

Status Max(Triplet T, int &e){
    e = (T[0] > T[1]) ? ((T[0] > T[2]) ? T[0] : T[2]) : ((T[1] > T[2]) ? T[1] : T[2]);
    return OK;
}

Status Min(Triplet T, int &e){
    e = (T[0] < T[1]) ? ((T[0] < T[2]) ? T[0] : T[2]) : ((T[1] < T[2]) ? T[1] : T[2]);
    return OK;
}