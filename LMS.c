#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

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
                updateBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                searchBook();
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

    int bookID;
    int duplicate = 0;
    do {
        printf("\t\tEnter book ID: ");
        if (scanf("%d", &bookID) != 1) {
            printf("\t\tInvalid input! Please enter a valid integer book ID.\n\n");
            while (getchar() != '\n');  
            duplicate = 1;
        } else {
            duplicate = 0;
            for (int i = 0; i < bookCount; i++) {
                if (books[i].bookID == bookID) {
                    printf("\t\tBook ID already exists! Try again with a unique book ID.\n\n");
                    duplicate = 1;
                    break;
                }
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
    printf("\n\t\tBook record added successfully!\n");
}



// <------------------------------ viewBooks() FUNCTION ---------------------------------->

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
    	
    	char str[] = "LIBRARY BOOKS";
    	int j = 0 ;
        printf("\n\n\n\t\t------------------------------- ");

		while(str[j] != '\0'){
			printf("%c",str[j]);
			Sleep(100);
			j++;
		}
		
		printf(" -------------------------------------\n");
//         printf("\n\t\t---------------------------------- LIBRARY BOOKS ----------------------------------\n\n");
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




// <------------------------------------ updateBook() FUNCTION ------------------------------------------>

void updateBook() {
    if (bookCount == 0) {
        printf("\n\t\tNo books available in the library.\n");
        return;
    }

    int bookID;

    printf("\n\t\tEnter the book ID of the book to update: ");
    while (scanf("%d", &bookID) != 1) {
        printf("\t\tInvalid input! Please enter a valid integer book ID.\n");
        while (getchar() != '\n');
        printf("\n\t\tEnter the book ID of the book to update: ");
    }

    for (int i = 0; i < bookCount; i++) {
        if (books[i].bookID == bookID) {
            printf("\n\t\t------------------------ CURRENT RECORD OF BOOK ----------------------\n");
            printf("\t\t%-10s%-30s%-30s\n", "Book ID", "Title", "Author");
            printf("\t\t--------------------------------------------------------------------------\n");
            printf("\t\t%-10d%-30s%-30s\n", books[i].bookID, books[i].title, books[i].author);
            printf("\t\t--------------------------------------------------------------------------\n");

            printf("\n\t\t--- Update Record ---\n");

            printf("\t\tEnter new title: ");
            scanf(" %[^\n]", books[i].title);

            printf("\t\tEnter new author: ");
            scanf(" %[^\n]", books[i].author);

            printf("\n\t\tBook record updated successfully!\n");
            return;
        }
    }

    printf("\n\t\tNo book found with ID %d.\n", bookID);
}


// <------------------------------------ deleteBook() FUNCTION ------------------------------------------>
void deleteBook() {
    if (bookCount == 0) {
        printf("\n\t\tNo books in the library.\n");
        return;
    }

    int bookID, found = 0;

    printf("\n\t\tEnter the book ID to delete: ");
    scanf("%d", &bookID);

    for (int i = 0; i < bookCount; i++) {
        if (books[i].bookID == bookID) {
            found = 1;

            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }

            bookCount--; 
            printf("\n\t\tBook with ID %d deleted successfully.\n", bookID);
            break;
        }
    }

    if (!found) {
        printf("\n\t\tNo book found with ID %d.\n", bookID);
    }
}



// <------------------------------ searchBook FUNCTION ---------------------------------->

void searchBook() {
    if (bookCount == 0) {
        printf("\n\t\tNo books in the library.\n");
        return;
    }

    int choice, bookID, found = 0;
    char title[50];

    printf("\n\t\t--- Search Book ---\n");
    printf("\t\t1. Search by ID\n");
    printf("\t\t2. Search by Title\n");
    printf("\t\tEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\t\tEnter book ID: ");
        scanf("%d", &bookID);

        printf("\n\t\t------------------------------ CURRENT RECORD OF BOOK -----------------------------\n");
        printf("\t\t%-10s%-30s%-30s%-15s\n", "Book ID", "Title", "Author", "Status");
        printf("\t\t-----------------------------------------------------------------------------------\n");

        for (int i = 0; i < bookCount; i++) {
            if (books[i].bookID == bookID) {
                printf("\t\t%-10d%-30s%-30s%-15s\n", 
                       books[i].bookID, 
                       books[i].title, 
                       books[i].author, 
                       books[i].isBorrowed ? "Borrowed" : "Available");
                found = 1;
                break;
            }
        }
    } else if (choice == 2) {
        printf("\t\tEnter book title: ");
        scanf(" %[^\n]", title);

        printf("\n\t\t------------------------------ CURRENT RECORD OF BOOK -----------------------------\n");
        printf("\t\t%-10s%-30s%-30s%-15s\n", "Book ID", "Title", "Author", "Status");
        printf("\t\t-----------------------------------------------------------------------------------\n");

        for (int i = 0; i < bookCount; i++) {
            if (strcasecmp(books[i].title, title) == 0) {
                printf("\t\t%-10d%-30s%-30s%-15s\n", 
                       books[i].bookID, 
                       books[i].title, 
                       books[i].author, 
                       books[i].isBorrowed ? "Borrowed" : "Available");
                found = 1;
            }
        }
    } else {
        printf("\t\tInvalid choice! Please enter 1 or 2.\n");
        return;
    }

    if (!found) {
        printf("\t\tNo matching book found.\n");
    } else {
        printf("\t\t-----------------------------------------------------------------------------------\n");
    }
}



