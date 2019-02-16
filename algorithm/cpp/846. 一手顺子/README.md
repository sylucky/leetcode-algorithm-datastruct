# 846. 一手顺子

[leetcode题目链接](https://leetcode-cn.com/contest/weekly-contest-87/problems/hand-of-straights/)

爱丽丝有一手（hand）由整数数组给定的牌。 

现在她想把牌重新排列成组，使得每个组的大小都是 W，且由 W 张连续的牌组成。

如果她可以完成分组就返回 true，否则返回 false。

 

    示例 1：
    输入：hand = [1,2,3,6,2,3,4,7,8], W = 3
    输出：true
    解释：爱丽丝的手牌可以被重新排列为 [1,2,3]，[2,3,4]，[6,7,8]。

    示例 2：    
    输入：hand = [1,2,3,4,5], W = 4
    输出：false
    解释：爱丽丝的手牌无法被重新排列成几个大小为 4 的组。
 

提示：

    1 <= hand.length <= 10000
    0 <= hand[i] <= 10^9
    1 <= W <= hand.length

## 解答思路：

 * 先考虑边界值
 * 牌分组算法
 * 数组先排序，存入list数据结构
 * 算法： 1.初始化取list.begin()
 *       2.查询并删除满足条件的list节点
 *       3.list为空则返回true

cpp代码：

    bool searchAndRemoveList(list<int>& listHand, int val)
    {
        auto it = listHand.begin();
        for(;it!=listHand.end();it++)
        {
            if (*it == val)
            {
                listHand.erase(it);
                //listHand.pop_front();
                return true;
            }
        }
    
        return false;
    }
    
    bool Solution::isNStraightHand(vector<int>& hand, int W)
    {
        bool result = false;
    
        //边界值
        if (hand.size() == 0)
            return false;
    
        if (W == 1)
            return true;
    
        //hand.size是W的整数倍
        if (hand.size() % W != 0)
            return false;
    
        //牌分组算法
        //先排序，存入list应该比较高效
        list<int> listHand;
    
        sort(hand.begin(), hand.end());
        for (auto& e : hand)
        {
            listHand.push_back(e);
        }
    
        int lastVal = 0;
        int len = 0;
    
        while (!listHand.empty())
        {
            for (auto &e : listHand)
                cout << e << "\t";
            cout << endl;
    
            //首位初始化
            if (len == 0)
            {
                lastVal = *listHand.begin();
                len++;
                listHand.pop_front();
                continue;
            }
    
            if (searchAndRemoveList(listHand, lastVal + 1) == false)
                return false;
    
            len++;
            lastVal++;
    
            if (len == W)
            {
                len = 0;
            }
        }
    
        return true;
    }