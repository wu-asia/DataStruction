// 插入
BSTree Insert(BSTree root, char *word){
    if(root == NULL)
        return CreateNode(word);
    int cmp = strcmp(word, root->word);
    if(cmp == 0)
        root->count++;
    else if(cmp < 0)
        root->left = Insert(root->left, word);
    else
        root->right = Insert(root->right, word);
    return root;
}