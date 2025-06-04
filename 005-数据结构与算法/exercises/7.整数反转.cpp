/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
// #include <math.h>
// #include "../stack/array_stack.hpp"
class Solution
{
public:
    int reverse(int x)
    {
        long result = 0;
        while (x != 0)
        {
            result = result * 10 + x % 10;
            x /= 10;
        }
        return (result > INT_MAX || result < INT_MIN) ? 0 : result;
    }
    /*
    int reverse1(int x)
    {
        ArrayStack<int> stack;
        int f = x < 0 ? -1 : 1;
        int i = 0;
        for (int i = 0; ((x / pow(10, i)) > 0); i++)
        {
            int tmp = (x / int(pow(10, i))) % 10;
            stack.push(tmp);
        }
        int d = 0;
        int len = stack.size;
        while (!stack.isEmpty())
        {
            int temp = stack.pop();
            d += temp * pow(10, --len);
        }

        return f * d;
    }*/
};
// @lc code=end
