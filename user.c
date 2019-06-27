#include"user.h"
/*****************************************************************************************************************
* 函数名称： User_Menu(struct staff *data)
* 功能描述：
*			 用户模块的打印
* 参数说明：
*           struct staff *data用户自身的结构体信息
* 返回值：
*	创建时间:   2016-12-18
*	修改日期：  2016-12-18		修改人：王齐文
*	描述：
* 版本号：V1.0
*********************************************************************************/
void User_Menu(struct staff *data)
{
	while(1)
	{
		
		char ch[1]={0};
		int back=0;
        system("cls");
		printf("           **********************************************************\n");
		printf("                                  用户模块                          \n");
		printf("           **********************************************************\n");
		printf("\n\n");
		printf("                                1.余额查询\n");
		printf("                                2.存款    \n");
		printf("                                3.取款  \n");
		printf("                                4.转账  \n");
		printf("                                5.密码修改\n");
		printf("                                6.交易记录查询\n");
		printf("                                7.退出ATM系统\n");
		printf("\n                               返回上一级(esc)\n");
		printf(" \n           **********************************************************\n");
		Gotoxy(10,1);
		printf("用户名:%s",data->name);
		Gotoxy(30,4);
		printf("请输入:");	
		back=glb_putString(ch, 0, 0,1);
		switch(*ch)
		{
		case '1':
			Money_Search(data);
			break;
		case '2':
			Money_Add(data);
			break;
		case '3':
			Money_Get(data);
			break;
		case '4':
			Money_Upd(data);
			break;
		case '5':
            Passwd_Upd(data);
			break;
		case '6':
           Deal_Memory(data);
			break;
		case '7':
			back=back_system(1,1);
			if(back==2)
				exit(0);
			break;
		default:
			if(back==1){

			back=back_system(1,2);
			if(back==2)
				return 0;}
			break;
		}
	}
}
void Money_Search(struct staff *data)
{
	while(1)
	{
		
		char ch;
        system("cls");
		printf("           **********************************************************\n");
		printf("                                  余额查询                          \n");
		printf("           **********************************************************\n");
		printf("\n                        您的余额为:               \n");
		
		printf(" \n\n                           esc返回页面\n           **********************************************************\n");
		Gotoxy(36,4);
		printf("%s",data->money);
		ch=getch();
		switch(ch)
		{
		case 27:
			return 0;
			break;
		default:break;
		}
	}
}
/*****************************************************************************************************************
* 函数名称： Money_Add(struct staff *data)
* 功能描述：
*			 页面存款的打印
* 参数说明：
*           struct staff *data需要存款用户的自身的结构体信息
* 返回值：
*	创建时间:   2016-12-18
*	修改日期：  2016-12-18		修改人：王齐文
*	描述：
* 版本号：V1.0
*********************************************************************************/
void Money_Add(struct staff *data)
{
	FILE *fp=NULL;
	LIST_T *head=NULL;
	struct record *re;
	while(1)
	{
		int money_add=0;
		int money_new=0;
		int number=0;
		char ch;
		char a[15];
		int back=0;
        system("cls");
		printf("           **********************************************************\n");
		printf("                                  存款界面                          \n");
		printf("           **********************************************************\n");
		printf("                              esc退回上一界面\n");
		printf("                        当前余额为:               \n");
		printf("\n                \n\n");
        printf("         (不得超过8位数)存款金额为:                    \n\n\n\n");
		printf("           **********************************************************\n");
		Gotoxy(36,4);
		printf("%s",data->money);
		Gotoxy(36,8);
		back=glb_putString(a, 7, 0, 1);
        switch(back)
		{
		case 1:
			return 0;
		default:break;
		}
		money_add=atoi(a);
		if(money_add%100!=0||money_add<=0)
		{
			Gotoxy(13,10);
			printf("     您输入的金额需是100的整数倍并且大于等于0");
		}
		else
		{
			fp=file_open("staff.txt");
			head=file_to_list(fp,sizeof(struct staff));
			fclose(fp);
			number=LIST_GetCount(head,data,1);
			money_new=money_add;
			money_add= money_add+atoi(data->money);
			sprintf(data->money,"%d",money_add);
			fp=file_open("staff.txt");
			rewind(fp);
			fseek(fp,(sizeof(struct staff))*number,0);
			fwrite(data,sizeof(struct staff),1,fp);
			fclose(fp);
			re=(struct record *)malloc(sizeof(struct record));
			memset(re,0,sizeof(struct record));
			re=record_into(data,money_new,0,0);
			
			fp=file_open("record.txt");
			head=file_to_list(fp,sizeof(struct record));
			fclose(fp);
			
			number=LIST_GetCount(head,NULL,0);    
			fp=file_open("record.txt");
			fseek(fp,(sizeof(struct record))*number,0);
			fwrite(re,sizeof(struct record),1,fp);
			fclose(fp);
		}
		Gotoxy(10,11);
		printf("         esc退回上一界面           任意键继续存款   ");
		ch=getch();
		switch(ch)
		{
		case 27:
			return 0;
			break;
		default:break;
		}
	}
	
}
/*****************************************************************************************************************
* 函数名称： Money_Add(struct staff *data)
* 功能描述：
*			 页面取款的打印
* 参数说明：
*           struct staff *data需要取款用户的自身的结构体信息
* 返回值：
*	创建时间:   2016-12-18
*	修改日期：  2016-12-18		修改人：王齐文
*	描述：
* 版本号：V1.0
*********************************************************************************/
void Money_Get(struct staff *data)
{
	FILE *fp=NULL;
	LIST_T *head=NULL;
	struct record *re;
	while(1)
	{
		int money_add=0;
		int money_new=0;
		int number=0;
		char ch;
		char a[15];
		int back=0;
        system("cls");
		printf("           **********************************************************\n");
		printf("                                  取款界面                          \n");
		printf("           **********************************************************\n\n");
		printf("                        当前余额为:               \n");
		printf("\n                \n\n");
        printf("         (不得超过8位数)取款金额为:                    \n\n\n\n");
		printf("           **********************************************************\n");
		Gotoxy(36,4);
		printf("%s",data->money);
		Gotoxy(36,8);
		back=glb_putString(a, 7, 0, 1);
		switch(back)
		{
		case 1:
			return 0;
		default:break;
		}
		money_add=atoi(a);
		if(money_add%100!=0||money_add<=0)
		{
			Gotoxy(13,10);
			printf("     您输入的金额需是100的整数倍并且大于0");
		}
		else if(money_add>atoi(data->money))
		{
			Gotoxy(13,10);
			printf("     您输入的金额不能大于你自己的余额");
		}
		else
		{
			fp=file_open("staff.txt");
			head=file_to_list(fp,sizeof(struct staff));
			number=LIST_GetCount(head,data,1);
			money_new=money_add;
			money_new=atoi(data->money)-money_add;
			sprintf(data->money,"%d",money_new);
			
			rewind(fp);
			fseek(fp,(sizeof(struct staff))*number,0);
			fwrite(data,sizeof(struct staff),1,fp);
			fclose(fp);
			re=(struct record *)malloc(sizeof(struct record));
			memset(re,0,sizeof(struct record));
			re=record_into(data,money_add,1,0);
			
			
			fp=file_open("record.txt");
			head=file_to_list(fp,sizeof(struct record));
			
			
			number=LIST_GetCount(head,NULL,0);    
			fseek(fp,(sizeof(struct record))*number,0);
			fwrite(re,sizeof(struct record),1,fp);
			fclose(fp);
		}
		Gotoxy(10,11);
		printf("    esc返回上一页面               任意键继续存款");
		ch=getch();
		switch(ch)
		{
		case 27:
			return 0;
			break;
		default:break;
		}
	}
}
/*****************************************************************************************************************
* 函数名称：  Money_Upd(struct staff *data)
* 功能描述：
*			 转账页面的打印和输入账户的判断
* 参数说明：
*           struct staff *data需要转账用户的自身的结构体信息
* 返回值：
*	创建时间:   2016-12-18
*	修改日期：  2016-12-18		修改人：王齐文
*	描述：
* 版本号：V1.0
*********************************************************************************/
void Money_Upd(struct staff *data)
{
   	FILE *fp=NULL;
	FILE *fp1=NULL;
	LIST_T *head=NULL;
	LIST_T *phead=NULL;
	struct record *re;
	struct staff *people;
    while(1)
	{
		int money_add=0;
		int money_new=0;
		int number=0;
		char ch;
		char a[15]={0},b[8]={0};
		int back=0;
        system("cls");
		printf("           **********************************************************\n");
		printf("                                  转账界面                          \n");
		printf("           **********************************************************\n");
		printf("                                esc退回上一级                     \n");
		printf("                 用户名/转账账号为:               \n");
		printf("\n                \n\n");
        printf("                        转账金额为:                    \n\n\n\n");
		printf("           **********************************************************\n");
		fp=file_open("staff.txt");
        head=file_to_list(fp,sizeof(struct staff));
		Gotoxy(36,4);
		back=glb_putString(b,7, 2, 1);
        switch(back)
		{
		case 1:
			return 0;
		default:break;
		}
		phead=People_Root(b,head);
		if(phead!=0)
		people=phead->data;
		if(phead==0)
		{
			Gotoxy(33,6);
			printf("该用户不存在");  
		}
		else if(atoi(people->role)==1)
		{
		  	Gotoxy(33,6);
			printf("不能转账给管理员"); 
		}
		else if(strcmp(people->root,data->root)==0)
		{
		    Gotoxy(33,6);
			printf("不能转账给你自己"); 
		}
		else
		{
			Gotoxy(36,8);
			back=0;
			back=glb_putString(a, 7, 0, 1);
            switch(back)
			{
			case 1:
				return 0;
			default:break;
				}
			money_add=atoi(a);
			if(money_add<=0)
			{
				Gotoxy(13,10);
				printf("            您输入的金额需大于0");
			}
			else if(money_add>atoi(data->money))
			{
				Gotoxy(13,10);
				printf("     您输入的金额不能大于你自己的余额");
			}
			else
			{
                people=phead->data;
				
				fp1=file_open("record.txt");
				number=LIST_GetCount(head,data,1);
				money_new=money_add;
				money_add=atoi(data->money)-money_add;
				sprintf(data->money,"%d",money_add);
				
				rewind(fp);
				fseek(fp,(sizeof(struct staff))*number,0);
				fwrite(data,sizeof(struct staff),1,fp);
				fflush(fp);
				
				re=(struct record *)malloc(sizeof(struct record));
				memset(re,0,sizeof(struct record));
				re=record_into(data,money_new,3,atoi(people->root));
                file_add(fp1,re,sizeof(struct record));
				
				
				money_add=atoi(people->money)+money_new;
				sprintf(people->money,"%d",money_add);
				number=LIST_GetCount(head,people,1);
				rewind(fp);
				fseek(fp,(sizeof(struct staff))*number,0);
				fwrite(people,sizeof(struct staff),1,fp);
                fflush(fp);
				
				re=(struct record *)malloc(sizeof(struct record));
				memset(re,0,sizeof(struct record));
				re=record_into(people,money_new,2,atoi(data->root));
                file_add(fp1,re,sizeof(struct record));
				
				fclose(fp1);
			}
		}
		fclose(fp);
		Gotoxy(10,11);
		printf("    esc返回上一页面               任意键继续转账");
		ch=getch();
		switch(ch)
		{
		case 27:
			return 0;
			break;
		default:break;
		}
		
	}
}
/*****************************************************************************************************************
* 函数名称：  Passwd_Upd(struct staff *data)
* 功能描述：
*			 密码修改页面的打印和判断
* 参数说明：
*           struct staff *data需要修改用户的自身的结构体信息
* 返回值：
*	创建时间:   2016-12-18
*	修改日期：  2016-12-18		修改人：王齐文
*	描述：
* 版本号：V1.0
******************************************************************************************************************/

