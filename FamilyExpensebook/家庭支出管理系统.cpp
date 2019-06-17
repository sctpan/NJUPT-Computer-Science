#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
typedef struct date                            							 //定义日期结构体 
	{
		int year;
		int month;
		int day;
	}date;
typedef struct expend                                                   //定义支出信息结构体 
	{
		date time;
		int type;
		double money;
		char remark[18];
	}expend;
typedef struct analyze                                                 //定义分析结构体以方便排序 
	{
		char type[10];
		double money;
	}analyze;	
void cursor(int n,int m);                                                 //控制光标位置 
void start();                                                              //开始界面 
void finish();                                     						   //结束界面 
void med();                                                                //边框样式一 
void med2();															  //边框样式二 
void med3();															  //边框样式三 
void reg(expend exp[],int cnt[]);										  //注册 
void menu(expend exp[],int cnt[]); 										  //注册界面	
void menu2(expend exp[],int cnt[]);										  //登录界面 
void menu3(expend exp[],int cnt[]);										  //主界面 
void menu4(expend exp[],int cnt[]);                                      //查询界面 
void menu5(expend exp[],int cnt[]);										 //分析界面 
void save(char c[],char d[]);											//保存用户名和密码 
void filesave(expend n,expend ex[],int cnt[]);								//保存新增记录 
void filesave2(expend exp[],int cnt[],int year,int month,double sum);                    //保存按月查询结果 
void filesave3(expend exp[],int cnt[],int y1,int m1,int d1,int y2,int m2,int d2,double sum);    //保存按区间查询结果 
void create();                                                            //创建文件以区分是否第一次使用 
void read(int n,char str[]);                                              //读取用户名和密码文件 
void readfile(expend exp[],int cnt[]);                                    //将所有记录读取至结构体数组 
void record(expend ex[],int cnt[]);                                       //新增记录 
void monthana(expend exp[],int cnt[]);									//按月分析 
void yearana(expend exp[],int cnt[]);										//按年分析 
void daycheck(expend exp[],int cnt[]);										//按日查询 
void monthcheck(expend exp[],int cnt[]);                                  //按月查询 
void intercheck(expend exp[],int cnt[]);                                  //按年查询 
void password(char p[]);                                                 //隐藏密码 
void sort1(expend exp[],int cnt[]);                                      //按日期排序 
void sort2(analyze ana[],int n);                                         //按金额排序 
int datejudge(int y, int m, int d);                                      //日期合法性检查 
int interjudge(int y,int m,int d);                                      //日期大小比较 

int main()
{
	start();										//开始界面 
	Sleep(3000);
	system("CLS");
	expend exp[30000];									//定义结构体数组以存储所有支出信息 
	int cnt[1]={0};										//定义一个单元素数组存储结构体长度 
	FILE *fp;											//判断是否第一次使用系统 
	fp=fopen("D:\\code.txt","r");
	if(fp==0)
	{
		fclose(fp);
		menu(exp,cnt);
	}
	else
	{
		menu2(exp,cnt);
	}
}

void cursor(int n,int m)                             //控制光标位置 
{
	HANDLE hout;
	COORD coord;
	coord.X=n;
	coord.Y=m;
	hout=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout,coord);
}

void start()
{
	printf("                                                                  \n");
	printf("      ┏·━·━·━·━·━·━·━·━·━·━·━·━·━·━·━·┓ \n");
    printf("      ·  ◇                                                          · \n");
	printf("      ┃─┼────                                                  ┃ \n");
	printf("      ·  │                                                          · \n");
	printf("      ┃  │                                                          ┃ \n");
	printf("      ·     ∧＿∧                                                   · \n");
	printf("      ┃   （·ω·)つ━☆..  ·*。                                   ┃ \n");
	printf("      ·   ㄈ　　  ノ 　  　　☆  ゜+.                                · \n");
	printf("      ┃    し ー Ｊ　  　　°。+ *′¨)                              ┃ \n"); 
	printf("      ·                          .·☆゜*¨) .·*¨                  · \n");
	printf("      ┃                              (.·′☆.·’*                  ┃ \n");
	printf("      ·                                                              · \n");
	printf("      ┃                                                              ┃ \n");
	printf("      ·                  >>>欢迎登录柚子财富家庭支出管理系统<<<      · \n");
	printf("      ┃                      >>>Welcome to use the system!<<<        ┃ \n");
	printf("      ·                         By  潘一帆  蒋文超  陈璇         │  · \n");
	printf("      ┃                                                          │  ┃ \n");
	printf("      ·                                                  ────┼─· \n");
	printf("      ┃                                                          ◇  ┃ \n");
	printf("      ·▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼· \n");
	printf("      ┗·━·━·━·━·━·━·━·━·━·━·━·━·━·━·━·┛ \n");
}

