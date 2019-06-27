#include"staff.h"
#include"file.h"

int Manage_Menu();
int Search_Menu();
int ALL_Search_Menu(char c[]);//包含查询所有用户，查询管理员，查询用户。
int If_Search_Menu();
int User_Add_Menu();
int User_Del_Menu();
int User_Upd_Menu();
int if_Menu(LIST_T*phead,char a[]);