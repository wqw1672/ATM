#include"file.h"
/*****************************************************************************************************************
* 函数名称： file_open(char *filename)
* 功能描述：
*			 实现 初始化文件 的功能  
* 参数说明：
*           无
* 返回值：  无
*	创建时间：	2018-12-06
*	修改日期：  2018-12-06		修改人：王齐文
*	描述：
* 版本号：V1.0
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
* 函数名称： file_add(FILE *fp,void *data,int size)
* 功能描述：
*			 将内容写入文件中
* 参数说明：
*           FILE *fp  输入文件的指针,void *data  需要存入文件的内容地址,int size  内容的大小
* 返回值：  无
*	创建时间：	2018-12-06
*	修改日期：  2018-12-06		修改人：王齐文
*	描述：
* 版本号：V1.0
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
* 函数名称： list_to_file(FILE *fp,void *head,int size)
* 功能描述：
*			 将链表写入文件
* 参数说明：
*           FILE *fp  输入文件的指针,void *head  从文件输入链表的头结点 ,int size  内容的大小
* 返回值：  无
*	创建时间：	2018-12-06
*	修改日期：  2018-12-06		修改人：王齐文
*	描述：
* 版本号：V1.0
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

