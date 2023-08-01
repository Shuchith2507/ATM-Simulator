#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#define LEN 150
#include "ATM_Header.h"

int main()
{
	char chr = 'y';

	while (chr == 'y' || chr == 'Y')
	{
		FILE *f1 = fopen("Accounts\\SB.csv", "r");
		FILE *f2 = fopen("Accounts\\RD.csv", "r");
		FILE *f3 = fopen("Accounts\\LN.csv", "r");
		FILE *f4 = fopen("Accounts\\Details.csv", "r");
		FILE *f5 = fopen("Accounts\\Banker.csv", "r");
		FILE *f6 = fopen("Accounts\\Amount.csv", "r"); // Opening SB,RD,LN,Cust & Banker Details,ATM_amount files in in r mode

		if (f1 == NULL || f2 == NULL || f3 == NULL || f4 == NULL || f5 == NULL || f6 == NULL)
		{
			perror("");
		}

		else
		{

			Acc st1[1000], st2[1000], st3[1000];
			Cust_Det st4[1000];
			B_det det[100];
			Denom_t denom;
			char data1[500], data2[500], data3[500], data4[500], data5[500], data6[500], samt[10];
			int c1, c2, i = 0, j = 0, k = 0, l = 0, m = 0, y = 0, res = 0;
			time_t curtime;
			struct tm *loc_time;
			int acc_no, pin, c3, amt, e, ctr1 = 0, ctr2 = 0;
			char buf[LEN];

			for (int z = 0; z < 2; z++)
			{
				fgets(data1, 500, f1);
				fgets(data2, 500, f2);
				fgets(data3, 500, f3);
				fgets(data4, 1000, f4);
				fgets(data5, 500, f5);
				fgets(data6, 500, f6);
			}

			while (fgets(data1, 500, f1) != NULL) // storing the details of the SB Account in structure array st1
			{
				char *p = strtok(data1, ",");
				st1[i].sl_no = atoi(p);

				p = strtok(NULL, ",");
				strcpy(st1[i].acc_type, p);

				p = strtok(NULL, ",");
				st1[i].cust_id = atoi(p);

				p = strtok(NULL, ",");
				st1[i].acc_num = atoi(p);

				p = strtok(NULL, ",");
				strcpy(st1[i].name, p);

				p = strtok(NULL, ",");
				st1[i].card_num = atoi(p);

				p = strtok(NULL, ",");
				st1[i].pin = atoi(p);

				p = strtok(NULL, ",");
				st1[i].bal_amount = atoi(p);

				i++;
			}

			while (fgets(data2, 500, f2) != NULL) // storing the details of the RD Account in structure array st2
			{
				char *q = strtok(data2, ",");
				st2[j].sl_no = atoi(q);

				q = strtok(NULL, ",");
				strcpy(st2[j].acc_type, q);

				q = strtok(NULL, ",");
				st2[j].acc_num = atoi(q);

				q = strtok(NULL, ",");
				st2[j].bal_amount = atoi(q);

				q = strtok(NULL, ",");
				st2[j].period = atoi(q);

				q = strtok(NULL, ",");
				st2[j].roi = atof(q);

				q = strtok(NULL, ",");
				st2[j].inst_amt = atoi(q);

				q = strtok(NULL, ",");
				strcpy(st2[j].date, q);

				j++;
			}

			while (fgets(data3, 500, f3) != NULL) // storing the details of the LN Account in structure array st3
			{
				char *r = strtok(data3, ",");
				st3[k].sl_no = atoi(r);

				r = strtok(NULL, ",");
				strcpy(st3[k].acc_type, r);

				r = strtok(NULL, ",");
				st3[k].acc_num = atoi(r);

				r = strtok(NULL, ",");
				st3[k].bal_amount = atoi(r);

				r = strtok(NULL, ",");
				st3[k].period = atoi(r);

				r = strtok(NULL, ",");
				st3[k].roi = atof(r);

				r = strtok(NULL, ",");
				strcpy(st3[k].date, r);

				r = strtok(NULL, ",");
				st3[k].inst_amt = atoi(r);

				k++;
			}

			while (fgets(data4, 1000, f4) != NULL) // storing the details of the customers in structure array st4
			{

				char *s = strtok(data4, ",");
				st4[l].sl_no = atoi(s);

				s = strtok(NULL, ",");
				st4[l].cust_id = atoi(s);

				s = strtok(NULL, ",");
				strcpy(st4[l].name, s);

				s = strtok(NULL, ",");
				st4[l].ph_num = atoi(s);

				s = strtok(NULL, ",");
				strcpy(st4[l].address, s);

				s = strtok(NULL, ",");
				strcpy(st4[l].place, s);

				s = strtok(NULL, ",");
				st4[l].pincode = atoi(s);

				s = strtok(NULL, ",");
				strcpy(st4[l].id_prf, s);

				s = strtok(NULL, ",");
				strcpy(st4[l].trans1, s);

				s = strtok(NULL, ",");
				strcpy(st4[l].trans2, s);

				s = strtok(NULL, ",");
				strcpy(st4[l].trans3, s);

				s = strtok(NULL, ",");
				strcpy(st4[l].trans4, s);

				s = strtok(NULL, ",");
				strcpy(st4[l].trans5, s);

				s = strtok(NULL, ",");
				st4[l].pamt = atoi(s);

				l++;
			}

			while (fgets(data5, 500, f5) != NULL) // storing the details of the banker in structure array det
			{
				strtok(data5, ",");
				char *t = strtok(NULL, ",");
				det[m].id = atoi(t);

				t = strtok(NULL, ",");
				det[m].pasw = atoi(t);

				m++;
			}

			if (fgets(data6, 500, f6) != NULL) // storing the denominations and total amount in ATM in structure denom
			{
				char *u = strtok(data6, ",");
				denom.ttho = atoi(u);

				u = strtok(NULL, ",");
				denom.fhun = atoi(u);

				u = strtok(NULL, ",");
				denom.thun = atoi(u);

				u = strtok(NULL, ",");
				denom.hun = atoi(u);

				u = strtok(NULL, ",");
				denom.fty = atoi(u);

				u = strtok(NULL, ",");
				denom.total = atoi(u);
			}

			fclose(f1);
			fclose(f2);
			fclose(f3);
			fclose(f4);
			fclose(f5);
			fclose(f6);

			printf("\n\t\t\t\t\t\t\t\t\t\tUser Type\t\t\t\t\t\t\t\t\t\t\n");
			printf("1.   Customer\n");
			printf("2.   Banker\n");
			printf("3.   Exit\n");
			scanf("%d", &c1);

			switch (c1)
			{
			case 1:
				printf("\n\t\t\t\t\t............................WELCOME  TO  ATM  TRANSACTIONS............................\t\t\t\t\t\n");

				printf("\n\nEnter your choice\n");
				printf("1. Check Account Balance\n");
				printf("2. Withdraw Money\n");
				printf("3. Deposit Money\n");
				printf("4. Change Pin\n");
				printf("5. Check Previous Transactions\n");
				printf("6. Exit\n");

				scanf("%d", &c2);

				switch (c2)
				{

				case 1:
					printf("\nEnter Account number : ");
					scanf("%d", &acc_no);

					for (int p = 0; p < i && ctr1 != 1; p++) // To check Account Balance according to customer's choice if 3 accounts present
					{
						if (acc_no == st1[p].acc_num)
						{
							printf("\nEnter your pin : ");
							scanf("%d", &pin);
							if (pin == st1[p].pin)
							{
								for (int h = 0; h < j && ctr1 != 1; h++)
								{
									if (st2[h].acc_num == acc_no)
									{
										for (e = 0; e < k && ctr1 != 1; e++)
										{
											ctr2 = 1;
											if (st3[e].acc_num == acc_no)
											{
												printf("1. SB Balance\n");
												printf("2. RD Balance\n");
												printf("3. Loan Balance\n");

												scanf("%d", &c3);

												switch (c3)
												{
												case 1:
													Balance(st1, p);
													ctr1 = 1;

													break;
												case 2:
													Balance(st2, h);
													ctr1 = 1;

													break;
												case 3:
													Balance(st3, e);
													ctr1 = 1;

													break;
												default:
													printf("Invalid Choice\n");
												}
											}

											else // To check Account Balance according to customer's choice if SB & RD accounts present
											{
												printf("1. SB Balance\n");
												printf("2. RD Balance\n");

												scanf("%d", &c3);

												switch (c3)
												{
												case 1:
													Balance(st1, p);
													ctr1 = 1;

													break;
												case 2:
													Balance(st2, h);
													ctr1 = 1;

													break;
												default:
													printf("Invalid Choice\n");
												}
											}
										}
									}
								}

								for (e = 0; e < k && ctr1 != 1; e++) // To check Account Balance according to customer's choice if SB && LN accounts present
								{
									ctr2 = 1;
									if (st3[e].acc_num == acc_no)
									{
										printf("1. SB Balance\n");
										printf("2. LN Balance\n");

										scanf("%d", &c3);

										switch (c3)
										{
										case 1:
											Balance(st1, p);
											ctr1 = 1;

											break;
										case 2:
											Balance(st3, e);
											ctr1 = 1;

											break;
										default:
											printf("Invalid Choice\n");
										}
									}
								}

								if (ctr2 != 1)
								{
									Balance(st1, p); // To check Account Balance according to customer's choice if only SB account present
									ctr1 = 1;
								}
							}

							else
							{
								printf("\n\t\t\t\tInvalid Pin\n");
								ctr1 = 1;
							}
						}
					}

					if (ctr1 != 1)
					{
						printf("\nInvalid Account Number\n");
					}
					break;

				case 2: // Witdraw money in SB Account

					printf("\nEnter Account number : ");
					scanf("%d", &acc_no);

					for (int p = 0; p < i; p++)
					{
						if (acc_no == st1[p].acc_num)
						{
							ctr2 = 1;
							printf("\nEnter your pin : ");
							scanf("%d", &pin);

							if (pin == st1[p].pin)
							{

								printf("\nEnter the Amount\n");
								scanf("%d", &amt);

								if (amt < st1[p].bal_amount)
								{

									st1[p].bal_amount -= amt;
									curtime = time(NULL);
									loc_time = localtime(&curtime);

									char samt[10];
									itoa(amt, samt, 10);

									strcpy(st4[p].trans5, st4[p].trans4);
									strcpy(st4[p].trans4, st4[p].trans3);
									strcpy(st4[p].trans3, st4[p].trans2);
									strcpy(st4[p].trans2, st4[p].trans1);

									strftime(buf, LEN, "%b %d: ", loc_time);
									strcpy(st4[p].trans1, buf);
									strftime(buf, LEN, "%I:%M %p.", loc_time);
									strcat(st4[p].trans1, buf);
									strcat(st4[p].trans1, "SB: Db - Rs.");
									strcat(st4[p].trans1, samt);

									res = withdraw(st1, &denom, i, amt);
									if (res)
									{
										st4[p].pamt = amt;
										trans_upd(st4, l);
										payment_slip(st1, st4, p);
									}
								}

								else if (amt > st1[p].bal_amount)
								{
									printf("\n Insufficient Balance\n");
								}

								else
								{
									printf("\n Account needs a minimum balance of Rs1000\n");
								}
							}
							else
							{
								printf("\nInvalid Pin\n");
							}
						}
					}

					if (ctr2 != 1)
					{
						printf("\nInvalid Account Number\n");
					}

					break;

				case 3: // Deposit Money According to Customer's Choice

					printf("\nEnter Account number : ");
					scanf("%d", &acc_no);

					for (int p = 0; p < i && ctr1 != 1; p++)
					{
						if (acc_no == st1[p].acc_num)
						{
							printf("\nEnter your pin : ");
							scanf("%d", &pin);
							if (pin == st1[p].pin)
							{
								printf("\nEnter Deposit Amount\n");
								scanf("%d", &amt);

								for (int h = 0; h < j && ctr1 != 1; h++)
								{
									if (st2[h].acc_num == acc_no)
									{
										for (e = 0; e < k && ctr1 != 1; e++)
										{
											ctr2 = 1;
											if (st3[e].acc_num == acc_no)
											{
												printf("1. SB Account\n"); // Deposit in any 1 of 3 Accounts
												printf("2. RD Account\n");
												printf("3. Loan Account\n");

												scanf("%d", &c3);

												switch (c3)
												{
												case 1:
													st1[p].bal_amount += amt;
													curtime = time(NULL);
													loc_time = localtime(&curtime);

													itoa(amt, samt, 10);

													strcpy(st4[p].trans5, st4[p].trans4);
													strcpy(st4[p].trans4, st4[p].trans3);
													strcpy(st4[p].trans3, st4[p].trans2);
													strcpy(st4[p].trans2, st4[p].trans1);

													strftime(buf, LEN, "%b %d: ", loc_time);
													strcpy(st4[p].trans1, buf);
													strftime(buf, LEN, "%I:%M %p.", loc_time);
													strcat(st4[p].trans1, buf);

													strcat(st4[p].trans1, "SB: Cr - Rs.");
													strcat(st4[p].trans1, samt);

													SB_Deposit(st1, &denom, i, amt);
													payment_slip(st1, st4, p);
													st4[p].pamt = amt;
													trans_upd(st4, l);
													ctr1 = 1;

													break;
												case 2:
													if (st2[h].inst_amt == amt)
													{
														st2[h].bal_amount += amt;
														curtime = time(NULL);
														loc_time = localtime(&curtime);

														itoa(amt, samt, 10);

														strcpy(st4[p].trans5, st4[p].trans4);
														strcpy(st4[p].trans4, st4[p].trans3);
														strcpy(st4[p].trans3, st4[p].trans2);
														strcpy(st4[p].trans2, st4[p].trans1);

														strftime(buf, LEN, "%b %d: ", loc_time);
														strcpy(st4[p].trans1, buf);
														strftime(buf, LEN, "%I:%M %p.", loc_time);
														strcat(st4[p].trans1, buf);

														strcat(st4[p].trans1, "RD: Cr - Rs.");
														strcat(st4[p].trans1, samt);

														st4[p].pamt = amt;
														trans_upd(st4, l);
														RD_Deposit(st2, &denom, j, amt);
														payment_slip(st1, st4, p);
														ctr1 = 1;
													}

													else if (st2[h].inst_amt > amt)
													{
														printf("\n\t\t\tDeposit greater than Installment Amount\n");
														printf("\nEnter Valid Amount\n");
														ctr1 = 1;
													}
													else
													{
														printf("\nDeposit lesser than Installment Amount\n");
														printf("\nEnter Valid Amount\n");
														ctr1 = 1;
													}
													break;
												case 3:
													st3[e].bal_amount -= amt;
													curtime = time(NULL);
													loc_time = localtime(&curtime);

													itoa(amt, samt, 10);

													strcpy(st4[p].trans5, st4[p].trans4);
													strcpy(st4[p].trans4, st4[p].trans3);
													strcpy(st4[p].trans3, st4[p].trans2);
													strcpy(st4[p].trans2, st4[p].trans1);

													strftime(buf, LEN, "%b %d: ", loc_time);
													strcpy(st4[p].trans1, buf);
													strftime(buf, LEN, "%I:%M %p.", loc_time);
													strcat(st4[p].trans1, buf);

													strcat(st4[p].trans1, "LN: Cr - Rs.");
													strcat(st4[p].trans1, samt);

													st4[p].pamt = amt;
													trans_upd(st4, l);
													LN_Deposit(st3, &denom, k, amt);
													payment_slip(st1, st4, p);
													ctr1 = 1;

													break;
												default:
													printf("Invalid Choice\n");
												}
											}

											else
											{
												printf("1. SB Account\n"); // Deposit in SB or RD Account
												printf("2. RD Account\n");

												scanf("%d", &c3);

												switch (c3)
												{
												case 1:
													st1[p].bal_amount += amt;
													curtime = time(NULL);
													loc_time = localtime(&curtime);

													itoa(amt, samt, 10);

													strcpy(st4[p].trans5, st4[p].trans4);
													strcpy(st4[p].trans4, st4[p].trans3);
													strcpy(st4[p].trans3, st4[p].trans2);
													strcpy(st4[p].trans2, st4[p].trans1);

													strftime(buf, LEN, "%b %d: ", loc_time);
													strcpy(st4[p].trans1, buf);
													strftime(buf, LEN, "%I:%M %p.", loc_time);
													strcat(st4[p].trans1, buf);

													strcat(st4[p].trans1, "SB: Cr - Rs.");
													strcat(st4[p].trans1, samt);

													st4[p].pamt = amt;
													trans_upd(st4, l);
													SB_Deposit(st1, &denom, i, amt);
													payment_slip(st1, st4, p);
													ctr1 = 1;

													break;
												case 2:

													if (st2[h].inst_amt == amt)
													{
														st2[h].bal_amount += amt;
														curtime = time(NULL);
														loc_time = localtime(&curtime);

														itoa(amt, samt, 10);

														strcpy(st4[p].trans5, st4[p].trans4);
														strcpy(st4[p].trans4, st4[p].trans3);
														strcpy(st4[p].trans3, st4[p].trans2);
														strcpy(st4[p].trans2, st4[p].trans1);

														strftime(buf, LEN, "%b %d: ", loc_time);
														strcpy(st4[p].trans1, buf);
														strftime(buf, LEN, "%I:%M %p.", loc_time);
														strcat(st4[p].trans1, buf);

														strcat(st4[p].trans1, "RD: Cr - Rs.");
														strcat(st4[p].trans1, samt);

														st4[p].pamt = amt;
														trans_upd(st4, l);
														RD_Deposit(st2, &denom, j, amt);
														payment_slip(st1, st4, p);

														ctr1 = 1;
													}

													else if (st2[h].inst_amt > amt)
													{
														printf("\nDeposit greater than Installment Amount\n");
														printf("\nEnter Valid Amount\n");
														ctr1 = 1;
													}

													else
													{
														printf("\nDeposit lesser than Installment Amount\n");
														printf("\nEnter Valid Amount\n");
														ctr1 = 1;
													}

													break;
												default:
													printf("Invalid Choice\n");
												}
											}
										}
									}
								}

								for (e = 0; e < k && ctr1 != 1; e++)
								{
									if (st3[e].acc_num == acc_no)
									{
										ctr2 = 1;
										printf("1. SB Balance\n"); // Deposit in SB or LN Account is present
										printf("2. LN Balance\n");

										scanf("%d", &c3);

										switch (c3)
										{
										case 1:
											st1[p].bal_amount += amt;
											curtime = time(NULL);
											loc_time = localtime(&curtime);

											itoa(amt, samt, 10);

											strcpy(st4[p].trans5, st4[p].trans4);
											strcpy(st4[p].trans4, st4[p].trans3);
											strcpy(st4[p].trans3, st4[p].trans2);
											strcpy(st4[p].trans2, st4[p].trans1);

											strftime(buf, LEN, "%b %d: ", loc_time);
											strcpy(st4[p].trans1, buf);
											strftime(buf, LEN, "%I:%M %p.", loc_time);
											strcat(st4[p].trans1, buf);

											strcat(st4[p].trans1, "SB: Cr - Rs.");
											strcat(st4[p].trans1, samt);

											st4[p].pamt = amt;
											trans_upd(st4, l);
											SB_Deposit(st1, &denom, i, amt);
											payment_slip(st1, st4, p);
											ctr1 = 1;

											break;
										case 2:
											st3[e].bal_amount -= amt;
											curtime = time(NULL);
											loc_time = localtime(&curtime);

											itoa(amt, samt, 10);

											strcpy(st4[p].trans5, st4[p].trans4);
											strcpy(st4[p].trans4, st4[p].trans3);
											strcpy(st4[p].trans3, st4[p].trans2);
											strcpy(st4[p].trans2, st4[p].trans1);

											strftime(buf, LEN, "%b %d: ", loc_time);
											strcpy(st4[p].trans1, buf);
											strftime(buf, LEN, "%I:%M %p.", loc_time);
											strcat(st4[p].trans1, buf);

											strcat(st4[p].trans1, "LN: Cr - Rs.");
											strcat(st4[p].trans1, samt);

											st4[p].pamt = amt;
											trans_upd(st4, l);
											LN_Deposit(st3, &denom, k, amt);
											payment_slip(st1, st4, p);
											ctr1 = 1;

											break;
										default:
											printf("Invalid Choice\n");
										}
									}
								}

								if (ctr2 != 1) // Deposit in only SB Account is present
								{
									st1[p].bal_amount += amt;
									curtime = time(NULL);
									loc_time = localtime(&curtime);

									itoa(amt, samt, 10);

									strcpy(st4[p].trans5, st4[p].trans4);
									strcpy(st4[p].trans4, st4[p].trans3);
									strcpy(st4[p].trans3, st4[p].trans2);
									strcpy(st4[p].trans2, st4[p].trans1);

									strftime(buf, LEN, "%b %d: ", loc_time);
									strcpy(st4[p].trans1, buf);
									strftime(buf, LEN, "%I:%M %p.", loc_time);
									strcat(st4[p].trans1, buf);

									strcat(st4[p].trans1, "SB: Cr - Rs.");
									strcat(st4[p].trans1, samt);

									st4[p].pamt = amt;
									trans_upd(st4, l);
									SB_Deposit(st1, &denom, i, amt);
									payment_slip(st1, st4, p);

									ctr1 = 1;
								}
							}

							else
							{
								printf("\nInvalid Pin\n");
								ctr1 = 1;
							}
						}
					}

					if (ctr1 != 1)
					{
						printf("\nInvalid Account Number\n");
					}

					break;

				case 4:
					change_pin(st1, &denom, i, amt); // Changing Pin
					update(st1, i);
					break;

				case 5: // To check previous 5 transaction details
					printf("\nEnter Account number : ");
					scanf("%d", &acc_no);

					for (int p = 0; p < i && ctr1 != 1; p++)
					{
						if (acc_no == st1[p].acc_num)
						{
							printf("\nEnter your pin : ");
							scanf("%d", &pin);
							if (pin == st1[p].pin)
							{
								transaction_det(st4, p);
							}
						}
					}

					break;

				case 6:
					chr = 'n';
					return 0;
					break;
				default:
					chr = 'y';
				}
				break;

				int id, passw, ctr4 = 0;
			case 2:

				printf("\nEnter your id : "); // To deposit money to ATM by banker
				scanf("%d", &id);

				for (int x = 0; x < m; x++)
				{
					if (id == det[x].id)
					{
						printf("\nEnter your password : ");
						scanf("%d", &passw);

						if (passw == det[x].pasw)
						{
							Deposit_Money(&denom);
							ctr4 = 1;
						}

						else
						{
							printf("\nInvalid Password\n");
						}
					}
				}
				if (ctr4 != 1)
					printf("\nInvalid ID\n");

				break;
			case 3:
				chr = 'n';
				return 0;
				break;
			default:
				printf("\nInvalid Choice\n");
			}
		}

		printf("\n\t\t\t\t\t\tEnter y to Continue / n to Exit\n");
		fflush(stdin);
		chr = getchar();
	}

	return 0;
}
