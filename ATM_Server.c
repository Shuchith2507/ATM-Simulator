#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ATM_Header.h"


void Balance(Acc* st1,int p)
{
	printf("Account Balance: %d\n",st1[p].bal_amount);
}


int withdraw(Acc* st1,Denom_t* denom,int n,int amt)
{
	int a[5]={2000,500,200,100,50},temp,i,total,res=0,res1=0,r;
	int b[5];

	temp=amt;
	for(i=0;i<5;i++)
	{
		b[i] = temp/a[i];
		temp=temp%a[i];
	}

	if(denom->fty<b[4])
		printf("\n\t\t\tEnter in Multiples of 100\n");

	if(denom->hun<b[3])
		printf("\n\t\t\tEnter in Multiples of 200\n");

	if(denom->thun<b[2])
		printf("\n\t\t\tEnter in Multiples of 500\n");

	if(denom->fhun<b[1])
		printf("\n\t\t\tEnter in Multiples of 2000\n");

	if(denom->ttho<b[0])
	{
		printf("\n\t\t\tInSufficient Amount in ATM\n");
		r=0;
	}

	if(denom->ttho>=b[0]  && denom->fhun>=b[1])
	{
		if(denom->thun>=b[2] && denom->hun>=b[3])
		{
			if(denom->fty>=b[4])
				res=1;
		}
	}

	if(res==1)
	{
		FILE *fp2 = fopen("E:\\Project\\Accounts\\Amount1.csv","w");
		fprintf(fp2,"D-2000,D-500,D-200,D-100,D-50,Total,\n\n");

		total=denom->total-amt;
		fprintf(fp2,"%d,%d,%d,%d,%d,%d,\n",denom->ttho-b[0],denom->fhun-b[1],denom->thun-b[2],denom->hun-b[3],denom->fty-b[4],total);

		fclose(fp2);
		fp2=NULL;
		remove("E:\\Project\\Accounts\\Amount.csv");
		rename("E:\\Project\\Accounts\\Amount1.csv","E:\\Project\\Accounts\\Amount.csv");

		FILE *fp1 = fopen("E:\\Project\\Accounts\\SB1.csv","w");
		fprintf(fp1,"Sl.No,Acc_Type,Customer_Id,Account No.,Customer Name,Card No.,Pin,Current_Balance,\n\n");

		for(int i=0;i<n;i++)
		{
			fprintf(fp1,"%d,%s,%d,%d,%s,%d,%d,%d,\n",st1[i].sl_no,st1[i].acc_type,st1[i].cust_id,st1[i].acc_num,st1[i].name,st1[i].card_num,st1[i].pin,st1[i].bal_amount);
		}
		fclose(fp1);
		fp1=NULL;
		remove("E:\\Project\\Accounts\\SB.csv");
		rename("E:\\Project\\Accounts\\SB1.csv","E:\\Project\\Accounts\\SB.csv");
		printf("Rs.%d withdrawn successfully\n",amt);

		r=1;
		
	}
	return r;
}

void trans_upd(Cust_Det* st,int n)
{

	FILE *fp2 = fopen("E:\\Project\\Accounts\\Details1.csv","w");
	fprintf(fp2,"Sl.No,Customer_Id,Customer Name,Phone_Num,Address,Place,Pin Code,Identity_Proof,\n\n");

	for(int i=0;i<n;i++)
	{	
		fprintf(fp2,"%d,%d,%s,%d,%s,%s,%d,%s,%s,%s,%s,%s,%s,%d",st[i].sl_no,st[i].cust_id,st[i].name,st[i].ph_num,st[i].address,st[i].place,st[i].pincode,st[i].id_prf,st[i].trans1,st[i].trans2,st[i].trans3,st[i].trans4,st[i].trans5,st[i].pamt);
		fprintf(fp2,"\n");
	}
	fclose(fp2);
	fp2=NULL;
	remove("E:\\Project\\Accounts\\Details.csv");
	rename("E:\\Project\\Accounts\\Details1.csv","E:\\Project\\Accounts\\Details.csv");
	
}	



