#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student {
    long long int sno;
    char sname[8];
    int score;
}datatype;

typedef struct Node {
    datatype data;
    struct Node *next;
}LinkList;

LinkList *create_linklist();                                                // 创建链表
void insert_tail(LinkList *L, datatype e);                                  // 添加学生信息
void stu_inf(LinkList *L);                                                  // 遍历学生信息
void insert_inf(LinkList *L, int pos, datatype e);                          // 指定位置插入信息
void delete_inf_pos(LinkList *L, int pos);                                  // 指定位置删除信息  
void delete_inf_score(LinkList *L, int score);                              // 根据成绩删除信息
void delete_inf_sname(LinkList *L, char sname[8]);                          // 根据姓名删除信息
void update_inf(LinkList *L, long long int sno, char sname[8], int score);  // 根据学号修改信息
void save_inf(LinkList *L, const char *fileName);                           // 存入学生信息
void load_inf(LinkList *L, const char *fileName);                           // 读取学生信息

int main() {
    LinkList *L = create_linklist();
    const char *fileName = "student_info.txt";
    
    while(1) {
		printf("欢迎进入学生管理系统\n");
		printf("\t1.添加学生信息\n");
		printf("\t2.遍历学生信息\n");
		printf("\t3.指定位置插入信息\n");
		printf("\t4.指定位置删除信息\n");
		printf("\t5.根据成绩删除信息\n");
		printf("\t6.根据姓名删除信息\n");
        printf("\t7.根据学号修改信息\n");
        printf("\t8.存入学生信息\n");
        printf("\t9.读取学生信息\n");
		printf("\t0.退出学生管理系统\n");
		printf("\t请填写数字以选择相应功能：\n");
        printf("------------------------------------------------------\n");

        int num;
        scanf("%d", &num);
        getchar();
        switch (num)
        {
        case 1:     // 添加学生信息
            {
                datatype e;

				printf("请输入学生学号：\n");
				scanf("%lld",&e.sno);
				printf("请输入学生姓名：\n");
				scanf("%s",e.sname);
				printf("请输入学生成绩：\n");
                scanf("%d",&e.score);

                insert_tail(L, e);

                break;
            }
        case 2:     // 遍历学生信息
            stu_inf(L);
            break;
        case 3:     // 指定位置插入信息
            {
                int pos;
                datatype e;

                printf("请输入插入的位置\n");
                scanf("%d",&pos);
				printf("请输入学生学号：\n");
				scanf("%d",&e.sno);
				printf("请输入学生姓名：\n");
				scanf("%s",e.sname);
				printf("请输入学生成绩：\n");
                scanf("%d",&e.score);

                insert_inf(L, pos, e);

                break;
            }
        case 4:     // 指定位置删除信息 
            {
                int pos;
                datatype e;

                printf("请输入删除的位置：\n");
                scanf("%d",&pos);

                delete_inf_pos(L, pos);

                break;
            }
        case 5:     // 根据成绩删除信息
            {
                int score;

                printf("请输入删除信息的学生成绩：\n");
                scanf("%d",&score);

                delete_inf_score(L, score);

                break;
            }
        case 6:     // 根据姓名删除信息
            {
                char sname[8];

                printf("请输入删除信息的学生姓名：\n");
                scanf("%s",sname);

                delete_inf_sname(L, sname);

                break;
            }
        case 7:     // 根据学号修改信息
            {
                char sname[8];
                long long int sno,score;

                printf("请输入要修改的学生学号：\n");
                scanf("%lld",&sno);
                printf("请输入修改为的姓名：\n");
                scanf("%s",sname);
                printf("请输入修改为的成绩：\n");
                scanf("%d",&score);

                update_inf(L, sno, sname , score);

                break;
            }
        case 8:
            {
                save_inf(L, fileName);
                break;
            }
        case 9:
            {
                load_inf(L, fileName);
                break;
            }
        case 0:     // 退出
            {
                printf("退出成功\n");
                exit(0);
                break;
            }
        default:
            printf("请输入正确数字\n");
            printf("\n");
            break;
        }
    }
    return 0;
}


void insert_tail(LinkList *L, datatype e) {      // 插入学生信息
    LinkList *p = (LinkList *)malloc(sizeof(LinkList));
    p->data = e;
    p->next = NULL;

    LinkList *q = L;
    while(q->next != NULL) {
        q = q->next;
    }
    q->next = p;

    printf("添加成功\n");
    return;
}

void insert_inf(LinkList *L, int pos, datatype e) {     // 指定位置插入信息
    if(pos < 1) {
        printf("请输入正确的序号\n");
        return;
    }

    LinkList *q = L;       
    for(int i = 0;i < pos;i++) {
        if(q == NULL) {
            printf("超出存有的信息数量\n");
            return;
        }
        q = q->next;
    }

    LinkList *p = (LinkList *)malloc(sizeof(LinkList));
    p->data = e;
    p->next = q->next;
    q->next = p;

    printf("添加成功\n");
    
    return;
}

