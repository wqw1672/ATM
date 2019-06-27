#include"staff.h"

LIST_T *People_init(void *data)
{
	LIST_T * head;
	head = (LIST_T *)malloc(sizeof(LIST_T));
	head->data=data;
	head->next=NULL;
	return head;
}


void People_Add(LIST_T *head,void *data)//将数据添加到最后一个
{
    LIST_T *pNode,*p1;
	p1=head;
	pNode=People_init(data);
	while(p1->next!= NULL )
	{   
		p1=p1->next;
	}   //遍历链表，找到最末尾的节点
    
	p1->next=pNode;
	
}
/*****************************************************************************************************************
* 函数名称： If_Search_Print(LIST_T *head,char ch[],int a,int b)
* 功能描述：
*			 打印出满足ch中在head中头节点中的存在的信息。并输出
* 参数说明：
*           LIST_T *head --用户链表的头节点 LIST_T *head --输入的查找信息ch  ，a顺序的第一个，b是最后一个的数字
* 返回值：无
*	创建时间:   2016-12-18
*	修改日期：  2016-12-18		修改人：王齐文
*	描述：
* 版本号：V1.0
******************************************************************************************************************/
void If_Search_Print(LIST_T *head,char ch[],int a,int b)
{
		int i=12,j=7,nu=1;
		int judge=0;//判断是否查到
		int x=0;//判断是否有查到过
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
		       printf("无法查到关联信息");
			}
			else
			{
			   Gotoxy(12,7);
		       printf("之后没有信息了");
			}
		}
}


void Search_Print(LIST_T *head,int a,int b,int c)//按顺序打印出查找到的信息，用来翻页
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
void move_printf(void *p,int i,int j,int a)//用来打印用户和管理员的信息按顺序
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
		printf("管理员");
	}
	if(atoi(people->role)==0)
	{
		Gotoxy(i,j);
		printf("用户");
	}
	
}
/*****************************************************************************************************************
* 函数名称：  People_Root(char a[],LIST_T *head)
* 功能描述：
*			 判断数列a是否在链表head中的root和name有相同的
* 参数说明：
*           char a[] 对比的信息,LIST_T *head 查找链表的头结点
* 返回值：相同就返回该结点  否则返回空
*	创建时间:   2016-12-18
*	修改日期：  2016-12-18		修改人：王齐文
*	描述：
* 版本号：V1.0
******************************************************************************************************************/

LIST_T *People_Root(char a[],LIST_T *head)//判断数列a是否在链表head中的root和name有相同的，相同就返回该结点
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
* 函数名称：  If_Search(char a[],void *head)
* 功能描述：
*			 用来判断模糊查询
* 参数说明：
*           char a[] 对比的信息,LIST_T *head 查找链表的头结点
* 返回值：如果查到信息就返回1，没查到就返回0；
*	创建时间:   2016-12-18
*	修改日期：  2016-12-18		修改人：王齐文
*	描述：
* 版本号：V1.0
******************************************************************************************************************/

int If_Search(char a[],void *head)//用来判断模糊查询，如果查到信息就返回1，没查到就返回0；
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
LIST_T *People_Passwd(char b[],LIST_T *head)//判断秘密是否正确
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

int User_Add(int ch)//用户添加进文件1添加管理员2添加用户
{
   	FILE *fp=NULL;
	int number=0;//用来计算有几个用户
	int judge=0;//用来判断是否用户名重叠
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
		printf("              (小于10位)请输入用户名:\n");
		printf("                     (6位)请输入密码:  \n");
		printf("                 (6位)请再次输入密码:\n");
		printf("\n                               退出ATM(esc)\n");
		printf(" \n\n\n           **********************************************************\n");
		printf("\n");
		fp=file_open("staff.txt");
		head=file_to_list(fp,sizeof(struct staff));
		fclose(fp);
		p=head;
		if(ch==1)
		{
			Gotoxy(35,1);
			printf("添加管理员模块");
		}
		if(ch==2)
		{
			Gotoxy(35,1);
			printf("添加用户模块");
		}
		Gotoxy(15,3);
		printf("                    esc返回上一级");
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
				printf("您输入的用户名与已有账号和其他用户名相同，摁任意键重新输入");
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
			printf("密码长度小于6，无效注册按任意键重新注册");
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
			printf("注册成功，您的账号为%s",people->root);
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
			printf("输入的两次密码不同");
		}
		Gotoxy(20,12);
		printf("    任意键（除esc）继续注册    ");
        ch1=getch();
		switch(ch1)
		{
		case 27:
			return 0;
		default:break;
		}
		
	}
	
}
int LIST_GetCount(LIST_T *head,struct staff *data,int x)//计算节点个数 X不等于1是用来计算全部节点个数
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