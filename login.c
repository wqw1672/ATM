#include"login.h"
#include"manage.h"
#include"user.h"
/*****************************************************************************************************************
* �������ƣ� login()
* ����������
*			 ��¼������ҳ����ʾ���ж�
* ����˵����
*           
* ����ֵ��  ��
*	����ʱ�䣺	2018-12-06
*	�޸����ڣ�  2018-12-06		�޸��ˣ�������
*	������
* �汾�ţ�V1.0
******************************************************************************************************************/

void login()
{
	while(1)
	{
	char a[9]={0};
	char b[8]={0};
	char ch;//�����ж��Ƿ���Ҫ��ʼ�������ʼ�˺�����
	int sta=0;
	int i=0;//�����ж�role
	int back=0;//�ж��Ƿ���esc
	FILE *fp=NULL;
    LIST_T *head=NULL,*phead=NULL;
	struct staff *data;
	fp=file_open("staff.txt");
	ch=fgetc(fp);
	fclose(fp);
    if(ch==EOF)//�ж��Ƿ��ļ�Ϊ��
		First_Add();
	system("cls");
	printf("           **********************************************************\n");
	printf("                                 ATM����¼����                       \n");
	printf("           **********************************************************\n");
	printf("\n\n");
	printf("             (8λ)�˺�/�û���:\n");
	printf("\n                    (6λ)����:  \n");
	printf("\n\n                            esc �˳�ϵͳ");
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
				printf("���û�������");
				getch();
				sta=1;
	}
    if(phead!=0)//����˺���ȷ
	{
		Gotoxy(30,7);
		glb_putString(b,5, 2,0);
		phead=People_Passwd(b,phead);
	}
	if(phead==0&&sta==0)
	{
		Gotoxy(24,9);
		printf("������󣬰��������������");
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
* �������ƣ�back_system(int back,int judge)
* ����������
*			 ��ӡ�Ƿ��˸�ı��
* ����˵����
*           int back  �ж��Ƿ���Ҫ�˳� int judge �ж���ע�������˳�
* ����ֵ��  ��
*	����ʱ�䣺	2018-12-06
*	�޸����ڣ�  2018-12-06		�޸��ˣ�������
*	������
* �汾�ţ�V1.0
******************************************************************************************************************/

int back_system(int back,int judge)//��ӡ���Ƿ��˳��ı��
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
	  printf("�Ƿ��˳�ϵͳ");}
	  if(judge==2){
	  Gotoxy(30,19);
	  printf("�Ƿ񷵻���һ��");}
      Gotoxy(30,20);
	  printf("1.ȷ��  2.ȡ��");
      Gotoxy(30,21);
	  printf("������:");
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

void First_Add()//ϵͳ�Դ����� ��λ�������û�mike,tiger��һ������Աrose
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