#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include <iostream> 
#include <windows.h>
int i;

struct newuser
{
	char username[50];
	char passward[50];
}user,admin;

struct carinfo
{
	char name[20];
	char model[20];
	int price;
	int rent;
}car[100];

// regarding passward ang login
void adminuserpass();
void login();
void adminlogin();
void costumerlogin();
void newusersignup();
void exit();
int main();


//funtions used for car info and adminarea


void adminarea();
void addcar();
void display();
void updatecar();
void deletecar();

//functions used for buying purposes

int buyerarea();
int billbuy();
void displaycars();
int billrent();
int totalbill(int x);
void rentcars();
void soldcars();

//PROJECT POTION

void soldcars()
{
	FILE *fp3;
	fp3=fopen("sold cars.txt","r+");
	printf("--------------------------------------------------------------------\n");
    printf("NAME\t\tMODEL\t\tPRICE\t\tRENT(per day)\n");
    printf("--------------------------------------------------------------------\n");
	while(fread(&car[i],sizeof(car[i]),1,fp3)>0)
	{
		printf("%s\t\t%s\t\t%d\t\t%d\n",car[i].name,car[i].model,car[i].price,car[i].rent);	
	}
	printf("--------------------------------------------------------------------\n");
	printf("press any key to go back");
	getch();
	fclose(fp3);
}

void rentcars()
{
	FILE *fp3;
	fp3=fopen("rent cars.txt","r+");
	printf("--------------------------------------------------------------------\n");
    printf("NAME\t\tMODEL\t\tPRICE\t\tRENT(per day)\n");
    printf("--------------------------------------------------------------------\n");
	while(fread(&car[i],sizeof(car[i]),1,fp3)>0)
	{
		printf("%s\t\t%s\t\t%d\t\t%d\n",car[i].name,car[i].model,car[i].price,car[i].rent);	
	}
	printf("--------------------------------------------------------------------\n");
	printf("press any key to go back");
	getch();
	fclose(fp3);
}

int totalbill(int x)
{
	system("cls");
	fflush(stdin);
	printf("\t\t\t\n\n\n\nTHANKYOU FOR VISITING H.A.M SHOWROOM!\n\n\n");
	fflush(stdin);
	printf("\t\t\tyour total bill is  %d dollars",x);
	fflush(stdin);
	printf("\t\t\t\n\n\nHOPE TO SEE YOU AGAIN!\nBEST WISHES!");		
}

int buyerarea()
{
	int a,c=0,b=0,d,e,f;
	e:
	system("cls");
	printf("\n\t\t\t<WELCOME COSTUMER>\n\n");
	printf("1-buy a car\n2-rent a car\n3-print bill\n4-view bought cars\n5-view rented cars\n6-go back\n7-exit\n\nenter your choice:");
	scanf("%d",&a);
	if(a==1)
	{
	
	b=billbuy();
	goto e;
	
}
	else if(a==2)
	{
	
	c=billrent();
	goto e;
}
	else if(a==3)
	{
		
	f=b+c;
	
	totalbill(f);

}
	else if(a==4)
	{
	
	soldcars();
		goto e;
}
	else if(a==5)
{
		
	rentcars();
		goto e;
}
	
	else if(a==7)
	
	exit(0);
	
	else if(a==6)
	
	login();

}


void displaycars()
{
	system("cls");
	char choise[20],modelcar[20];
	FILE *fp;
	fp=fopen("carinformation.txt","r+");
	    printf("--------------------------------------------------------------------\n");
    printf("NAME\t\tMODEL\t\tPRICE\t\tRENT(per day)\n");
    printf("--------------------------------------------------------------------\n");
	
	while(fread(&car[i],sizeof(car[i]),1,fp)>0)
	{
		printf("%s\t\t%s\t\t%d\t\t%d\n",car[i].name,car[i].model,car[i].price,car[i].rent);	
	}
	printf("--------------------------------------------------------------------\n");
	fclose(fp);
}
	