void Passwd_Upd(struct staff *data)
{
	LIST_T *head=NULL;
	LIST_T *phead=NULL;
	FILE *fp=NULL;
   	while(1)
	{
		char new_code[10]={0};
		char again_code[10]={0};
		char ch;
		int count=0;
		int back=0;
		fp=file_open("staff.txt");
        head=file_to_list(fp,sizeof(struct staff));
        system("cls");
		printf("           **********************************************************\n");
		printf("                                  密码修改                          \n");
		printf("           **********************************************************\n");
		printf("                               esc退回上一页面\n");
		printf("                     (6位)新密码为:               \n");
		printf("\n                \n\n");
        printf("           (6位)请重新输入新密码为:                    \n\n\n\n");
		printf("           **********************************************************\n");
		Gotoxy(36,4);
		back=glb_putString(new_code,5,2,0);		
		switch(back)
		{
		case 1:
			return 0;
		default:break;
		}
		if(strlen(new_code)<6)
		{
			Gotoxy(22,6);
			printf("您输入的密码不得小于6位");
		}
		else
		{
			back=0;
			Gotoxy(36,8);
			back=glb_putString(again_code,5,2,0);
					switch(back)
				{
				case 1:
					return 0;
				default:break;
				}
			if(strcmp(new_code,again_code)==0)
			{
				count=LIST_GetCount(head,data,1);
				strcpy(data->passwd,again_code);
				rewind(fp);
				fseek(fp,(sizeof(struct staff))*count,0);
				fwrite(data,sizeof(struct staff),1,fp);
				fflush(fp);
			}
			else
			{
				Gotoxy(22,10);
				printf("您输入的而两次密码不相同");
			}
		}
		fclose(fp);
		Gotoxy(10,11);
		printf("       esc返回上一页面               任意键继续修改");
		ch=getch();
		switch(ch)
		{
		case 27:
			return 0;
			break;
		default:break;
		}
	}
}
void Deal_Memory(struct staff *data)
{
	
	   while(1)
	   {
		   char ch[1]={0};
		   int back=0;
		   system("cls");
		   printf("           **********************************************************\n");
		   printf("                               交易记录界面                          \n");
		   printf("           **********************************************************\n");
		   printf("                             esc返回上一页面\n");
		   printf("                               \n");
		   printf("                            1.全部查询               \n");
		   printf("                            2.按时间段查询                \n");
		   printf("                            esc返回上一页面                    \n\n");
		   printf("           **********************************************************\n");
		   Gotoxy(30,4);
	       printf("请输入:");
		   back=glb_putString(ch, 0, 0,1);
		   switch(*ch)
		   {
		   case '1':
			   All_Deal(data,atoi(ch));
			   break;
		   case '2':
			   All_Deal(data,atoi(ch));
			   break;
		   default:break;
		   }
		   switch(back)
		   {
		   case 1:
			   return 0;
			   break;
		   default:break;
		   }
	   }
}
void All_Deal(struct staff *data,int c)
{
	FILE *fp=NULL;
	int i=1;
	int x=0;
	LIST_T *head=People_init(NULL);
	LIST_T *phead=NULL;
     


	fp=file_open("record.txt");
	
    head=file_to_list(fp,sizeof(struct record));
	fclose(fp);
	
	while(1)
	{
		char ch;

		system("cls");
		printf("           **********************************************************\n");
		printf("                                                        \n");
		printf("           **********************************************************\n");
		printf("\n                            \n");
		printf("         \n");
		printf("        序号       时间          金额         余额        摘要     交易发生源\n");
		printf("        \n");
		printf("        \n");
		printf("        \n");
		printf("        \n");
		printf("        \n");
		printf("        \n");
		printf("\n                      按    ↑    ↓     箭      翻     页  \n");
		printf("\n                              esc返回上一级                                  \n");
		printf(" \n\n\n           **********************************************************\n");
		if(x==1)
		{
				Gotoxy(30,4);
						   printf("已经到达底部了");
		}
		if(x==2)
		{		       Gotoxy(30,4);
     	printf("已到达顶部");
		}
		x=0;
		if(c==1)
		{
			Gotoxy(35,1);
			printf("全部查询");
			Search_Deal(head,data,i,i+5);
			ch=getch();
		switch(ch)
		{
		case 27:
			return 0;
			break;
		case 80:
			if(i<LIST_GetCount(head,NULL,0)-1)
			{
			i+=6;
			}
			else
			{
               x=1;
			}
			break;
		case 72:
			if(i>6)
				i-=6;
			else
			{
				x=2;
			}
			break;
		default: break;
		}
		}
		if(c==2)
		{
			Gotoxy(35,1);
			printf("按时间段查询");
			Time_Search(head,data);
			return 0;
		}
		
	}	
}
/*****************************************************************************************************************
* 函数名称： Search_Deal(LIST_T *head,struct staff *data,int a,int b)
* 功能描述：
*			 日期的翻页打印
* 参数说明：
*           LIST_T *head 交易记录的头结点,struct staff *data  传入该用户的个人信息 ,int a 序号的开始a,int b序号的结束b
* 返回值：无
*	创建时间:   2016-12-18
*	修改日期：  2016-12-18		修改人：王齐文
*	描述：
* 版本号：V1.0
******************************************************************************************************************/
void Search_Deal(LIST_T *head,struct staff *data,int a,int b)
{
    struct record *re;
	int i=12,j=7,nu=1;
	LIST_T *phead=People_init(NULL);
	phead=head->next;
	re=(struct record *)malloc(sizeof(struct record));
	memset(re,0,sizeof(struct record));
	while(phead!=NULL&&nu<a)
	{
        re=phead->data;
		if(strcmp(re->my_root,data->root)==0||strcmp(re->other_root,data->root))
			nu++;
		phead=phead->next;
	}
    while(phead!=NULL&&a<=b)
	{
		re=phead->data;
		if(strcmp(re->my_root,data->root)==0)
		{
			Deal_printf(re, i, j,a);
			a++;
			j++;
		}	
		phead=phead->next;
	}
	
}
/*****************************************************************************************************************
* 函数名称：  Time_Search(LIST_T *head,struct staff *data)
* 功能描述：
*			 进行时间查询的输入判断和打印
* 参数说明：
*           LIST_T *head查找的账单头结点 struct staff *data  查找的用户本身的结构体
* 返回值：
*	创建时间:   2016-12-18
*	修改日期：  2016-12-18		修改人：王齐文
*	描述：
* 版本号：V1.0
******************************************************************************************************************/

