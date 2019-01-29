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