#include<stdio.h> 
#include<book.h>
#include<customer.h>
#include<string.h>

static char *ask_question(const char *question)
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
static void main_menu()
{
	int choice = 5;
	do
	{
		char *answer = ask_question("Please choose an option:\n1) Register an account\n2) Login\n3) Search for books\n4) Display all books\n5) Quit");
		choice = atoi(answer);
		free(answer);
		switch(choice)
		{
			case 1:
				_Register_an_account();
				break;
			case 2:
				_Login();
				break;
			case 3:
				_Search_for_books();
				break;
			case 4:
				_Display_all_books();
				break;
			case 5:
				printf("Good bye");
				break;
			default:
				printf("Sorry, the option you entered was invalid, please try again.");
		}while(choice != 5);
	}
}
static void _Register_an_account()
{
	Customer *c = (Customer*)malloc(LEN2);
	char *username = ask_qusetion("Please enter your username:\n");
	char *passwords = ask_qusetion("Please enter your passwords:\n");
	if(check_customer_existece(username) == 0)
	{
		c->account = username;
		c->passwords = passwords;
		if(add_customer(c) == 0)printf("Registered library account successfully.\n");
	}
	else printf("Sorry, registration unsuccessful, the username you entered already exists.");
	
}
static void _Login();
{
	Customer *temp = (Customer*)malloc(LEN2);
	char *username = ask_question("Please enter your username:\n");
	char *passwords = ask_question("Please enter you passwords:\n");
	if(strcpy(find_customer_by_account(username), username) == 0)
	{
		if(strcpy(username, "librarian") == 0) librarian_interface;//¹ÜÀíÔ±
		else customer_interface(username);
	}
	free(username);
	free(passwords);
}
static void librarian_interface()
{
	int choice = 5;
	do
	{
		printf("(Logged in as librarian)\n");
		char *answer = ask_question("Please choose an option:\n1) Add a book\n2) Remove a book\n3) Search for books\n4) Display all books\n5) Log out");
		choice = atoi(answer);
		free(answer);
		switch(choice)
		{
			case 1:
				_Add_book();
				break;
			case 2:
				_Remove_book();
				break;
			case 3:
				_Search_for_books();
				break;
			case 4:
				_Display_all_books();
				break;
			case 5:
				main_menu();
				break;
			default:
				printf("\nSorry, the option you entered was invalid, please try again.");
		}while(choice != 5);
	}
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
	if(flag1 == 0 && flag2 ==0 && flag3 == 0 && check_char(temp->authors) == 0 && check_char(temp->title) == 0)
	printf("Book was successfully added.");
	else
	printf("Sorry, you attemped to add an invalid book, please try again.");
}
static void _Remove_book()
{
	printf("\nEnter the id of the book you wish to removeP:");
	if(find_book_by_id)
}
static int check_char(char* str)
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
static void customer_interface(char *username)
{
	int choice = 5;
	do
	{
		printf("(Logged in as :%s\n)",username);
		char *answer = ask_question("Please choose an option:\n1) Borrow a book\n2) Return a book\n3) Search for books\n4) Display all books\n5) Log out\n");
		choice = atoi(answer);
		free(answer);
		switch(choice)
		{
			case 1:
				_Borrow_book();
				break;
			case 2:
				_Return_book();
				break;
			case 3:
				_Search_for_books();
				break;
			case 4:
				_Display_all_books();
				break;
			case 5:
				_Log_out();
				break;
			default:
				printf("Sorry, the option you entered was invalid, please try again.\n");
		}while(choice != 5);
	}
}
static void _Borrow_book()
{
	
}