void finish()
{
	printf("                                                                  \n");
	printf("      ┏·━·━·━·━·━·━·━·━·━·━·━·━·━·━·━·┓ \n");
    printf("      ·▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼· \n");
	printf("      ┃                                                              ┃ \n");
	printf("      ·                                                              · \n");
	printf("      ┃               ∧ ∧                                          ┃ \n");
	printf("      ·            (  - з -)                                        · \n");
	printf("      ┃      ┌────〇〇───────────┐                  ┃ \n");
	printf("      ·      │                                  │                  · \n");
	printf("      ┃      │           ※感谢使用※           │                  ┃ \n"); 
	printf("      ·      │    ※柚子财富家庭支出管理系统※  │                  · \n");
	printf("      ┃      │         ※谢谢您的支持※         │                  ┃ \n");
	printf("      ·      │           ※BYE  BYE※           │                  · \n");
	printf("      ┃      │         ※欢迎下次登录※         │                  ┃ \n");
	printf("      ·      └─────────────────┘                  · \n");
	printf("      ┃                                                              ┃ \n");
	printf("      ·                                 ┈ ┈ .o┈ ﹎  ﹎.. ○       · \n");
	printf("      ┃                              ﹎┈﹎ ●  ○ .﹎ ﹎o▂▃▅▆   ┃ \n");
	printf("      ·                              ┈ ┈- █▓ ﹎ ┈ ﹎﹎ ┈ ﹎   · \n");
	printf("      ┃                              ▅▆▇█████▇▆▅▃▂┈﹎  ┃ \n");
	printf("      ·▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼· \n");
	printf("      ┗·━·━·━·━·━·━·━·━·━·━·━·━·━·━·━·┛ \n");
}

void med()												//边框样式一 
{
	int i,j;
	cursor(0,0);
	for(i=0;i<5;i++)
	printf("\n");
	for(i=0;i<20;i++)
	printf(" ");
	for(i=0;i<20;i++)
	printf("* ");
	printf("\n");
	for(i=0;i<15;i++)
	{
		for(j=0;j<20;j++)
		printf(" ");
		printf("*");
		for(j=0;j<37;j++)
		printf(" ");
		printf("*\n");
	}
	for(i=0;i<20;i++)
	printf(" ");
	for(i=0;i<20;i++)
	printf("* ");
	printf("\n");
}

void med2()														//边框样式二 
{
	cursor(0,0);
	int i,j;
	for(i=0;i<3;i++)
	printf("\n");
	for(i=0;i<12;i++)
	printf(" ");
	for(i=0;i<30;i++)
	printf("* ");
	printf("\n");
	for(i=0;i<290;i++)
	{
		for(j=0;j<12;j++)
		printf(" ");
		printf("*");
		for(j=0;j<57;j++)
		printf(" ");
		printf("*\n");
	}
	for(i=0;i<12;i++)
	printf(" ");
	for(i=0;i<30;i++)
	printf("* ");
	printf("\n");
}

void med3()														//边框样式三 
{
	cursor(0,0);
	int i,j;
	for(i=0;i<3;i++)
	printf("\n");
	for(i=0;i<12;i++)
	printf(" ");
	for(i=0;i<29;i++)
	printf("* ");
	printf("\n");
	for(i=0;i<20;i++)
	{
		for(j=0;j<12;j++)
		printf(" ");
		printf("*");
		for(j=0;j<55;j++)
		printf(" ");
		printf("*\n");
	}
	for(i=0;i<12;i++)
	printf(" ");
	for(i=0;i<29;i++)
	printf("* ");
	printf("\n");
}

void menu(expend exp[],int cnt[])												//注册界面 
{
	int i;
	char x;
	char a[20];
	char b[20];
	med();
	cursor(27,10);
	printf("-------- 1.注册 --------");
	cursor(27,11);
	printf("-------- 2.退出 --------");
	cursor(27,12);
	scanf("%c",&x);
	system("CLS");
	switch(x)
	{
	case '1':     reg(exp,cnt);
	case '2':     system("CLS");
					finish();
	               Sleep(3000);
			      exit(1);
	default:    menu(exp,cnt);
	}
}

void reg(expend exp[],int cnt[])												//注册程序 
{
				char c[20];
				char d[20];
				char e[20];
				int i;
				med();
				cursor(30,8);
				printf("请设置用户名");
				cursor(30,9);
				scanf("%s",c);
				cursor(30,10);
				printf("请设置密码");
				cursor(30,11);
				password(d);
				cursor(30,12);
				printf("请确认密码");
				cursor(30,13);
				password(e);
				cursor(30,14);
				if(strcmp(d,e)==0)
				{
					printf("注册成功!");
					cursor(30,15);
					save(c,d);
					create();
					printf("3秒钟后返回");
					cursor(30,16);
					for(i=3;i>=1;i--)
					{
						printf("%d",i);
						Sleep(1000);
						cursor(30,16);
					}
					system("CLS");
					menu2(exp,cnt); 
				}
				else
				{
					cursor(30,15);
					printf("密码不一致，请重新注册!");
					cursor(30,16);
					printf("3秒钟后返回");
					cursor(30,17);
					for(i=3;i>=1;i--)
					{
						printf("%d",i);
						Sleep(1000);
						cursor(30,17);
					}
					system("CLS");
					reg(exp,cnt);
				}
}

void menu2(expend exp[],int cnt[])								//登录界面 
{
	int i=0,ct=0;
	char x;
	char a[20];
	char b[20];
	char a2[20];
	char b2[20];
	med();
	cursor(27,10);
	printf("-------- 1.登录 --------");
	cursor(27,11);
	printf("-------- 2.退出 --------");
	cursor(27,12);
	scanf("%c",&x);
	cursor(27,13);
	system("CLS");
	switch(x)
	{
	case '1':		read(1,a2);
				med();
				cursor(30,8);	
				printf("欢迎您，尊敬的%s\n",a2);
				cursor(30,9); 
				printf("请输入密码\n");
				cursor(30,10);
				password(b);
				cursor(30,11);
				read(2,b2);
				if(strcmp(b,b2)==0)
					{
						printf("登陆成功!\n");
						cursor(27,14);
						printf("欢迎访问家庭支出管理系统!");
						readfile(exp,cnt);
						Sleep(800);
						system("CLS");
						menu3(exp,cnt);
					}
				while(strcmp(b,b2)!=0)
				{
					
					if(ct>2)
					{
						printf("密码输错三次，程序自动关闭！");
						i++;
						cursor(30,11+i);
						Sleep(1000);
						exit(1);	
					}
					printf("密码错误，请重新输入\n");
					i++;
					ct++;
					cursor(30,11+i);
					password(b);
					i++;
					if(strcmp(b,b2)==0)
					{
						cursor(30,11+i);
						printf("登陆成功!\n");
						i++;
						cursor(27,13+i);
						printf("欢迎访问家庭支出管理系统!");
						readfile(exp,cnt);
						Sleep(1500);
						system("CLS");
						menu3(exp,cnt);
					}
					cursor(30,11+i);
				}
				break;
	case '2':   system("CLS");
				finish();
				Sleep(3000);  
				exit(1);
	default: menu2(exp,cnt);
	}
}

