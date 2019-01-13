vector<vector<int>> Solution::kClosest(vector<vector<int>>& points, int K)
{
    vector<vector<int>> result;

    //防止平方和溢出
    vector<vector<int>> sum;

    //边界值处理
    if (points.size() < K)
        return result;
    else if (points.size() == K)
        return points;

    //计算平方和
    int i = 0;
    for (auto& elem : points)
    {
        long j = pow(elem[0],2) + pow(elem[1], 2);
        sum.push_back({ j, i });
        i++;
    }

    sort(sum.begin(), sum.end());

    cout << "sort sum:";
    for (auto elem : sum)
    {
        cout << elem[0] << "," << elem[1] << "\t";
    }
    cout << endl;

    //返回前K个到result
    i = 0;
    while(i<K)
    {
        result.push_back(points[sum[i++][1]]);
    }

    return result;
}
