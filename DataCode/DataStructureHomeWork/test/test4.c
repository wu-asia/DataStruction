// 删除员工
void Delete(){
    int id;
    printf("请输入要删除的工号：");
    scanf("%d", &id);
    int pos = Search(id);
    if(pos == -1){
        printf("员工不存在！\n");
        return;
    }
    HashTable[pos].state = 2;
    printf("删除成功！\n");
}