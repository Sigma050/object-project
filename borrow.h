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
	char *cc;
	struct _borrow *next;
}Borrow;
typedef struct _borrow_array{
	Borrow *array;
	unsigned int length;
}BorrowArray;
int store_borrow(FILE *file);

int load_borrow(FILE *file);

int borrow_add(Book *book, char *cc);

int borrow_remove(unsigned int id, char *cc);

Borrow *find_customer_from_borrow(char *cc);

int check_book_existence(Book *book, char *cc);

void _Borrow_book(char *username);

void _Return_book(char *username);

void _Display_borrowing(char *name);

void Borrow_cleanup();
#endif

