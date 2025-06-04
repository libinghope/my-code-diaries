#include "linked_hash.h"
#include "../hash/hash.h"
#include <string>

HashTbl::HashTbl(int TableSize){
    InitializeTable(TableSize);
}

HashTable HashTbl::InitializeTable(int TableSize)
{
    int i;

    if (TableSize < MinTableSize)
    {
        throw("散列表太小");
    }

    //这里要获取>=TableSize的质数
    this->TableSize = NextPrime(TableSize);

    //分配表头数组
    this->TheLists = new ListNode[this->TableSize];
    if (this->TheLists == nullptr)
        throw("空间溢出!!!");

    /* 以下设置表头结点 */
    for (i = 0; i < this->TableSize; i++)
    {
        this->TheLists[i].Element[0] = '\0';
        this->TheLists[i].Times = 0; //* 单链表中结点数量
        this->TheLists[i].Next = nullptr;
    }
}

Position HashTbl::Find(ElementType Key)
{
    Position P;
    List L;

    L = &(this->TheLists[Hash(Key, this->TableSize)]);
    P = L->Next;
    while (P != 0 && strcmp(P->Element, Key))
        P = P->Next;

    return P;
}

void HashTbl::InsertAndCount(ElementType Key)
{
    Position Pos, NewCell;
    List L;

    Pos = Find(Key, H);
    if (Pos) //* 关键词找到
        Pos->Times++;
    else
    { //* 关键词未找到
        NewCell = new ListNode;
        if (NewCell == nullptr)
            throw("空间溢出!!!");
        else
        {
            L = &(this->TheLists[Hash(Key, this->TableSize)]);
            NewCell->Next = L->Next; //* 插入第一个结点
            L->Next = NewCell;
            strcpy(NewCell->Element, Key);
            NewCell->Times = 1;
            L->Times++; //* 头结点的Times表示该链表的长度，增1
        }
    }
}

void HashTbl::DestroyTable()
{
    int i;
    Position P, Tmp;

    for (i = 0; i < this->TableSize; i++)
    {
        P = this->TheLists[i].Next;
        while (P != NULL)
        {
            Tmp = P->Next;
            free(P);
            P = Tmp;
        }
    }

    delete[] this->TheLists;
}
