typedef struct Account
{
	int sl_no;
	char acc_type[10];
	char name[50];
	int acc_num;
	int cust_id;
	int card_num;
	int pin;
	int bal_amount;
	int period;
	float roi;
	char date[50];
	int inst_amt;
}Acc;

typedef struct Customer_Details
{
	int sl_no;
	int cust_id;
	char name[50];
	int ph_num;
	char address[100];
	char place[50];
	int pincode;
	char id_prf[10];
	char trans1[100];
	char trans2[100];
	char trans3[100];
	char trans4[100];
	char trans5[100];
	int pamt;
}Cust_Det;

typedef struct Denominations
{
	int ttho;
	int fhun;
	int hun;
	int thun;
	int fty;
	int total;
}Denom_t;


typedef struct Banker_Details
{
	int id;
	int pasw;
}B_det;


void Balance(Acc*, int);
int withdraw(Acc*,Denom_t*,int,int);
void trans_upd(Cust_Det*,int);
void SB_Deposit(Acc*,Denom_t* ,int,int);
void RD_Deposit(Acc*,Denom_t* ,int,int);
void LN_Deposit(Acc*,Denom_t* ,int,int);
void change_pin(Acc* ,Denom_t*,int ,int);
void update(Acc*,int);
void transaction_det(Cust_Det*,int);
void Deposit_Money(Denom_t*);
void payment_slip(Acc*,Cust_Det*,int);
int main();