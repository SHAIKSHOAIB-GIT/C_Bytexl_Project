#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    int id;
    char title[100];
    char author[100];
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void addBook(int id, const char *title, const char *author) {
    if (book_count < MAX_BOOKS) {
        library[book_count].id = id;
        strcpy(library[book_count].title, title);
        strcpy(library[book_count].author, author);
        book_count++;
        printf("Book added successfully.\n");
    } else {
        printf("Library is full. Cannot add more books.\n");
    }
}

void deleteBook(int id) {
    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            found = 1;
            for (int j = i; j < book_count - 1; j++) {
                library[j] = library[j + 1];
            }
            book_count--;
            printf("Book deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }
}

void searchBook(int id) {
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            printf("Book found:\n");
            printf("ID: %d\n", library[i].id);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            return;
        }
    }
    printf("Book with ID %d not found.\n", id);
}

void displayBooks() {
    if (book_count == 0) {
        printf("No books in the library.\n");
    } else {
        for (int i = 0; i < book_count; i++) {
            printf("ID: %d, Title: %s, Author: %s\n", library[i].id, library[i].title, library[i].author);
        }
    }
}

int main() {
    int choice, id;
    char title[100], author[100];

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Search Book\n");
        printf("4. Display All Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter book ID: ");
                scanf("%d", &id);
                printf("Enter book title: ");
                scanf(" %[^\n]%*c", title);  // To read a string with spaces
                printf("Enter book author: ");
                scanf(" %[^\n]%*c", author); // To read a string with spaces
                addBook(id, title, author);
                break;
            case 2:
                printf("Enter book ID to delete: ");
                scanf("%d", &id);
                deleteBook(id);
                break;
            case 3:
                printf("Enter book ID to search: ");
                scanf("%d", &id);
                searchBook(id);
                break;
            case 4:
                displayBooks();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
