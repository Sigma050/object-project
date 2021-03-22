#include<stdio.h> 
#include<string.h>
#include"book.h"
#include"customer.h"
#include"interface.h"
#include"borrow.h"
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
		}
	}while(choice != 5);
}
static void _Register_an_account()
{
	Customer *c = (Customer*)malloc(LEN2);
	char *username = ask_question("Please enter your username:\n");
	char *passwords = ask_question("Please enter your passwords:\n");
	if(check_customer_existece(username) == 0)
	{
		c->account = username;
		c->passwords = passwords;
		if(add_customer(*c) == 0)printf("Registered library account successfully.\n");
	}
	else 
	{
		printf("Sorry, registration unsuccessful, the username you entered already exists.");
		free(c);
	}
	free(username);
	free(passwords);
}
static void _Login()
{
	Customer *temp = (Customer*)malloc(LEN2);
	char *username = ask_question("Please enter your username:\n");
	char *passwords = ask_question("Please enter you passwords:\n");
	if(strcmpy(find_customer_by_account(username), passwords) == 0)
	{
		if(strcpy(username, "librarian") == 0) librarian_interface();//π‹¿Ì‘±
		else customer_interface(username);
	}
	else printf("Sorry, you may enter wrong account or passwords, please check it.");
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
				_Display_borrowing();
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

	Book_cleanup();
	Customer_cleanup();

	return;
}