void menu3(expend exp[],int cnt[])												//主界面 
{
	char x;
	med();
	cursor(25,10);
	printf("-------- 1.增加记录 --------");
	cursor(25,11);
	printf("-------- 2.消费查询 --------");
	cursor(25,12);
	printf("-------- 3.消费分析 --------");
	cursor(25,13);
	printf("-------- 4.注    销 --------"); 
	cursor(25,14);
	scanf("%c",&x);
	switch(x)
	{
		case '1': record(exp,cnt);
		case '2': menu4(exp,cnt);
		case '3':menu5(exp,cnt);
		case '4': menu2(exp,cnt);
		default: menu3(exp,cnt);
	}
}

void menu4(expend exp[],int cnt[])											//查询界面 
{
	char x;
	system("CLS");
	med();
	cursor(25,10);
	printf("-------- 1.按日查询 --------");
	cursor(25,11);
	printf("-------- 2.按月查询 --------");
	cursor(25,12);
	printf("-------- 3.区间查询 --------");
	cursor(25,13);
	printf("-------- 4.返    回 --------");
	cursor(25,14);
	scanf("%c",&x);
	switch(x)
	{
		case '1': daycheck(exp,cnt);
		case '2': monthcheck(exp,cnt);
		case '3': intercheck(exp,cnt);
		case '4': menu3(exp,cnt);
		default: menu4(exp,cnt);
	}
}

void menu5(expend exp[],int cnt[])										//分析界面 
{
	char x;
	system("CLS");
	med();
	cursor(25,10);
	printf("-------- 1.按月分析 --------");
	cursor(25,11);
	printf("-------- 2.按年分析 --------");
	cursor(25,12);
	printf("-------- 3.返    回 --------");
	cursor(25,13);
	scanf("%c",&x);
	switch(x)
	{
		case '1': monthana(exp,cnt);
		case '2': yearana(exp,cnt);
		case '3': menu3(exp,cnt);
		default: menu5(exp,cnt);
	}	
}

void save(char c[],char d[])											//保存用户名和密码 
{
	FILE *fp;
	fp=fopen("D:\\code.txt","w+");
	fputs(c,fp);
	fputc('\n',fp);
	fputs(d,fp);
	fputc('\n',fp);
	fclose(fp);
}

void filesave(expend n,expend ex[],int cnt[])								//保存新增记录 
{
	int m;
	FILE *fp;
	fp=fopen("D:\\expend.txt","a+");
	fprintf(fp,"%d %d %d %d %f %s\n",n.time.year,n.time.month,n.time.day,n.type,n.money,n.remark);
	fclose(fp);
	m=cnt[0];
	ex[m].time.year=n.time.year;
	ex[m].time.month=n.time.month;
	ex[m].time.day=n.time.day;
	ex[m].type=n.type;
	ex[m].money=n.money;
	strcpy(ex[m].remark,n.remark);
	cnt[0]++;	
}

void filesave2(expend exp[],int cnt[],int year,int month,double sum)           //保存按月查询结果 
{
	int i,j;
	char name[25];
	char num[25];
	strcpy(name,"D:\\");
	int y=year;
	int m=month;
	for(i=0;i<4;i++)
	{
		
		num[i]=y/int(pow(10,3-i))+48;
		y=y%int(pow(10,3-i));
	}
	num[4]='-';
	for(i=5;i<7;i++)
	{
		
		num[i]=m/int(pow(10,6-i))+48;
		m=m%int(pow(10,6-i));
	}
	strcat(name,num);
	strcat(name,"消费详情.txt");
	cursor(0,0);
	printf("%s",name);
	FILE *fp;
	fp=fopen(name,"w+");
	fprintf(fp,"               总计:  %.2f元\n",sum);
	fprintf(fp,"消费日期      消费种类    消费金额       备注\n");
	for(j=0;j<cnt[0];j++)
  	{   
	  if(year==exp[j].time.year&&month==exp[j].time.month)
	  {
		fprintf(fp,"%d年%d月%d日      ",exp[j].time.year,exp[j].time.month,exp[j].time.day); 
		switch(exp[j].type)
	  {
		case 1: fprintf(fp,"饮食");break;
		case 2: fprintf(fp,"学习");break;
		case 3: fprintf(fp,"医疗");break;
		case 4: fprintf(fp,"交通");break;
		case 5: fprintf(fp,"水电");break;
		case 6: fprintf(fp,"娱乐");break;
		case 7: fprintf(fp,"服饰");break;
		case 8: fprintf(fp,"其他");break;	
	  }      
		fprintf(fp,"  %10.2f         %s\n",exp[j].money,exp[j].remark);
	  }
  	}
	   fclose(fp);	
}

