//* 分离链接法散列表

#define KEYLENGTH 15                     //* 关键词字符串的长度不超过 15
typedef char ElementType[KEYLENGTH + 1]; //* 关键词类型用字符串

typedef unsigned int Index;
#ifndef _HashSep_H
#define _HashSep_H

struct ListNode;
typedef struct ListNode *Position, *List;
struct HashTbl;
typedef struct HashTbl *HashTable;

#define MinTableSize (10)
struct ListNode
{
    ElementType Element;
    unsigned short Times; //词频统计
    Position Next;
};
//*  为了简单起见，单链表的头结点就是散列表数组元素
struct HashTbl
{
    public:
    HashTbl(int TableSize);
    Position Find(ElementType Key);
    void InsertAndCount(ElementType Key);
    void DestroyTable();

    private:
    HashTable InitializeTable(int TableSize);
    int TableSize;
    List TheLists;
};

#endif
