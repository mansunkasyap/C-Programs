//
//  main.c
//  BookLibrary
//
//  Created by Ayush kanyal on 09/07/24.
//

#include <stdio.h>
#include <string.h>
#include "ranlib.h"
struct Book{
    int book_id;
    char bookName[50];
    float price;
    short int isAvailable;
};
struct Book add_book(void);
void printBookDetails(struct Book );
void findBook(char bookName[], struct Book [], int);

struct Book add_book(void){
    struct Book book;
    printf("--------------------------------\n");
    printf("Enter Book Id : ");
    scanf("%d", &book.book_id);
    fflush(stdin);
    printf("Enter Book Name : ");
    scanf("%s", book.bookName);
    fflush(stdin);

    printf("Enter Book Price : ");
    scanf("%f", &book.price);
    fflush(stdin);
    
    book.isAvailable = 1;
    
    return book;
}
void printBookDetails(struct Book book)
{
    printf("--------------------------------\n");
    printf("Book ID: %d\n", book.book_id);
    printf("Book Name: %s\n", book.bookName);
    printf("Book Price: %.2f\n", book.price);
    printf("Availability: %i\n", book.isAvailable);
    printf("\n--------------------------------\n");
}

//void fill_book(int space){
//
//}

void findBook(char bookName[], struct Book books[], int length)
{
    int check = 0;
    for(int i = 0; i < length; i++)
    {
//        printf("%s\n", bookName);
//        printf("%s\n", books[i].bookName);
        int compare = strcmp(bookName, books[i].bookName);
        if(compare == 0){
            check = 1;
            break;
//            printf("%s\n", bookName);
//            printf("%s\n", books[i].bookName);
        }
    }
    if (check == 1)
    {
        printf("--------------------------------\n");
        printf("Book available\n");
        printf("--------------------------------\n");
    }
    else{
        printf("--------------------------------\n");
        printf("Book unavailable\n");
        printf("--------------------------------\n");
    }
      
}

struct Book check_availabilty(char book_name[], struct Book book_shelf[], int l)
{
    for (int i = 0; i < l; i++)
    {
        int cmp = strcmp(book_name, book_shelf[i].bookName);
        if (cmp == 0)
        {
            if (book_shelf[i].isAvailable == 1)
            {
                return book_shelf[i];
            }
        }
    }
    struct Book b1={0, '\0', 0, 0};
    return  b1;
}


// Reduce availaiblity
void reduceAvail(char bookName[], struct Book bookShelf[], int lenght)
{
    for(int i=0; i<lenght; i++){
        if(strcmp(bookShelf[i].bookName, bookName) == 0)
        {
            bookShelf[i].isAvailable -= 1;
        }
    }
}


int main(int argc, const char * argv[]) {
    struct Book book;
    struct Book book_shelf[5];
    short int space = sizeof(book_shelf)/sizeof(book);
    printf("How many books you want to insert. ");
    int toInsert = 0;
    scanf("%d", &toInsert);
    
    for(int i = 0; i < toInsert; i++)
    {
        book_shelf[i] = add_book();
    }
    
    int _continue = 1;
    
    while (_continue){
        printf("--------------------------------\n");
        printf("What action do you want to perform?\nPress 1 to show available books.\nPress 2 to find a book.\nPress 3 to buy a book.\n");
        
        int user_input = 0;
        scanf("%d", &user_input);
        char user_book_name[50];
        
        
        switch (user_input)
        {
            case 1:
                for(int i = 0; i < toInsert; i++)
                {
                    printBookDetails(book_shelf[i]);
                }
                break;
            case 2:
                printf("--------------------------------\n");
                printf("Write the name of the book you want to find.\n");
                scanf("%s", user_book_name);
                findBook(user_book_name, book_shelf, toInsert);
                break;
            case 3:
                printf("--------------------------------\n");
                printf("Write the name of the book you want to buy.");
                scanf("%s", user_book_name);
                findBook(user_book_name, book_shelf, toInsert);
                struct Book available = check_availabilty(user_book_name, book_shelf, space);
                if (available.book_id != 0)
                {
                    printBookDetails(available);
                    float payment_by_user = 0;
                    printf("Price of the book is %.2f", available.price);
                    printf("Enter money.\n");
                    scanf("%f", &payment_by_user);
                    fflush(stdin);
                    if (payment_by_user >= available.price)
                    {
                        float change = payment_by_user - available.price;
                        printf("Thank you for the purchase! Here is your change %.2f\n", change);
                        printf("--------------------------------\n");
                        
                        // find book and reduce avail
                        
                        reduceAvail(user_book_name, book_shelf, toInsert);
                        
                        available.isAvailable = 0;
                     
                    }
                    else
                    {
                        printf("Sorry not enough money provided. Money refunded.");
                        printf("--------------------------------\n");
                    }
                }
                else
                {
                    printf("Sorry, book unavailable.\n");
                    printf("--------------------------------\n");
                }
                break;
            default:
                printf("Invalid action performed.\n");
        }
    }
        return 0;
}
