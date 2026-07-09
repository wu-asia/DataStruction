Polynomial add(Polynomial A, Polynomial B){
    Polynomial C = NULL;
    Node *p = A;
    while (p){
        insert(&C, p->coef, p->exp);
        p = p->next;
    }
    p = B;
    while (p){
        insert(&C, p->coef, p->exp);
        p = p->next;
    }
    return C;
}

// 多项式减法 A-B
Polynomial subtract(Polynomial A, Polynomial B){
    Polynomial C = NULL;
    Node *p = A;
    while (p){
        insert(&C, p->coef, p->exp);
        p = p->next;
    }
    p = B;
    while (p){
        insert(&C, -p->coef, p->exp);
        p = p->next;
    }
    return C;
}