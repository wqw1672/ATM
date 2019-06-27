#include"staff.h"

LIST_T *People_init(void *data)
{
	LIST_T * head;
	head = (LIST_T *)malloc(sizeof(LIST_T));
	head->data=data;
	head->next=NULL;
	return head;
}


void People_Add(LIST_T *head,void *data)//��������ӵ����һ��
{
    LIST_T *pNode,*p1;
	p1=head;
	pNode=People_init(data);
	while(p1->next!= NULL )
	{   
		p1=p1->next;
	}   //���������ҵ���ĩβ�Ľڵ�
    
	p1->next=pNode;
	
}
/*****************************************************************************************************************
* �������ƣ� If_Search_Print(LIST_T *head,char ch[],int a,int b)
* ����������
*			 ��ӡ������ch����head��ͷ�ڵ��еĴ��ڵ���Ϣ�������
* ����˵����
*           LIST_T *head --�û������ͷ�ڵ� LIST_T *head --����Ĳ�����Ϣch  ��a˳��ĵ�һ����b�����һ��������
* ����ֵ����
*	����ʱ��:   2016-12-18
*	�޸����ڣ�  2016-12-18		�޸��ˣ�������
*	������
* �汾�ţ�V1.0
******************************************************************************************************************/
void If_Search_Print(LIST_T *head,char ch[],int a,int b)
{
		int i=12,j=7,nu=1;
		int judge=0;//�ж��Ƿ�鵽
		int x=0;//�ж��Ƿ��в鵽��
	    LIST_T *phead=People_init(NULL);
	    phead=head;
    	while(phead!=NULL&&nu<a)
		{
			judge=If_Search(ch,phead->data);
		    if(judge>0)
			{
		    	nu++;
				x++;
			}
			phead=phead->next;
		}
		judge=0;
		while(phead!=NULL&&a<=b)
		{
			judge=If_Search(ch,phead->data);
			if(judge>0)
			{
                    x++;
					move_printf(phead->data,i,j,a);
					a++;
					j++;
			}
			phead=phead->next;
		}
		if(x<nu)
		{
			if(x==0)
			{
			  Gotoxy(20,7);
		       printf("�޷��鵽������Ϣ");
			}
			else
			{
			   Gotoxy(12,7);
		       printf("֮��û����Ϣ��");
			}
		}
}


void Search_Print(LIST_T *head,int a,int b,int c)//��˳���ӡ�����ҵ�����Ϣ��������ҳ
{
	struct staff *people;
	int i=12,j=7,nu=1;
	LIST_T *phead=People_init(NULL);
	phead=head->next;
	people=(struct staff *)malloc(sizeof(struct staff));
	memset(people,0,sizeof(struct staff));
	while(phead!=NULL&&nu<a)
	{
        people=phead->data;
		if(((c==2&&atoi(people->role)==0)||(c==1)||(c==3&&atoi(people->role)==1))&&(atoi(people->state)==0))
			nu++;
		phead=phead->next;
	}
    while(phead!=NULL&&a<=b)
	{
		people=phead->data;
		if(((c==2&&atoi(people->role)==0)||(c==1)||(c==3&&atoi(people->role)==1))&&(atoi(people->state)==0))
		{
	     move_printf(people, i, j,a);
			a++;
			j++;
		}	
		phead=phead->next;
	}
}
void move_printf(void *p,int i,int j,int a)//������ӡ�û��͹���Ա����Ϣ��˳��
{
	struct staff *people;
	people=p;
	i=12;
	Gotoxy(i,j);
	printf("%d.%s",a,people->root);
	i+=15;
	Gotoxy(i,j);
	printf("%s",people->name);
	i+=14;
	Gotoxy(i,j);
	printf("%s",people->passwd);
	i+=11;
	Gotoxy(i,j);
	printf("%s",people->money);
	i+=13;
	if(atoi(people->role)==1)
	{		
		Gotoxy(i,j);
		printf("����Ա");
	}
	if(atoi(people->role)==0)
	{
		Gotoxy(i,j);
		printf("�û�");
	}
	
}
/*****************************************************************************************************************
* �������ƣ�  People_Root(char a[],LIST_T *head)
* ����������
*			 �ж�����a�Ƿ�������head�е�root��name����ͬ��
* ����˵����
*           char a[] �Աȵ���Ϣ,LIST_T *head ���������ͷ���
* ����ֵ����ͬ�ͷ��ظý��  ���򷵻ؿ�
*	����ʱ��:   2016-12-18
*	�޸����ڣ�  2016-12-18		�޸��ˣ�������
*	������
* �汾�ţ�V1.0
******************************************************************************************************************/

LIST_T *People_Root(char a[],LIST_T *head)//�ж�����a�Ƿ�������head�е�root��name����ͬ�ģ���ͬ�ͷ��ظý��
{
	LIST_T *p=head;
	int sta=0;
	struct staff *data;
	data=(struct staff *)malloc(sizeof(struct staff));
	memset(data,0,sizeof(struct staff));
	while(p->next!=NULL)
	{
		p=p->next;
		data=p->data;
		if((strcmp(a,data->root)==0)||(strcmp(a,data->name)==0))
		{
			sta=1;
			break;
		}
	}
	if(sta==0||atoi(data->state)==1)
		return 0;
	if(sta==1)
		return p;
	
}
/*****************************************************************************************************************
* �������ƣ�  If_Search(char a[],void *head)
* ����������
*			 �����ж�ģ����ѯ
* ����˵����
*           char a[] �Աȵ���Ϣ,LIST_T *head ���������ͷ���
* ����ֵ������鵽��Ϣ�ͷ���1��û�鵽�ͷ���0��
*	����ʱ��:   2016-12-18
*	�޸����ڣ�  2016-12-18		�޸��ˣ�������
*	������
* �汾�ţ�V1.0
******************************************************************************************************************/

