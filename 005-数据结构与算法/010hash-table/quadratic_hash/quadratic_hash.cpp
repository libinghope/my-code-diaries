#include "quadratic_hash.h"
#include "../hash/hash.h"

HashTbl::HashTbl(int TableSize){
    InitializeTable(TableSize);
}
HashTable HashTbl::InitializeTable(int TableSize)
{
    int i;

    if (TableSize < MinTableSize)
        throw("散列表太小");

    this->TableSize = NextPrime(TableSize);

    this->TheCells = new Cell[sizeof(Cell) * this->TableSize];
    if (this->TheCells == nullptr)
        throw("空间溢出!!!");

    for (i = 0; i < this->TableSize; i++)
        this->TheCells[i].Info = Empty;

    return H;
}

Position HashTbl::Find(ElementType Key)
{
    Position CurrentPos, NewPos;
    int CNum; //!记录冲突次数

    CNum = 0;
    NewPos = CurrentPos = Hash(Key, this->TableSize);
    while (this->TheCells[NewPos].Info != Empty && this->TheCells[NewPos].Element != Key)
    {
        //字符串类型的关键词需要 strcmp 函数进行对比!!
        if (++CNum % 2)
        { //*判断冲突的奇偶次
            NewPos = CurrentPos + (CNum + 1) / 2 * (CNum + 1) / 2;
            while (NewPos >= this->TableSize)
                NewPos -= this->TableSize;
        }
        else
        {
            NewPos = CurrentPos - CNum / 2 * CNum / 2;
            while (NewPos < 0)
                NewPos += this->TableSize;
        }
    }
    return NewPos;
}

void HashTbl::Insert(ElementType Key)
{
    Position Pos;

    Pos = Find(Key);
    if (this->TheCells[Pos].Info != Legitimate)
    {
        /* 确认在此插入 */
        this->TheCells[Pos].Info = Legitimate;
        this->TheCells[Pos].Element = Key;
    }
}
