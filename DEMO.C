#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct details1
 {
  char c[20];
  char n[20];
  char co[20];
  char s[20];
  int q;
 };
struct details2
 {
  char ca[20];
  int cos;
 };
struct details1 d;
struct details2 e;
int k=50,b=30,z=10;
void main()
 {
  void write(void);
  void display1(char []);
  void display2(char []);
  void display3(void);
  int x,y;
  char st[20];
  do
   {
    clrscr();
    printf("\n----------------------------------------------------------------");
    printf("\n*********************CSE DEPARTMENTAL STORE*********************");
    printf("\n----------------------------------------------------------------");
    printf("\npress<1> to create a new entry");
    printf("\npress<2> to display details");
    printf("\npress<0> to exit");
    printf("\n\nenter your choice:");
    scanf("%d",&x);
    switch(x)
     {
      case 1:
       {
	write();
	printf("\ndata entered successfully");
	getch();
	break;
       }
      case 2:
       {
	printf("\n\npress<3> to search for availability");
	printf("\npress<4> to display the complete details");
	printf("\npress<5> to display the details of the unavailable products");
	printf("\n\nenter your choice:");
	scanf("%d",&y);
	switch(y)
	 {
	  case 3:
	   {
	    printf("\nenter the code or name of the product:");
	    scanf("%s",st);
	    display1(st);
	    break;
	   }
	  case 4:
	   {
	    printf("\nenter the category of the product:");
	    scanf("%s",st);
	    display2(st);
	    break;
	   }
	  case 5:
	   {
	    display3();
	    break;
	   }
	  default:
	   {
	    printf("\ninvalid entry");
	   }
	 }
	 break;
       }
      case 0:
       {
	exit(0);
	break;
       }
      default:
       {
	printf("\ninvalid entry");
       }
     }
   }while(x!=0);
   getch();
 }
void write()
 {
  FILE *fp1,*fp2;
  printf("\nenter the category:");
  scanf("%s",d.c);
  printf("enter the name of the product:");
  scanf("%s",d.n);
  printf("enter the code:");
  scanf("%s",d.co);
  printf("enter the specification:");
  scanf("%s",d.s);
  printf("enter the quantity:");
  scanf("%d",&d.q);
  printf("enter the cost of the product:");
  scanf("%d",&e.cos);
  fp1=fopen("praneeth.txt","a");
  if(fp1==NULL)
   {
    printf("\nerror in openening the file");
   }
  else
   {
    fwrite(&d,sizeof(d),1,fp1);
   }
  fclose(fp1);
  strcpy(e.ca,d.c);
  fp2=fopen("pr.txt","a");
  if(fp2==NULL)
   {
    printf("\nerror in opening the file");
   }
  else
   {
    fwrite(&e,sizeof(e),1,fp2);
   }
  fclose(fp2);
  return;
 }
void display1(char st[])
 {
  FILE *fp1,*fp2;
  char k;
 // textbackground(14);
  //textcolor(1);
  fp1=fopen("praneeth.txt","r");
  if(fp1==NULL)
   {
    printf("\nerror in opening the file");
   }
  else
   {
    while(fread(&d,sizeof(d),1,fp1)>0)
     {
      if(strcmp(st,d.co)==0||strcmp(st,d.n)==0)
       {
	k=0;
	printf("\navailability=%d",d.q);
       }
     }
   }
  if(k!=0)
   {
    printf("\nproduct with given details does not exists");
   }
  fclose(fp1);
  getch();
  return;
 }
void display2(char st[])
 {
  FILE *fp1,*fp2;
  fp2=fopen("pr.txt","r");
  fp1=fopen("praneeth.txt","r");
 // textbackground(14);
  //textcolor(1);
  if(fp1==NULL)
   {
    printf("\nerror in opening the file");
   }
  else
   {
    while(fread(&d,sizeof(d),1,fp1)>0)
     {
      if(strcmp(st,d.c)==0)
       {
	b=0;
	printf("\n\ncategory:%s",d.c);
	printf("\nname of the product:%s",d.n);
	printf("\ncode for the product:%s",d.co);
	printf("\navailbility of the product:%d",d.q);
	printf("\nspecification:%s",d.s);
       }
  if(fp2==NULL)
   {
    printf("\nerror in opening the file");
   }
  else
   {
    fread(&e,sizeof(e),1,fp2);
     {
      if(strcmp(st,e.ca)==0)
       {
	printf("\ncost of the given product=%d",e.cos);
       }
     }
   }
  }
 }
  if(b!=0)
   {
    printf("\nproduct with given details does not exists");
   }
  fclose(fp1);
  fclose(fp2);
  getch();
  return;
 }
void display3()
 {
  FILE *fp1,*fp2;
 // textbackground(14);
  //textcolor(1);
  fp1=fopen("praneeth.txt","r");
  if(fp1==NULL)
   {
    printf("error in opening the file");
   }
  else
   {
    while(fread(&d,sizeof(d),1,fp1)>0)
     {
      if(d.q==0)
       {
	z=0;
	printf("\n\ncategory:%s",d.c);
	printf("\nname of the product:%s",d.n);
	printf("\ncode of the product:%s",d.co);
	printf("\nspecification:%s",d.s);
       }
     }
   }
  fclose(fp1);
  if(z!=0)
   {
    printf("\nproduct with given details does not exists");
   }
  getch();
  return;
}

