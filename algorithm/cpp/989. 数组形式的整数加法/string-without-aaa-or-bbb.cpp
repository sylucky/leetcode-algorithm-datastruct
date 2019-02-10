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

        //A和K反转
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
        
        if (signal == 1)
        result.push_back(signal);

        std::reverse(result.begin(),result.end());

        return result;
    }
};