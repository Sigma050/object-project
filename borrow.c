#include"borrow.h"

static BorrowArray *bhead;
static Borrow *b1, *b2, *b3;
static Book *b3, *re;
int borrow_add(Book *book, Customer *customer)
{
	int flag = 0;
	if(bhead == NULL)
	{
		bhead = (BorrowArray*)malloc(len3);
		bhead->length = 0;
		b1 = bhead->array = (Borrow*)malloc(LEN3);
		b1->next = NULL;
	}
	if((b2 = find_customer_from_borrow(customer)) != NULL)
	{
		if(check_book_existence(book,customer))return 0;
		b3 = b2->bookarray->array;
		while(b3->next != NULL)b3 = b3->next;
		b3 = b3->next = (Book*)malloc(LEN1);
		b3->id = book->id;
		b3->title = book->title;
		b3->authors = book->authors;
		b3->year = book->year;
		b3->copies = book->copies;
		b3->next = NULL;
		b2->bookarray->length +=1;
	}  
	else
	{
		b1 = b1->next = (Borrow*)malloc(LEN3);
		b1->next = NULL;
		b1->bookarray = (BookArray*)malloc(len1);
		b1->customer = customer;
		b3 = b1->bookarray->array = (Book*)malloc(LEN1);
		b3 = b3->next = (Book*)malloc(LEN1);
		b3->id = book->id;
		b3->title = book->title;
		b3->authors = book->authors;
		b3->year = book->year;
		b3->copies = book->copies;
		b3->next = NULL;
		b1->bookarray->length = 1;
		bhead->length += 1;
	}
	return 1;
}
int borrow_remove(unsigned int id, Customer *customer)
{
	int flag = 0;
	b3 = b2 = bhead->array;
	b2 = b2->next;
	while(b2)
	{
		if(b2->cusomter == customer)
		{
			flag = 1;
			b3 = b2->bookarray->array
			while(b3->next)
			{
				re = b3;
				b3 = b3->next;
				if(b3->id == id)
				{
					flag = 2;
					re->next = b3->next;
					free(b3->title);
					free(b3->authors);
					free(b3);
					b2->bookarray->length -= 1;
				}
			}
		}
		if(!b2->bookarray->length)
		{
			b3->next = b2->next;
			free(b2->bookarray->array);
			free(b2->bookarray);
			free(b2);
		}
		b3 = b2;
		b2 = b2->next;
	}
	return flag;
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
int check_book_existence(Book *book, Customer* customer)
{
	b2 = find_customer_from_borrow(customer);
	b3 = b2->bookarray->array;
	while(b3->next != NULL)
	{
		b3 = b3->next;
		if(b3->id == book->id)return 1;
	}
	return 0;
}
void _Borrow_book(char *username)
{
	unsigned int ii,check;
	printf("What is the id of the book you wish to borrow?");
	check = scanf("%u",&ii);
	getchar();
	if(check)
	{
		printf("Sorry, you should enter correct id.");
		fflush(stdin);
	}
	else if(find_book_by_id(ii)->copies == 0)printf("Sorry, all this term of books have been borrowed.");
	else
	{
		if(borrow_add(find_book_by_id (ii), find_customer_by_name(username)) == 1)
		printf("Successfully borrowed.");
		else printf("Maybe you have borrowed this book, please choose other book.");
	}
}
void _Return_book(char *username)
{
	unsigned int ii, check, bb;
	printf("What is the id of the book you wish to return?");
	check = scanf("%u",&ii);
	getchar();
	if(check)
	{
		printf("Sorry, you should enter correct id.");
		fflush(stdin);
	}
	else if(!find_book_by_id(ii))printf("There is no such id book.");
	else 
		if((bb = borrow_remove(ii, find_customer_by_name(username))) == 2)printf("Successfully returned.");
		if(bb == 1)printf("You may not have borrowed books.");
		if(!bb) printf("Sorry, you have not borrrowed books.");
}
void _Display_borrowing()
{
}