void SB_Deposit(Acc* st1,Denom_t* denom,int n,int amt)
{
	int a[5]={2000,500,200,100,50},temp,i,total;
	int b[5];
	FILE *fp2 = fopen("E:\\Project\\Accounts\\Amount1.csv","w");
	fprintf(fp2,"D-2000,D-500,D-200,D-100,D-50,Total,\n\n");
	
	temp=amt;
	for(i=0;i<5;i++)
	{
		b[i] = temp/a[i];
		temp=temp%a[i];
	}
	
	total=denom->total+amt;
	fprintf(fp2,"%d,%d,%d,%d,%d,%d,\n",denom->ttho+b[0],denom->fhun+b[1],denom->thun+b[2],denom->hun+b[3],denom->fty+b[4],total);

	fclose(fp2);
	fp2=NULL;
	remove("E:\\Project\\Accounts\\Amount.csv");
	rename("E:\\Project\\Accounts\\Amount1.csv","E:\\Project\\Accounts\\Amount.csv");


	FILE *fp1 = fopen("E:\\Project\\Accounts\\SB1.csv","w");
	fprintf(fp1,"Sl.No,Acc_Type,Customer_Id,Account No.,Customer Name,Card No.,Pin,Current_Balance,\n\n");

	for(int i=0;i<n;i++)
	{
		fprintf(fp1,"%d,%s,%d,%d,%s,%d,%d,%d,\n",st1[i].sl_no,st1[i].acc_type,st1[i].cust_id,st1[i].acc_num,st1[i].name,st1[i].card_num,st1[i].pin,st1[i].bal_amount);
	}
	fclose(fp1);
	fp1=NULL;
	remove("E:\\Project\\Accounts\\SB.csv");
	rename("E:\\Project\\Accounts\\SB1.csv","E:\\Project\\Accounts\\SB.csv");
	printf("\nRs.%d deposited successfully",amt);
}


void RD_Deposit(Acc* st2,Denom_t* denom,int n,int amt)
{
	int a[5]={2000,500,200,100,50},temp,i,total;
	int b[5];
	FILE *fp2 = fopen("E:\\Project\\Accounts\\Amount1.csv","w");
	fprintf(fp2,"D-2000,D-500,D-200,D-100,D-50,Total,\n\n");
	
	temp=amt;
	for(i=0;i<5;i++)
	{
		b[i] = temp/a[i];
		temp=temp%a[i];
	}
	
	total=denom->total+amt;
	fprintf(fp2,"%d,%d,%d,%d,%d,%d,\n",denom->ttho+b[0],denom->fhun+b[1],denom->thun+b[2],denom->hun+b[3],denom->fty+b[4],total);

	fclose(fp2);
	fp2=NULL;
	remove("E:\\Project\\Accounts\\Amount.csv");
	rename("E:\\Project\\Accounts\\Amount1.csv","E:\\Project\\Accounts\\Amount.csv");


	FILE *fp1 = fopen("E:\\Project\\Accounts\\RD1.csv","w");
	fprintf(fp1,"Sl.No,Acc_Type,Account number,Amount,Period,Rate of interest,Maturity Date,Installment Amount\n\n");

	for(int i=0;i<n;i++)
	{
		fprintf(fp1,"%d,%s,%d,%d,%d,%f,%s,%d,\n",st2[i].sl_no,st2[i].acc_type,st2[i].acc_num,st2[i].bal_amount,st2[i].period,st2[i].roi,st2[i].date,st2[i].inst_amt);
	}
	fclose(fp1);
	fp1=NULL;
	remove("E:\\Project\\Accounts\\RD.csv");
	rename("E:\\Project\\Accounts\\RD1.csv","E:\\Project\\Accounts\\RD.csv");

	printf("\nRs.%d deposited successfully",amt);
}


void LN_Deposit(Acc* st3,Denom_t* denom,int n,int amt)
{
	int a[5]={2000,500,200,100,50},temp,i,total;
	int b[5];
	
	
	temp=amt;
	for(i=0;i<5;i++)
	{
		b[i] = temp/a[i];
		temp=temp%a[i];
	}
	

	FILE *fp2 = fopen("E:\\Project\\Accounts\\Amount1.csv","w");
	fprintf(fp2,"D-2000,D-500,D-200,D-100,D-50,Tota,l\n\n");

	total=denom->total+amt;
	fprintf(fp2,"%d,%d,%d,%d,%d,%d,\n",denom->ttho+b[0],denom->fhun+b[1],denom->thun+b[2],denom->hun+b[3],denom->fty+b[4],total);

	fclose(fp2);
	fp2=NULL;
	remove("E:\\Project\\Accounts\\Amount.csv");
	rename("E:\\Project\\Accounts\\Amount1.csv","E:\\Project\\Accounts\\Amount.csv");


	FILE *fp1 = fopen("E:\\Project\\Accounts\\LN1.csv","w");
	fprintf(fp1,"Sl.No,Acc_Type,Account number,Amount,Period,Rate of interest,Maturity Date,Installment Amount,\n\n");

	for(int i=0;i<n;i++)
	{
		fprintf(fp1,"%d,%s,%d,%d,%d,%f,%s,%d\n",st3[i].sl_no,st3[i].acc_type,st3[i].acc_num,st3[i].bal_amount,st3[i].period,st3[i].roi,st3[i].date,st3[i].inst_amt);
	}
	fclose(fp1);
	fp1=NULL;
	remove("E:\\Project\\Accounts\\LN.csv");
	rename("E:\\Project\\Accounts\\LN1.csv","E:\\Project\\Accounts\\LN.csv");

	printf("\nRs.%d deposited successfully",amt);
}