void filesave3(expend exp[],int cnt[],int y1,int m1,int d1,int y2,int m2,int d2,double sum)    //保存按区间查询结构 
{
	int i,j;
	char name[40];
	char num[25];
	strcpy(name,"D:\\");
	int y=y1;
	int m=m1;
	int d=d1;
	for(i=0;i<4;i++)
	{
		
		num[i]=y/int(pow(10,3-i))+48;
		y=y%int(pow(10,3-i));
	}
	num[4]='-';
	for(i=5;i<7;i++)
	{
		
		num[i]=m/int(pow(10,6-i))+48;
		m=m%int(pow(10,6-i));
	}
	num[7]='-';
	for(i=8;i<10;i++)
	{
		
		num[i]=d/int(pow(10,9-i))+48;
		d=d%int(pow(10,9-i));
	}
	strcat(name,num);
	strcat(name,"至");
	y=y2;
	m=m2;
	d=d2;
	for(i=0;i<4;i++)
	{
		
		num[i]=y/int(pow(10,3-i))+48;
		y=y%int(pow(10,3-i));
	}
	num[4]='-';
	for(i=5;i<7;i++)
	{
		
		num[i]=m/int(pow(10,6-i))+48;
		m=m%int(pow(10,6-i));
	}
	num[7]='-';
	for(i=8;i<10;i++)
	{
		
		num[i]=d/int(pow(10,9-i))+48;
		d=d%int(pow(10,9-i));
	}
	strcat(name,num);
	strcat(name,"消费详情.txt");
	FILE *fp;
	fp=fopen(name,"w+");
	fprintf(fp,"               总计:  %.2f元\n",sum);
	fprintf(fp,"消费日期      消费种类    消费金额       备注\n");
	for(j=0;j<cnt[0];j++)
  	{   
	  if(interjudge(exp[j].time.year,exp[j].time.month,exp[j].time.day)>=interjudge(y1,m1,d1)&&interjudge(exp[j].time.year,exp[j].time.month,exp[j].time.day)<=interjudge(y2,m2,d2))
	  {
		fprintf(fp,"%d年%d月%d日      ",exp[j].time.year,exp[j].time.month,exp[j].time.day); 
		switch(exp[j].type)
	  {
		case 1: fprintf(fp,"饮食");break;
		case 2: fprintf(fp,"学习");break;
		case 3: fprintf(fp,"医疗");break;
		case 4: fprintf(fp,"交通");break;
		case 5: fprintf(fp,"水电");break;
		case 6: fprintf(fp,"娱乐");break;
		case 7: fprintf(fp,"服饰");break;
		case 8: fprintf(fp,"其他");break;	
	  }      
		fprintf(fp,"  %10.2f         %s\n",exp[j].money,exp[j].remark);
	  }
  	}
	   fclose(fp);	
}

void create()																//创建文件以区分是否第一次使用 
{
	FILE *fp;
	fp=fopen("D:\\flag.txt","w+");
	fputc('0',fp);
	fclose(fp);
}

void read(int n,char str[])                                                //读取用户名和密码 
{
	FILE *fp;
	char ch;
	int i=0;
	fp=fopen("D:\\code.txt","r");
		while(!feof(fp))
	{
		if(fscanf(fp,"%s",str))
		{
			i++;
			if(i==n)
			{
				break;
			}
		}
	}
	fclose(fp);
}

void readfile(expend exp[],int cnt[])                                       //读取所有支出信息并存入结构体数组 
{
	int i=1;
	FILE *fp;
	fp=fopen("D:\\expend.txt","r");
	if(fp==0)
	{
		cursor(27,18);
		printf("您还没有任何消费记录!");
		Sleep(1500);
		system("CLS");
		menu3(exp,cnt);
	}
	fscanf(fp,"%d %d %d %d %lf %s",&exp[0].time.year,&exp[0].time.month,&exp[0].time.day,&exp[0].type,&exp[0].money,exp[0].remark);
	while(!feof(fp))
  {   
  	fscanf(fp,"%d %d %d %d %lf %s",&exp[i].time.year,&exp[i].time.month,&exp[i].time.day,&exp[i].type,&exp[i].money,exp[i].remark);
  	i++;
  }
	cnt[0]=i-1;
	fclose(fp);
}

