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
        name = s;
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

    Books B1;
    B1.setName("Harry Potter");
    B1.setPrice(700);
    B1.setPages(120);

    cout << "Name: " << B1.getName() << endl;
    cout << "Price: " << B1.getPrice() << endl;
    cout << "Pages: " << B1.getPages() << endl;

    cout << B1.countBooks(71) << endl;
    cout << B1.isBookPresent("Harry Potter") << endl;



    return 0;
}