#ifndef SEQLIST_H
#define SEQLIST_H

#include"common.h"

typedef struct{
    ElemType* data;
    int length;
    int Maxsize;
}Seqlist;

bool Seqlist_Init(Seqlist*L);

bool Seqlist_Insert(Seqlist*L,int pos,int data);

bool Seqlist_DeletePos(Seqlist*L,int pos,int*val);

bool Seqlist_DeleteVal(Seqlist*L,int val);

void Seqlist_GetPos(Seqlist*L,int pos);

void Seqlist_GetVal(Seqlist* L,int val);

bool Seqlist_Change(Seqlist* L,int newdata,int pos);

void Seqlist_Print(Seqlist* L);

void Seqlist_Drop(Seqlist* L);


#endif