int If_Search(char a[],void *head)//�����ж�ģ����ѯ������鵽��Ϣ�ͷ���1��û�鵽�ͷ���0��
{
	int judge=0;
	struct staff *data;
    int next[32] = {-999};
	data=(struct staff *)malloc(sizeof(struct staff));
	memset(data,0,sizeof(struct staff));
	data=head;
	if(data->state==1)
		return 0;
    if(strstr(data->name,a)==NULL&&strstr(data->root,a)==NULL)
		return 0;
	return 1;
}
LIST_T *People_Passwd(char b[],LIST_T *head)//�ж������Ƿ���ȷ
{
    struct staff *data;
	data=(struct staff *)malloc(sizeof(struct staff));
	memset(data,0,sizeof(struct staff));
	data=head->data;
	if( strcmp(b,data->passwd)==0)
		return head;
	
	return 0;
	
}

void LIST_Free(LIST_T *head)
{
    int a=1; 
	LIST_T *ptr=head;
	while(ptr!=NULL)
	{
		ptr=ptr->next;
		free(head->data);
		free(head);
		head=ptr;
	}
}

int User_Add(int ch)//�û���ӽ��ļ�1��ӹ���Ա2����û�
{
   	FILE *fp=NULL;
	int number=0;//���������м����û�
	int judge=0;//�����ж��Ƿ��û����ص�
	char a[10]={0},b[10]={0},c[10]={0};
    LIST_T *head=People_init(NULL);
	LIST_T *phead=NULL;
	LIST_T *p=NULL;
	struct staff *people;
	char ch1;
	while(1)
	{
		int back=0;
        judge=0;
		system("cls");
		printf("           **********************************************************\n");
		printf("                                                          \n");
		printf("           **********************************************************\n");
		printf("\n\n");
		printf("              (С��10λ)�������û���:\n");
		printf("                     (6λ)����������:  \n");
		printf("                 (6λ)���ٴ���������:\n");
		printf("\n                               �˳�ATM(esc)\n");
		printf(" \n\n\n           **********************************************************\n");
		printf("\n");
		fp=file_open("staff.txt");
		head=file_to_list(fp,sizeof(struct staff));
		fclose(fp);
		p=head;
		if(ch==1)
		{
			Gotoxy(35,1);
			printf("��ӹ���Աģ��");
		}
		if(ch==2)
		{
			Gotoxy(35,1);
			printf("����û�ģ��");
		}
		Gotoxy(15,3);
		printf("                    esc������һ��");
		Gotoxy(37,5);
	    back=glb_putString(a,7,2,1);
        switch(back)
		{
		case 1:
			return 0;
		default:break;
		}
		while(p->next!=NULL)
		{   
			p=p->next;
			people=(struct staff *)malloc(sizeof(struct staff));
			memset(fp,0,sizeof(struct staff));
			people=p->data;
			if(strcmp(people->name,a)==0||strcmp(people->root,a)==0)
			{
				Gotoxy(13,11);
				printf("��������û����������˺ź������û�����ͬ�����������������");
				judge=1;
				
				getch();
				break;
			}
			
		}
		if(judge==1)
			continue;
		Gotoxy(37,6);
		back=0;
		back=glb_putString(b,5,2,0);
		switch(back)
		{
		case 1:
			return 0;
		default:break;
		}
		if(strlen(b)<6)
		{
			Gotoxy(20,11);
			printf("���볤��С��6����Чע�ᰴ���������ע��");
			getch();
			continue;
		}
		Gotoxy(37,7);
		back=0;

		back=glb_putString(c,5,2,0);
		switch(back)
		{
		case 1:
			return 0;
		default:break;
		}
		if(strcmp(b,c)==0)
		{
			phead=People_init(NULL);
			number=LIST_GetCount(head,NULL,0);
			number=18060136+number;
			people=(struct staff *)malloc(sizeof(struct staff));
			memset(people,0,sizeof(struct staff));
			strcpy(people->name,a);
			strcpy(people->passwd,b);
			sprintf(c,"%d",number);
			strcpy(people->root,c);
			Gotoxy(20,11);
			printf("ע��ɹ��������˺�Ϊ%s",people->root);
			if(ch==2)
			{
				strcpy(people->role,"0");
				strcpy(people->money,"0");

			}
			if(ch==1)
				strcpy(people->role,"1");
			strcpy(people->state,"0");
			People_Add(phead,people);
			fp=file_open("staff.txt");
			list_to_file(fp,phead,sizeof(struct staff));
			fclose(fp);
			
		}
		else
		{
			Gotoxy(30,11);
			printf("������������벻ͬ");
		}
		Gotoxy(20,12);
		printf("    ���������esc������ע��    ");
        ch1=getch();
		switch(ch1)
		{
		case 27:
			return 0;
		default:break;
		}
		
	}
	
}
int LIST_GetCount(LIST_T *head,struct staff *data,int x)//����ڵ���� X������1����������ȫ���ڵ����
{
	int a=0;
	struct staff *people;
	LIST_T *phead=head->next;
	while(phead!=NULL)
	{
		if(x==1)
		{
		people=phead->data;
		if(strcmp(data->root,people->root)==0)
			break;
		}
		phead=phead->next;
		a++;
	}
	return a;
}