int billrent()

	{
	system("cls");
	char choise[20],a;
	int b,sum=0,summ=0;
	b:
	displaycars();
	FILE *fp,*fp2,*fp3;
	fp3=fopen("rent cars.txt","a+");
	fp=fopen("carinformation.txt","r+");
	fp2=fopen("soldcars.txt","a+");
		printf("enter the name of the car you want to buy:");
		fflush(stdin);
	gets(choise);
		fflush(stdin);
		printf("enter the days in which you will return the car:");
		scanf("%d",&b);
		fflush(stdin);
	
	if(fp2==NULL)
	{
		printf("no file exist");
		exit(0);
	}
	if(fp==NULL)
	{
	printf("no file exist");
		exit(0);	
	}
		
	while(fread(&car[i],sizeof(car[i]),1,fp)>0)
	{
		
		if(strcmp(choise,car[i].name)==0 )
		{
		
		printf("\nyou rented %s car for %d days in %d dollars\n\n",car[i].name,b,car[i].price*b);
		sum=sum+car[i].price*b;
		fwrite(&car[i],sizeof(car[i]),1,fp3);
		
		}
			else if(strcmp(choise,car[i].name)!=0 )
		{
		
			fwrite(&car[i],sizeof(car[i]),1,fp2);}	
	}
	

fflush(stdin);

			fclose(fp);
			fclose(fp2);
			fclose(fp3);
		remove("carinformation.txt");
		rename("soldcars.txt","carinformation.txt");
		fflush(stdin);

			printf("do you want to rent any other car?\npress y for yes\npress n for no\nenter your choice:");
			fflush(stdin);
			scanf("%c",&a);
			if(a=='y')
			{
				
			fflush(stdin);
			goto b;
			
		}
			else
			{
			
			fflush(stdin);
			
			return sum;
	}}
	


int billbuy()
	
{
	system("cls");
	char choise[20],a;
	int b,sum=0,summ=0;
	b:
	displaycars();
	FILE *fp,*fp2,*fp3;

	fp=fopen("carinformation.txt","r+");
	fp2=fopen("soldcars.txt","a+");
	fp3=fopen("sold cars.txt","a+");
		printf("enter the name of the car you want to buy:");
		fflush(stdin);
	gets(choise);
		fflush(stdin);
		fflush(stdin);
	
	if(fp2==NULL)
	{
		printf("no file exist");
		exit(0);
	}
	if(fp==NULL)
	{
	printf("no file exist");
		exit(0);	
	}
		
	while(fread(&car[i],sizeof(car[i]),1,fp)>0)
	{
		
		if(strcmp(choise,car[i].name)==0 )
		{
		
		printf("\nCONGRATULATIONS!! you bought %s car in %d dollars\n\n",car[i].name,car[i].price);
		sum=sum+car[i].price;
		fwrite(&car[i],sizeof(car[i]),1,fp3);
		
		}
			else if(strcmp(choise,car[i].name)!=0 )
		{
				
			fwrite(&car[i],sizeof(car[i]),1,fp2);}
					
	}
	

fflush(stdin);

			fclose(fp);
			fclose(fp2);
			fclose(fp3);
		remove("carinformation.txt");
		rename("soldcars.txt","carinformation.txt");
		fflush(stdin);

			printf("do you want to buy any other car?\npress y for yes\npress n for no\nenter your choice:");
			fflush(stdin);
			scanf("%c",&a);
			if(a=='y')
			{
			fflush(stdin);
			goto b;
			
		}
			else
			{
			
			fflush(stdin);
			return sum;
	}}
	
	






	
void adminarea()
{
	system("cls");
	printf("\t\t\tWELCOME HAMZA\n\n");
	
	int a;
	printf("\n1-add car\n2-display all car\n3-modify cars\n4-delete car\n5-go back\n\nenter your choice:");
	scanf("%d",&a);
	if(a==1)
	addcar();
	else if (a==2)
	display();
	else if (a==3)
	updatecar();
	else if(a==4)
	deletecar();
	else if(a==5)
	login();
	
}	




