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

// Функція для виведення інформації про книги
void printBook(struct Book *book) {
    printf("Назва книги: %s\n", book->title);
    printf("Ціна: %.2f$\n", book->price);
    printf("Число сторінок: %d\n", book->numPages);
    printf("Мова: %s\n", book->language);
    printf("Вага: %.2f\n", book->weight);
    printf("Рік видання: %d\n", book->yearPublished);
    printf("\n");
}

int main() {
    // Створення книг та додавання їх до списку
    struct Book *firstBook = createBook("Harry Potter and the Philosopher's Stone", 9.99, 223, "English", 0.5, 1997);
    struct Book *secondBook = createBook("Harry Potter and the Chamber of Secrets", 21.05, 251, "English", 0.6, 1998);
    struct Book *thirdBook = createBook("Harry Potter and the Prisoner of Azkaban", 14.99, 317, "English", 0.7, 1999);
    struct Book *fourthBook = createBook("Harry Potter and the Goblet of Fire", 20.47, 636, "English", 1.4, 2000);
    struct Book *fifthBook = createBook("Harry Potter and the Order of the Phoenix", 18.07, 766, "English", 1.6, 2003);
    struct Book *sixthBook = createBook("Harry Potter and the Half-Blood Prince", 20.99, 607, "English", 1.3, 2005);
    struct Book *seventhBook = createBook("Harry Potter and the Deathly Hallows", 23.99, 607, "English", 1.3, 2007);


    // З'єднання книг в зв'язаний список
    firstBook->next = secondBook;
    secondBook->next = thirdBook;
    thirdBook->next = fourthBook;
    fourthBook->next = fifthBook;
    fifthBook->next = sixthBook;
    sixthBook->next = seventhBook;


    // Виведення інформації про всі книги в списку
    struct Book *currentBook = firstBook;
    while (currentBook != NULL) {
        printBook(currentBook);
        currentBook = currentBook->next;
    }

    // Звільнення виділеної пам'яті
    currentBook = firstBook;
    while (currentBook != NULL) {
        struct Book *temp = currentBook;
        currentBook = currentBook->next;
        free(temp);
    }

    return 0;
}
