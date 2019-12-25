/*********************************************************************************************************************
     **
     **  Library Management System : To develop a library management system using C and graphics in C.
     **
     **  Written By:    Akash Vishwas Londhe
     **  Written On:    November 2018 - December 2018
     **  Last Updated:  December 2018 - Akash Vishwas Londhe
     **
     **  This File May Be Modified And Re-Distributed Freely.
     **  Original File Content written by Akash Vishwas Londhe
     **
*********************************************************************************************************************/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>

#define IN 1;
#define OUT 0;

FILE *lib,*fs,*member,*fp;

char pass[8]="Library";
char info[500];

void reset();
void searchBook();
void addBook();
void displayBook();
void displayMember();
void displayIssue();
void addMember();
void deleteBook();
void design(char *);
void issue();
void search();

int f=0;

struct book
{
	int id;
	char name[20];
	char author[20];
	int tot;
	int status;
};
struct book BOOK;

struct member
{
	int roll;
	char name[20];
	char dep[20];

}MEMBER;

void mainmenu()
{
	int opt;
	system("cls");
	gotoxy(10,4);
	printf("\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\tMainMenu\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(15,6);
	printf("\t\xDB\xDB\xDB 1 : Search Book");
	gotoxy(15,7);
	printf("\t\xDB\xDB\xDB 2 : Issue Book");
	gotoxy(15,8);
	printf("\t\xDB\xDB\xDB 3 : Display Books");
	gotoxy(15,9);
	printf("\t\xDB\xDB\xDB 4 : Display Members");
	gotoxy(15,10);
	printf("\t\xDB\xDB\xDB 5 : Display Issue List");
	gotoxy(15,11);
	printf("\t\xDB\xDB\xDB 6 : Add Books");
	gotoxy(15,12);
	printf("\t\xDB\xDB\xDB 7 : Add Member");
	gotoxy(15,13);
	printf("\t\xDB\xDB\xDB 8 : Delete Book");
	gotoxy(15,14);
	printf("\t\xDB\xDB\xDB 9 : Do you want to reset data");
	gotoxy(15,15);
	printf("\t\xDB\xDB\xDB 10 : Close Application");
	gotoxy(15,17);

	printf("\tChoose Option  : ");
	scanf("%d",&opt);

	switch(opt)
	{
		case 1:search();
		       break;
		case 2:issue();
		       break;
		case 3:displayBook();
		       break;
		case 4:displayMember();
		       break;
		case 5:displayIssue();
		       break;
		case 6:addBook();
		       break;
		case 8:deleteBook();
		       break;
		case 7:addMember();
		       break;
		case 9:reset();
		       break;
		case 10:break;

		default :printf("Wrong Entry");
			mainmenu();
	}

}

void reset()
{
	lib=fopen("library1.txt","w");
	rewind(lib);
	free(lib);
	fclose(lib);
	lib=fopen("member.txt","w");
	rewind(lib);
	free(lib);
	lib=fopen("issue.txt","w");
	rewind(lib);
	free(lib);
}

void issue()
{       char name[]="Issue Book";
	int dd,mm,yy;
	char name1[20];
	design(name);
	gotoxy(15,4);

	searchBook();

	if(f==1)
	{
		system("cls");
		lib=fopen("issue.txt","a+");
		gotoxy(15,4);
		printf("\tEnter Roll No : ");
		scanf("%d",&MEMBER.roll);
		gotoxy(15,5);
		printf("\tEnter  Name : ");
		scanf("%s",MEMBER.name);
		gotoxy(15,6);
		printf("\tEnter Department Name : ");
		scanf("%s",MEMBER.dep);
		gotoxy(15,7);
		printf("\tEnter Book name : ");
		scanf("%s",name1);
		gotoxy(15,8);
		printf("\tEnter date of issue : ");
		scanf("%d %d %d",&dd,&mm,&yy);
		fprintf(lib,"\n\t%4d\t%s\t%s\t%s\t%d-%d-%d",MEMBER.roll,MEMBER.name,MEMBER.dep,name1,dd,mm,yy);
		printf("\nYou Can take book now & return it within 7 days");
		fclose(lib);

	}

	getch();
	mainmenu();
}

void search()
{
	char name[]="Search Book";
	design(name);
	gotoxy(15,4);
	searchBook();
	mainmenu();
}

void searchBook()
{
	char del[20];
	int i;
	printf("Enter Book name or author name to be search : ");
	scanf("%s",del);
	lib=fopen("library1.txt","r");
	rewind(lib);

	while((fscanf(lib,"%d %s %s %d %d",&BOOK.id,BOOK.name,BOOK.author,&BOOK.tot,&BOOK.status))!=EOF)
	{
	       i=(strcmp(del,BOOK.name)&&strcmp(del,BOOK.author));
	       if(i==0)
		f=1;
	}

	if(f==0)
		printf("Book Not Found");
	else
		printf("Book Found");

	fclose(lib);
	getch();
}

void addBook()
{
	char name[]="Add Book";
	int j;
	design(name);
	lib=fopen("library1.txt","a+");
	gotoxy(15,4);
	printf("Enter Book Id : ");
	scanf("%d",&BOOK.id);
	gotoxy(15,5);
	printf("Enter Book Name : ");
	scanf("%s",BOOK.name);
	gotoxy(15,6);
	printf("Enter Author Name : ");
	scanf("%s",BOOK.author);
	gotoxy(15,7);
	printf("Enter Total No. of books : ");
	scanf("%d",&BOOK.tot);
	BOOK.status=IN;
	fprintf(lib,"\n%d\t%s\t%s\t%d\t\t%d",BOOK.id,BOOK.name,BOOK.author,BOOK.tot,BOOK.status);
	fclose(lib);
	gotoxy(15,8);
	printf("A new book has been added successfully");
	getch();
	mainmenu();
}

void addMember()
{
	char name[]="Add Member";
	int j;
	design(name);
	member=fopen("member.txt","a+");
	gotoxy(15,4);
	printf("Enter Roll No : ");
	scanf("%d",&MEMBER.roll);
	gotoxy(15,5);
	printf("Enter  Name : ");
	scanf("%s",&MEMBER.name);
	gotoxy(15,6);
	printf("Enter Department Name : ");
	scanf("%s",&MEMBER.dep);
	gotoxy(15,7);
	fprintf(lib,"\n\t\t%4d\t%s\t%s",MEMBER.roll,MEMBER.name,MEMBER.dep);
	fclose(member);
	gotoxy(15,8);
	printf("A new member has been added successfully");
	getch();
	mainmenu();
}

void displayBook()
{
	char name[]="Display Book";
	design(name);
	lib=fopen("library1.txt","a+");
	gotoxy(1,4);
	rewind(lib);
	printf(" Id\tBook Name\tAuthor Name    Total\t   Book Status",info);
	gotoxy(1,6);

	do
	{
		fgets(info,500,lib);
		printf("%s\n",info);
	}while(!feof(lib));

	fclose(lib);
	getch();
	mainmenu();
}

void displayMember()
{
	char name[]="Display Members";
	design(name);
	lib=fopen("member.txt","a+");
	gotoxy(1,4);
	rewind(lib);
	printf("\t\tRoll No  Student Name\tDepartment Name ");
	gotoxy(1,6);

	do
	{
		fgets(info,500,lib);
		printf("%s\n",info);
	}while(!feof(lib));

	fclose(lib);
	getch();
	mainmenu();
}

void displayIssue()
{
	char name[]="Display Issue list";
	design(name);
	lib=fopen("issue.txt","a+");
	gotoxy(1,4);
	rewind(lib);
	printf("\tRoll No  Student Name  Department Name  Issued Book\t  Date");
	gotoxy(1,6);

	do
	{
		fgets(info,500,lib);
		printf("%s\n",info);
	}while(!feof(lib));

	fclose(lib);
	getch();
	mainmenu();
}

void deleteBook()
{
	char del[20];
	int i,f=0;
	char name[]="Delete Book";
	design(name);
	gotoxy(15,4);
	printf("Enter Book name or author name to be deleted : ");
	scanf("%s",&del);
	lib=fopen("library1.txt","a+");
	rewind(lib);
	fp=fopen("temp.txt","wb+");

	while((fscanf(lib,"%d %s %s %d %d",&BOOK.id,BOOK.name,BOOK.author,&BOOK.tot,&BOOK.status))!=EOF)
	{
	       i=(strcmp(del,BOOK.name)&&strcmp(del,BOOK.author));
	       if(i==0)
			f=1;
	       else
			fprintf(fp,"\n%d\t%s\t%s\t%d\t%d",BOOK.id,BOOK.name,BOOK.author,BOOK.tot,BOOK.status);
	}

	if(f==0)
		printf("Book Not Found");
	else
		printf("Book deleted succesfully");

	fclose(lib);
	fclose(fp);
	remove("library1.txt");
	rename("temp.txt","library1.txt");
	getch();
	mainmenu();
}

void password()
{
	char ch,pass2[8],name[]="Library Management";
	int i=0;
	design(name);
	gotoxy(15,4);
	printf("Enter Password : ");

	while(ch!=13)
	{
		ch=getch();
		if(ch!=13&&ch!=8)
		{
			putch('*');
			pass2[i]=ch;
			i++;
		}
	}

	pass2[i]='\0';

	if(strcmp(pass,pass2)==0)
	{
		gotoxy(15,4);
		printf("Correct Password          ");
		gotoxy(15,6);
		printf("Press any key to continue");
		getch();
		mainmenu();
	}
	else
	{
		gotoxy(15,6);
		printf("Wrong Password");
		getch();
		password();
	}

}

void design(char *name)
{
	int j;
	system("cls");
	gotoxy(1,2);

	for(j=0;j<30;j++)
	{
		delay(50);
		printf("*");
	}

	for(j=0;name[j]!='\0';j++)
	{
		delay(50);
		printf("%c",name[j]);
	}

	for(j=0;j<30;j++)
	{
		delay(50);
		printf("*");
	}

}

int main()
{

	textcolor(RED);
	password();
	getch();
	return 0;

}