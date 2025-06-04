/*
数组是最常用也是最简单的数据结构了
几乎所有的编程语言都支持，不再赘述
核心：连续分配的一段内存空间
*/

/* 简单的应用 数组 求解的例子
字母异位词: 判断t是否是s的异位词
示例例1输⼊入: s = "anagram", t = "nagaram"
输出: true示例例 2
输入: s = "rat", t = "car"
输出: false
提示:假设s,t中只有小写字母
*/
#define CHAR_NUM 26
#include <stdlib.h>
#include <string>
bool dystopy(char *s, char *t)
{
    //const int CHAR_NUM = 26;
    char sNum[CHAR_NUM] = {0};
    char tNum[CHAR_NUM] = {0};

    if (strlen(s) != strlen(t))
    {
        return false;
    }
    //两个单词长度相等,遍历两个数组
    for (int j = 0; j < strlen(s); j++)
    {
        sNum[int(s[j])]++;
        tNum[int(t[j])]++;
    }
    //比较字符出现的次数是否相等
    for (int k = 0; k < CHAR_NUM; k++)
    {
        if (sNum[k] != tNum[k])
            return false;
    }
    return true;
}
