# 973. 最接近原点的 K 个点

[leetcode题目链接](https://leetcode-cn.com/contest/weekly-contest-119/problems/k-closest-points-to-origin/)

我们有一个由平面上的点组成的列表 points。需要从中找出 K 个距离原点 (0, 0) 最近的点。

（这里，平面上两点之间的距离是欧几里德距离。）

你可以按任何顺序返回答案。除了点坐标的顺序之外，答案确保是唯一的。

 示例 1：

    输入：points = [[1,3],[-2,2]], K = 1
    输出：[[-2,2]]
    解释： 
    (1, 3) 和原点之间的距离为 sqrt(10)，
    (-2, 2) 和原点之间的距离为 sqrt(8)，
    由于 sqrt(8) < sqrt(10)，(-2, 2) 离原点更近。
    我们只需要距离原点最近的 K = 1 个点，所以答案就是 [[-2,2]]。

示例 2：

    输入：points = [[3,3],[5,-1],[-2,4]], K = 2
    输出：[[3,3],[-2,4]]
    （答案 [[-2,4],[3,3]] 也会被接受。）
 

提示：

    1 <= K <= points.length <= 10000
    -10000 < points[i][0] < 10000
    -10000 < points[i][1] < 10000

## 解答思路：

 * 计算平方和再做二次方根，只需要比较平方和大小，所以可以简化为计算平方和
 * 上一步的结果存储到一个容器内，然后对容器的值排序（从小到大）
 * 输出前K个数

### 容器选用数组存放
sum[value,i]：把平方和的值作为数组第一个元素，方便排序，i为points的下标。

    vector<vector<int>> Solution::kClosest(vector<vector<int>>& points, int K)
    {
        vector<vector<int>> result;
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
            sum.push_back({ j, i++ });
        }
        sort(sum.begin(), sum.end());

        //返回前K个到result
        i = 0;
        while(i<K)
        {
            result.push_back(points[sum[i++][1]]);
        }
        return result;
    }
