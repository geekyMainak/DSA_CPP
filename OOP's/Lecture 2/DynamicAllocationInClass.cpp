#include <iostream>
#include <string>

using namespace std;

class Books {
    private:
    string name;   // data members
    int price;     // data members
    int pages;     // data members

    public:
    // SETTERS
    void setName(string s) {
        this->name = s;
    }

    void setPrice(int p) {
        price = p;
    }

    void setPages(int page) {
        pages = page;
    }

    // GETTERS
    string getName() {
        return name;
    }

    int getPrice() {
        return price;
    }

    int getPages() {
        return pages;
    }

    int countBooks(int n) {
        if(price < n)   return 1;
        else return 0; 
    }

    bool isBookPresent(string n) {
        if(n == name)   return true;
        else    return false;
    }

};

int main() {

    Books B1;   // COMPILE MEMORY ALLOCATION
    B1.setName("Harry Potter");
    B1.setPrice(700);
    B1.setPages(120);

    Books *B2 = new Books;  // RUN TIME MEMORY ALLOCATION
    Books B2Obj = *B2;

    B2Obj.setName("Aesop Fasbles");
    B2Obj.setPrice(400);
    B2Obj.setPages(100);


    //Alternate
    Books *B3 = new Books;  // RUN TIME MEMORY ALLOCATION

    B3->setName("Folk Tales");
    B3->setPrice(500);
    B3->setPages(250);


    cout << "Name: " << B1.getName() << endl;
    cout << "Price: " << B1.getPrice() << endl;
    cout << "Pages: " << B1.getPages() << endl;

    cout << "Name: " << B2Obj.getName() << endl;
    cout << "Price: " << B2Obj.getPrice() << endl;
    cout << "Pages: " << B2Obj.getPages() << endl;

    cout << "Name: " << B3->getName() << endl;
    cout << "Price: " << B3->getPrice() << endl;
    cout << "Pages: " << B3->getPages() << endl;



    return 0;
}