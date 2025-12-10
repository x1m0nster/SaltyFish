#ifndef SEQLIST.h
#define SEQLIST.h

#include"common.h"

typedef struct{
    ElemType* data;
    int length;
    int Maxsize;
}Seqlist;

bool Initlist(Seqlist*L,int Initsize);

bool InsertData(Seqlist*L,int pos,int data);

#endif