void Time_Search(LIST_T *head,struct staff *data)
{
	struct record *re;
    char begin_time[20]={0};
	char end_time[20]={0};
	LIST_T *rhead=People_init(NULL);
	int p=0,q=0;
	LIST_T *phead=People_init(NULL);
	phead=head->next;
	re=(struct record *)malloc(sizeof(struct record));
	memset(re,0,sizeof(struct record));
	while(1)
	{

		char ch1;
		int back=0;
    	int x=0;
		system("cls");
		printf("           **********************************************************\n");
		printf("                                按时间查询账单                                  \n");
		printf("           **********************************************************\n");
		printf("                                esc退回上一级\n\n");
		printf("         \n");
		printf("        \n");
		printf("        \n");
		printf("        \n");
		printf("        \n");
		printf("        \n");
		printf("        \n");
		printf("        \n");
		printf("\n                       \n");
		printf("\n                                                           \n");
		printf("\n                             \n");
		printf(" \n\n\n           **********************************************************\n");

	Gotoxy(30,6);
    printf("输入格式2018-01-01");
    Gotoxy(7,5);
	printf("开始时间:");
	Gotoxy(16,5);
    back=glb_putString(begin_time,9,3,1);
	switch(back)
		{
		case 1:
			return 0;
			break;
		default:break;
		}
    p=judge_time(begin_time);
    if(p==0)
	{  
		Gotoxy(30,9);
		printf("您输入的时间格式不对");
	}
	if(p==1)
	{
		Gotoxy(30,9);
		printf("您输入的时间不得大于现在时间");
	}
	if(p==2)
	{
    Gotoxy(44,5);
    printf("结束时间:");
	back=0;
	Gotoxy(53,5);
    back=glb_putString(end_time,9,3,1);
		switch(back)
		{
		case 1:
			return 0;
			break;
		default:break;
		}
	q=judge_time(end_time);
	}
    if(q==0&&p==2)
	{  
		Gotoxy(30,9);
		printf("您输入的时间格式不对");
	}
	if(q==1&&p==2)
	{
		Gotoxy(30,9);
		printf("您输入的时间不得大于现在时间");
	}
	if(p==2&&p==2)
	{
			if(strcmp(begin_time,end_time)>0)
			{
				Gotoxy(30,9);
				printf("结束时间不得小于开始时间");
			}
			else
			{
				while(phead!=NULL)
				{
				    re=phead->data;
					if(strcmp(re->my_root,data->root)==0||strcmp(re->other_root,data->root))
						if(strcmp(re->time,begin_time)>=0&&strcmp(re->time,end_time)<=0)
							People_Add(rhead,re);
						phead=phead->next;
				}
				show_if_deal(rhead);
				continue;
			}
	}
	Gotoxy(25,15);
	printf("按任意键重新输入，或esc退回上一级");
    ch1=getch();
	switch(ch1)
	{
	case 27:
		return 0;
		break;
	default:break;
	}

	}		
}
/*****************************************************************************************************************
* 函数名称：  Deal_printf(void *p,int i,int j,int a)
* 功能描述：
*			 按顺序打印时间账单
* 参数说明：
*           void *p 结构体信息,int i 从第几个开始,int j第几个结束,int a 序号
* 返回值：
*	创建时间:   2016-12-18
*	修改日期：  2016-12-18		修改人：王齐文
*	描述：
* 版本号：V1.0
******************************************************************************************************************/

