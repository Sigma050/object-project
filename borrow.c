#include<borrow.h>
#include<stdio.h>
#include<string.h>
static BorrowArray *head;
static Borrow *p1, *p2;
static Book *p3;
int borrow_add(Book *book, Customer *customer)
{
	int flag = 0;
	if(head == NULL)
	{
		head = (BorrowArray*)malloc(len3);
		p1 = head->array = (Borrow*)malloc(LEN3);
		p1->next = NULL;
	}
	if((p2 = find_customer_from_borrow(customer)) != NULL)
	{
		p3 = p2->bookarray->array;
		while(p3->next != NULL)p3 = p3->next;
		p3->next = book;
		p3->next->next = NULL;
		p2->bookarray->length +=1;
	}
	else
	{
		p1 = p1->next = (Borrow*)malloc(LEN3);
		p1->next = NULL;
		p1->bookarray = (BookArray*)malloc(len1);
		p3 = p1->bookarray->array = (Book*)malloc(LEN1);
		p3->next = book;
		p3->next->next = NULL;
		p1->bookarray->length = 1;
	}
}
Borrow *find_customer_from_borrow(Customer *customer)
{
	p2 = head->array;
	while(p2->next != NULL)
	{
		p2 = p2->next;
		if(p2->customer == customer)return p2;
	}
	return NULL;
}
