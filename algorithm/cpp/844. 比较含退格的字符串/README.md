# 844. 比较含退格的字符串

[leetcode题目链接](https://leetcode-cn.com/contest/weekly-contest-87/problems/backspace-string-compare/)

给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。

 

    示例 1：
    输入：S = "ab#c", T = "ad#c"
    输出：true
    解释：S 和 T 都会变成 “ac”。

    示例 2：    
    输入：S = "ab##", T = "c#d#"
    输出：true
    解释：S 和 T 都会变成 “”。

    示例 3：    
    输入：S = "a##c", T = "#a#c"
    输出：true
    解释：S 和 T 都会变成 “c”。

    示例 4：    
    输入：S = "a#c", T = "b"
    输出：false
    解释：S 会变成 “c”，但 T 仍然是 “b”。
 

提示：

    1 <= S.length <= 200
    1 <= T.length <= 200
    S 和 T 只含有小写字母以及字符 '#'。

## 解答思路：

 * 用栈数据结构，字符串按字符入栈，遇#出栈，最后结果比较
 * 算法： 1.数组入栈
 *       2.栈相等比较，长度相等，且每个元素相等

cpp代码：

    template <typename T>
    bool isSameStack(stack<T> s, stack<T> t)
    {
        //长度相等
        if (s.size() != t.size())
            return false;
    
        //逐个弹出栈中元素比较
        while (!s.empty())
        {
            if (s.top() != t.top())
            {
                return false;
            }
    
            s.pop();
            t.pop();
        }
        return true;
    }
    
    bool Solution::backspaceCompare(string S, string T)
    {
        //用栈的属性，字符串按字符入栈，遇#出栈，最后结果比较
        stack<char> s, t;
    
        //S入栈
        for (auto& e : S)
        {
            //cout << e << endl;
            if (e == '#')
            {
                if (!s.empty())
                {
                    s.pop();
                }
                continue;
            }
    
            s.push(e);
        }
    
        //T入栈
        for (auto& e : T)
        {
            //cout << e << endl;
            if (e == '#')
            {
                if (!t.empty())
                {
                    t.pop();
                }
                continue;
            }
    
            t.push(e);
        }
    
        //s与t比较
        return isSameStack(s, t);
    }