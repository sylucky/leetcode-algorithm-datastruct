# 998. 最大二叉树 II

[leetcode题目链接](https://leetcode-cn.com/contest/weekly-contest-125/problems/maximum-binary-tree-ii/)

最大树定义：一个树，其中每个节点的值都大于其子树中的任何其他值。

给出最大树的根节点 root。

就像之前的问题那样，给定的树是从表 A（root = Construct(A)）递归地使用下述 Construct(A) 例程构造的：

如果 A 为空，返回 null
否则，令 A[i] 作为 A 的最大元素。创建一个值为 A[i] 的根节点 root
root 的左子树将被构建为 Construct([A[0], A[1], ..., A[i-1]])
root 的右子树将被构建为 Construct([A[i+1], A[i+2], ..., A[A.length - 1]])
返回 root
请注意，我们没有直接给定 A，只有一个根节点 root = Construct(A).

假设 B 是 A 的副本，并附加值 val。保证 B 中的值是不同的。

返回 Construct(B)。

 

示例 1：



    输入：root = [4,1,3,null,null,2], val = 5
    输出：[5,4,null,1,3,null,null,2]
    解释：A = [1,4,2,3], B = [1,4,2,3,5]
示例 2：


    输入：root = [5,2,4,null,1], val = 3
    输出：[5,2,4,null,1,null,3]
    解释：A = [2,1,5,4], B = [2,1,5,4,3]
示例 3：


    输入：root = [5,2,3,null,1], val = 4
    输出：[5,2,4,null,1,3]
    解释：A = [2,1,5,3], B = [2,1,5,3,4]
 

提示：

    1 <= B.length <= 100

## 解答思路：

 * 遍历root的右子树，满足条件则插入

cpp代码：

    /**
    * Definition for a binary tree node.
    * struct TreeNode {
    *     int val;
    *     TreeNode *left;
    *     TreeNode *right;
    *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    * };
    */
    TreeNode * Solution::insertIntoMaxTree(TreeNode * root, int val)
    {
        //新增父节点
        TreeNode dummy(INT_MAX);
        dummy.right = root;
    
        //前置节点
        TreeNode *pre = &dummy;
    
        //新插入节点
        TreeNode *x = new TreeNode(val);
    
        //遍历右节点
        for (TreeNode *cur = root; cur != NULL; cur = cur->right) {
    
            // val大于右节点的值，则插入Node，但是不改变原树指向
            if (val > cur->val) {
                x->left = cur;
                break;
            }
            // val小于节点的值，则记录位置
            else pre = cur;
        }
    
        //循环遍历结束，x指向应该指向的节点
        //x的前置节点未指向，前置节点已经赋值为pre
        pre->right = x;
        return dummy.right;
    }
