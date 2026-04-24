/* This program defines a ShopItemOrder class with private attributes for 
the name, price, and number of items ordered. It includes public methods to 
set and get these attributes, calculate the total price, and print the order details. */

#include <iostream>
#include <string>

class ShopItemOrder
{
    public:
        ShopItemOrder(std::string name, double price, int nos):
            name(name), price(price), nos(nos) {}
        void set_nos(int nos);
        void set_price(double price);
        std::string get_name();
        double get_nos();
        double get_price();
        double get_total_price();
        void print();
        
    private:
        std::string name;
        double price;
        int nos;
};

void ShopItemOrder:: set_nos(int nos){
    this->nos = nos;
}

void ShopItemOrder:: set_price(double price){
    this->price = price;
}

double ShopItemOrder:: get_nos(){
    return nos;
}

double ShopItemOrder:: get_price(){
    return price;
}

std::string ShopItemOrder:: get_name(){
    return name;
}

double ShopItemOrder:: get_total_price(){
    if(nos && price){
        return nos*price;
    } else {
        return 0;
    }
}

void ShopItemOrder:: print(){
    std::cout << "You have order " << get_nos() << " items from " << get_name() << " and one item costs " << get_price() << " and total cost is " << get_total_price() <<std::endl;
}

int main(){
    ShopItemOrder order1("book", 10.5, 3);
    order1.print();

    order1.set_nos(5);
    order1.set_price(12.0);
    order1.print();
    return 0;
}