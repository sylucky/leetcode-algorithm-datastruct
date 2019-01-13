# 976. 三角形的最大周长

[leetcode题目链接](https://leetcode-cn.com/contest/weekly-contest-119/problems/largest-perimeter-triangle/)

给定由一些正数（代表长度）组成的数组 A，返回由其中三个长度组成的、面积不为零的三角形的最大周长。

如果不能形成任何面积不为零的三角形，返回 0。

 示例 1：

    输入：[2,1,2]
    输出：5
示例 2：

    输入：[1,2,1]
    输出：0
示例 3：

    输入：[3,2,3,4]
    输出：10
示例 4：

    输入：[3,6,2,3]
    输出：8
 

提示：

    3 <= A.length <= 10000
    1 <= A[i] <= 10^6

## 解答思路：

 * 满足N>3
 * 任意两边和大于第三边，且长度大于0
 * 取最大值
 * 贪婪算法和动态规划

cpp代码：

    class Solution {
    public:
        int largestPerimeter(vector<int>& A) {
            int result = 0;
            //先排序
            sort(A.rbegin(), A.rend());

            //边界值处理
            if (A.size() < 3)
                return 0;

            cout << endl;
            //再用贪婪算法，动态规划
            //三角形两边
            auto left = A.begin();
            auto right = A.begin();
            for (int i = 0; i < A.size()-2; i++)    //三角形的底
            {
                left = A.begin();
                left += (i+1);
                right = left+1;
                
                while (left != A.end()-1 || right != A.end())
                {
                    if (left == right)
                    {
                        right++;
                        continue;
                    }

                    //三角形的两条边，满足>0，并且两边和>A[i]
                    if (*left > 0 && *right > 0 && (*left + *right) > A[i])
                    {
                        int temp = *left + *right + A[i];
                        result = (result > temp) ? result : temp;
                    }

                    left++;
                }
            }

            return result;
            
        }
    };