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
	if(!head)//起始开辟 
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
	while(p3)
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
	free(findbook->array);
	free(findbook);
	findbook = (BookArray*)malloc(len1);
	findbook->array = (Book*)malloc(LEN1);
	findbook->length = 0;
	p2 = head->array;
	p3 = findbook->array;
	p3->next = NULL;
	while (p2)
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
BookArray find_book_by_authors (const char *authors);
{ 
	free(findbook->array);
	free(findbook);
	findbook = (BookArray*)malloc(len1);
	findbook->array = (Book*)malloc(LEN1);
	findbook->length = 0;
	p2 = head->array;
	p3 = findbook->array;
	p3->next = NULL;
	while (p2) 
	{
		while(*p2->authors != )//要写一个一个判断 
		if (strcmp(p2->authors, authors) >= 0)
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
	free(findbook->array);
	free(findbook);
	findbook = (BookArray*)malloc(len1);
	findbook->array = (Book*)malloc(LEN1);
	findbook->length = 0;
	p2 = head->array;
	p3 = findbook->array;
	p3->next = NULL;
	while (p2) 
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
Book *find_book_by_id (unsigned int id);
{
	p2 = head->array;
	while(p2)
	{
		if(id == p2->id)
		{
			return p2;
		}
		p2 = p2->next;
	}
	return NULL;
}
static void _Add_book()
{
	int flag1 = flag2 = flag3 = 0;  
	Book *temp = (Book*)malloc(LEN1);
	printf("\nEnter the id of the book you wish to add:");
	flag1 = scanf("%d",temp->id);
	temp->authors = ask_question("\nEnter the authors of the book you wish to add:");
	temp->title = ask_question("\nEnter the title of the book you wish to add:");
	printf("\nEnter the year of the book you wish to add:");
	flag2 = scanf("%d",temp->year);
	printf("\nEnter the copies of the book you wish to add:");
	flag3 = scanf("%d",temp->copies);
	if(!flag1 && !flag2 && !flag3 && !check_char(temp->authors) && !check_char(temp->title)&& !add_book(*temp))
	printf("Book was successfully added.");
	else
	{ 
		printf("Sorry, you attemped to add an invalid book, please try again.");
		free(temp->authors);
		free(temp->title);
		fflush(stdin);//需要清空缓存区
	}
}
static void _Remove_book()
{
	unsigned int id;
	Book *temp;
	printf("\nEnter the id of the book you wish to remove:");
	if(scanf("%u",&id))
	{
		if(temp = find_book_by_id(id))
		{
			if(!remove_book(*temp))printf("Book was successfully removed.");
			else printf("Sorry, there are problems when try removing this book.");
		}
		else printf("Sorry, you attemped to remove an invalid book, please try again.");
	}
	else 
	{
		printf("Sorry, the id you entered was invalid, please try again.")
		fflush(stdin);
	}
}
static void _Search_for_books();
{
	int choice = 5;
	do {
		char *answer = ask_question("Please choose an option:\n1) Search by id\n2) Search by title\n3) Search by authors\n4) Search by years\n5) Return to customer interface");
			choice = atoi(answer);
			free(answer);
		switch(choice)
		{
			case 1:
				Find_book_by_id();
				break;
			case 2:
				Find_book_by_title(); 
				break;
			case 3:
				Find_book_by_authors();
				break;
			case 4:
				Find_book_by_year();
				break;
			case 5:
				break;
			default:
				printf("\nSorry, the option you entered was invalid, please try again.");
		}
	}while(choice != 5);
}
void _Display_all_books();
{
	
}
void Find_book_by_id()
{
	unsigned int temp1; 
	BookArray *temp2;
	printf("What is the id of the book you wish to find");
	if(scanf("%u",&temp););
	{
		if(temp2 = find_book_by_id(temp1))
		show_book_array(temp2);//还没写呢 
		else printf("Sorry, this book can not be founded.");
	}
	else printf("\nSorry, the id you entered was invalid, please try again.");
}
void Find_book_by_title()
{
	char *temp1 = ask_question("What is the title of the book you wish to find:");
	BookArray *temp2;
	if(check_char(temp1) == 1)
	{
		printf("You enter the invalid title, please try again.");
	}
	else 
	{
		if(temp2 = find_book_by_title(temp1))
		show_book_array(temp2);
		else printf("Sorry, this book can not be founded.");
	}
	free(temp1);
}
void Find_book_by_authors()
{
	char *temp1 = ask_question("What is the authors of the book you wish to find");
	BookArray *temp2;
	if(check_char(temp1) == 1)
	{
		printf("You enter the invalid authors, please try again.");
	}
	else 
	{
		if(temp2 = find_book_by_authors(temp1))
		show_book_array(temp2);
		else printf("Sorry, this book can not be founded.");
	}
	free(temp1);
}
void Find_book_by_year()
{	
	unsigned int temp1; 
	BookArray *temp2;
	printf("What is the year of the book you wish to find");
	if(scanf("%u",&temp1));
	{
		if(temp2 = find_book_by_year(temp1))
		show_book_array(temp2);
		else printf("Sorry, this book can not be founded.");
	}
	else printf("\nSorry, the id you entered was invalid, please try again.");
}
static int check_char(char* str)//判断字符串里是否有数字 
{
	char *p;
	int have = 0;
	p = str;
	while(*p && ! have)
	{
		if (*p>='0' && *p<='9') have=1;
		p++;
	}
	return(have?1:0);
}
char *ask_question(const char *question)
{
	static char *ask_question(const char *question) {

	printf("%s",question);

	const int size_step = 2;
	char *answer = malloc(size_step);
	answer[0] = 0; //now it's a string of length 0.

	//read until a new line in blocks of size_step  bytes at at time
	char *next_chunk = answer;
	int iteration = 0;
	do {
		answer = realloc(answer, size_step + iteration*size_step);
		next_chunk = answer + strlen(answer); //answer may have moved.
		fgets(next_chunk, size_step, stdin);

		next_chunk = answer + strlen(answer); //take the new read into account
		++iteration;
	} while (* (next_chunk-1) != '\n');

	*(next_chunk-1) = 0; //truncate the string eliminating the new line.

	return answer;
}
void show_book_array(BookArray* temp)
{
	
} 
int find_the_longest_title(BookArray* temp)
{
	int max = 0;
	while(p2 = temp->array->next)
	{
		max = strlen(p2->title) > max?strlen(p2->title):max;
		p2 = p2->next;
	}
	return max;
} 
