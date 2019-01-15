int Solution::subarraysDivByK(vector<int>& A, int K)
{
    //数组做容器
    if(1==0)
    {
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

    ////暴力法：循环实现，效率太低
    if (2 == 0)
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
    }

    return result;
}