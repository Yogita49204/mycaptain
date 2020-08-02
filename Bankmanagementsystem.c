#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<dos.h>
#include<conio.h>
struct bank
{
	int accno;
	char name[20];
	float bal;
	
}b;
void main()
{
	int ch;
	b:printf("\n\t\t\t\t Welcome to Mycaptain banking corporation\n\n\n\t Please select your appropriate option....");
	printf("\n1. NEW CUSTOMER\n 2. EXISTING CUSTOMER");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			{
				FILE*ff;
				ff=fopen("customer.dat","a");
				printf("\n Welcome to Mycaptain banking corporation(ABC.Ltd).\n it is a pleasure to have you here\n Please enter your name without spaces:");
				scanf("%s",&b.name);
				printf("\n welcome %s, please enter a suitable account number ",b.name);
				scanf("%d",&b.accno);
				printf("\n Please mention the initial deposit....Rs:");
				scanf("%f",&b.bal);
				printf("\ncomgratulations your account has been created.\n To deposit please login as existing customer");
				fwrite(&b,sizeof(b),1,ff);
				fclose(ff);
				getch();
				goto b;
				
			}break;
		case 2:
	        {
	        	int num,count=0,n,ch,flag;
	        	int a,c,t;
	        	float amount,value,temp;
	        	FILE*fp;
	        	printf("\n welcome once again to Mycaptain banking corporation(ABC)...");
	        	printf("\n\n Please enter your account number");
	        	scanf("%d",&num);
	        	fp=fopen("customer.dat","r+");
	        	rewind(fp);
	        	while(!feof(fp)&&count==0)
	        	{
	        		fread(&b,sizeof(b),1,fp);
	        		if(b.accno==num)
	        		{
	        			count==1;
					}
					
				}
				if(count==0)
				{
					printf("\n wrong account number....no such user");
					getch();
					goto b;
				}
				else
				{
					int m;
					printf("\n Welcome %s, what service would you like to avail",b.name);
					printf("\n1. DEPOSIT AMOUNT");
					printf("\n2. WITHDRAW AMOUNT");
					printf("\n3.VIEW DETAILS");
					printf("\n4. EXIT PROGRAM ");
					printf("please enter your choice:");
					scanf("%d",&m);
					switch(m)
					{
						case 1: {
						printf("\n\n\n Dear %s, please enter the amoount you want to deposit:",b.name);
						scanf("%d",&amount);
						b.bal=b.bal+amount;
						printf("\n your current available bank balance is %f",b.bal);
						n=sizeof(b);
						fseek(fp,-n,SEEK_CUR);
						fwrite(&b,n,1,fp);
						fclose(fp);
						getch();
					}break;
				
				 case 2: 
					    {
					    	printf("\n\n\n Dear %s, please enter the amount you want to withdraw:",b.name);
					    	scanf("%d",&amount);
					    	if(b.bal-amount<=0)
					    	{
					    		printf("\n SORRY! you dont have enough money in your account");
					    		fclose(fp);
					    		getch();
					    		goto b;
							}
							else
							{
								b.bal=b.bal-amount;
								printf("\n your current available bank balance is %f",b.bal);
								getch();
								n=sizeof(b);
								fseek(fp,-n,SEEK_CUR);
								fwrite(&b,n,1,fp);
								fclose(fp);
								goto b;
							}
						}break;
						case 3:
							{
								printf("\n your account details are as follows:");
								printf("\n\n Name: %s",b.name);
								printf("\n\n Account number:%d",b.accno);
								printf("\n\n Available balance:%f",b.bal);
								fclose(fp);
								printf("\n press any key to continue");
								getch();
								goto b;
							}break;
							default :
								exit(0);
							}break;
								
						
					}
				}
			}
				
	}
