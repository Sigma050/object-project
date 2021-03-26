#ifndef BORROW_MANAGEMENT_GURAD__H
#define BORROW_MANAGEMENT_GURAD__H
#include "book.h"
#include "customer.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LEN3 sizeof(Borrow)
#define len3 sizeof(BorrowArray)
typedef struct _borrow{
	BookArray *bookarray;
	Customer *customer;
	struct _borrow *next;
}Borrow;
typedef struct _borrow_array{
	Borrow *array;
	unsigned int length;
}BorrowArray;
int borrow(Book book, Customer customer);

Borrow *find_customer_from_borrow(Customer *customer);

int check_book_existence(Book *book, Customer* customer);

void _Borrow_book(char *username);
#endif

