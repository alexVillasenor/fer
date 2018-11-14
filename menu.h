#ifndef MENU_H
#define MENU_H
#include <fstream>
#include <iostream>
#include <string>

class Menu
{
private:
    std::string result;
    unsigned claveXor=13;
public:
    Menu();
    void show();
    void read();
    void print();
    void setCesar();
    void unSetCesar();
    void setXOR();
    void unSetXOR();
    std::string getResult() const;
    void setResult(const std::string &value);
};

#endif // MENU_H
