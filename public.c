#include"public.h"
int Gotoxy(int x, int y)
{
	HANDLE handle;
	COORD coord;
	coord.X = x;
	coord.Y = y;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, coord);
	return 0;
}

int glb_putString(char str[], int maxLen, int putType, int isPlaintext)//输入函数
{
	char ch=0,ch1=0;
	int ilen=0,add=0,i,j;

	while(1)
	{
		int b=0;
		ch=getch();
		if(ch==27)
		{
			return 1;
		}
			if(ch==75)//←
			{
				
				if(ilen>add)
				{
					add++;
					printf("\b");
				}

			}
			if(ch==77)//→ 
			{
				if(0<add)
				{
							if(1==isPlaintext)
							{
								putchar(str[ilen-add]);
							}
							else
							{
								putchar('*');
							}
					add--;
				}

		}
		if(ch=='\r')
		{ 
				if(ilen)
			{ 
					str[ilen]='\0';
			        break;
			} 
				if(!ilen)
				{
					printf("输入不能为空");
					getch();
		            printf("\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b");
					continue;
				}
		}
		if(ch=='\b')
		{ 
			if(ilen)
			{
				printf("\b \b");
                for(i=ilen-add-1;i<ilen-1;i++)
				{
				   str[i]=str[i+1];
				}
                if(1==isPlaintext)
					{
						for(i=ilen-add-1;i<ilen-1;i++)
						{
							printf("%c",str[i]);
							if(i==ilen-2)
							{
							  printf(" \b");
							}
						}
						for(j=0;j<add;j++)
						{
							printf("\b");
						}
                       
					}
				else
					{
					for(i=ilen-add-1;i<ilen-1;i++)
						{
							printf("*");
							if(i==ilen-2)
							{
							  printf(" \b");
							}
						}
						for(j=0;j<add;j++)
						{
							printf("\b");
						}
					}

				str[ilen]='\0';
				ilen--;
			}
		}
		if(ilen<=maxLen&&ch!='\b'&&ch!=77&&ch!=75 )
		{ 
			switch(putType)
			{
				case 0:
				{
					if(ch>='0'&&ch<='9')
					{
						for(i=ilen;i>ilen-add;i--)
						{
						   str[i]=str[i-1];
						}

						if(1==isPlaintext)
						{
							putchar(ch);
							for(i=ilen-add+1;i<=ilen;i++)
							{
								printf("%c",str[i]);
							}
							for(j=0;j<add;j++)
							{
								printf("\b");
							}

						}
						else
						{
							putchar('*');
							for(i=ilen-add+1;i<=ilen;i++)
							{
								printf("*");
							}
							for(j=0;j<add;j++)
							{
								printf("\b");
							}

						}
                        



						str[ilen-add]=ch;
						ilen++;
					}
				};break;
				case 1:
				{
						if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))   
					   {
							for(i=ilen;i>ilen-add;i--)
						{
						   str[i]=str[i-1];
						}

						if(1==isPlaintext)
						{
							putchar(ch);
							for(i=ilen-add+1;i<=ilen;i++)
							{
								printf("%c",str[i]);
							}
							for(j=0;j<add;j++)
							{
								printf("\b");
							}

						}
						else
						{
							putchar('*');
							for(i=ilen-add+1;i<=ilen;i++)
							{
								printf("*");
							}
							for(j=0;j<add;j++)
							{
								printf("\b");
							}

						}
                        



						str[ilen-add]=ch;
						ilen++;
					}
				};break;
				case 2:
					{
						if((ch>='0'&&ch<='9')||(ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
					   {
						  	for(i=ilen;i>ilen-add;i--)
						{
						   str[i]=str[i-1];
						}

						if(1==isPlaintext)
						{
							putchar(ch);
							for(i=ilen-add+1;i<=ilen;i++)
							{
								printf("%c",str[i]);
							}
							for(j=0;j<add;j++)
							{
								printf("\b");
							}

						}
						else
						{
							putchar('*');
							for(i=ilen-add+1;i<=ilen;i++)
							{
								printf("*");
							}
							for(j=0;j<add;j++)
							{
								printf("\b");
							}

						}
                        



						str[ilen-add]=ch;
						ilen++;
					}
				};break;
				case 3:
						for(i=ilen;i>ilen-add;i--)
						{
						   str[i]=str[i-1];
						}

						if(1==isPlaintext)
						{
							putchar(ch);
							for(i=ilen-add+1;i<=ilen;i++)
							{
								printf("%c",str[i]);
							}
							for(j=0;j<add;j++)
							{
								printf("\b");
							}

						}
						else
						{
							putchar('*');
							for(i=ilen-add+1;i<=ilen;i++)
							{
								printf("*");
							}
							for(j=0;j<add;j++)
							{
								printf("\b");
							}

						}
                        



						str[ilen-add]=ch;
						ilen++;
					break;	
				default: break;
					
			}
			
			
		}		
		
	}printf("\n");
	
	
	return 0;
}



