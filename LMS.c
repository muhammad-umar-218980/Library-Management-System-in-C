#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// <------------------------------ STRUCTURE FOR BOOKS ---------------------------------->

typedef struct {
    int bookID;
    char title[50];
    char author[50];
    int isBorrowed; 
} Book;

// <------------------------------ FUNCTION DECLARATIONS ---------------------------------->

void addBook();
void viewBooks();
void updateBook();
void deleteBook();
void searchBook();
void borrowOrReturnBook();
void menu();
void displayMenu();
void printBook(Book* book);
void animation();

// <------------------------------ GLOBAL VARIABLES ---------------------------------->

Book books[100];
int bookCount = 0;

// <------------------------------ MAIN FUNCTION ---------------------------------->

int main() {
	animation();
    menu();
    return 0;
}



void animation() {
    char text[] = " WELCOME TO LIBRARY MANAGEMENT SYSTEM (LMS)";
    int length = strlen(text);

    printf("          ");
    for (int i = 0; i < length + 30; i++) {
        printf("-");
    }
    printf("\n\n");

    printf("\t\t\t");

    for (int i = 0; text[i] != '\0'; i++) {
        printf("%c", text[i]);
         Sleep(100);
    }

    
printf("\n\n");

    printf("          ");
    for (int i = 0; i < length + 30; i++) {
        printf("-");
    }
    printf("\n");
}


// <------------------------------ DISPLAY MENU FUNCTION ---------------------------------->

void displayMenu() {
    printf("\n\t\t--------------------------\n");
    printf("\t\t1. Add Book\n");
    printf("\t\t2. View Books\n");
    printf("\t\t3. Update Book\n");
    printf("\t\t4. Delete Book\n");
    printf("\t\t5. Search Book\n");
    printf("\t\t6. Borrow/Return Book\n");
    printf("\t\t7. Exit\n");
    printf("\t\tEnter your choice: ");
}

// <------------------------------ MENU FUNCTION ---------------------------------->

void menu() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
    	printf("\t\t--------------------------\n");

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
//                viewBooks();
                break;
            case 3:
//                updateBook();
                break;
            case 4:
//                deleteBook();
                break;
            case 5:
//                searchBook();
                break;
            case 6:
//                borrowOrReturnBook();
                break;
            case 7:
                printf("\t\tExiting...\n");
                break;
            default:
                printf("\t\tInvalid choice! Please try again.\n");
        }
    } while (choice != 7);
}

// <------------------------------ addBook FUNCTION ---------------------------------->

void addBook() {
    if (bookCount >= 100) {
        printf("\t\tMaximum book limit reached. Cannot add more books.\n");
        return;
    }

    printf("\n\t\t--- Add Book ---\n");
    printf("\t\tEnter book ID: ");
    scanf("%d", &books[bookCount].bookID);

    printf("\t\tEnter title: ");
    scanf(" %[^\n]", books[bookCount].title);

    printf("\t\tEnter author: ");
    scanf(" %[^\n]", books[bookCount].author);

    books[bookCount].isBorrowed = 0; 
    bookCount++;
    printf("\t\tBook added successfully!\n");
}