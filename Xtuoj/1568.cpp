#include <iostream>
#include <queue>
using namespace std;

// struct
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// insert
void insertNode(TreeNode*& root, int val) {
    if (root == NULL) {
        root = new TreeNode(val);
        return;
    }
    if (val < root->val) {
        insertNode(root->left, val);
    } else {
        insertNode(root->right, val);
    }
}

// check
bool isCompleteBST(TreeNode* root) {
    if (root == NULL) return true;
    
    queue<TreeNode*> q;
    q.push(root);
    bool reachedEnd = false;
    
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        
        if (curr == NULL) {
            reachedEnd = true;
        } else {
            if (reachedEnd) return false;
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    
    return true;
}

int main() {
    int t;scanf("%d",&t);
    while(t--){
    int n;scanf("%d",&n);
    int numbers[102] ;
    for(int i=0;i<n;i++)scanf("%d",&numbers[i]);
    TreeNode* root = NULL;
    // int size = sizeof(numbers) / sizeof(numbers[0]);
    for (int i = 0; i < n; ++i) {
        insertNode(root, numbers[i]);
    }
    
    if (isCompleteBST(root)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    }
    return 0;
}
