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