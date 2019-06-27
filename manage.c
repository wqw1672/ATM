#include"manage.h"

/*****************************************************************************************************************
* 函数名称：Manage_Menu()
* 功能描述：
*			 打印管理员模块
* 参数说明：
*          
* 返回值： 
*	创建时间：	2018-12-06
*	修改日期：  2018-12-06		修改人：王齐文
*	描述：
* 版本号：V1.0
******************************************************************************************************************/

int Manage_Menu()
{
	while(1)
	{
		
		char ch[1]={0};
		int back=0;
		system("cls");
		printf("           **********************************************************\n");
		printf("                                 管理员模块                      \n");
		printf("           **********************************************************\n");
		printf("\n\n");
		printf("                                1.用户查询\n");
		printf("                                2.用户增加  \n");
		printf("                                3.用户删除  \n");
		printf("                                4.用户密码修改  \n");
		printf("                                5.退出系统\n");
		printf("\n                              返回登陆页面(esc)\n");
		printf(" \n\n\n           **********************************************************\n");
		Gotoxy(30,4);
		printf("请输入:");
		back=glb_putString(ch, 0, 0,1);

		switch(*ch)
		{
		case '1':
			Search_Menu();
			break;
		case '2':
			User_Add_Menu();
			break;
		case '3':
			User_Del_Menu();
			break;
		case '4':
			User_Upd_Menu();
			break;
		case '5':
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
/*****************************************************************************************************************
* 函数名称：Search_Menu()
* 功能描述：
*			 打印管理员用户查询模块
* 参数说明：
*          
* 返回值： 
*	创建时间：	2018-12-06
*	修改日期：  2018-12-06		修改人：王齐文
*	描述：
* 版本号：V1.0
******************************************************************************************************************/

int Search_Menu()
{
	while(1)
	{
		char ch[1]={0};
		int back=0;
        system("cls");
		printf("           **********************************************************\n");
		printf("                             管理员用户查询模块                      \n");
		printf("           **********************************************************\n");
		printf("\n\n");
		printf("                                1.全部查询\n");
		printf("                                2.查询用户信息  \n");
		printf("                                3.查询管理员信息  \n");
		printf("                                4.条件查询  \n");
		printf("                                5.退出ATM机\n");
		printf("\n                              返回上一界面(esc)\n");
		printf(" \n\n\n           **********************************************************\n");
		Gotoxy(30,4);
		printf("请输入:");
		back=glb_putString(ch, 0, 0,1);
		switch(*ch)
		{
		case '1':
			ALL_Search_Menu(ch);
			break;
		case '2':
			ALL_Search_Menu(ch);
			break;
		case '3':
			ALL_Search_Menu(ch);
			break;
		case '4':
			If_Search_Menu();
			break;
		case '5':
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
/*****************************************************************************************************************
* 函数名称：ALL_Search_Menu(char c[])
* 功能描述：
*			 打印查询的信息
* 参数说明：
*          char c[]  如果atoi(c)为1 输出全部信息，2输出用户信息，3输出管理员信息
* 返回值： 
*	创建时间：	2018-12-06
*	修改日期：  2018-12-06		修改人：王齐文
*	描述：
* 版本号：V1.0
******************************************************************************************************************/

int ALL_Search_Menu(char c[])//atoi（c）为1是查询全部信息，2是查询用户信息，3是查询管理员信息
{
	FILE *fp=NULL;
	int i=1;
	int x=0;
	LIST_T *head=NULL,*phead=NULL;
	struct staff *data;
	fp=file_open("staff.txt");
    head=file_to_list(fp,sizeof(struct staff));
	fclose(fp);

	while(1)
	{
		char ch;

        system("cls");
		printf("           **********************************************************\n");
		printf("                                                        \n");
		printf("           **********************************************************\n");
		printf("\n\n");
		printf("           _____________________________________________________________\n");
		printf("          ｜  账号    ｜   用户名  ｜     密码    ｜    余额   ｜ 身份 ｜\n");
		printf("          ｜__________｜___________｜_____________｜___________｜______｜\n");
		printf("          ｜__________｜___________｜_____________｜___________｜______｜\n");
		printf("          ｜__________｜___________｜_____________｜___________｜______｜\n");
		printf("          ｜__________｜___________｜_____________｜___________｜______｜\n");
		printf("          ｜__________｜___________｜_____________｜___________｜______｜\n");
		printf("          ｜__________｜___________｜_____________｜___________｜______｜\n");
		printf("          ｜_________按___↑____↓____箭______翻________页_____________｜\n");
		printf("\n                               esc返回上一级                                  \n");
		printf("\n                               ");
		printf(" \n           **********************************************************\n");
		if(x==1)
		{
				Gotoxy(30,4);
						   printf("已经到达底部了");
		}
		if(x==2)
		{		       Gotoxy(30,4);
     	printf("已到达顶部");
		}
		if(atoi(c)==1)
		{
			Gotoxy(35,1);
			printf("全部查询");
		}
		if(atoi(c)==2)
		{
			Gotoxy(35,1);
			printf("查询用户信息");
		}
		if(atoi(c)==3)
		{
			Gotoxy(35,1);
			printf("查询管理员信息");
		}
        Search_Print(head,i,i+5,atoi(c));
		ch=getch();
		x=0;
		switch(ch)
		{
		case 27: 
			return 0;
			break;
		case 80:
			if(i<LIST_GetCount(head,NULL,0))
			{
			i+=6;
			}
			else
			{
               x=1;
			}
			break;
		case 72:
			if(i>=6)
				i-=6;
			else
			{
				x=2;
			}
			break;
		default: break;
		}
	}	
}
/*****************************************************************************************************************
* 函数名称：If_Search_Menu()
* 功能描述：
*			 打印条件查询的信息
* 参数说明：
*          
* 返回值： 
*	创建时间：	2018-12-06
*	修改日期：  2018-12-06		修改人：王齐文
*	描述：
* 版本号：V1.0
******************************************************************************************************************/

int If_Search_Menu()//管理员条件查询输入条件的模块。
{
	struct staff *people;
	LIST_T *head=NULL;
	char ch1;
	LIST_T *phead=NULL;
	
	FILE *fp=NULL;
	
	while(1)
	{
		
		char ch[10]={0};
		int back=0;
        system("cls");
		printf("           **********************************************************\n");
		printf("                             管理员条件查询模块                      \n");
		printf("           **********************************************************\n");
		printf("	                          返回上一界面(esc)   \n\n");
		printf("         (账号或用户名)请输入相关信息:\n");
		printf("                        (不得超过10位)\n");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n            \n");
		printf("\n                               )\n");
		printf("            **********************************************************\n");
		

		
		Gotoxy(38,5);
		back=glb_putString(ch, 9, 2, 1);
        if(back==1)
			return 0;
        fp=file_open("staff.txt");
        head=file_to_list(fp,sizeof(struct staff));
		phead=head->next;
		fclose(fp);
		Gotoxy(20,15);
		if_Menu(phead,ch);
	}
	return 0;
}

/*****************************************************************************************************************
* 函数名称： if_Menu(LIST_T *head,char ch[])
* 功能描述：
*			 管理员条件查询的查出的查看的模块。
* 参数说明：
*           LIST_T *head --用户链表的头节点 LIST_T *head --输入的查找信息ch  
* 返回值：无
*	创建时间:   2016-12-18
*	修改日期：  2016-12-18		修改人：王齐文
*	描述：
* 版本号：V1.0
******************************************************************************************************************/
int if_Menu(LIST_T *head,char ch[])//管理员条件查询的查出的查看的模块。
{
	LIST_T *phead=NULL;
	char ch1;
	int i=1;
	int x=0;
	while(1)
	{
		phead=head;
        system("cls");
		printf("           **********************************************************\n");
		printf("                             管理员条件查询模块                      \n");
		printf("           **********************************************************\n");
		printf("\n\n");
		
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("                    按     ↑     ↓    箭     翻      页         \n ");
		printf("                                按esc返回上一级           \n ");
		printf("\n                               \n");
		printf("            **********************************************************\n");
		if(x==1)
		{
				Gotoxy(30,4);
						   printf("已经到达底部了");
		}
		if(x==2)
		{		       Gotoxy(30,4);
     					printf("已到达顶部");
		}
        If_Search_Print(phead,ch,i,i+5);
		ch1=getch();
		x=0;
		switch(ch1)
		{
		case 27: 
			return 0;
			break;
		case 80:
			if(i<LIST_GetCount(head,NULL,0))
			{
			i+=6;
			}
			else
			{
               x=1;
			}
			break;
		case 72:
			if(i>=6)
				i-=6;
			else
			{
				x=2;
			}
			break;
		default: break;
		}
	}
}
/*****************************************************************************************************************
* 函数名称： User_Add_Menu()
* 功能描述：
*			 添加用户的模块打印
* 参数说明：
*           
* 返回值：无
*	创建时间:   2016-12-18
*	修改日期：  2016-12-18		修改人：王齐文
*	描述：
* 版本号：V1.0
******************************************************************************************************************/

int User_Add_Menu()//添加用户的模块
{
	
	while(1)
	{
		char ch[1]={0};
		int back=0;
		system("cls");
		printf("           **********************************************************\n");
		printf("                                 用户增加模块                         \n");
		printf("           **********************************************************\n");
		printf("\n\n");
		printf("                                1.管理员添加\n");
		printf("                                2.普通用户添加  \n");
		printf("                                3.退出ATM系统\n");
		printf("\n                              返回上一级(esc)\n");
		printf(" \n\n\n           **********************************************************\n");
		Gotoxy(30,4);
		printf("请输入:");
		back=glb_putString(ch, 0, 0,1);
		
		switch(*ch)
		{
		case '1':
			User_Add(atoi(ch));
			break;
		case '2':
			User_Add(atoi(ch));
			break;
		case '3':
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

/*****************************************************************************************************************
* 函数名称：  User_Del_Menu()
* 功能描述：
*			 删除用户模块打印
* 参数说明：
*           
* 返回值：无
*	创建时间:   2016-12-18
*	修改日期：  2016-12-18		修改人：王齐文
*	描述：
* 版本号：V1.0
******************************************************************************************************************/

int User_Del_Menu()//删除用户
{
	char ch1;
	FILE *fp=NULL;
	int judge;//判断是否有用户
	int count=0;
	LIST_T *head=NULL;
    LIST_T *phead=NULL;
	struct staff *people;
	
	while(1)
	{
		char ch[10]={0};
		int back=0;
		char ch1={0};
		system("cls");
		judge=0;
		fp=file_open("staff.txt");
		rewind(fp);
        head=file_to_list(fp,sizeof(struct staff));
		fclose(fp);
		phead=head->next;
		printf("           **********************************************************\n");
		printf("                                   删除模块                          \n");
		printf("           **********************************************************\n");
		printf("\n           \n     \n");
		printf("   (8位数字)请输入需要删除用户的账号:                                 \n");
		printf("                                                                     \n");
		printf("                                                                     \n");
		printf("\n                               \n");
		printf("\n                   \n");
		printf(" \n           **********************************************************\n");
		Gotoxy(15,3);
		printf("             esc返回上一级          ");
		Gotoxy(37,6);
		back=glb_putString(ch,7, 0,1);
        switch(back)
		{
		case 1:
            return 0;
			break;
		default:break;
		}
		while(phead!=NULL)
		{
			
			people=phead->data;
			if(strcmp(people->root,ch)==0&&atoi((people->state))==0)
			{
				if(atoi(people->role)==0)
				{
					if(atoi(people->money)==0)
					{   
						Gotoxy(34,8);
						printf("删除成功!");
						sprintf(people->state,"%d",1);
						fp=file_open("staff.txt");
						rewind(fp);
						fseek(fp,(sizeof(struct staff))*count,0);
						fwrite(people,sizeof(struct staff),1,fp);
						fclose(fp);
					}
					if(atoi(people->money)!=0)
					{
						Gotoxy(34,8);
						printf("该用户还有余额，无法删除!");
					}
				}
				if(atoi(people->role)==1)
				{
					Gotoxy(34,8);
					printf("管理员无法删除!");
				}
				judge=1;
				break;
			}
			phead=phead->next;
			count++;
		}
		
		if(judge==0)
		{
			Gotoxy(34,8);
			printf("不存在此用户!");
		}

			Gotoxy(20,10);
			printf("按任意键继续删除(esc退回上一级)");
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
* 函数名称：  User_Upd_Menu()
* 功能描述：
*			 修改用户密码模块打印
* 参数说明：
*           
* 返回值：无
*	创建时间:   2016-12-18
*	修改日期：  2016-12-18		修改人：王齐文
*	描述：
* 版本号：V1.0
******************************************************************************************************************/

int User_Upd_Menu()//修改用户密码
{
	char ch1;
	FILE *fp=NULL;
	int judge;//判断是否有用户
	int count;
	LIST_T *head=NULL;
    LIST_T *phead=NULL;
	struct staff *people;
	while(1)
	{
		char ch[10]={0};
		char new_ch[10]={0};
		char old_ch[10]={0};
		int back=0;
		count=0;
		
		judge=0;
		fp=file_open("staff.txt");
		rewind(fp);
        head=file_to_list(fp,sizeof(struct staff));
		fclose(fp);
		phead=head->next;
		system("cls");
		printf("           **********************************************************\n");
		printf("                                   修改密码模块                          \n");
		printf("           **********************************************************\n");
		printf("\n           \n     \n");
		printf("            请输入需要修改密码的账号:                                 \n");
		printf("                                                                     \n");
		printf("                                                                     \n");
		printf("\n\n");
		printf("\n                   \n");
		printf("\n\n                         返回上一界面(esc) \n           **********************************************************\n");

		
		Gotoxy(37,6);
		back=glb_putString(ch,7, 0,1);
		 switch(back)
		{
		case 1:
            return 0;
			break;
		default:break;
		}
		while(phead!=NULL)
		{	
			people=phead->data;
			if(strcmp(people->root,ch)==0&&atoi((people->state))==0)
			{
				judge=1;
				Gotoxy(24,7);
				printf("请输入原密码:");
				back=0;
				Gotoxy(37,7);
				back=glb_putString(old_ch,5, 3,0);
						 switch(back)
						{
						case 1:
							return 0;
							break;
						default:break;
						}
				if(strcmp(old_ch,people->passwd)==0)
				{	
					Gotoxy(24,8);
					printf("请输入新密码:");
					Gotoxy(37,8);
					glb_putString(old_ch,5, 3,0);
					if(strlen(old_ch)<6)
					{
						Gotoxy(24,11);
						printf("密码长度小于6，修改失败");
						break;
					}
					else
					{
						Gotoxy(20,9);
						printf("请再次输入新密码:");
						back=0;
						Gotoxy(37,9);
						back=glb_putString(new_ch,5, 3,0);
						 switch(back)
						{
						case 1:
							return 0;
							break;
						default:break;
						}
						if(strcmp(new_ch,old_ch)==0)
						{
							Gotoxy(24,11);
							printf("成功修改密码");
							strcpy(people->passwd,new_ch);
							fp=file_open("staff.txt");
							rewind(fp);
							fseek(fp,(sizeof(struct staff))*count,0);
							fwrite(people,sizeof(struct staff),1,fp);
							fclose(fp);
						}
						else
						{
							Gotoxy(20,11);
							printf("两次密码不相同");
							break;
						}
				}}
					if(strcmp(old_ch,people->passwd)!=0)
					{
						Gotoxy(32,8);
						printf("您输入的密码有误!");
					}

				}
			
			phead=phead->next;
			count++;
		}
		
		if(judge==0)
		{
			Gotoxy(34,8);
			printf("不存在此用户!");
		}
		Gotoxy(20,12);
		printf("按任意键继续修改(esc退回上一级)");

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

