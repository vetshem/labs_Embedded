#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для представлення книги про Гарі Поттера
struct Book {
    char title[100];
    float price;
    int numPages;
    char language[50];
    float weight;
    int yearPublished;
    struct Book *next; // Вказівник на наступний елемент у списку
};
void printBook(struct Book *book);
// Функція для створення нової книги
struct Book *createBook(const char title[], float price, int numPages, const char language[], float weight, int yearPublished) {
    struct Book *book = (struct Book *)malloc(sizeof(struct Book));
    if (book == NULL) {
        printf("Помилка при виділенні пам'яті для книги.\n");
        exit(1);
    }

    strncpy(book->title, title, sizeof(book->title));
    book->price = price;
    book->numPages = numPages;
    strncpy(book->language, language, sizeof(book->language));
    book->weight = weight;
    book->yearPublished = yearPublished;
    book->next = NULL;

    return book;
}

// Функція для додавання книги до списку
void addToBookList(struct Book **head, struct Book *newBook) {
    if (*head == NULL) {
        *head = newBook;
    } else {
        struct Book *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newBook;
    }
}

// Функція для виведення інформації про всі книги в списку
void printAllBooks(struct Book *head) {
    struct Book *currentBook = head;
    while (currentBook != NULL) {
        printBook(currentBook);
        currentBook = currentBook->next;
    }
}

// Функція для виведення інформації про книгу
void printBook(struct Book *book) {
    printf("Назва книги: %s\n", book->title);
    printf("Ціна: %.2f$\n", book->price);
    printf("Число сторінок: %d\n", book->numPages);
    printf("Мова: %s\n", book->language);
    printf("Вага: %.2f\n", book->weight);
    printf("Рік видання: %d\n", book->yearPublished);
    printf("\n");
}

// Функція для звільнення виділеної пам'яті
void freeAllBooks(struct Book *head) {
    struct Book *currentBook = head;
    while (currentBook != NULL) {
        struct Book *temp = currentBook;
        currentBook = currentBook->next;
        free(temp);
    }
}

int main() {
    // Ініціалізація голови списку
    struct Book *bookListHead = NULL;

    // Створення та додавання книг до списку
    addToBookList(&bookListHead, createBook("Harry Potter and the Philosopher's Stone", 9.99, 223, "English", 0.5, 1997));
    addToBookList(&bookListHead, createBook("Harry Potter and the Chamber of Secrets", 21.05, 251, "English", 0.6, 1998));
    addToBookList(&bookListHead, createBook("Harry Potter and the Prisoner of Azkaban", 14.99, 317, "English", 0.7, 1999));
    addToBookList(&bookListHead, createBook("Harry Potter and the Goblet of Fire", 20.47, 636, "English", 1.4, 2000));
    addToBookList(&bookListHead, createBook("Harry Potter and the Order of the Phoenix", 18.07, 766, "English", 1.6, 2003));
    addToBookList(&bookListHead, createBook("Harry Potter and the Half-Blood Prince", 20.99, 607, "English", 1.3, 2005));
    addToBookList(&bookListHead, createBook("Harry Potter and the Deathly Hallows", 23.99, 607, "English", 1.3, 2007));

    // Виведення інформації про всі книги в списку
    printAllBooks(bookListHead);

    // Звільнення виділеної пам'яті
    freeAllBooks(bookListHead);

    return 0;
}
