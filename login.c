#include"login.h"
#include"manage.h"
#include"user.h"
/*****************************************************************************************************************
* 函数名称： login()
* 功能描述：
*			 登录函数的页面显示和判定
* 参数说明：
*           
* 返回值：  无
*	创建时间：	2018-12-06
*	修改日期：  2018-12-06		修改人：王齐文
*	描述：
* 版本号：V1.0
******************************************************************************************************************/

void login()
{
	while(1)
	{
	char a[9]={0};
	char b[8]={0};
	char ch;//用来判断是否需要初始化输入初始账号密码
	int sta=0;
	int i=0;//用来判断role
	int back=0;//判断是否按了esc
	FILE *fp=NULL;
    LIST_T *head=NULL,*phead=NULL;
	struct staff *data;
	fp=file_open("staff.txt");
	ch=fgetc(fp);
	fclose(fp);
    if(ch==EOF)//判断是否文件为空
		First_Add();
	system("cls");
	printf("           **********************************************************\n");
	printf("                                 ATM机登录界面                       \n");
	printf("           **********************************************************\n");
	printf("\n\n");
	printf("             (8位)账号/用户名:\n");
	printf("\n                    (6位)密码:  \n");
	printf("\n\n                            esc 退出系统");
	printf("\n\n           **********************************************************\n");
	fp=file_open("staff.txt");
    head=file_to_list(fp,sizeof(struct staff));
	fclose(fp);
	Gotoxy(30,5);
	back=glb_putString(a,7, 2,1);
	if(back==1);
    back=back_system(back,1);
	if(back==2)
		return 0;
	if(back==3)
		continue;
	phead=People_Root(a,head);
	if(phead==0)
	{
				Gotoxy(30,9);
				printf("该用户不存在");
				getch();
				sta=1;
	}
    if(phead!=0)//如果账号正确
	{
		Gotoxy(30,7);
		glb_putString(b,5, 2,0);
		phead=People_Passwd(b,phead);
	}
	if(phead==0&&sta==0)
	{
		Gotoxy(24,9);
		printf("密码错误，按任意键重新输入");
		getch();
	}
    if(phead!=0)
	{   
        data=(struct staff *)malloc(sizeof(struct staff));
		memset(data,0,sizeof(struct staff));
		data=phead->data;
        i=atoi(data->role);
		switch(i)
		{
		      case 1:
				  Manage_Menu();
				  break;
			  case 0:
                  User_Menu(data->root);
					break;
		};
	}
	}
}
/*****************************************************************************************************************
* 函数名称：back_system(int back,int judge)
* 功能描述：
*			 打印是否退格的表格
* 参数说明：
*           int back  判断是否需要退出 int judge 判断是注销还是退出
* 返回值：  无
*	创建时间：	2018-12-06
*	修改日期：  2018-12-06		修改人：王齐文
*	描述：
* 版本号：V1.0
******************************************************************************************************************/

int back_system(int back,int judge)//打印出是否退出的表格
{
	if(back==1)
	{
		char a[1];
      Gotoxy(29,18);
	  printf("_________________");
      Gotoxy(29,19);
	  printf("|               |");
	  Gotoxy(29,20);
	  printf("|               |");
	  Gotoxy(29,21);
	  printf("|               |");
	  Gotoxy(29,22);
	  printf("|_______________|");
      if(judge==1){
	  Gotoxy(30,19);
	  printf("是否退出系统");}
	  if(judge==2){
	  Gotoxy(30,19);
	  printf("是否返回上一级");}
      Gotoxy(30,20);
	  printf("1.确认  2.取消");
      Gotoxy(30,21);
	  printf("请输入:");
	  while(1)
	  {
	  Gotoxy(37,21);
      glb_putString(a,0, 0,1);
	  switch(atoi(a))
	  {
	  case 1:
		  back=2;
		  return 2;
	  case 2:
		  back=3;
	      return 3;
      default:
       Gotoxy(37,21);
	  printf(" ");
			  break;
	  }
	  }
	}
}

void First_Add()//系统自带三个 单位，两个用户mike,tiger，一个管理员rose
{
   	struct staff *data;
	LIST_T *head=NULL;
	FILE *fp;
	head=People_init(NULL);	 
	data=(struct staff *)malloc(sizeof(struct staff));
	memset(data,0,sizeof(struct staff));
    strcpy(data->root,"18060136");
    strcpy(data->name,"tiger");
    strcpy(data->passwd,"123456");
	strcpy(data->money,"5000");
    strcpy(data->role,"0");
	strcpy(data->state,"0");


    People_Add(head,data);
	data=(struct staff *)malloc(sizeof(struct staff));
	memset(data,0,sizeof(struct staff));
    strcpy(data->root,"18060138");
    strcpy(data->name,"rose");
    strcpy(data->passwd,"123456");
    strcpy(data->role,"1");
	strcpy(data->state,"0");
	strcpy(data->money,"0");


	People_Add(head,data);


	data=(struct staff *)malloc(sizeof(struct staff));
	memset(data,0,sizeof(struct staff));
    strcpy(data->root,"18060137");
    strcpy(data->name,"mike");
    strcpy(data->passwd,"123456");
	strcpy(data->money,"10000");
    strcpy(data->role,"0");
	strcpy(data->state,"0");

    People_Add(head,data);


	fp=file_open("staff.txt");
	list_to_file(fp,head,sizeof(struct staff));
	fclose(fp);
}