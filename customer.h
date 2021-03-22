#ifndef CUSTOMER_GUARD__H
#define CUSTOMER_GUARD__H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN2 sizeof(Customer)
#define len2 sizeof(CustomerArray)
typedef struct _customer{
	char *account;
	char *passwords;
	struct _customer *next;
}Customer;

typedef struct customer_Array{
	Customer *array;
	unsigned int length;
}CustomerArray;
static Customer *c1, *c2, *c3;
static CustomerArray *chead;
int store_customer(FILE *file);

int load_customer(FILE *file);

int add_customer(Customer customer);

int remove_customer(Customer customer);

char *find_customer_by_account(char *account);
#endif

 
