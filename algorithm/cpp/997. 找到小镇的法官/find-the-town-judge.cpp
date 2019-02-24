class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int result = -1;
        int len = trust.size();
        set<int> A;
        
        //边界值判定
        if (N == 1)
            return 1;

        //遍历把每个人都当法官
        for (int i = 1; i <= N; i++)
        {
            A.clear();
            //遍历trust数组
            for (int j = 0;j<len;j++)
            {
                //法官不相信任何人
                if (trust[j][0] == i)
                {
                    result = -1;
                    break;
                }

                //每个人相信法官，去重插入set
                if (trust[j][1] == i)
                    A.insert(trust[j][0]);

                //满足N-1个人相信法官
                if (A.size() == N - 1)
                    result = i;
            }
            if (result != -1)
                return result;
            
        }

        return result;
    }
};