// 查找
BSTNode* Search(BSTree root, char *word){
    if(root == NULL) return NULL;
    int cmp = strcmp(word, root->word);
    if(cmp == 0)
        return root;
    else if(cmp < 0)
        return Search(root->left, word);
    else
        return Search(root->right, word);
}