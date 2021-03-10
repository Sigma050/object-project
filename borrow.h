#include <stdio.h>
#include <string.h>
#include <book.h>
#include <customer.h>
#define LEN3 sizeof(Borrow)
#define len3 sizeof(BorrowArray)
typedef struct _borrow{
	BookArray *bookarray;
	Customer *customer;
	Borrow *next;
}Borrow;
typedef struct _borrow_array{
	Borrow *array;
	unsigned int length;
}BorrowArray;
int borrow(Book book, Customer customer);

Borrow *find_customer_from_borrow(Customer *customer);

