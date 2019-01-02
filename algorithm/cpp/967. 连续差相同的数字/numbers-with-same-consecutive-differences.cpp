class Solution {
public:

    struct TreeNode {
        int val;
        int level;
        TreeNode *p;
        TreeNode *left;
        TreeNode *right;
    };

    void dispTree(TreeNode* root,vector<int>* vec,int N,string str) {

        if (root == NULL)
            return;

        str = str + char(root->val+48);

        if (root->level == N) {
            //cout << "result:" <<root->p->p->val << root->p->val << root->val << endl;
            //cout << "str:" << str << endl;
            vec->push_back(atoi(str.c_str()));
            return;
        }

        dispTree(root->left,vec,N,str);
        dispTree(root->right,vec,N,str);
    }

    void createTree(TreeNode* root, int N, int K) {
        //cout << "val:" << root->val << ",level:" << root->level << endl;

        // N is max level
        if (root->level == N)
            return;

        if (root->val - K >= 0) {
            TreeNode *left = new TreeNode();
            left->p = root;
            root->left = left;
            root->left->val = root->val - K;
            root->left->level = root->level + 1;
            //cout << "生成左节点:" << "val:" << left->val << ",level:" << left->level << endl;
            createTree(root->left, N, K);
        }

        if (root->val + K <= 9) {
            TreeNode *right = new TreeNode();
            right->p = root;
            root->right = right;
            root->right->val = root->val + K;
            root->right->level = root->level + 1;
            //cout << "生成右节点:" << "val:" << right->val << ",level:" << right->level << endl;
            createTree(root->right, N, K);
        }

        return;
    }

    vector<int> numsSameConsecDiff(int N, int K) {
        //1.拆分数字为数组
        //int a[N];

        vector<int> vec;
        if (N<1)
            return vec;
        else if (N == 1) {
            if (K <= 9) {
                for (int i = 0; i<10; i++)
                    vec.push_back(i);
                return vec;
            }
            else
                return vec;
        }

        //所有可能的tree
        for(int i=1;i<=9;i++){
            TreeNode *root = new TreeNode();

            root->val = i;
            root->level = 1;
            createTree(root, N, K);
            //cout << "root->val:" << root->val << endl;
            //打印所有满足条件的tree
            if(root->val!=NULL)
                dispTree(root,&vec,N,"");

            delete root;
        }

        if (K == 0) {
            set<int> s;
            for (int e : vec) {
                s.insert(e);
            }
            vec.clear();
            for (int e : s) {
                vec.push_back(e);
            }
        }

        return vec;
    }
};