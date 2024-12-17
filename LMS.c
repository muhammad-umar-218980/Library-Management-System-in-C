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
                viewBooks();
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

// <------------------------------ ADD BOOK FUNCTION ---------------------------------->

void addBook() {
    if (bookCount >= 100) {
        printf("\t\tMaximum book limit reached. Cannot add more books.\n");
        return;
    }

    printf("\n\t\t-------- Add Book --------\n");

    // Ye Duplicate Book ID check karay ga 
    int bookID;
    int duplicate = 0;
    do {
        printf("\t\tEnter book ID: ");
        scanf("%d", &bookID);

        duplicate = 0;
        for (int i = 0; i < bookCount; i++) {
            if (books[i].bookID == bookID) {
                printf("\t\tBook ID already exists! Try again with a unique book ID.\n\n");
                duplicate = 1;
                break;
            }
        }
    } while (duplicate);

    books[bookCount].bookID = bookID;

    printf("\t\tEnter title: ");
    scanf(" %[^\n]", books[bookCount].title); 

    printf("\t\tEnter author: ");
    scanf(" %[^\n]", books[bookCount].author); 

    books[bookCount].isBorrowed = 0; 
    bookCount++;
    printf("\t\tBook added successfully!\n");
}




// <------------------------------ VIEW BOOKS FUNCTION ---------------------------------->

void viewBooks() {
    int choice, bookID, found = 0;

    if (bookCount == 0) {
        printf("\n\t\tNo books in the library.\n");
        return;
    }

    printf("\n\t\tDo you want to:\n");
    printf("\t\t1. View all books\n");
    printf("\t\t2. View a specific book by ID\n");
    printf("\t\tEnter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
         printf("\n\t\t---------------------------------- LIBRARY BOOKS ----------------------------------\n\n");
        printf("\t\t%-10s%-30s%-30s%-15s\n", "Book ID", "Title", "Author", "Status");
        printf("\t\t-----------------------------------------------------------------------------------\n");
        

        for (int i = 0; i < bookCount; i++) {
            char status[15]; 
            if (books[i].isBorrowed) {
                strcpy(status, "Borrowed");
            } else {
                strcpy(status, "Available");
            }

            printf("\t\t%-10d%-30s%-30s%-15s\n", 
                   books[i].bookID, 
                   books[i].title, 
                   books[i].author, 
                   status);

            if (i != bookCount - 1) {
                printf("\n");
            }
        }
        printf("\t\t-----------------------------------------------------------------------------------\n");
    } 
    else if (choice == 2) {
        printf("\n\t\tEnter the book ID: ");
        scanf("%d", &bookID);

        for (int i = 0; i < bookCount; i++) {
            if (books[i].bookID == bookID) {
                char status[15]; 
                if (books[i].isBorrowed) {
                    strcpy(status, "Borrowed");
                } else {
                    strcpy(status, "Available");
                }

                printf("\n\t\tBook Details:\n");
                printf("\t\t%-10s%-30s%-30s%-15s\n", "Book ID", "Title", "Author", "Status");
                printf("\t\t-----------------------------------------------------------------------------------\n");
                printf("\t\t%-10d%-30s%-30s%-15s\n", 
                       books[i].bookID, 
                       books[i].title, 
                       books[i].author, 
                       status);
                printf("\t\t-----------------------------------------------------------------------------------\n");

                found = 1;
                break;
            }
        }

        if (!found) {
            printf("\n\t\tNo book found with ID %d.\n", bookID);
        }
    } 
    else {
        printf("\n\t\tInvalid choice! Please enter 1 or 2.\n");
    }
}


