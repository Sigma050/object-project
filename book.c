#include "book.h"
#include "interface.h"
int store_books(FILE *file)
{
	p2 = head->array->next;
	fwrite(&head->length, sizeof(head->length), 1, file);
	while(p2)
	{
		int leng1 = strlen(p2->title), leng2 = strlen(p2->authors);
		fwrite(&leng1, sizeof(leng1), 1, file);
		fwrite(&leng2, sizeof(leng2), 1, file);
		p2 = p2->next;
	}
	while(p2)
	{
		fwrite(&p2->id, sizeof(p2->id), 1, file);
		fwrite(p2->title, sizeof(p2->title), 1, file);
		fwrite(p2->authors, sizeof(p2->authors), 1, file);
		fwrite(&p2->year, sizeof(p2->year), 1, file);
		fwrite(&p2->copies, sizeof(p2->copies), 1, file);
		p2 = p2->next;
	}
	fclose(file);
	return 0;
}
int load_books(FILE *file)
{
	head = (BookArray*)malloc(len1);
	p1 = head->array = (Book*)malloc(LEN1);
	p1->next = NULL;
	fread(&head->length, sizeof(head->length), 1, file);
	int titlen[head->length], autlen[head->length];
	for(int i = 0;i < (head->length);i++) 
	{
		fread(&titlen[i], sizeof(titlen[i]), 1, file);
		fread(&autlen[i], sizeof(autlen[i]), 1, file);
	}
	for(int i = 0;i < head->length;i++)
	{
		p1 = p1->next = (Book*)malloc(LEN1);
		p1->title = (char *)malloc(titlen[i]*(sizeof(char)));
		p1->authors = (char *)malloc(autlen[i]*(sizeof(char)));
		fread(&p1->id, sizeof(p1->id), 1, file);
		fread(p1->title, titlen[i]*(sizeof(char)), 1, file);
		fread(p1->authors, autlen[i]*(sizeof(char)), 1, file);
		fread(&p1->year, sizeof(p1->year), 1, file);
		fread(&p1->copies, sizeof(p1->copies), 1, file);
	}
	fclose(file);
	return 0;
}
int add_book(Book* book)
{
	if(!head)//起始开辟 
	{
		head = (BookArray*)malloc(len1);
		p1 = head->array = (Book*)malloc(LEN1);
		p1 = p1->next = book;
		p1->next = NULL;
		head->length = 1;
	}
	else//添加书 
	{
		if(find_book_by_id (book->id))return 1;
		p1->next = book;
		p1 = book;//要写一个判断是否开辟成功和存储的语句 
		p1->next = NULL;
		head->length += 1;
	}
	return 0;
}
int remove_book(Book* book)
{
	Book *re = book;
	int flag = 0;
	p2 = head->array;
	p3 = p2->next;
	while(p3)
	{
		if(p3 == re)
		{
			p2->next = p3->next;
			free(re->title);
			free(re->authors);
			free(re);
			flag = 1;
		}
		p2 = p3;
		p3 = p3->next;
	}
	if(flag == 0)return 1;
	if(flag == 1)return 0;
}
BookArray* find_book_by_title (const char *title)
{ 	
	findbook = (BookArray*)malloc(len1);
	p3 = findbook->array = (Book*)malloc(LEN1);
	findbook->length = 0;
	p2 = head->array->next;
	p3->next = NULL;
	while (p2)
	{
		if (strcmp(p2->title, title) == 0)
		{
			p3 = p3->next = (Book*)malloc(LEN1);
			p3->id = p2->id;
			p3->title = p2->title;
			p3->authors = p2->authors;
			p3->year = p2->year;
			p3->copies = p2->copies;
			p3->next = NULL;
			findbook->length +=1;
		}
		p2 = p2->next;
	}
	return findbook;
} 
BookArray* find_book_by_authors (const char *authors)
{ 
	findbook = (BookArray*)malloc(len1);
	p3 = findbook->array = (Book*)malloc(LEN1);
	findbook->length = 0;
	p2 = head->array->next;
	p3->next = NULL;
	while (p2)
	{
		if (strcmp(p2->authors, authors) == 0)
		{
			p3 = p3->next = (Book*)malloc(LEN1);
			p3->id = p2->id;
			p3->title = p2->title;
			p3->authors = p2->authors;
			p3->year = p2->year;
			p3->copies = p2->copies;
			p3->next = NULL;
			findbook->length +=1;
		}
		p2 = p2->next;
	}
	return findbook;
} 
BookArray* find_book_by_year (unsigned int year)
{
	findbook = (BookArray*)malloc(len1);
	p3 = findbook->array = (Book*)malloc(LEN1);
	findbook->length = 0;
	p2 = head->array->next;
	p3->next = NULL;
	while (p2) 
	{
		if (year == p2->year)
		{
			p3 = p3->next = (Book*)malloc(LEN1);
			p3->id = p2->id;
			p3->title = p2->title;
			p3->authors = p2->authors;
			p3->year = p2->year;
			p3->copies = p2->copies;
			p3->next = NULL;
			findbook->length +=1;
		}
		p2 = p2->next;
	}
	return findbook;
}
Book* find_book_by_id (unsigned int id)
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
void _Add_book()
{
	int flag1 = 0, flag2 = 0, flag3 = 0;  
	Book *temp = (Book*)malloc(LEN1);
	printf("\nEnter the id of the book you wish to add:");
	flag1 = scanf("%d",&temp->id);
	getchar();
	temp->title = ask_question("\nEnter the title of the book you wish to add:");
	temp->authors = ask_question("\nEnter the authors of the book you wish to add:");
	printf("\nEnter the year of the book you wish to add:");
	flag2 = scanf("%d",&temp->year);
	printf("\nEnter the copies of the book you wish to add:");
	flag3 = scanf("%d",&temp->copies);
	getchar();
	if(flag1 && flag2 && flag3 && !check_char(temp->authors) && !check_char(temp->title)&& !add_book(temp))
	printf("\nBook was successfully added.");
	else
	{ 
		printf("\nSorry, you attemped to add an invalid book, please try again.");
		free(temp->authors);
		free(temp->title);
		free(temp);
		fflush(stdin);//需要清空缓存区
	}
}
void _Remove_book()
{
	unsigned int id;
	Book *temp;
	printf("\nEnter the id of the book you wish to remove:");
	if(scanf("%u",&id))
	{
		if(temp = find_book_by_id(id))
		{
			if(!remove_book(temp))printf("Book was successfully removed.");
			else printf("Sorry, there are problems when try removing this book.");
		}
		else printf("Sorry, you attemped to remove an invalid book, please try again.");
	}
	else 
	{
		printf("Sorry, the id you entered was invalid, please try again.");
		fflush(stdin);
	}
	getchar();
}
void _Search_for_books()
{
	int choice = 5;
	do {
		char *answer = ask_question("Please choose an option:\n1) Search by id\n2) Search by title\n3) Search by authors\n4) Search by years\n5) Return to customer interface\n");
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
void _Display_all_books()
{
	if(!head)printf("Sorry, ther are no book, please wait for the librarian to add some books.");
	else show_book_array(head->array->next);
}
void Find_book_by_id()
{
	unsigned int temp1; 
	Book *temp2;
	printf("What is the id of the book you wish to find");
	if(scanf("%u",&temp1))
	{
		getchar();
		if(temp2 = find_book_by_id(temp1))
		show_book_array(temp2);// 
		else printf("Sorry, this book can not be founded.");
	}
	else printf("\nSorry, the id you entered was invalid, please try again.");
	fflush(stdin);
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
		temp2 = find_book_by_title(temp1);
		if(temp2->length)
		show_book_array(temp2->array->next);
		else printf("Sorry, this book can not be founded.");
	}
	findbook_cleanup();
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
		temp2 = find_book_by_authors(temp1); 
		if(temp2->length)
		show_book_array(temp2->array->next);
		else printf("Sorry, this book can not be founded.");
	}
	findbook_cleanup();
	free(temp1);
}
void Find_book_by_year()
{	
	unsigned int temp1; 
	BookArray *temp2;
	printf("What is the year of the book you wish to find");
	if(scanf("%u",&temp1))
	{
		getchar();
		temp2 = find_book_by_year(temp1);
		if(temp2->length)show_book_array(temp2->array->next);
		else printf("Sorry, this book can not be founded.");
	}
	else printf("\nSorry, the id you entered was invalid, please try again.");
	findbook_cleanup();
	fflush(stdin);
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
	} while (* (next_chunk -1) != '\n');

	*(next_chunk - 1) = 0; //truncate the string eliminating the new line.

	return answer;
}
void show_book_array(Book* boo)
{
	int title_length, authors_length, times = 0;
	title_length = find_the_longest_title(boo);
	authors_length = find_the_longest_authors(boo);
	while((title_length % 8) >= 0)
	{
		title_length -= 8;
		times += 1;
	}
	title_length = times + 1;
	times = 0;
	while((authors_length % 8) >= 0)
	{
		authors_length -= 8;
		times += 1;
	}
	authors_length = times + 1;
	printf("Id\tTitle");
	for(int i = 0; i<title_length; i++)printf("\t");
	printf("Authors");
	for(int i = 0; i<authors_length; i++)printf("\t");
	printf("Year\tCopies\n");
	while(boo)
	{
		printf("%u\t%s",boo->id,boo->title);
		for(int i = 0; i<title_length; i++)printf("\t");
		printf("%s",boo->authors);
		for(int i = 0; i<authors_length; i++)printf("\t");
		printf("%u\t%u\n",boo->year,boo->copies);
		boo = boo->next;
	}
} 

int find_the_longest_title(Book* temp)
{
	int max = 0;
	p2 = temp;
	while(p2)
	{
		max = strlen(p2->title) > max?strlen(p2->title):max;
		p2 = p2->next;
	}
	return max;
} 
int find_the_longest_authors(Book* temp)
{
	int max = 0;
	p2 = temp;
	while(p2)
	{
		max = strlen(p2->authors) > max?strlen(p2->authors):max;
		p2 = p2->next;
	}
	return max;
}
void Book_cleanup()
{
	p2 = p3 = head->array;
	while(p2)
	{
		p3 = p3->next; 
		if(p2->title);
		free(p2->title);
		if(p2->authors)
		free(p2->authors);
		free(p2);
		p2 = p3;
	}
	free(head);
}
void findbook_cleanup()
{
	p2 = p3 = findbook->array;
	while(p2)
	{
		p3 = p3->next;
		free(p2);
		p2 = p3;
	}
}
