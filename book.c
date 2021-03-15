#include "book.h"
#include <stdio.h>
#include <string.h>
static BookArray *head, *findbook;
static Book *p1, *p2, *p3;
int store_books(FILE *file);
{
}
int load_books(FILE *file);
{
}
int add_book(Book book)
{
	if(head == NULL)//起始开辟 
	{
		head = (BookArray*)malloc(Len1);
		p1 = head->array = (Book*)malloc(LEN1);
		p1->next = NULL;
		head->length = 1;
	}
	else//添加书 
	{
		p1->next = &book;
		p1 = &book;//要写一个判断是否开辟成功和存储的语句 
		p1->next = NULL;
		head->length += 1;
	}
	return 0;
}
int remove_book(Book book);
{
	int flag = 0;
	p2 = head->array;
	p3 = head->array->next;
	while(p3 != NULL)
	{
		if(p3 == &book)
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
BookArray find_book_by_title (const char *title)
{ 	
	free(findbook);
	findbook = (BookArray*)malloc(len1);
	findbook->array = (Book*)malloc(LEN1);
	findbook->length = 0;
	p2 = head->array;
	p3 = findbook->array;
	p3->next = NULL;
	while (p2 ! = NULL)
	{
		if (strcmp(p2->title, title) == 0)
		{
			p3->next = p2;
			p3 = p3->next;
			findbook->length += 1;
		}
		p2 = p2->next;
	}
	return findbook;
} 
BookArray find_book_by_author (const char *author);
{ 
	free(findbook);
	findbook = (BookArray*)malloc(len1);
	findbook->array = (Book*)malloc(LEN1);
	findbook->length = 0;
	p2 = head->array;
	p3 = findbook->array;
	p3->next = NULL;
	while (p2 ! = NULL) 
	{
		if (strcmp(p2->author, author) == 0)
		{
			p3->next = p2;
			p3 = p3->next;
			findbook->length +=1;
		}
		p2 = p2->next;
	}
	return findbook;
} 
BookArray find_book_by_year (unsigned int year);
{
	free(findbook);
	findbook = (BookArray*)malloc(len1);
	findbook->array = (Book*)malloc(LEN1);
	findbook->length = 0;
	p2 = head->array;
	p3 = findbook->array;
	p3->next = NULL;
	while (p2 ! = NULL) 
	{
		if (year == p2->year)
		{
			p3->next = p2;
			p3 = p3->next;
			findbook->length +=1;
		}
		p2 = p2->next;
	}
	return findbook;
}
