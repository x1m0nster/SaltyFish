#ifndef LINKLIST_H
#define LINKLIST_H

#include"common.h"

typedef struct node
{
    ElemType data;
    struct node* next;
    
}LNode,*Linklist;

bool Linklist_Init(Linklist* L);

LNode* Linklist_CreatLNode(ElemType data);

LNode* Linklist_GetPos(Linklist L,int pos,ElemType* data);

bool Linklist_InsertLNode(LNode* target,LNode* newLNode);//向指定节点 target 后方 插入 newLNode

bool Linklist_DeleteLNode(LNode* target);//将target 的下一个数据和指针给到他 然后删除他的下一个节点 变相等于删除target 但是对于最后一个节点就不好用了

bool Linklist_Insert(Linklist* L,int pos,ElemType data);

bool Linklist_DeletePos(Linklist* L,int pos,ElemType* data);

bool Linklist_DeleteVal(Linklist* L,ElemType val);

bool Linklist_Print(Linklist L);

bool Linklist_Drop(Linklist* L);

#endif
