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

    //前置阶段
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
