#include"file.h"
/*****************************************************************************************************************
* �������ƣ� file_open(char *filename)
* ����������
*			 ʵ�� ��ʼ���ļ� �Ĺ���  
* ����˵����
*           ��
* ����ֵ��  ��
*	����ʱ�䣺	2018-12-06
*	�޸����ڣ�  2018-12-06		�޸��ˣ�������
*	������
* �汾�ţ�V1.0
******************************************************************************************************************/

FILE *file_open(char *filename)
{
   FILE *fp=NULL;
   fp=fopen(filename,"r+");
   if(!fp)
   {
      fp=fopen(filename,"w+");
   }
   return fp;
}
/*****************************************************************************************************************
* �������ƣ� file_add(FILE *fp,void *data,int size)
* ����������
*			 ������д���ļ���
* ����˵����
*           FILE *fp  �����ļ���ָ��,void *data  ��Ҫ�����ļ������ݵ�ַ,int size  ���ݵĴ�С
* ����ֵ��  ��
*	����ʱ�䣺	2018-12-06
*	�޸����ڣ�  2018-12-06		�޸��ˣ�������
*	������
* �汾�ţ�V1.0
******************************************************************************************************************/

void file_add(FILE *fp,void *data,int size)
{
   fseek(fp,0,SEEK_END);
    fwrite(data,size,1,fp);
		fflush(fp);
}
LIST_T *file_to_list(FILE *fp,int size)
{
    LIST_T *head=NULL;
	void *data=NULL;
		data=malloc(size);
	memset(data,0,size);
	head=People_init(NULL);
    rewind(fp);
	while(fread(data,size,1,fp)>0)
	{
    People_Add(head,data);
	data=malloc(size);
	memset(data,0,size);
	}
	fflush(fp);
    return head;
}
/*****************************************************************************************************************
* �������ƣ� list_to_file(FILE *fp,void *head,int size)
* ����������
*			 ������д���ļ�
* ����˵����
*           FILE *fp  �����ļ���ָ��,void *head  ���ļ����������ͷ��� ,int size  ���ݵĴ�С
* ����ֵ��  ��
*	����ʱ�䣺	2018-12-06
*	�޸����ڣ�  2018-12-06		�޸��ˣ�������
*	������
* �汾�ţ�V1.0
******************************************************************************************************************/

void list_to_file(FILE *fp,void *head,int size)
{
  	LIST_T *p;
	int x;
	p=head;
    while(p->next!=NULL)
	{
		p=p->next;
	   fseek(fp,0,SEEK_END);
	   x=fwrite(p->data,size,1,fp);
	   fflush(fp);
	}
	LIST_Free(head);
}

