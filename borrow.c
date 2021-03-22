#include"borrow.h"

static BorrowArray *bhead;
static Borrow *b1, *b2;
static Book *b3;
int borrow_add(Book *book, Customer *customer)
{
	int flag = 0;
	if(bhead == NULL)
	{
		bhead = (BorrowArray*)malloc(len3);
		b1 = bhead->array = (Borrow*)malloc(LEN3);
		b1->next = NULL;
	}
	if((b2 = find_customer_from_borrow(customer)) != NULL)
	{
		b3 = b2->bookarray->array;
		while(b3->next != NULL)b3 = b3->next;
		b3->next = book;
		b3->next->next = NULL;
		b2->bookarray->length +=1;
	}
	else
	{
		b1 = b1->next = (Borrow*)malloc(LEN3);
		b1->next = NULL;
		b1->bookarray = (BookArray*)malloc(len1);
		b3 = b1->bookarray->array = (Book*)malloc(LEN1);
		b3->next = book;
		b3->next->next = NULL;
		b1->bookarray->length = 1;
	}
}
Borrow *find_customer_from_borrow(Customer *customer)
{
	b2 = bhead->array;
	while(b2->next != NULL)
	{
		b2 = b2->next;
		if(b2->customer == customer)return b2;
	}
	return NULL;
}
