#include "customer.h"
int store_customer(FILE *file)
{
	if(file == NULL)
	{
		printf("Open file failed");
		return 1;
	}
	c2 = chead->array;
	fwrite(&(chead->length), sizeof(chead->length), 1, file);
	while(c2)
	{
		int leng1 = strlen(c2->account), leng2 = strlen(c2->passwords);
		fwrite(&leng1, sizeof(leng1), 1, file);
		fwrite(&leng2, sizeof(leng2), 1, file);
		c2 = c2->next;
	}
	c2 = chead->array;
	while(c2)
	{
		fwrite(c2->account, strlen(c2->account) + 1, 1, file);
		fwrite(c2->passwords, strlen(c2->passwords) + 1, 1, file);
		c2 = c2->next;
	}
	fclose(file);
	return 0;
}
int load_customer(FILE *file)
{
	if(file == NULL)
	{
		printf("Open file failed");
		return 1;
	}
	chead = (CustomerArray*)malloc(len2);
	c1 = chead->array = (Customer*)malloc(LEN2);
	c1->next = NULL;
	fread(&chead->length, sizeof(chead->length), 1, file);
	int acclen[chead->length], paslen[chead->length];
	for(int i = 0;i < chead->length;i++) 
	{
		fread(&acclen[i], sizeof(int), 1, file);
		fread(&paslen[i], sizeof(int), 1, file);
	}
	for(int i = 0;i < chead->length;i++)
	{
		c1 = c1->next = (Customer*)malloc(LEN2);
		c1->account = (char *)malloc(acclen[i] + 1); 
		c1->passwords = (char *)malloc(paslen[i] + 1);
		fread(&c1->account, acclen[i] + 1, 1, file);
		fread(&c1->passwords, paslen[i] + 1, 1, file);
	}
	fclose(file);
	return 0;
}
int add_customer(Customer* customer)
{
	if(!chead)//起始开辟 
	{
		chead = (CustomerArray*)malloc(len2);
		c1 = chead->array = (Customer*)malloc(LEN2);
		c1->account = (char*)malloc(9 * sizeof(char));
		strcpy(c1->account, "librarian");
		c1->passwords = (char*)malloc(9 * sizeof(char));
		strcpy(c1->passwords, "librarian");
		c1->next = customer;
		c1 = customer;
		c1->next = NULL;
		chead->length = 1;
	}
	else//添加用户 
	{
		c1->next = customer;
		c1 = customer;//要写一个判断是否开辟成功和存储的语句
		c1->next = NULL;
		chead->length += 1;
	}
	return 0;
}
int remove_customer(Customer customer)
{
	Customer *rec = &customer;
	int flag = 0;
	c2 = chead->array;
	c3 = c2->next;
	while(c3)
	{
		if(c3 == &customer)
		{
			c2->next = c3->next;
			free(rec);
			flag = 1;
		}
		c2 = c3;
		c3 = c3->next;
	}
	if(flag == 0)return 1;
	if(flag == 1)return 0;
}
char *find_customer_by_account(char *account)
{
	c2 = chead->array;
	while(c2)
	{
		if(strcmp(c2->account, account) ==0)
		{
			return(c2->passwords);
		} 
		c2 = c2->next;
	}
	return NULL;
}
Customer *find_customer_by_name(char *name)
{
	c2 = chead->array;
	while(c2)
	{
		if(strcmp(c2->account, name) ==0)
		{
			return(c2);
		} 
		c2 = c2->next;
	}
	return NULL;
}
int check_customer_existence(char *account)
{
	if(!chead)return 0;
	c2 = chead->array;
	while(c2)
	{
		if(strcmp(c2->account, account) ==0)
		{
			return 1;
		}
		c2 = c2->next;
	}
	return 0;
}
void Customer_cleanup()

{
	c2 = c3 = chead->array;
	while(c2)
	{
		c3 = c3->next;
		free(c2->account);
		free(c2->passwords);
		free(c2);
		c2 = c3;
	}
	free(chead);
	chead = NULL;
}