void change_pin(Acc* st1,Denom_t* denom,int i,int amt)
{
	int acc_no,pin,pin1,pin2,ctr3=0;
	
	printf("\nEnter Account number : ");
	scanf("%d",&acc_no);

	for(int p=0;p<i;p++)
	{
		if(acc_no == st1[p].acc_num) 
		{
			printf("\nEnter your pin : ");
			scanf("%d",&pin);			
			if(pin == st1[p].pin)
			{
				printf("\nEnter new pin\n");
				scanf("%d",&pin1);
				printf("\nConfirm new pin\n");
				scanf("%d",&pin2);
				if(pin1 == pin2)
				{	
					ctr3=1;
					st1[p].pin=pin2;
					printf("\nPin Changed Successfully\n");										
										
				}
				else 
				{
					printf("\nPin not Matched\n");
					printf("\nRe-Confirm pin\n");
					scanf("%d",&pin2);
					if(pin1 == pin2)
					{	
						ctr3=1;
						st1[p].pin=pin2;
						printf("\nPin Changed Successfully\n");
					}

					else
					{
						ctr3=1;
						printf("\n\t\t\tMaximum Limit Reached\n\t\t\tLogin After Sometime\n");
					}
				}
			}
			else
			{
				printf("Pin did not match\n");
				printf("\nRe-enter the details\n");
				change_pin(st1,denom,i,amt);
			}
		}
	}
		
	if(ctr3!=1)
	{
		printf("\nInvalid Account Number\n");
		printf("Re-enter the details\n");
		change_pin(st1,denom,i,amt);
	}
}

void update(Acc* st1,int n)
{
	FILE *fp1 = fopen("E:\\Project\\Accounts\\SB1.csv","w");
	fprintf(fp1,"Sl.No,Acc_Type,Customer_Id,Account No.,Customer Name,Card No.,Pin,Current_Balance,\n\n");

	for(int i=0;i<n;i++)
	{
		fprintf(fp1,"%d,%s,%d,%d,%s,%d,%d,%d,\n",st1[i].sl_no,st1[i].acc_type,st1[i].cust_id,st1[i].acc_num,st1[i].name,st1[i].card_num,st1[i].pin,st1[i].bal_amount);
	}
	fclose(fp1);
	fp1=NULL;
	remove("E:\\Project\\Accounts\\SB.csv");
	rename("E:\\Project\\Accounts\\SB1.csv","E:\\Project\\Accounts\\SB.csv");
}


void transaction_det(Cust_Det* st4,int n)
{
	char* d1 = strtok(st4[n].trans1,".");
	char* tr1 = strtok(NULL,",");
	char* d2 = strtok(st4[n].trans2,".");
	char* tr2 = strtok(NULL,",");
	char* d3 = strtok(st4[n].trans3,".");
	char* tr3 = strtok(NULL,",");
	char* d4 = strtok(st4[n].trans4,".");
	char* tr4 = strtok(NULL,",");
	char* d5 = strtok(st4[n].trans5,".");
	char* tr5 = strtok(NULL,",");
	
	printf("\n\n\t\t\t\t%s\t\t%s\t\t%s\t%s\t\t%s\n",d1,d2,d3,d4,d5);
	printf("\t\t\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",tr1,tr2,tr3,tr4,tr5);
}

void Deposit_Money(Denom_t* denom)
{
	int fty,hun,thun,fhun,ttho,amt,total;
	printf("\n\t\t\t\t\t\tEnter Denominations of money to be deposited in ATM\t\t\t\t\t\t\t\n");
	printf("50 100 200 500 2000\n");
	scanf("%d%d%d%d%d",&fty,&hun,&thun,&fhun,&ttho);
	
	amt = fty*50 + hun*100 + thun*200 + fhun*500 + ttho*2000;

	FILE *fp1 = fopen("E:\\Project\\Accounts\\Amount1.csv","w");
	fprintf(fp1,"D-2000,D-500,D-200,D-100,D-50,Total,\n\n");

	total=denom->total+amt;
	fprintf(fp1,"%d,%d,%d,%d,%d,%d,\n",denom->ttho+ttho,denom->fhun+fhun,denom->thun+thun,denom->hun+hun,denom->fty+fty,total);

	fclose(fp1);
	fp1=NULL;
	remove("E:\\Project\\Accounts\\Amount.csv");
	rename("E:\\Project\\Accounts\\Amount1.csv","E:\\Project\\Accounts\\Amount.csv");

	printf("Deposit to ATM successful\n");
}

void payment_slip(Acc* st1,Cust_Det* st4,int n)
{	

	char* d1 = strtok(st4[n].trans1,".");
	char* tr1 = strtok(NULL,",");
	printf("\n\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t");
	printf("PAYMENT SLIP\n\n");
	printf("\t\t\tA/c No.\t\t\t\tNAME\t\t\t\tTRANSACTION\t\t\tDATE\n");
	printf("\n\t\t\t%d\t\t\t%s\t\t\t%s\t\t%s\n\n",st1[n].acc_num,st1[n].name,tr1,d1);
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");	
}

