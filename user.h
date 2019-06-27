#include"staff.h"
void User_Menu(struct staff *data);
void Money_Search(struct staff *data);
void Money_Add(struct staff *data);
struct record *record_into(struct staff *data,int money_new,int a,int b);
void Money_Get(struct staff *data);
void Money_Upd(struct staff *data);
void Passwd_Upd(struct staff *data);
void Deal_Memory(struct staff *data);
void All_Deal(struct staff *data);
void Search_Deal(LIST_T *head,struct staff *data,int a,int b);
void Deal_printf(void *p,int i,int j,int a);
void Time_Search(LIST_T *head,struct staff *data);
int judge_time(char a[]);
time_t Transformation(struct tm t);
void show_if_deal(LIST_T *rhead);