void record(expend ex[],int cnt[])              //新增记录 
{
	expend exp;
	char f[5]="无";
	int x,n,m,y,i=0;
	med();
	cursor(30,8);
	printf("请输入日期  (请输入整数)");
	cursor(27,10);
	printf("年份： ");
	cursor(37,10);
	printf("(请输入一个四位整数)");
	cursor(33,10);
	scanf("%d",&exp.time.year);
	cursor(27,11);
	printf("月份： ");
	scanf("%d",&exp.time.month);
	cursor(27,12);
	printf("日期： ");
	scanf("%d",&exp.time.day);
	cursor(27,13);
	while(!datejudge(exp.time.year,exp.time.month,exp.time.day))
	{
		cursor(27,14);
		printf("输入日期不合法,请重新输入!");
		Sleep(1500);
		record(ex,cnt);
	}
	system("CLS");
	med();
	cursor(32,7);
	printf("请选择消费类型");
	cursor(27,10);
	printf("-------- 1.饮食 --------");
	cursor(27,11);
	printf("-------- 2.学习 --------");
	cursor(27,12);
	printf("-------- 3.医疗 --------");
	cursor(27,13);
	printf("-------- 4.交通 --------");
	cursor(27,14);
	printf("-------- 5.水电 --------");
	cursor(27,15);
	printf("-------- 6.娱乐 --------");
	cursor(27,16);
	printf("-------- 7.服饰 --------");
	cursor(27,17);
	printf("-------- 8.其他 --------");
	cursor(27,18);
	scanf("%d",&exp.type); 
	system("CLS");
	med();
	cursor(30,9);
	printf("请输入金额(元):  ");
	scanf("%lf",&exp.money);
	i++;
	while(exp.money<0)
	{
		cursor(30,9+i);
		printf("金额不能为负数!");
		cursor(30,10+i);
		printf("请输入金额:  ");
		scanf("%lf",&exp.money);
		i=i+2;
	}
	cursor(30,9+i);
	printf("是否需要备注?");
	cursor(27,10+i);
	printf("-------- 1.是 --------");
	cursor(27,11+i);
	printf("-------- 2.否 --------");
	cursor(27,12+i);
	scanf("%d",&n);
	if(n==1)
	{
		cursor(27,13+i);
		printf("请输入备注: ");
		scanf("%s",exp.remark);
	}
	else
	strcpy(exp.remark,f);
	system("CLS");
	med();
	cursor(30,9);
	printf("请确认：");
	cursor(27,10);
	printf("日期: %d 年 %d 月 %d 日",exp.time.year,exp.time.month,exp.time.day);
	cursor(27,11); 
	printf("消费种类: ");
	switch(exp.type)
	{
		case 1: printf("饮食");break;
		case 2: printf("学习");break;
		case 3: printf("医疗");break;
		case 4: printf("交通");break;
		case 5: printf("水电");break;
		case 6: printf("娱乐");break;
		case 7: printf("服饰");break;
		case 8: printf("其他");break;	
	}
	cursor(27,12);
	printf("消费金额: %.2f",exp.money);
	cursor(27,13);
	if(n==1)
	printf("备注: %s",exp.remark);
	else
	printf("备注: 无");
	cursor(27,15);
	printf("-------- 1.确认输入 --------");
	cursor(27,16);
	printf("-------- 2.取消输入 --------");
	cursor(27,17);
	scanf("%d",&m);
	if(m!=1)
	menu3(ex,cnt);
	if(m==1)
	{
		filesave(exp,ex,cnt);
		system("CLS");
		med();
		cursor(30,9);
		printf("是否需要继续记录?");
		cursor(27,10);
		printf("-------- 1.是 --------");
		cursor(27,11);
		printf("-------- 2.否 --------");
		cursor(27,12);
		scanf("%d",&y);
		if(y==1)
		record(ex,cnt);
		else
		menu3(ex,cnt);
	}	
}

void monthana(expend exp[],int cnt[])                                //按月分析 
{
	int year,month,day,i=0,x,j;
	double sum=0;
	analyze t[8];
	for(j=0;j<8;j++)
	t[j].money=0;
	strcpy(t[0].type,"饮食");
	strcpy(t[1].type,"学习");
 	strcpy(t[2].type,"医疗");
	strcpy(t[3].type,"交通");
	strcpy(t[4].type,"水电");
	strcpy(t[5].type,"娱乐");
 	strcpy(t[6].type,"服饰");
	strcpy(t[7].type,"其他");
	system("CLS");
	med();
	cursor(25,9);
	printf("请输入需要分析的月份  (请输入整数)");
	cursor(25,11);
	printf("年份： ");
	cursor(37,11);
	printf("(请输入一个四位整数)");
	cursor(32,11);
	scanf("%d",&year);
	cursor(25,12);
	printf("月份： ");
	scanf("%d",&month);
	while(!(year>=1000&&year<=9999&&month>=1&&month<=12))
	{
		cursor(25,14);
		printf("输入月份不合法,请重新输入!");
		Sleep(1500);
		monthana(exp,cnt);
	}
	system("CLS");
	med3();
	cursor(25,5);
	printf("%d年%d月消费分析      ",year,month);
	cursor(20,7);
    printf("消费种类    消费总金额     占总支出百分比");
	for(j=0;j<cnt[0];j++)
  {   
	  if(year==exp[j].time.year&&month==exp[j].time.month)
	  {
        switch(exp[j].type)
	{
		case 1: t[0].money+=exp[j].money;break;
		case 2: t[1].money+=exp[j].money;break;
		case 3: t[2].money+=exp[j].money;break;
		case 4: t[3].money+=exp[j].money;break;
		case 5: t[4].money+=exp[j].money;break;
		case 6: t[5].money+=exp[j].money;break;
		case 7: t[6].money+=exp[j].money;break;
		case 8: t[7].money+=exp[j].money;;break;	
	}
        sum=sum+exp[j].money;
  	  }	
  }	
  	  cursor(48,5);
  	  printf("总计%.2f元",sum);
  	  cursor(20,8);
	  sort2(t,8);
  	  for(j=0;j<8;j++)
	{
		printf("%s     %10.2f元    %10.2f%%",t[i].type,t[i].money,(t[i].money/sum)*100);
		i++;
		cursor(20,8+i);
	}	
	if(sum==0) 
	{
		system("CLS");
		med3();
		cursor(32,5);
		printf("%d年%d月消费分析      ",year,month);
		cursor(20,7);
    	printf("消费种类    消费总金额     占总支出百分比");
		cursor(30,8);
		printf("该月没有消费记录！");
		cursor(27,12);
  		printf("-------- 1.返回 --------");
  		cursor(27,13);
		scanf("%d",&x);
		if(x==1)
		menu5(exp,cnt);
	}
  	cursor(27,12+i);
  	printf("-------- 1.返回 --------");
  	cursor(27,13+i);
	scanf("%d",&x);
	menu5(exp,cnt);
}

