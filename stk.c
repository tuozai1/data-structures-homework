#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXSIZE = 1024;

typedef int DataType;
typedef struct {
    DataType data[MAXSIZE];
    int top;
}SeqStack;

SeqStack *intSeqStack();                                          // 创建栈
int empty(SeqStack *s);                                           // 栈判空
int stk_push(SeqStack *s, DataType x);                            // 入栈
int stk_pop(SeqStack *s);                                         // 出栈
DataType get_top(SeqStack *s);                                    // 访问栈顶元素
void transform(SeqStack *s, int inputnum, int outnum, char *num); // 进制转换

int main() {
    SeqStack *s = intSeqStack();
    char num[MAXSIZE];
    int inputnum, outnum;

    printf("请输入要转换的数：\n");
    scanf("%s",num);
    printf("请输入输入进制：\n");
    scanf("%d",&inputnum);
    printf("请输入输出进制：\n");
    scanf("%d",&outnum);

    transform(s, inputnum, outnum, num);

    return 0;
}

SeqStack *intSeqStack() {
    SeqStack *s;
    s = (SeqStack *)malloc(sizeof(SeqStack));
    s->top = -1;

    return s;
}

int empty(SeqStack *s) {
    if(s->top == -1) return 1;
    return 0;
}

int stk_pop(SeqStack *s) {
    if(empty(s)) return 0;

    s->top--;
    return 1;
}

int stk_push(SeqStack *s, DataType x) {
    if(s->top == MAXSIZE - 1) {
        return 0;
    }

    s->top++;
    s->data[s->top] = x;
    
    return 1;
}

int get_top(SeqStack *s) {
    if(empty(s)) {
        return -1;
    }

    return (s->data[s->top]);
}

void transform(SeqStack *s, int inputnum, int outnum, char *num) {
    int res = 0;

    for(int i = 0; i < strlen(num); i++) {
        int digit = num[i] - '0';
        if(digit >= 10 && digit <= 35 ) digit = num[i] - 'A' + 10;
        else if(digit >= 36) digit = num[i] - 'a' + 36;

        if(digit >= inputnum) {
            printf("输入数不合法\n");
            return;
        }

        res = res * inputnum + digit;
    }

    while(res) {
        stk_push(s, res % outnum);
        res /= outnum;
    }

    printf("转换结果是：\n");
    while(!empty(s)) {
        int ans = get_top(s);
        if(stk_pop(s)) {
            if(ans <= 9) printf("%d",ans);
            else if(ans >= 10 && ans <= 35) printf("%c",ans + 'A' - 10);
            else printf("%c",ans + 'a' - 36);
        }
    }

    printf("\n");
}