void delete_inf_pos(LinkList *L, int pos) {     // 指定位置删除信息
    if(pos < 1) {
        printf("请输入正确的序号\n");
        return;
    }

    LinkList *q = L;       
    for(int i = 1;i < pos;i++) {
        if(q == NULL) {
            printf("超出存有的信息数量\n");
            return;
        }
        q = q->next;
    }

    LinkList *p = q->next;
    q->next = p->next;
    free(p);
    p = NULL;

    printf("删除成功\n");
    printf("\n");

    return;
}

int list_empty(LinkList *L) {       // 判断链表是否为空
    if(L->next == NULL) return 1;
    return 0;
}

void delete_inf_score(LinkList *L, int score) {     // 根据成绩删除信息
    if(list_empty(L)) {
        printf("链表为空\n");
        return;
    }

    LinkList *q = L;
    while(q->next != NULL && q->next->data.score != score) {
        q = q->next;
    }

    if(q->next == NULL) {
        printf("没有找到符合条件的信息\n");
        printf("\n");
        return;
    }
    else{
        LinkList *p = q->next;
        q->next = p->next;
        free(p);
        p = NULL;

        printf("删除成功\n");
        printf("\n");
    }
    
    return;
}

void delete_inf_sname(LinkList *L, char sname[8]) {     // 根据姓名删除信息
    if(list_empty(L)) {
        printf("链表为空\n");
        return;
    }

    LinkList *q = L;
    while(q->next != NULL && strcmp(q->next->data.sname, sname)) {
        q = q->next;
    }

    if(q->next == NULL) {
        printf("没有找到符合条件的信息\n");
        printf("\n");
        return;
    }
    else{
        LinkList *p = q->next;
        q->next = p->next;
        free(p);
        p = NULL;

        printf("删除成功\n");
        printf("\n");
    }
    
    return;
}

void update_inf(LinkList *L, long long int sno, char sname[8], int score) {       // 根据学号修改信息
    if(list_empty(L)) {
        printf("链表为空\n");
        return;
    }

    LinkList *q = L;
    while(q->next != NULL && q->data.sno != sno) {
        q = q->next;
    }

    if(q == NULL) {
        printf("没有找到符合条件的信息\n");
        printf("\n");
        return;
    }
    else{
        strcpy(q->data.sname, sname);
        q->data.score = score;

        printf("修改成功\n");
        printf("\n");
    }

    return;
}

void stu_inf(LinkList *L) {     // 遍历学生信息
    if(list_empty(L)) {
        printf("链表为空\n");
        return;
    }

    printf("查询学生信息\n");
    printf("\n");

    LinkList *p = L->next;
    int len = 0;
    while(p != NULL) {
        printf("学生学号：%lld\t",p->data.sno);
        printf("学生姓名：%s\t",p->data.sname);
        printf("学生成绩：%d\t",p->data.score);
        printf("\n");
        p = p->next;
        len++;
    }

    printf("\n");
    printf("共%d条信息\n",len);
    printf("\n");

    return;
}

void save_inf(LinkList *L, const char *fileName) {      // 存入学生信息
    FILE *file = fopen(fileName, "w");

    if(file == NULL) {
        printf("无法打开文件 %s\n", fileName);
        return;
    }

    if(list_empty(L)) {
        printf("链表为空\n");
        fclose(file);
        return;
    }

    printf("存入信息：\n");
    LinkList *p = L->next;
    while(p != NULL) {
        printf("学号：%lld 姓名：%s 成绩：%d\n", p->data.sno, p->data.sname, p->data.score);

        fprintf(file, "%lld %s %d\n", p->data.sno, p->data.sname, p->data.score);
        p = p->next;
    }

    fclose(file);
    printf("学生信息已保存到 %s\n", fileName);
    printf("\n");

    return;
}

void load_inf(LinkList *L, const char *fileName) {      // 读取学生信息
    FILE *file = fopen(fileName, "r");

    if(file == NULL) {
        printf("无法打开文件 %s\n", fileName);
        return;
    }

    LinkList *p = L->next;
    printf("从文件 %s 读取的学生信息:\n", fileName);

    datatype e;
    while(fscanf(file, "%lld %s %d", &e.sno, e.sname, &e.score) != EOF) {
        insert_tail(L, e);
    }

    fclose(file);

    return;
}

LinkList *create_linklist() {       // 创建链表
    LinkList *L = (LinkList *)malloc(sizeof(LinkList));
    if(L == NULL){
        printf("创建失败\n");
        return NULL;
    }

    L->next = NULL;

    return L;
}