void yearana(expend exp[],int cnt[])                      //按年分析 
{
	int year,i=0,x,j;
	double sum=0;
	analyze t[8];
	analyze m[12];
	for(j=0;j<8;j++)
	t[j].money=0;
	strcpy(t[0].type,"饮食");
	strcpy(t[1].type,"学习");
 	strcpy(t[2].type,"医疗");
	strcpy(t[3].type,"交通");
	strcpy(t[4].type,"水电");
	strcpy(t[5].type,"娱乐");
 	strcpy(t[6].type,"服饰");
	strcpy(t[7].type,"其他");
	system("CLS");
	med();
	cursor(25,9);
	printf("请输入需要分析的年份  (请输入整数)");
	cursor(25,11);
	printf("年份： ");
	cursor(37,11);
	printf("(请输入一个四位整数)");
	cursor(32,11);
	scanf("%d",&year);
	while(!(year>=1000&&year<=9999))
	{
		cursor(25,12);
		printf("输入年份不合法,请重新输入!");
		Sleep(1500);
		yearana(exp,cnt);
	}
	system("CLS");
	med3();
	cursor(28,5);
	printf("%d年消费分析      ",year);
	cursor(20,7);
    printf("消费种类    消费总金额     占总支出百分比");
	for(j=0;j<cnt[0];j++)
  {   
	  if(year==exp[j].time.year)
	  {
        switch(exp[j].type)
	{
		case 1: t[0].money+=exp[j].money;break;
		case 2: t[1].money+=exp[j].money;break;
		case 3: t[2].money+=exp[j].money;break;
		case 4: t[3].money+=exp[j].money;break;
		case 5: t[4].money+=exp[j].money;break;
		case 6: t[5].money+=exp[j].money;break;
		case 7: t[6].money+=exp[j].money;break;
		case 8: t[7].money+=exp[j].money;;break;	
	}
        sum=sum+exp[j].money;
  	  }	
  }	
  	  cursor(48,5);
  	  printf("总计%.2f元",sum);
	  sort2(t,8);
	  cursor(20,8);
  	  for(j=0;j<8;j++)
	{
		printf("%s     %10.2f元    %10.2f%%",t[i].type,t[i].money,(t[i].money/sum)*100);
		i++;
		cursor(20,8+i);
	}	
	if(sum==0) 
	{
		system("CLS");
		med3();
		cursor(32,5);
		printf("%d年消费分析      ",year);
		cursor(20,7);
    	printf("消费种类    消费总金额     占总支出百分比");
		cursor(30,8);
		printf("该年没有消费记录！");
		cursor(27,11);
  		printf("-------- 1.返回 --------");
  		cursor(27,12);
		scanf("%d",&x);
		if(x==1)
		menu5(exp,cnt);
		
	}
  	cursor(20,12+i);
	printf("-------- 1.继续查看各月消费情况 --------");
	cursor(27,13+i);
	printf("-------- 2.返回 --------");
	cursor(27,14+i);
	scanf("%d",&x);
	if(x==2)
	menu5(exp,cnt);
	else
	{
	      system("CLS");
	      med3();
	      for(j=0;j<12;j++)
			m[j].money=0;
			strcpy(m[0].type,"1月");
			strcpy(m[1].type,"2月");
 			strcpy(m[2].type,"3月");
			strcpy(m[3].type,"4月");
			strcpy(m[4].type,"5月");
			strcpy(m[5].type,"6月");
 			strcpy(m[6].type,"7月");
			strcpy(m[7].type,"8月");
			strcpy(m[8].type,"9月");
			strcpy(m[9].type,"10月");
 			strcpy(m[10].type,"11月");
			strcpy(m[11].type,"12月");
	      cursor(28,5);
	      printf("%d年消费分析      ",year);
	      cursor(20,7);
          printf("消费月份    消费总金额     占总支出百分比");
	      for(j=0;j<cnt[0];j++)
         {   
	  		if(year==exp[j].time.year)
	    	{
        			switch(exp[j].time.month)
				{
				case 1: m[0].money+=exp[j].money;break;
				case 2: m[1].money+=exp[j].money;break;
				case 3: m[2].money+=exp[j].money;break;
				case 4: m[3].money+=exp[j].money;break;
				case 5: m[4].money+=exp[j].money;break;
				case 6: m[5].money+=exp[j].money;break;
				case 7: m[6].money+=exp[j].money;break;
				case 8: m[7].money+=exp[j].money;;break;
				case 9: m[8].money+=exp[j].money;break;
				case 10: m[9].money+=exp[j].money;break;
				case 11: m[10].money+=exp[j].money;break;
				case 12: m[11].money+=exp[j].money;;break;	
				}	
  	        }	
         }	
  	  	cursor(48,5);
  	  	printf("总计%.2f元",sum);
	  	sort2(m,12);
	  	cursor(20,8);
	  	i=0;
  	  	for(j=0;j<12;j++)
	  {
		printf("%s     %10.2f元    %10.2f%%",m[j].type,m[j].money,(m[j].money/sum)*100);
		i++;
		cursor(20,8+i);
	  }	
	    cursor(27,10+i);
		printf("-------- 1.返回 --------");
  		cursor(27,11+i);
		scanf("%d",&x);
		menu5(exp,cnt);		
	}
}

