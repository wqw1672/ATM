#include"manage.h"

/*****************************************************************************************************************
* �������ƣ�Manage_Menu()
* ����������
*			 ��ӡ����Աģ��
* ����˵����
*          
* ����ֵ�� 
*	����ʱ�䣺	2018-12-06
*	�޸����ڣ�  2018-12-06		�޸��ˣ�������
*	������
* �汾�ţ�V1.0
******************************************************************************************************************/

int Manage_Menu()
{
	while(1)
	{
		
		char ch[1]={0};
		int back=0;
		system("cls");
		printf("           **********************************************************\n");
		printf("                                 ����Աģ��                      \n");
		printf("           **********************************************************\n");
		printf("\n\n");
		printf("                                1.�û���ѯ\n");
		printf("                                2.�û�����  \n");
		printf("                                3.�û�ɾ��  \n");
		printf("                                4.�û������޸�  \n");
		printf("                                5.�˳�ϵͳ\n");
		printf("\n                              ���ص�½ҳ��(esc)\n");
		printf(" \n\n\n           **********************************************************\n");
		Gotoxy(30,4);
		printf("������:");
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
* �������ƣ�Search_Menu()
* ����������
*			 ��ӡ����Ա�û���ѯģ��
* ����˵����
*          
* ����ֵ�� 
*	����ʱ�䣺	2018-12-06
*	�޸����ڣ�  2018-12-06		�޸��ˣ�������
*	������
* �汾�ţ�V1.0
******************************************************************************************************************/

int Search_Menu()
{
	while(1)
	{
		char ch[1]={0};
		int back=0;
        system("cls");
		printf("           **********************************************************\n");
		printf("                             ����Ա�û���ѯģ��                      \n");
		printf("           **********************************************************\n");
		printf("\n\n");
		printf("                                1.ȫ����ѯ\n");
		printf("                                2.��ѯ�û���Ϣ  \n");
		printf("                                3.��ѯ����Ա��Ϣ  \n");
		printf("                                4.������ѯ  \n");
		printf("                                5.�˳�ATM��\n");
		printf("\n                              ������һ����(esc)\n");
		printf(" \n\n\n           **********************************************************\n");
		Gotoxy(30,4);
		printf("������:");
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
* �������ƣ�ALL_Search_Menu(char c[])
* ����������
*			 ��ӡ��ѯ����Ϣ
* ����˵����
*          char c[]  ���atoi(c)Ϊ1 ���ȫ����Ϣ��2����û���Ϣ��3�������Ա��Ϣ
* ����ֵ�� 
*	����ʱ�䣺	2018-12-06
*	�޸����ڣ�  2018-12-06		�޸��ˣ�������
*	������
* �汾�ţ�V1.0
******************************************************************************************************************/

int ALL_Search_Menu(char c[])//atoi��c��Ϊ1�ǲ�ѯȫ����Ϣ��2�ǲ�ѯ�û���Ϣ��3�ǲ�ѯ����Ա��Ϣ
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
		printf("          ��  �˺�    ��   �û���  ��     ����    ��    ���   �� ��� ��\n");
		printf("          ��__________��___________��_____________��___________��______��\n");
		printf("          ��__________��___________��_____________��___________��______��\n");
		printf("          ��__________��___________��_____________��___________��______��\n");
		printf("          ��__________��___________��_____________��___________��______��\n");
		printf("          ��__________��___________��_____________��___________��______��\n");
		printf("          ��__________��___________��_____________��___________��______��\n");
		printf("          ��_________��___��____��____��______��________ҳ_____________��\n");
		printf("\n                               esc������һ��                                  \n");
		printf("\n                               ");
		printf(" \n           **********************************************************\n");
		if(x==1)
		{
				Gotoxy(30,4);
						   printf("�Ѿ�����ײ���");
		}
		if(x==2)
		{		       Gotoxy(30,4);
     	printf("�ѵ��ﶥ��");
		}
		if(atoi(c)==1)
		{
			Gotoxy(35,1);
			printf("ȫ����ѯ");
		}
		if(atoi(c)==2)
		{
			Gotoxy(35,1);
			printf("��ѯ�û���Ϣ");
		}
		if(atoi(c)==3)
		{
			Gotoxy(35,1);
			printf("��ѯ����Ա��Ϣ");
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
* �������ƣ�If_Search_Menu()
* ����������
*			 ��ӡ������ѯ����Ϣ
* ����˵����
*          
* ����ֵ�� 
*	����ʱ�䣺	2018-12-06
*	�޸����ڣ�  2018-12-06		�޸��ˣ�������
*	������
* �汾�ţ�V1.0
******************************************************************************************************************/

int If_Search_Menu()//����Ա������ѯ����������ģ�顣
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
		printf("                             ����Ա������ѯģ��                      \n");
		printf("           **********************************************************\n");
		printf("	                          ������һ����(esc)   \n\n");
		printf("         (�˺Ż��û���)�����������Ϣ:\n");
		printf("                        (���ó���10λ)\n");
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
* �������ƣ� if_Menu(LIST_T *head,char ch[])
* ����������
*			 ����Ա������ѯ�Ĳ���Ĳ鿴��ģ�顣
* ����˵����
*           LIST_T *head --�û������ͷ�ڵ� LIST_T *head --����Ĳ�����Ϣch  
* ����ֵ����
*	����ʱ��:   2016-12-18
*	�޸����ڣ�  2016-12-18		�޸��ˣ�������
*	������
* �汾�ţ�V1.0
******************************************************************************************************************/
int if_Menu(LIST_T *head,char ch[])//����Ա������ѯ�Ĳ���Ĳ鿴��ģ�顣
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
		printf("                             ����Ա������ѯģ��                      \n");
		printf("           **********************************************************\n");
		printf("\n\n");
		
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("                    ��     ��     ��    ��     ��      ҳ         \n ");
		printf("                                ��esc������һ��           \n ");
		printf("\n                               \n");
		printf("            **********************************************************\n");
		if(x==1)
		{
				Gotoxy(30,4);
						   printf("�Ѿ�����ײ���");
		}
		if(x==2)
		{		       Gotoxy(30,4);
     					printf("�ѵ��ﶥ��");
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
* �������ƣ� User_Add_Menu()
* ����������
*			 ����û���ģ���ӡ
* ����˵����
*           
* ����ֵ����
*	����ʱ��:   2016-12-18
*	�޸����ڣ�  2016-12-18		�޸��ˣ�������
*	������
* �汾�ţ�V1.0
******************************************************************************************************************/

int User_Add_Menu()//����û���ģ��
{
	
	while(1)
	{
		char ch[1]={0};
		int back=0;
		system("cls");
		printf("           **********************************************************\n");
		printf("                                 �û�����ģ��                         \n");
		printf("           **********************************************************\n");
		printf("\n\n");
		printf("                                1.����Ա���\n");
		printf("                                2.��ͨ�û����  \n");
		printf("                                3.�˳�ATMϵͳ\n");
		printf("\n                              ������һ��(esc)\n");
		printf(" \n\n\n           **********************************************************\n");
		Gotoxy(30,4);
		printf("������:");
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
* �������ƣ�  User_Del_Menu()
* ����������
*			 ɾ���û�ģ���ӡ
* ����˵����
*           
* ����ֵ����
*	����ʱ��:   2016-12-18
*	�޸����ڣ�  2016-12-18		�޸��ˣ�������
*	������
* �汾�ţ�V1.0
******************************************************************************************************************/

int User_Del_Menu()//ɾ���û�
{
	char ch1;
	FILE *fp=NULL;
	int judge;//�ж��Ƿ����û�
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
		printf("                                   ɾ��ģ��                          \n");
		printf("           **********************************************************\n");
		printf("\n           \n     \n");
		printf("   (8λ����)��������Ҫɾ���û����˺�:                                 \n");
		printf("                                                                     \n");
		printf("                                                                     \n");
		printf("\n                               \n");
		printf("\n                   \n");
		printf(" \n           **********************************************************\n");
		Gotoxy(15,3);
		printf("             esc������һ��          ");
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
						printf("ɾ���ɹ�!");
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
						printf("���û��������޷�ɾ��!");
					}
				}
				if(atoi(people->role)==1)
				{
					Gotoxy(34,8);
					printf("����Ա�޷�ɾ��!");
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
			printf("�����ڴ��û�!");
		}

			Gotoxy(20,10);
			printf("�����������ɾ��(esc�˻���һ��)");
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
* �������ƣ�  User_Upd_Menu()
* ����������
*			 �޸��û�����ģ���ӡ
* ����˵����
*           
* ����ֵ����
*	����ʱ��:   2016-12-18
*	�޸����ڣ�  2016-12-18		�޸��ˣ�������
*	������
* �汾�ţ�V1.0
******************************************************************************************************************/

int User_Upd_Menu()//�޸��û�����
{
	char ch1;
	FILE *fp=NULL;
	int judge;//�ж��Ƿ����û�
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
		printf("                                   �޸�����ģ��                          \n");
		printf("           **********************************************************\n");
		printf("\n           \n     \n");
		printf("            ��������Ҫ�޸�������˺�:                                 \n");
		printf("                                                                     \n");
		printf("                                                                     \n");
		printf("\n\n");
		printf("\n                   \n");
		printf("\n\n                         ������һ����(esc) \n           **********************************************************\n");

		
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
				printf("������ԭ����:");
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
					printf("������������:");
					Gotoxy(37,8);
					glb_putString(old_ch,5, 3,0);
					if(strlen(old_ch)<6)
					{
						Gotoxy(24,11);
						printf("���볤��С��6���޸�ʧ��");
						break;
					}
					else
					{
						Gotoxy(20,9);
						printf("���ٴ�����������:");
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
							printf("�ɹ��޸�����");
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
							printf("�������벻��ͬ");
							break;
						}
				}}
					if(strcmp(old_ch,people->passwd)!=0)
					{
						Gotoxy(32,8);
						printf("���������������!");
					}

				}
			
			phead=phead->next;
			count++;
		}
		
		if(judge==0)
		{
			Gotoxy(34,8);
			printf("�����ڴ��û�!");
		}
		Gotoxy(20,12);
		printf("������������޸�(esc�˻���һ��)");

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

