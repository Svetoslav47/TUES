#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

char *read_string()
{
    char *str = (char *)malloc(1);
    if (str == NULL)
    {
        printf("Error allocating memory\n");
        exit(1);
    }
    *str = '\0';
    char c;
    int len = 0;
    while ((c = getchar()) != '\n')
    {
        str = (char *)realloc(str, len + 2);
        if (str == NULL)
        {
            printf("Error allocating memory\n");
            exit(1);
        }
        str[len++] = c;
        str[len] = '\0';
    }
    return str;
}

void main()
{
    LinkedList list = init();
    // read books from file
    FILE *fp = fopen("books.txt", "a+");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    char line[100];
    while (fgets(line, 100, fp) != NULL)
    {
        Book *book = (Book *)malloc(sizeof(Book));
        if (book == NULL)
        {
            printf("Error allocating memory\n");
            exit(1);
        }
        char *token = strtok(line, ",");
        book->ISBN = atoi(token);
        token = strtok(NULL, ",");
        book->title = (char *)malloc(strlen(token) + 1);
        if (book->title == NULL)
        {
            printf("Error allocating memory\n");
            exit(1);
        }
        strcpy(book->title, token);
        token = strtok(NULL, ",");
        book->author = (char *)malloc(strlen(token) + 1);
        if (book->author == NULL)
        {
            printf("Error allocating memory\n");
            exit(1);
        }
        strcpy(book->author, token);
        token = strtok(NULL, ",");
        book->genre = (char *)malloc(strlen(token) + 1);
        if (book->genre == NULL)
        {
            printf("Error allocating memory\n");
            exit(1);
        }
        strcpy(book->genre, token);
        token = strtok(NULL, ",");
        book->year = atoi(token);
        pushback(&list, book);
    }

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Print all books\n");
        printf("2. Add book\n");
        printf("3. Delete book\n");
        printf("4. Save\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            for (int i = 0; i < list.size; i++)
            {
                printBook(get(&list, i)->value);
            }
            break;
        case 2:
            printf("Enter ISBN: ");
            int ISBN;
            scanf("%d", &ISBN);
            getchar();
            printf("Enter title: ");
            char *title = read_string();
            printf("Enter author: ");
            char *author = read_string();
            printf("Enter genre: ");
            char *genre = read_string();
            printf("Enter year: ");
            int year;
            scanf("%d", &year);
            getchar();
            Book *book = (Book *)malloc(sizeof(Book));
            if (book == NULL)
            {
                printf("Error allocating memory\n");
                exit(1);
            }
            book->ISBN = ISBN;
            book->title = title;
            book->author = author;
            book->genre = genre;
            book->year = year;
            pushback(&list, book);

            break;
        case 3:
            printf("Enter ISBN: ");
            int deleteISBN;
            scanf("%d", &deleteISBN);
            getchar();
            for (int i = 0; i < list.size; i++)
            {
                if (get(&list, i)->value->ISBN == deleteISBN)
                {
                    pop(&list, i);
                    break;
                }
            }
            break;

        case 4:
            fp = fopen("books.txt", "w");
            if (fp == NULL)
            {
                printf("Error opening file\n");
                exit(1);
            }
            for (int i = 0; i < list.size; i++)
            {
                Book *book = get(&list, i)->value;
                fprintf(fp, "%d,%s,%s,%s,%d\n", book->ISBN, book->title, book->author, book->genre, book->year);
            }
            fclose(fp);
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
