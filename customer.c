#include <customer.h>
#include <stdio.h>
#include <string.h>
static Customer *p1, *p2, *p3;
static CustomerArray *head;
int store_customer(FILE *file)
{
	
}
int load_customer(FILE *file)
{
	
}
int add_customer(Customer customer)
{
	if(head == NULL)//起始开辟 
	{
		head = (CustomerArray*)malloc(Len2);
		p1 = head->array = (Customer*)malloc(LEN2);
		p1->next = NULL;
		head->length = 1;
	}
	else//添加用户 
	{
		p1->next = &book;
		p1 = &book;//要写一个判断是否开辟成功和存储的语句才能再将p1赋值给p2  
		p1->next = NULL;
		head->length += 1;
	}
	return 0;
}
int remove_customer(Customer customer)
{
	int flag = 0;
	p2 = head->array;
	p3 = head->array->next;
	while(p3 != NULL)
	{
		if(p3 == &customer)
		{
			p2->next = p3->next;
			flag = 1;
		}
		p3 = p3->next;
		p2 = p3;
	}
	if(flag == 0)return 1;
	if(flag == 1)return 0;
}
char *find_customer_by_account(char *account)
{
	p2 = head->array;
	while(p2->next !=NULL)
	{
		p2 = p2->next;
		if(strcpy(p2->account, account) ==0)
		{
			return(p2->password);
		} 
	}
	return 0;
}
