// 生成哈夫曼编码
void CreateCode(HTNode ht[], char HC[][MAXSIZE], int n){
    char code[MAXSIZE];
    for (int i = 1; i <= n; i++){
        int start = MAXSIZE - 1;
        code[start] = '\0';
        int c = i;
        int p = ht[c].parent;
        while (p){
            if (ht[p].lchild == c) code[--start] = '0';
            else code[--start] = '1';
            c = p; p = ht[c].parent;
        }
        strcpy(HC[i], &code[start]);
    }
}