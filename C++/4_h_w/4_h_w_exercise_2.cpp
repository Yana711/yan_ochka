#include <iostream>
using namespace std;

struct Author {
    string Name;
    string Surname;
};

struct Book {
    string book_title = "Неизвестно";
    struct Author author {"Неизвестно", "Неизвестно"};
    int year = 0;
    int number_of_pages = 0;

    void display_book(){
        cout << "Название книги: " << book_title << '\n';
        cout << "Автор: " << author.Name << " " << author.Surname << '\n';
        cout << "Год издания: " << year << '\n';
        cout << "Количество страниц: " << number_of_pages << '\n';
    }
};

struct Book createBook(string book_title, string Name, string Surname, int year, int number_of_pages) {
    struct Book book;
    book.book_title = book_title;
    book.author.Name = Name;
    book.author.Surname = Surname;
    book.year = year;
    book.number_of_pages = number_of_pages;
    return book;
}

int main() 
{
    Book library[3];
    for (int i = 0; i < 3; i++) {
        string books;
        cout << "Как инициализируется книга. Если значениями по умолчанию, то напишите d, если с использованием пользовательского ввода - u\n";
        cin >> books;
        if (books == "d") {
            Book by_default;
            library[i] = by_default;
        } 
        else {
            string book_title, Name, Surname;
            int year, number_of_pages;
            cout << "Введите название книги, имя автора, фамилию автора, год издания и количество страниц:\n";
            cin >> book_title >> Name >> Surname >> year >> number_of_pages;
            library[i] = createBook(book_title, Name, Surname, year, number_of_pages);
        }
    }

    for (int i = 0; i < 3; i++) {
        library[i].display_book();
    }

    return 0;
}