void addcar()
{
	system("cls");
	FILE *fp;
	int a,i;
	
	fp=fopen("carinformation.txt","a+");
	printf("\t\t\t<--:ADD RECORD:-->\n\n");
	printf("enter the number of cars you want to add:");
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
	
	printf("\n\t\t\t*information about car %d*\n\n",i+1);
	printf("enter the name of the car:");
	scanf("%s",car[i].name);
	printf("enter the model of car:");
	scanf("%s",car[i].model);
	printf("set the price of car(in $s):");
	scanf("%d",&car[i].price);
	printf("set the rent amount per day:");
	scanf("%d",&car[i].rent);	
	
	fwrite(&car[i],sizeof(car[i]),1,fp);	
}
fclose(fp);
	printf("\nCAR ADDED SUCCESSFULLY!!\n\n");
	printf("press any key to go back to admin page");
	getch();

adminarea();

}

void display()
{
	system("cls");
		
	FILE *fp;
	printf("\t\t\t<--:VIEW RECORD:-->\n\n");
	fp=fopen("carinformation.txt","r");
	if(fp == NULL)
	{
    printf("Error opening file.");
    exit(1);
	}
    printf("--------------------------------------------------------------------\n");
    printf("NAME\t\tMODEL\t\tPRICE($)\tRENT(per day($))\n");
    printf("--------------------------------------------------------------------\n");
	while(fread(&car[i],sizeof(car[i]),1,fp)>0)
	{
		printf("%s\t\t%s\t\t%d\t\t%d\n",car[i].name,car[i].model,car[i].price,car[i].rent);
	}
	fclose(fp);
	printf("--------------------------------------------------------------------\n");
	printf("\n");
	printf("press any key to go back to admin page");
	getch();
	adminarea();
	
}
void updatecar()
{
	system("cls");
	char search[20],c;
	FILE *fp;
	fp=fopen("carinformation.txt","r+");
  	printf("\t\t\t<--:MODIFY RECORD:-->\n\n");
	printf("\nenter the name of the car you want to modify:");
	fflush(stdin);
	gets(search);
	fflush(stdin);

	rewind(fp);
	fflush(stdin);
	while(fread(&car[i],sizeof(car[i]),1,fp)>0)
	{
		if(strcmp(search,car[i].name)==0)
		{
			printf("enter the name of the car:");
			scanf("%s",car[i].name);
			printf("enter the model of car:");
			scanf("%s",car[i].model);
			printf("set the price of car(in $s):");
			scanf("%d",&car[i].price);
			printf("set the rent amount per day");
			scanf("%d",&car[i].rent);	
			 fseek(fp ,-sizeof(car[i]),SEEK_CUR);
			fwrite(&car[i],sizeof(car[i]),1,fp);	
			break;	
		}
		
	}
	fclose(fp);
	printf("\nCAR UPDATED SUCCESSFULLY!!\n\n");
	printf("do you want to update another car?\npress y for yes\npress n for no\nenter your choice:");
	fflush(stdin);
		scanf("%c",&c);
		fflush(stdin);
	if(c=='n')
	{
		printf("\npress any key to go back to adminarea\n");
		getch();
		adminarea();
	}
	else
	updatecar();	
	}	
	
void deletecar()
{
	system("cls");
	char c;
	printf("\t\t\t<--:DELETE RECORD:-->\n\n");
	FILE *fp,*fp1;
	fp=fopen("carinformation.txt","r+");
	fp1=fopen("delete.txt","a+");
	
	char search[20];
	printf("enter the name of the car that you want to delete:");
	fflush(stdin);
	gets(search);
	fflush(stdin);
	if(fp1==NULL)
	{
		printf("no file exist");
		exit(0);
	}
	if(fp==NULL)
	{
	printf("no file exist");
		exit(0);	
	}
	while(fread(&car[i],sizeof(car[i]),1,fp)>0)
	{
		if(strcmp(search,car[i].name)!=0)
		{
			fwrite(&car[i],sizeof(car[i]),1,fp1);	
		}}
		fclose(fp);
		fclose(fp1);
		remove("carinformation.txt");
		rename("delete.txt","carinformation.txt");
	
	printf("\nRECORD DELETED SUCCESFULLY!!\n\n");
	printf("do you want to delete another car?\npress y for yes\npress n for no\nenter your choice:");
	scanf("%c",&c);
	if(c=='n')
	{
		printf("\npress any key to go back to adminarea\n");
		getch();
		adminarea();
	}
	else
	deletecar();
}

