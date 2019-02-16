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