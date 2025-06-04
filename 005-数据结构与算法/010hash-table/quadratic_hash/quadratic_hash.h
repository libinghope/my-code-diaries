//* 平方探测法散列表
#ifndef _HashQuad_H
#define _HashQuad_H

typedef int ElementType; //* 关键词类型用整型

typedef unsigned int Index; //* 散列地址类型
typedef Index Position;     //* 数据所在位置与散列地址是同一类型

struct HashTbl;
typedef struct HashTbl *HashTable;

#define MinTableSize (10)
enum EntryType
{
    Legitimate,
    Empty,
    Deleted
};

struct HashEntry
{
    ElementType Element;
    enum EntryType Info;
};

typedef struct HashEntry Cell;

struct HashTbl
{
    HashTbl(int TableSize);
    //初始化散列表
    HashTable InitializeTable(int TableSize);
    //查找指定key
    Position Find(ElementType Key);
    //插入数据
    void Insert(ElementType Key);

    ElementType Retrieve(Position P);

    HashTable Rehash();
    //省略了Delete 和 MakeEmpty 等函数

    HashTable H;
    int TableSize;
    Cell *TheCells;
    //* 单元 *TheCells 是一个数组，每个元素是 HashEntry*/
    //* 随后分配存储 */
};

#endif
