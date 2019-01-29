# 984. 不含 AAA 或 BBB 的字符串

[leetcode题目链接](https://leetcode-cn.com/contest/weekly-contest-121/problems/string-without-aaa-or-bbb/)

给定两个整数 A 和 B，返回任意字符串 S，要求满足：

S 的长度为 A + B，且正好包含 A 个 'a' 字母与 B 个 'b' 字母；
子串 'aaa' 没有出现在 S 中；
子串 'bbb' 没有出现在 S 中。
 

示例 1：

    输入：A = 1, B = 2
    输出："abb"
    解释："abb", "bab" 和 "bba" 都是正确答案。
示例 2：

    输入：A = 4, B = 1
    输出："aabaa"
 

提示：

    0 <= A <= 100
    0 <= B <= 100
    对于给定的 A 和 B，保证存在满足要求的 S。

## 解答思路：

 * 满足不能三个连续字符
 * 得出A,B的大小，以下均以A大B小提供思路
 * 边界值处理，B为0或者A>2*B+2的情况
 * 算法：二元一次方程
 * 设共有 x 个 "ab"， y 个 "aab"
 * 则有 A = x + 2y;
        B = x + y;
 * 得出：
        y = A - B;
        x = 2B - A;

cpp代码：

    string Solution::strWithout3a3b(int A, int B)
    {
        string result="";

        //区分A,B大小
        int getmax = max(A, B);
        int maxval = 0, minval = 0;
        char maxchar = 0;
        char minchar = 0;

        if (getmax == A)
        {
            maxval = A;
            minval = B;
            maxchar = 'a';
            minchar = 'b';
        }
        else
        {
            maxval = B;
            minval = A;
            maxchar = 'b';
            minchar = 'a';
        }
        
        //边界值处理
        if (minval == 0)
        {
            if (maxval == 0 || maxval>2)
                ;
            else if (maxval == 1)
                result = "" + maxchar;
            else if (maxval == 2)
                result = "" + maxchar + maxchar;
            
            return result;
        }

        if (maxval >= (minval * 2))
        {
            int sum_char = maxval - (minval * 2);

            for (int i = 0; i < minval; i++)
            {
                result = result + maxchar + maxchar + minchar;
            }

            if (sum_char > 2)
                result = "";
            else if (sum_char == 1)
                result = result + maxchar;
            else if (sum_char == 2)
                result = result + maxchar + maxchar;

            return result;
        }

        /*算法：x 个 "ab"， y 个 "aab"
        A = x + 2y;
        B = x + y;
        y = A - B;
        x = 2B - A;
        */
        int x = 2 * minval - maxval;
        int y = maxval - minval;

        for (int i = 0; i < x; i++)
            result = result + maxchar + minchar;

        for (int i = 0; i < y; i++)
            result = result + maxchar + maxchar + minchar;

        return result;
    }