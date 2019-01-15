# 974. 和可被 K 整除的子数组

[leetcode题目链接](https://leetcode-cn.com/contest/weekly-contest-119/problems/subarray-sums-divisible-by-k/)

给定一个整数数组 A，返回其中元素之和可被 K 整除的（连续、非空）子数组的数目。

 

示例：

    输入：A = [4,5,0,-2,-3,1], K = 5
    输出：7
    解释：
    有 7 个子数组满足其元素之和可被 K = 5 整除：
    [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
 

提示：

    1 <= A.length <= 30000
    -10000 <= A[i] <= 10000
    2 <= K <= 10000

## 解答思路：

 * 暴力法：循环实现，效率太低
 * 计算A从下标0到i的元素之和，存储到一个容器sum中（数组或其他）
 * sum对K求余，按余数统计出现次数，结果存储到容器count中
 * 算法，count相同下标的计数器有n*(n-1)/2个子数组
 * 相比于暴力法，少了很多数组相加的操作，而且优化了A大部分值一样的算法

cpp代码--暴力法：

    ////暴力法：循环实现，效率太低
    int Solution::subarraysDivByK(vector<int>& A, int K)
    {
        int sum=0;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = i; j < A.size(); j++)
            {
                sum = 0;
                for (int k = i; k < j + 1; k++)
                {
                    sum += A[k];
                }
                if (sum%K == 0)
                    result++;
            }
        }
        return result;
    }

cpp代码--数组实现：

    int Solution::subarraysDivByK(vector<int>& A, int K)
    {
        //数组做容器
        int result = 0;

        int N = A.size();
        int *P = new int[N + 1];
        P[0] = 0;
        for (int i = 0; i < N; ++i)
        {
            P[i + 1] = P[i] + A[i];
            cout << P[i + 1] << endl;
        }

        int* count = new int[K];
        for (int i = 0; i < K; i++)
        {
            count[i] = 0;
        }
        for (int i = 0; i < N + 1; i++)
            count[(P[i] % K + K) % K]++;

        for (int i = 0; i < K; i++)
        {
            cout << i << "," << count[i] << endl;
            result += count[i] * (count[i] - 1) / 2;
        }
        return result;
    }

cpp代码--vector与map容器实现：

    int Solution::subarraysDivByK(vector<int>& A, int K)
    {
        //使用vector和map做容器
        int result = 0;
        //边界值
        if (A.size() == 0)
            return 0;

        vector<int> sum;//数组存储从下标0到下标i的值之和
        sum.resize(A.size() + 1);
        sum[0] = 0;
        for (int i = 0; i < A.size(); i++)
        {
            sum[i + 1] = sum[i] + A[i];
        }

        cout << "vector:";
        for (auto& e : sum)
        {
            cout << e << "\t";
        }
        cout << endl;

        //vector<vector<int>> count(sum.size());//下标为对K求余的值，值为计数器
        map<int, int> count;
        for (int i = 0; i < sum.size(); i++)
        {
            count[(sum[i] % K + K) % K] ++;//int值为负的处理
        }

        cout << "count:";
        for (auto& e : count)
        {
            cout << e.first << "," << e.second << "\t";
        }
        cout << endl;

        //算法，count相同下标的计数器有n*(n-1)/2个子数组
        //相比于暴力法，少了很多数组相加的操作，而且优化了A大部分值一样的算法
        for (auto& e : count)
        {
            result += e.second * (e.second - 1) / 2;
        }
    }