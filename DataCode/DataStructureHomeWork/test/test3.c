// 存储迷宫坐标
typedef struct{
    int x, y;
} Position;
// 顺序栈结构，存放路径坐标
typedef struct{
    Position data[MAXSIZE];
    int top;
} Stack;
// 初始化栈
void InitStack (Stack *s){
    s->top = -1;
}
// 判断栈是否为空
int Empty (Stack *s){
    return s->top == -1;
}
// 坐标入栈
void Push (Stack *s, Position p){
    s->data[++s->top] = p;
}
// 栈顶元素出栈
Position Pop (Stack *s){
    return s->data[s->top--];
}
// 获取栈顶元素，不出栈
Position GetTop (Stack *s){
    return s->data[s->top];
}