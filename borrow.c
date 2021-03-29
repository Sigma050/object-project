#include"borrow.h"

static BorrowArray *bhead;
static Borrow *b1, *b2, *b3;
static Book *b4, *b5, *re;
int store_borrow(FILE *file)
{
	b2 = bhead->array->next;
	fwrite(&bhead->length, sizeof(bhead->length), 1, file);
	while(b2)
	{
		fwrite(&b2->bookarray->length, sizeof(b2->bookarray->length), 1, file);
		b4 = b2->bookarray->array->next;
		while(b4)
		{
			int leng1 = strlen(b4->title), leng2 = strlen(b4->authors);
			fwrite(&leng1, sizeof(leng1), 1, file);
			fwrite(&leng2, sizeof(leng2), 1, file);
			b4 = b4->next;
		}
		while(b4)
		{
			fwrite(&b4->id, sizeof(b4->id), 1, file);
			fwrite(b4->title, sizeof(b4->title), 1, file);
			fwrite(b4->authors, sizeof(b4->authors), 1, file);
			fwrite(&b4->year, sizeof(b4->year), 1, file);
			fwrite(&b4->copies, sizeof(b4->copies), 1, file);
			b4 = b4->next;
		}
		int leng3 = strlen(b2->cc);
		fwrite(&leng3, sizeof(leng3), 1, file);
		fwrite(b2->cc, sizeof(b2->cc), 1 ,file);
		b2 = b2->next; 
	}
	fclose(file);
	return 0;
}
int load_borrow(FILE *file)
{
	bhead = (BorrowArray*)malloc(len3);
	b1 = bhead->array = (Borrow*)malloc(LEN3);
	b1->next = NULL;
	b1->bookarray = (BookArray*)malloc(len1);
	b4 = b1->bookarray->array = (Book*)malloc(LEN1);
	b4->next = NULL;
	fread(&bhead->length, sizeof(bhead->length), 1, file);
	int borlen[bhead->length],length;
	for(int i = 0;i< bhead->length;i++)
	{
		b1 = b1->next = (Borrow*)malloc(LEN3);
		fread(&b1->bookarray->length, sizeof(b1->bookarray->length), 1, file);
		int titlen[b1->bookarray->length], autlen[b1->bookarray->length],le;
		for(int j = 0;j < b1->bookarray->length;j++)
		{
			fread(&titlen[j], sizeof(titlen[j]), 1, file);
			fread(&autlen[j], sizeof(autlen[j]), 1, file);
		}
		for(int j = 0;j < head->length;j++)
		{
			b4 = b4->next = (Book*)malloc(LEN1);
			b4->title = (char *)malloc(titlen[j]*(sizeof(char)));
			b4->authors = (char *)malloc(autlen[j]*(sizeof(char)));
			fread(&b4->id, sizeof(p1->id), 1, file);
			fread(b4->title, titlen[j]*(sizeof(char)), 1, file);
			fread(b4->authors, autlen[j]*(sizeof(char)), 1, file);
			fread(&b4->year, sizeof(b4->year), 1, file);
			fread(&b4->copies, sizeof(b4->copies), 1, file);
		}
		fread(&le, sizeof(le), 1, file);
		b1->cc = (char*)malloc(le*sizeof(char));
		fread(b1->cc, le*sizeof(char), 1, file);
	}
	fclose(file);
	return 0;
}
int borrow_add(Book *book, char *cc)
{
	int flag = 0;
	if(bhead == NULL)
	{
		bhead = (BorrowArray*)malloc(len3);
		bhead->length = 0;
		b1 = bhead->array = (Borrow*)malloc(LEN3);
		b1->next = NULL;
	}
	if((b2 = find_customer_from_borrow(cc)) != NULL)
	{
		if(check_book_existence(book,cc))return 0;
		b4 = b2->bookarray->array;
		while(b4->next != NULL)b4 = b4->next;
		b4 = b4->next = (Book*)malloc(LEN1);
		b4->id = book->id;
		b4->title = book->title;
		b4->authors = book->authors;
		b4->year = book->year;
		b4->copies = book->copies;
		b4->next = NULL;
		b2->bookarray->length +=1;
	}  
	else
	{
		b1 = b1->next = (Borrow*)malloc(LEN3);
		b1->next = NULL;
		b1->bookarray = (BookArray*)malloc(len1);
		b1->cc = (char*)malloc((strlen(cc)+1)*sizeof(char));
		strcpy(b1->cc,cc);
		b4 = b1->bookarray->array = (Book*)malloc(LEN1);
		b4 = b4->next = (Book*)malloc(LEN1);
		b4->id = book->id;
		b4->title = book->title;
		b4->authors = book->authors;
		b4->year = book->year;
		b4->copies = book->copies;
		b4->next = NULL;
		b1->bookarray->length = 1;
		bhead->length += 1;
	}
	return 1;
}
int borrow_remove(unsigned int id, char *cc)
{
	int flag = 0;
	b3 = b2 = bhead->array;
	b2 = b2->next;
	while(b2)
	{
		if(strcmp(b2->cc,cc) == 0)
		{
			flag = 1;
			b4 = b2->bookarray->array;
			while(b4->next)
			{
				re = b4;
				b4 = b4->next;
				if(b4->id == id)
				{
					flag = 2;
					re->next = b4->next;
					free(b4->title);
					free(b4->authors);
					free(b4);
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
Borrow *find_customer_from_borrow(char *cc)
{
	b2 = bhead->array;
	while(b2->next != NULL)
	{
		b2 = b2->next;
		if(b2->cc == cc)return b2;
	}
	return NULL;
	
}
int check_book_existence(Book *book, char* cc)
{
	b2 = find_customer_from_borrow(cc);
	b4 = b2->bookarray->array;
	while(b4->next != NULL)
	{
		b4 = b4->next;
		if(b4->id == book->id)return 1;
	}
	return 0;
}
void _Borrow_book(char *username)
{
	unsigned int ii,check;
	printf("What is the id of the book you wish to borrow?");
	check = scanf("%u",&ii);
	getchar();
	if(!check)
	{
		printf("Sorry, you should enter correct id.");
		fflush(stdin);
	}
	else if(find_book_by_id(ii)->copies == 0)printf("Sorry, all this term of books have been borrowed.");
	else
	{
		if(borrow_add(find_book_by_id (ii), username) == 1)
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
	{ 
		if((bb = borrow_remove(ii, username)) == 2)printf("Successfully returned.");
		if(bb == 1)printf("You may not have borrowed books.");
		if(!bb) printf("Sorry, you have not borrrowed books.");
	} 
}
void _Display_borrowing(char *name)
{
	b2 = bhead->array->next;
	while(b2)
	{
		if(strcmp(b2->cc, name) == 0)
		{
			int title_length, authors_length, times = 0;
			title_length = find_the_longest_title(b4 = b2->bookarray->array->next);
			authors_length = find_the_longest_authors(b4);
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
			while(b4)
			{
				printf("%u\t%s", b4->id, b4->title);
				for(int i = 0; i<title_length; i++)printf("\t");
				printf("%s",b4->authors);
				for(int i = 0; i<authors_length; i++)printf("\t");
				printf("%u\t%u\n",b4->year,b4->copies);
				b4 = b4->next;
			}	
		}
		b2 = b2->next;	
	}
}
void Borrow_cleanup()
{
	b2 = b3 = bhead->array;
	while(b2)
	{
		b3 = b3->next;
		b4 = b5 = b2->bookarray->array;
		while(b4)
		{
			b5 = b5->next;
			free(b4->authors);
			free(b4->title);
			free(b4);
			b4 = b5;
		}
		free(b2->bookarray);
		free(b2->cc);
		free(b2);
		b2 = b3;
	}
	free(bhead);
}