void Deal_printf(void *p,int i,int j,int a)
{
	struct record *re;
	re=p;
	i=10;
	Gotoxy(i,j);
	printf("%d",a);
	i+=7;
	Gotoxy(i,j);
	printf("%s",re->time);
	i+=17;
	Gotoxy(i,j);
	printf("%s",re->change_money);
	i+=11;
	Gotoxy(i,j);
	printf("%s",re->remain_money);
	i+=10;
    switch(atoi(re->way))
	{
	   case 0:
		   Gotoxy(i,j);
		   printf("存款");
		   break;
	   case 1:
		   Gotoxy(i,j);
		   printf("取款");
		   break;
	   case 2:
		   Gotoxy(i,j);
		   printf("转账转入");
		   break;
	   case 3:
		   Gotoxy(i,j);
		   printf("转账转出");
		   break;
	}
	i+=12;
	if(atoi(re->other_root)==0)
	{
		Gotoxy(i,j);
		printf("ATM");
	}
	else
	{
		Gotoxy(i,j);
		printf("%s",re->other_root);
	}
	
}
/*****************************************************************************************************************
* 函数名称： judge_time(char a[])
* 功能描述：
*			 用来判断时间是否规范/闰年/年月/输入规范性！
* 参数说明：
*          char a[]  传入的一段字符，用来判断是否满足  2018-02-02相关格式的要求。
* 返回值：无
*	创建时间:   2016-12-18
*	修改日期：  2016-12-18		修改人：王齐文
*	描述：
* 版本号：V1.0
******************************************************************************************************************/
int judge_time(char a[])//用来判断时间是否规范/闰年/年月/输入规范性！
{
	int c=0;
	char year[4]={0};
	char mon[2]={0};
	char day[2]={0};
	char now_time[20]={0};
	int i,j,x;
	time_t t;
	struct tm * lt;
	time (&t);//获取时间戳。
	lt=localtime (&t);//转换为时间结构
	
	sprintf(now_time,"%d-%0.2d-%0.2d",lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday);
    j=0;
	for(i=0;i<4;i++)
	{
		if(!(a[j]<='9'&&a[j]>='0'))
		{
			return 0;
		}
		year[i]=a[j];
		j++;
	}
	if(a[4]!='-'||a[7]!='-')
		return 0;
	j=5;
	for(i=0;i<2;i++)
	{
		if(!(a[j]<='9'&&a[j]>='0'))
		{
			return 0;
		}
		mon[i]=a[j];
		j++;
	}
	j=8;
	for(i=0;i<2;i++)
	{
		if(!(a[j]<='9'&&a[j]>='0'))
		{
			return 0;
		}
		day[i]=a[j];
		j++;
	}
	if(strcmp(now_time,a)<0)
		return 1;
	if(0<atoi(mon)<=12)
	{
		      if(atoi(mon)==1||atoi(mon)==5||atoi(mon)==3||atoi(mon)==7||atoi(mon)==8||atoi(mon)==10||atoi(mon)==12)
			  {
				  if(0<atoi(day)&&atoi(day)<=31)
				  {
					  return 2;
				  }
			  }
			  
			  if(atoi(mon)==4||atoi(mon)==6||atoi(mon)==9||atoi(mon)==11)
			  {
				  if(0<atoi(day)&&atoi(day)<=30)
				  {
					  return 2;
				  }
			  }
			  if(atoi(mon)==2)
			  {
				  if((atoi(year)%4==0)&&(atoi(year)%100!=0)||(atoi(year)%400==0))
				  {
					  if(0<atoi(day)&&atoi(day)<=29)
						  return 2;
				  }
				  else
				  {
					  if(0<atoi(day)&&atoi(day)<=28)
						  return 2;
				  }
			  }
	}
	return 0;
}
struct record *record_into(struct staff *data,int money_new,int a,int b)
{
	struct record *re;
	time_t t;
	struct tm * lt;
	time (&t);//获取时间戳。
	lt=localtime (&t);//转换为时间结构
	re=(struct record *)malloc(sizeof(struct record));
	memset(re,0,sizeof(struct record));
	strcpy(re->my_root,data->root);
	sprintf(re->change_money,"%d",money_new);
	strcpy(re->remain_money,data->money);
	sprintf(re->way,"%d",a);
	sprintf(re->time,"%d-%0.2d-%0.2d",lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday);
	sprintf(re->other_root,"%d",b);
	return re;
}

