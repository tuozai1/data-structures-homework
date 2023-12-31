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

LinkList *create_linklist();                                                // ��������
void insert_tail(LinkList *L, datatype e);                                  // ���ѧ����Ϣ
void stu_inf(LinkList *L);                                                  // ����ѧ����Ϣ
void insert_inf(LinkList *L, int pos, datatype e);                          // ָ��λ�ò�����Ϣ
void delete_inf_pos(LinkList *L, int pos);                                  // ָ��λ��ɾ����Ϣ  
void delete_inf_score(LinkList *L, int score);                              // ���ݳɼ�ɾ����Ϣ
void delete_inf_sname(LinkList *L, char sname[8]);                          // ��������ɾ����Ϣ
void update_inf(LinkList *L, long long int sno, char sname[8], int score);  // ����ѧ���޸���Ϣ
void save_inf(LinkList *L, const char *fileName);                           // ����ѧ����Ϣ
void load_inf(LinkList *L, const char *fileName);                           // ��ȡѧ����Ϣ

int main() {
    LinkList *L = create_linklist();
    const char *fileName = "student_info.txt";
    
    while(1) {
		printf("��ӭ����ѧ������ϵͳ\n");
		printf("\t1.���ѧ����Ϣ\n");
		printf("\t2.����ѧ����Ϣ\n");
		printf("\t3.ָ��λ�ò�����Ϣ\n");
		printf("\t4.ָ��λ��ɾ����Ϣ\n");
		printf("\t5.���ݳɼ�ɾ����Ϣ\n");
		printf("\t6.��������ɾ����Ϣ\n");
        printf("\t7.����ѧ���޸���Ϣ\n");
        printf("\t8.����ѧ����Ϣ\n");
        printf("\t9.��ȡѧ����Ϣ\n");
		printf("\t0.�˳�ѧ������ϵͳ\n");
		printf("\t����д������ѡ����Ӧ���ܣ�\n");
        printf("------------------------------------------------------\n");

        int num;
        scanf("%d", &num);
        getchar();
        switch (num)
        {
        case 1:     // ���ѧ����Ϣ
            {
                datatype e;

				printf("������ѧ��ѧ�ţ�\n");
				scanf("%lld",&e.sno);
				printf("������ѧ��������\n");
				scanf("%s",e.sname);
				printf("������ѧ���ɼ���\n");
                scanf("%d",&e.score);

                insert_tail(L, e);

                break;
            }
        case 2:     // ����ѧ����Ϣ
            stu_inf(L);
            break;
        case 3:     // ָ��λ�ò�����Ϣ
            {
                int pos;
                datatype e;

                printf("����������λ��\n");
                scanf("%d",&pos);
				printf("������ѧ��ѧ�ţ�\n");
				scanf("%d",&e.sno);
				printf("������ѧ��������\n");
				scanf("%s",e.sname);
				printf("������ѧ���ɼ���\n");
                scanf("%d",&e.score);

                insert_inf(L, pos, e);

                break;
            }
        case 4:     // ָ��λ��ɾ����Ϣ 
            {
                int pos;
                datatype e;

                printf("������ɾ����λ�ã�\n");
                scanf("%d",&pos);

                delete_inf_pos(L, pos);

                break;
            }
        case 5:     // ���ݳɼ�ɾ����Ϣ
            {
                int score;

                printf("������ɾ����Ϣ��ѧ���ɼ���\n");
                scanf("%d",&score);

                delete_inf_score(L, score);

                break;
            }
        case 6:     // ��������ɾ����Ϣ
            {
                char sname[8];

                printf("������ɾ����Ϣ��ѧ��������\n");
                scanf("%s",sname);

                delete_inf_sname(L, sname);

                break;
            }
        case 7:     // ����ѧ���޸���Ϣ
            {
                char sname[8];
                long long int sno,score;

                printf("������Ҫ�޸ĵ�ѧ��ѧ�ţ�\n");
                scanf("%lld",&sno);
                printf("�������޸�Ϊ��������\n");
                scanf("%s",sname);
                printf("�������޸�Ϊ�ĳɼ���\n");
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
        case 0:     // �˳�
            {
                printf("�˳��ɹ�\n");
                exit(0);
                break;
            }
        default:
            printf("��������ȷ����\n");
            printf("\n");
            break;
        }
    }
    return 0;
}


void insert_tail(LinkList *L, datatype e) {      // ����ѧ����Ϣ
    LinkList *p = (LinkList *)malloc(sizeof(LinkList));
    p->data = e;
    p->next = NULL;

    LinkList *q = L;
    while(q->next != NULL) {
        q = q->next;
    }
    q->next = p;

    printf("��ӳɹ�\n");
    return;
}

void insert_inf(LinkList *L, int pos, datatype e) {     // ָ��λ�ò�����Ϣ
    if(pos < 1) {
        printf("��������ȷ�����\n");
        return;
    }

    LinkList *q = L;       
    for(int i = 0;i < pos;i++) {
        if(q == NULL) {
            printf("�������е���Ϣ����\n");
            return;
        }
        q = q->next;
    }

    LinkList *p = (LinkList *)malloc(sizeof(LinkList));
    p->data = e;
    p->next = q->next;
    q->next = p;

    printf("��ӳɹ�\n");
    
    return;
}

void delete_inf_pos(LinkList *L, int pos) {     // ָ��λ��ɾ����Ϣ
    if(pos < 1) {
        printf("��������ȷ�����\n");
        return;
    }

    LinkList *q = L;       
    for(int i = 1;i < pos;i++) {
        if(q == NULL) {
            printf("�������е���Ϣ����\n");
            return;
        }
        q = q->next;
    }

    LinkList *p = q->next;
    q->next = p->next;
    free(p);
    p = NULL;

    printf("ɾ���ɹ�\n");
    printf("\n");

    return;
}

int list_empty(LinkList *L) {       // �ж������Ƿ�Ϊ��
    if(L->next == NULL) return 1;
    return 0;
}

void delete_inf_score(LinkList *L, int score) {     // ���ݳɼ�ɾ����Ϣ
    if(list_empty(L)) {
        printf("����Ϊ��\n");
        return;
    }

    LinkList *q = L;
    while(q->next != NULL && q->next->data.score != score) {
        q = q->next;
    }

    if(q->next == NULL) {
        printf("û���ҵ�������������Ϣ\n");
        printf("\n");
        return;
    }
    else{
        LinkList *p = q->next;
        q->next = p->next;
        free(p);
        p = NULL;

        printf("ɾ���ɹ�\n");
        printf("\n");
    }
    
    return;
}

void delete_inf_sname(LinkList *L, char sname[8]) {     // ��������ɾ����Ϣ
    if(list_empty(L)) {
        printf("����Ϊ��\n");
        return;
    }

    LinkList *q = L;
    while(q->next != NULL && strcmp(q->next->data.sname, sname)) {
        q = q->next;
    }

    if(q->next == NULL) {
        printf("û���ҵ�������������Ϣ\n");
        printf("\n");
        return;
    }
    else{
        LinkList *p = q->next;
        q->next = p->next;
        free(p);
        p = NULL;

        printf("ɾ���ɹ�\n");
        printf("\n");
    }
    
    return;
}

void update_inf(LinkList *L, long long int sno, char sname[8], int score) {       // ����ѧ���޸���Ϣ
    if(list_empty(L)) {
        printf("����Ϊ��\n");
        return;
    }

    LinkList *q = L;
    while(q->next != NULL && q->data.sno != sno) {
        q = q->next;
    }

    if(q == NULL) {
        printf("û���ҵ�������������Ϣ\n");
        printf("\n");
        return;
    }
    else{
        strcpy(q->data.sname, sname);
        q->data.score = score;

        printf("�޸ĳɹ�\n");
        printf("\n");
    }

    return;
}

void stu_inf(LinkList *L) {     // ����ѧ����Ϣ
    if(list_empty(L)) {
        printf("����Ϊ��\n");
        return;
    }

    printf("��ѯѧ����Ϣ\n");
    printf("\n");

    LinkList *p = L->next;
    int len = 0;
    while(p != NULL) {
        printf("ѧ��ѧ�ţ�%lld\t",p->data.sno);
        printf("ѧ��������%s\t",p->data.sname);
        printf("ѧ���ɼ���%d\t",p->data.score);
        printf("\n");
        p = p->next;
        len++;
    }

    printf("\n");
    printf("��%d����Ϣ\n",len);
    printf("\n");

    return;
}

void save_inf(LinkList *L, const char *fileName) {      // ����ѧ����Ϣ
    FILE *file = fopen(fileName, "w");

    if(file == NULL) {
        printf("�޷����ļ� %s\n", fileName);
        return;
    }

    if(list_empty(L)) {
        printf("����Ϊ��\n");
        fclose(file);
        return;
    }

    printf("������Ϣ��\n");
    LinkList *p = L->next;
    while(p != NULL) {
        printf("ѧ�ţ�%lld ������%s �ɼ���%d\n", p->data.sno, p->data.sname, p->data.score);

        fprintf(file, "%lld %s %d\n", p->data.sno, p->data.sname, p->data.score);
        p = p->next;
    }

    fclose(file);
    printf("ѧ����Ϣ�ѱ��浽 %s\n", fileName);
    printf("\n");

    return;
}

void load_inf(LinkList *L, const char *fileName) {      // ��ȡѧ����Ϣ
    FILE *file = fopen(fileName, "r");

    if(file == NULL) {
        printf("�޷����ļ� %s\n", fileName);
        return;
    }

    LinkList *p = L->next;
    printf("���ļ� %s ��ȡ��ѧ����Ϣ:\n", fileName);

    datatype e;
    while(fscanf(file, "%lld %s %d", &e.sno, e.sname, &e.score) != EOF) {
        insert_tail(L, e);
    }

    fclose(file);

    return;
}

LinkList *create_linklist() {       // ��������
    LinkList *L = (LinkList *)malloc(sizeof(LinkList));
    if(L == NULL){
        printf("����ʧ��\n");
        return NULL;
    }

    L->next = NULL;

    return L;
}