void daycheck(expend exp[],int cnt[])                                   //按日查询 
{
	int year,month,day,i=0,x;
	expend n;
	system("CLS");
	med();
	cursor(25,9);
	printf("请输入查询日期  (请输入整数)");
	cursor(25,11);
	printf("年份： ");
	cursor(37,11);
	printf("(请输入一个四位整数)");
	cursor(32,11);
	scanf("%d",&year);
	cursor(25,12);
	printf("月份： ");
	scanf("%d",&month);
	cursor(25,13);
	printf("日期： ");
	scanf("%d",&day);
	while(!datejudge(year,month,day))
	{
		cursor(25,14);
		printf("输入日期不合法,请重新输入!");
		Sleep(1500);
		daycheck(exp,cnt);
	}
	system("CLS");
	med2();
	cursor(37,5);
	printf("查询结果");
	cursor(18,6);
    printf("消费日期      消费种类    消费金额     备注");
	cursor(16,7);
	FILE *fp;
	fp=fopen("D:\\expend.txt","r");
	if(fp==0)
	{
		printf("file error\n");
		exit(1);
	}
	fscanf(fp,"%d %d %d %d %lf %s",&n.time.year,&n.time.month,&n.time.day,&n.type,&n.money,n.remark);
	while(!feof(fp))
  {   
	  if(year==n.time.year&&month==n.time.month&&day==n.time.day)
	  {
        printf("%d年%d月%d日      ",n.time.year,n.time.month,n.time.day);
        switch(n.type)
	{
		case 1: printf("饮食");break;
		case 2: printf("学习");break;
		case 3: printf("医疗");break;
		case 4: printf("交通");break;
		case 5: printf("水电");break;
		case 6: printf("娱乐");break;
		case 7: printf("服饰");break;
		case 8: printf("其他");break;
		default: daycheck(exp,cnt);	
	}
        printf("  %10.2f       %s",n.money,n.remark);
        i++;
        cursor(16,7+i);
  	  }
  	  fscanf(fp,"%d %d %d %d %lf %s",&n.time.year,&n.time.month,&n.time.day,&n.type,&n.money,n.remark);
  }
  	fclose(fp);
    if(i==0)
    {
		cursor(32,7+i);
  		printf("没有找到符合条件的结果!");
    }
  	cursor(32,12+i);
  	printf("是否需要继续查询?");
  	cursor(32,13+i);
  	printf("-------- 1.是 --------");
  	cursor(32,14+i);
  	printf("-------- 2.否 --------");
  	cursor(32,15+i);
	scanf("%d",&x);
	if(x==1)
	daycheck(exp,cnt);
	else
	menu4(exp,cnt);
}

void monthcheck(expend exp[],int cnt[])                           //按月查询 
{
	int year,month,day,i=0,x,j;
	double sum=0;
	system("CLS");
	med();
	cursor(25,10);
	printf("请输入查询月份  (请输入整数)");
	cursor(25,11);
	printf("年份： ");
	cursor(37,11);
	printf("(请输入一个四位整数)");
	cursor(32,11);
	scanf("%d",&year);
	cursor(25,12);
	printf("月份： ");
	scanf("%d",&month);
	while(!(year>=1000&&year<=9999&&month>=1&&month<=12))
	{
		cursor(25,13);
		printf("输入月份不合法,请重新输入!");
		Sleep(1500);
		monthcheck(exp,cnt);
	}
	system("CLS");
	med2();
	cursor(20,5);
	printf("%d年%d月消费情况      ",year,month);
	cursor(18,8);
    printf("消费日期      消费种类    消费金额     备注");
	cursor(16,9);
	sort1(exp,cnt);
	for(j=0;j<cnt[0];j++)
  {   
	  if(year==exp[j].time.year&&month==exp[j].time.month)
	  {
        printf("%d年%d月%d日      ",exp[j].time.year,exp[j].time.month,exp[j].time.day);
        switch(exp[j].type)
	{
		case 1: printf("饮食");break;
		case 2: printf("学习");break;
		case 3: printf("医疗");break;
		case 4: printf("交通");break;
		case 5: printf("水电");break;
		case 6: printf("娱乐");break;
		case 7: printf("服饰");break;
		case 8: printf("其他");break;
		default: monthcheck(exp,cnt);	
	}
        printf("  %10.2f         %s",exp[j].money,exp[j].remark);
        sum=sum+exp[j].money;
        i++;
        cursor(16,9+i);
  	  }
  }
  	cursor(48,5);
  	printf("总计%.2f元",sum);
    if(i==0)
    {
		cursor(32,9+i);
  		printf("该月没有消费记录!");
    }
  	cursor(32,14+i);
  	printf("是否需要将信息保存为文件?");
  	cursor(32,15+i);
  	printf("-------- 1.是 --------");
  	cursor(32,16+i);
  	printf("-------- 2.否 --------");
  	cursor(32,17+i);
  	scanf("%d",&x);
	if(x==1)
	{
		filesave2(exp,cnt,year,month,sum);
		cursor(38,18+i);
		printf("保存成功!");
	}
	cursor(32,20+i);
  	printf("是否需要继续查询?");
  	cursor(32,21+i);
  	printf("-------- 1.是 --------");
  	cursor(32,22+i);
  	printf("-------- 2.否 --------");
  	cursor(32,23+i);
	scanf("%d",&x);
	if(x==1)
	monthcheck(exp,cnt);
	else
	menu4(exp,cnt);
}