/*****************************************************************************************************************
* 函数名称：  show_if_deal(LIST_T *rhead)
* 功能描述：
*			 对比和打印时间查询的账单
* 参数说明：
*           LIST_T *rhead  需要查找的账单记录链表
* 返回值：
*	创建时间:   2016-12-18
*	修改日期：  2016-12-18		修改人：王齐文
*	描述：
* 版本号：V1.0
******************************************************************************************************************/

void show_if_deal(LIST_T *rhead)
{
	LIST_T *phead=NULL;
	int a=1,b=a+5;
	int x=0;
	char ch1;
	while(1)
	{

	    int i=1,j=7,nu=1;
		phead=rhead->next;
		system("cls");
		printf("           **********************************************************\n");
		printf("                                    时间查询账单      \n");
		printf("           **********************************************************\n");
		printf("\n\n");
		printf("         \n");
		printf("        序号       时间          金额         余额        摘要     交易发生源\n");
		printf("        \n");
		printf("        \n");
		printf("        \n");
		printf("        \n");
		printf("        \n");
		printf("        \n");
		printf("\n                      按    ↑    ↓     箭      翻     页  \n");
		printf("\n                                                             \n");
		printf("\n                             返回上一界面(esc)\n");
		printf(" \n\n\n           **********************************************************\n");
		if(rhead==NULL)
		{
		     Gotoxy(30,8);
			 printf("没有交易信息");
		}
		if(x==1)
		{
				Gotoxy(30,4);
						   printf("已经到达底部了");
		}
		if(x==2)
		{		       Gotoxy(30,4);
     					printf("已到达顶部");
		}
		
		x=0;
		while(phead!=NULL&&nu<a)
			{
					nu++;
				phead=phead->next;
			}
			while(phead!=NULL&&a<=b)
			{
					Deal_printf(phead->data, i, j,a);
					a++;
					j++;	
				phead=phead->next;
			}
		ch1=getch();
	    switch(ch1)
		{
		case 27:
			return 0;
			break;

		case 80:
			if(b<LIST_GetCount(rhead,NULL,0)+3)
			b+=6;
			break;
		case 72:
			if(b>=10)
				b-=6;
			else
			{
				x=2;
			}
			break;
		default: break;
		}
	    a=b-5; 
}
}