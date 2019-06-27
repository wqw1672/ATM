#ifndef _STAFF_H_
#define _STAFF_H_
#include"public.h"

struct staff
{
    char root[9];
	char passwd[8];
    char name[10];
	char money[10];
	char state[2];//0������1ע��
	char role[2]; // 0����ͨ�û� 1�ǹ���Ա
};
struct record
{
   char my_root[9];
   char time[20];
   char change_money[11];//�����Ľ��
   char remain_money[11];//���
   char way[2];//0��� 1ȡ�� 2ת��ת��  3ת��ת��
   char other_root[10];// 0Ŀ��Դ�� ATM
};

typedef struct list
{
   void *data;
   struct list *next;
}LIST_T;


LIST_T *People_init(void *data);

void People_Add(LIST_T *head,void *data);

void Search_Print(LIST_T *head,int a,int b,int c);

void LIST_Free(LIST_T *head);

LIST_T *People_Root(char a[],LIST_T *head);

LIST_T *People_Passwd(char b[],LIST_T *head);

void move_printf(void *p,int i,int j,int a);

int LIST_GetCount(LIST_T *head,struct staff *data,int x);//����ڵ����

int User_Add(int ch);

int If_Search(char a[],void *head);

void If_Search_Print(LIST_T *head,char ch[],int a,int b);

#endif