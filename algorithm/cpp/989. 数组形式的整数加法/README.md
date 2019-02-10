# 989. 数组形式的整数加法

[leetcode题目链接](https://leetcode-cn.com/contest/weekly-contest-123/problems/add-to-array-form-of-integer/)

对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。

给定非负整数 X 的数组形式 A，返回整数 X+K 的数组形式。

 

示例 1：

    输入：A = [1,2,0,0], K = 34
    输出：[1,2,3,4]
    解释：1200 + 34 = 1234
    解释 2：
    
    输入：A = [2,7,4], K = 181
    输出：[4,5,5]
    解释：274 + 181 = 455
    示例 3：
    
    输入：A = [2,1,5], K = 806
    输出：[1,0,2,1]
    解释：215 + 806 = 1021
    示例 4：
    
    输入：A = [9,9,9,9,9,9,9,9,9,9], K = 1
    输出：[1,0,0,0,0,0,0,0,0,0,0]
    解释：9999999999 + 1 = 10000000000
 

提示：

    1 <= A.length <= 10000
    0 <= A[i] <= 9
    0 <= K <= 10000
    如果 A.length > 1，那么 A[0] != 0

## 解答思路：

 * 不能用int,long做运算，会溢出
 * 可以用栈存储A，K的数组，依次出栈相加这样处理，也可以用数组反转的形式处理
 * 算法： 1.关注点，A与K数组长度不一致的处理
 *       2.符号进位问题，用一个变量存储
 *       3.两个数组相加结果数组变长的处理

cpp代码：

    class Solution {
    public:
        vector<int> addToArrayForm(vector<int>& A, int K) {
            //进位符
            int signal = 0;
            vector<int> result;
            vector<int> k;
    
            //边界值处理
            if (A.size() == 0)
                return result;
            if (K == 0)
                return A;
    
            //A和K反转，做运算
            std::reverse(A.begin(),A.end());
    
            int temp = K;
            while (temp >= 10)
            {
                k.push_back(temp % 10);
                temp = temp / 10;       
            }
            k.push_back(temp);
    
            //算法
            int mavValue = max(A.size(), k.size());
            temp = 0;
            for (int i = 0; i<mavValue; i++)
            {
                if (i >= A.size())
                {
                    temp = k[i] + signal;
                }
                else if (i >= k.size())
                {
                    temp = A[i] + signal;
                }
                else
                {
                    temp = A[i] + k[i] + signal;
                }
    
                if (temp > 9)
                {
                    temp %= 10;
                    signal = 1;
                }
                else
                {
                    signal = 0;
                }
                result.push_back(temp);
            }
            
            //如果循环结束，进位符仍为1，则增加结果数组一个字符
            if (signal == 1)
            result.push_back(signal);
    
            //字符反转为正常
            std::reverse(result.begin(),result.end());
    
            return result;
        }
    };