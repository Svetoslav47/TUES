#include <stdio.h>
#include "book.h"

void printBook(Book *book)
{
    printf("ISBN: %d\n", book->ISBN);
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Genre: %s\n", book->genre);
    printf("Year: %d\n", book->year);
}