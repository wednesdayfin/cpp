#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    int pages;
    string author = "Peter";

protected:
    float price;

public:
    string publisher;

    void displayAuthorInfo() {
        cout << "Author: " << author << endl;
    }

    void setTitle(string newTitle) {
        title = newTitle;
    }

    void displayTitle() {
        cout << "Title: " << title << endl;
    }
};

int main() {
    Book myBook;

    myBook.setTitle("C++ Programming");
    myBook.displayTitle();

    myBook.publisher = "Pearson";
    cout << "Publisher: " << myBook.publisher << endl;

    myBook.displayAuthorInfo();

    return 0;
}
