#ifndef _FILE_H_
#define _FILE_H_
#include"staff.h"
#include"public.h"
FILE *file_open(char *filename);
void file_add(FILE *fp,void *data,int size);
LIST_T *file_to_list(FILE *fp,int size);
void list_to_file(FILE *fp,void *head,int size);

#endif