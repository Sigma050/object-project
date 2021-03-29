#include<stdio.h> 
#include<string.h>
#include<stdlib.h> 
#include"interface.h"
#include"book.h"
#include"customer.h"
#include"interface.h"
#include"borrow.h"
extern Customer *c1;
extern CustomerArray *chead;
static void main_menu()
{
	int choice = 7;
	do
	{
		char *answer = ask_question("Please choose an option:\n1) Register an account\n2) Login\n3) Search for books\n4) Display all books\n5) Quit\n");
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
				load();
				break;
			case 6:
				save();
				break;
			case 7:
				printf("Good bye");
				break;
			default:
				printf("Sorry, the option you entered was invalid, please try again.");
		}
	}while(choice != 7);
}
static void _Register_an_account()
{
	Customer *c = (Customer*)malloc(LEN2);
	char *username = ask_question("Please enter your username:\n");
	char *passwords = ask_question("Please enter your passwords:\n");
	c->account = username;
	c->passwords = passwords;
	if(check_customer_existence(c->account) == 0)
	{
		if(add_customer(c) == 0)printf("Registered library account successfully.\n");
	}
	else 
	{
		printf("Sorry, registration unsuccessful, the username you entered already exists.");
		free(c);
	}
}
static void _Login()
{
	char *username = ask_question("Please enter your username:\n");
	char *passwords = ask_question("Please enter you passwords:\n");
	if(!chead)//起始开辟 
	{
		chead = (CustomerArray*)malloc(len2);
		c1 = chead->array = (Customer*)malloc(LEN2);
		c1->account = (char*)malloc(9 * sizeof(char));
		strcpy(c1->account, "librarian");
		c1->passwords = (char*)malloc(9 * sizeof(char));
		strcpy(c1->passwords, "librarian");
		c1->next = NULL;
		chead->length = 1;
	}
	if(find_customer_by_account(username))
	{
		if(strcmp(find_customer_by_account(username), passwords) == 0)
		{
			if(strcmp(username, "librarian") == 0) librarian_interface();//管理员
			else customer_interface(username);
		}
		else printf("Sorry, you may enter wrong account or passwords, please check it.");
	}
	else printf("Sorry, you may enter invalid account.");
	free(username);
	free(passwords);
}
static void librarian_interface()
{
	int choice = 5;
	do
	{
		printf("\n(Logged in as librarian)\n");
		char *answer = ask_question("Please choose an option:\n1) Add a book\n2) Remove a book\n3) Search for books\n4) Display all books\n5) Log out\n");
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
				break;
			default:
				printf("\nSorry, the option you entered was invalid, please try again.");
		}
	}while(choice != 5);
}
static void customer_interface(char *username)
{
	int choice = 6;
	do
	{
		printf("(Logged in as :%s\n)",username);
		char *answer = ask_question("Please choose an option:\n1) Borrow a book\n2) Return a book\n3) Search for books\n4) Display all books\n5) Display borrowing\n6) Log out\n");
		choice = atoi(answer);
		free(answer);
		switch(choice)
		{
			case 1:
				_Borrow_book(username);
				break;
			case 2:
				_Return_book(username);
				break;
			case 3:
				_Search_for_books();
				break;
			case 4:
				_Display_all_books();
				break;
			case 5:
				_Display_borrowing(username);
			case 6:
				break;
			default:
				printf("Sorry, the option you entered was invalid, please try again.\n");
		}
	}while(choice != 6);
}

void run_interface() {

	main_menu();
	//time to clean up behind us.
	findbook_cleanup();
	Book_cleanup();
	Customer_cleanup();
	Borrow_cleanup();

	return;
}
void load()
{
	FILE *fp1, *fp2, *fp3;
	fp1 = fopen("booksma", "rb");
	fp2 = fopen("customerma", "rb");
	fp3 = fopen("borrowma", "rb");
	if(load_books(fp1) == 0 && load_customer(fp2) == 0 && load_borrow(fp3) == 0);
	printf("Load successfully");
}
void save()
{
	FILE *fp1, *fp2, *fp3;
	fp1 = fopen("booksma","wb");
	fp2 = fopen("customerma","wb");
	fp3 = fopen("borrowma","wb");
	if(store_books(fp1) == 0 && store_customer(fp2) == 0 && store_borrow(fp3) == 0);
	printf("Save successfully");
}
