# 845. 数组中的最长山脉

[leetcode题目链接](https://leetcode-cn.com/contest/weekly-contest-87/problems/longest-mountain-in-array/)

我们把数组 A 中符合下列属性的任意连续子数组 B 称为 “山脉”：

B.length >= 3
存在 0 < i < B.length - 1 使得 B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
（注意：B 可以是 A 的任意子数组，包括整个数组 A。）

给出一个整数数组 A，返回最长 “山脉” 的长度。

如果不含有 “山脉” 则返回 0。

 

    示例 1：
    输入：[2,1,4,7,3,2,5]
    输出：5
    解释：最长的 “山脉” 是 [1,4,7,3,2]，长度为 5。

    示例 2：    
    输入：[2,2,2]
    输出：0
    解释：不含 “山脉”。
 

提示：

    0 <= A.length <= 10000
    0 <= A[i] <= 10000

## 解答思路：

 * 不能用int,long做运算，会溢出
 * 可以用栈存储A，K的数组，依次出栈相加这样处理，也可以用数组反转的形式处理
 * 算法： 思路一：
        初始化设定数组开头是山顶，后面实现找山顶与计算山脉长度length，爬山长度up，下山长度down
        三种情况，1. A[i] == A[i-1] 则结果存入result，length清0，up清0，down清0
        三种情况，2. A[i] > A[i-1]，提高 up++
        三种情况，3. A[i] < A[i-1]，下降 则down++
        考虑山顶与山底的情况
        
        思路二：
        新建一个数组，连续上山-1，下山1，平地0累计计入数组B
        计算B[i]-B[i-1]的值最大

cpp代码：

    int Solution::longestMountain(vector<int>& A)
    {
        int result = 0;
    
        if (A.size()<3)
        {
            return result;
        }
        //思路一：
        //初始化设定数组开头是山顶，后面实现找山顶与计算山脉长度length，爬山长度up，下山长度down
        //三种情况，1. A[i] == A[i-1] 则结果存入result，length清0，up清0，down清0
        //三种情况，2. A[i] > A[i-1]，提高 up++
        //三种情况，3. A[i] < A[i-1]，下降 则down++
        //考虑山顶与山底的情况
        
        //思路二：
        //新建一个数组，连续上山-1，下山1，平地0累计计入数组B
        //计算B[i]-B[i-1]的值最大
        vector<int> B;
        int len =2;
        int oflag = -2;
        int nflag = -2;
    
        //初始化原上山、下山标志
        if (A[1] == A[0])
        {
            oflag = 0;
        }
        else if (A[1] > A[0])
        {
            oflag = -1;
        }
        else
        {
            oflag = 1;
        }
    
        //得出数组B
        for (int i=2;i<A.size();i++)
        {
            //平地
            if (A[i] == A[i - 1])
            {
                nflag = 0;
                if (oflag != nflag)
                {
                    B.push_back(len * oflag);
                    oflag = 0;
                    len = 1;
                }
            }
            //上山
            else if(A[i] > A[i - 1]) 
            {
                nflag = -1;
                if (oflag != nflag)
                {
                    B.push_back(len * oflag);
                    oflag = -1;
                    len = 1;
                }
            }
            //下山
            else
            {
                nflag = 1;
                if (oflag != nflag)
                {
                    B.push_back(len * oflag);
                    oflag = 1;
                    len = 1;
                }
            }
    
            len++;
        }
        B.push_back(len * oflag);
    
        for (auto& e : B)
        {
            cout << e << "\t";
        }
        cout << endl;
        //对数组B相邻元素求最大差
        for (int i = 1; i < B.size(); i++)
        {
            if (B[i] == 0 || B[i-1]==0)
                continue;
    
            len = B[i] - B[i - 1] -1;
            result = result > len ? result : len;
        }
    
        return result;
    }