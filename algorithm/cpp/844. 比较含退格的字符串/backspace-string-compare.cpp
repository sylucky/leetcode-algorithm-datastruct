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