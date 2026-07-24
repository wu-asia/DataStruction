// 建立哈夫曼树
void CreateHuffmanTree(HTNode ht[], char chars[], int freq[], int n){
    int m = 2 * n - 1;
    for (int i = 1; i <= m; i++){
        ht[i].parent = 0; ht[i].lchild = 0;
        ht[i].rchild = 0; ht[i].weight = 0;
        ht[i].ch = '\0';
    }

    for (int i = 1; i <= n; i++){
        ht[i].ch = chars[i - 1];
        ht[i].weight = freq[i - 1];
    }
    for (int i = n + 1; i <= m; i++){
        int s1, s2;
        Select(ht, i - 1, &s1, &s2);
        ht[s1].parent = i;
        ht[s2].parent = i;
        ht[i].lchild = s1;
        ht[i].rchild = s2;
        ht[i].weight = ht[s1].weight + ht[s2].weight;
    }
}