void intercheck(expend exp[],int cnt[])                                         //区间查询 
{
    int y1,m1,d1,i=0,x,j;
    int y2,m2,d2;
	double sum=0;
	system("CLS");
	med();
	cursor(25,6);
	printf("请输入初始日期  (请输入整数)");
	cursor(25,7);
	printf("年份： ");
	cursor(37,7);
	printf("(请输入一个四位整数)");
	cursor(32,7);
	scanf("%d",&y1);
	cursor(25,8);
	printf("月份： ");
	scanf("%d",&m1);
	cursor(25,9);
	printf("日期： ");
	scanf("%d",&d1);
	while(!(datejudge(y1,m1,d1)))
	{
		cursor(25,10);
		printf("输入日期不合法,请重新输入!");
		Sleep(1500);
		intercheck(exp,cnt);
	}
	cursor(25,10);
	printf("请输入结束日期(请输入整数)");
	cursor(25,11);
	printf("年份： ");
	cursor(37,11);
	printf("(请输入一个四位整数)");
	cursor(32,11);
	scanf("%d",&y2);
	cursor(25,12);
	printf("月份： ");
	scanf("%d",&m2);
	cursor(25,13);
	printf("日期： ");
	scanf("%d",&d2);
	while(!(datejudge(y2,m2,d2)))
	{
		cursor(25,14);
		printf("输入日期不合法,请重新输入!");
		Sleep(1500);
		intercheck(exp,cnt);
	}
	while(!(interjudge(y2,m2,d2)>=interjudge(y1,m1,d1)))
	{
		cursor(25,15);
		printf("输入区间不合法,请重新输入!");
		Sleep(1500);
		intercheck(exp,cnt);
	}
	system("CLS");
	med2();
	cursor(15,5);
	printf("%d年%d月%d日--%d年%d月%d日消费情况      ",y1,m1,d1,y2,m2,d2);
	cursor(18,8);
    printf("消费日期      消费种类    消费金额     备注");
	cursor(16,9);
	sort1(exp,cnt);
	for(j=0;j<cnt[0];j++)
  {   
	  if(interjudge(exp[j].time.year,exp[j].time.month,exp[j].time.day)>=interjudge(y1,m1,d1)&&interjudge(exp[j].time.year,exp[j].time.month,exp[j].time.day)<=interjudge(y2,m2,d2))
	  {
        printf("%d年%d月%d日      ",exp[j].time.year,exp[j].time.month,exp[j].time.day);
        switch(exp[j].type)
	{
		case 1: printf("饮食");break;
		case 2: printf("学习");break;
		case 3: printf("医疗");break;
		case 4: printf("交通");break;
		case 5: printf("水电");break;
		case 6: printf("娱乐");break;
		case 7: printf("服饰");break;
		case 8: printf("其他");break;
		default: intercheck(exp,cnt);	
	}
        printf("  %10.2f         %s",exp[j].money,exp[j].remark);
        sum=sum+exp[j].money;
        i++;
        cursor(16,9+i);
        if(i>280)
        {
        	cursor(14,10+i);
			printf("查找区间过大导致显示范围已超过屏幕缓冲区大小,无法继续显示!");
        	cursor(20,11+i);
        	printf("请缩小区间重新查询(区间不要超过4个月)!");
        	Sleep(10000);
        	intercheck(exp,cnt);
        }
  	  }
  }
  	cursor(56,5);
  	printf("总计%.2f元",sum);
    if(i==0)
    {
		cursor(32,9+i);
  		printf("该段时间没有消费记录!");
    }
  	cursor(32,14+i);
  	printf("是否需要将信息保存为文件?");
  	cursor(32,15+i);
  	printf("-------- 1.是 --------");
  	cursor(32,16+i);
  	printf("-------- 2.否 --------");
  	cursor(32,17+i);
  	scanf("%d",&x);
	if(x==1)
	{
		filesave3(exp,cnt,y1,m1,d1,y2,m2,d2,sum);
		cursor(38,18+i);
		printf("保存成功!");
	}
	cursor(32,21+i);
  	printf("是否需要继续查询?");
  	cursor(32,22+i);
  	printf("-------- 1.是 --------");
  	cursor(32,23+i);
  	printf("-------- 2.否 --------");
  	cursor(32,24+i);
	scanf("%d",&x);
	if(x==1)
	intercheck(exp,cnt);
	else	
	menu4(exp,cnt);
}

void password(char p[])                                  //隐藏密码 
{
	int i=0;
	while(p[i]=getch())
	{
		if(p[i]==13)
		break;
		if(p[i]!='\b')
		{
			printf("*");
			i++;
		}
		else
		{
			printf("\b \b");
			i--;
		}	
	}
	p[i]='\0';
}

void sort1(expend exp[],int cnt[])                                    //按日期排序 
{
	int i,k,index;
	expend t;
	for(k=0;k<cnt[0];k++)
	{
		index=k;
		for(i=k+1;i<cnt[0];i++)
		if(interjudge(exp[i].time.year,exp[i].time.month,exp[i].time.day)<interjudge(exp[index].time.year,exp[index].time.month,exp[index].time.day))
			index=i;
			if(index!=k)
			{
				t=exp[index];
				exp[index]=exp[k];
				exp[k]=t;
			}
	}
}

void sort2(analyze ana[],int n)                                  //按金额排序 
{
	int i,k,index;
	analyze temp;
	for(k=0;k<n;k++)
	{
		index=k;
		for(i=k+1;i<n;i++)
		if(ana[i].money>ana[index].money)
			index=i;
			if(index!=k)
			{
				temp=ana[index];
				ana[index]=ana[k];
				ana[k]=temp;
			}
	}
}

int datejudge(int y, int m, int d)                           //判断日期合法性 
{
        int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
                month[1] = 29; 
        return  y>=1000&&y<=9999&&m > 0 && m <= 12 && d > 0 && d <= month[m - 1]; 
}

int interjudge(int y,int m,int d)                         //日期大小比较 
{
	return y*10000+m*100+d;	
}