void login()
{
	system("cls");
	int b;
	printf("login as:\n\n1-admin\n2-customer\n3-go back\n");
	printf("\nenter your choice:");
	scanf("%d",&b);
		switch(b)
		{
		case 1:
		
			adminlogin();	
			break;
		case 2:
		
			costumerlogin();
			break;
		case 3:
			main();
			break;
		}
}

void newusersignup()
{
	printf("\n\t\t\t<WELCOME COSTUMER>\n\n");
	system("cls");
	FILE *fp;
	fp=fopen("newuser.txt","w");
	char username[50],passward[50],ch;
	printf("\t\t\t*welcome costumer*\n\n");
	printf("set your username:");
	fflush(stdin);
	gets(user.username);
	fflush(stdin);
	printf("set your passward:");
	fflush(stdin);
	gets(user.passward);
	fwrite(&user,sizeof(user),1,fp);
	fclose(fp);
	printf("press any key to continue");
	getch();
	login();
}
	
	
void costumerlogin()
{
	system("cls");
	printf("\n\t\t\t<WELCOME COSTUMER>\n\n");
	char use[50],pass[50],ch,a;
	FILE *fp;
	fp=fopen("newuser.txt","r");
	fscanf(fp,"%s  %s",&user.username,user.passward);
	a:
		printf("\nenter username:");
		fflush(stdin);
		gets(use);
		fflush(stdin);	
		printf("enter password:");
		gets(pass);
		
		if(strcmp(use,user.username)==0 && strcmp(pass,user.passward)==0)
		
	
		{
			fclose(fp);
			printf("\n\n");
			printf("LOGIN SUCCESFUL!!\n\npress any key to continue");
			getch();
			buyerarea();
			
		}
		else
		{
			fflush(stdin);
			printf("\n\n");
			
			printf("INCORRECT USERNAME OR PASSWARD!!\n");
			printf("login again in 2 seconds\n");
			Beep(1000,1500);
			sleep(2);
			
			goto a;	
		}
		}
	
		
void adminlogin()
{
	int i=0;
	system("cls");
	int a;
	struct newuser admin={"hamza","123"};
	char u_username[50],p_passward[50],ch;
	printf("\t\t\t<WELCOME ADMINS>\n\n");
	a:
	printf("enter username:");
	fflush(stdin);
	gets(u_username);
	fflush(stdin);
	
	fflush(stdin);

	printf("enter passward:");
	fflush(stdin);
	gets(p_passward);

if( strcmp(p_passward,admin.passward)==0 &&  strcmp(u_username,admin.username)==0)

{
	printf("\n\n");
	adminarea();
}
else
	{
	printf("\n\n");
	fflush(stdin);
	Beep(1000,1500);

	printf("INCORRECT USERNAME OR PASSWARD!!\n");
	printf("login again in 2 seconds\n");
	sleep(2);
	goto a;

}}


int main()

{
	system("cls");
	int a,b;
	system("color f1");
	printf("\t\t=================================================\n");
	printf("\t\t|     ****WELCOME TO H.A.M SHOWROOM****         |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");
	printf("1-login\n2-sign up\n3-exit\n\n");
	printf("enter choice:");
	scanf("%d",&a);
	
	switch(a)
	{
		case 1:
			login();
			break;
		case 2:
			newusersignup();
		case 3:
			exit(0);	
	}	
}
