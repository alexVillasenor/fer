#include "menu.h"

using namespace std;

std::string Menu::getResult() const
{
    return result;
}

void Menu::setResult(const std::string &value)
{
    result = value;
}

Menu::Menu()
{

}

void Menu::show()
{
    string op;
    do{
        system("cls");
        cout<<"::Menu::"<<endl
        <<"1) Imprimir contenido de archivo"<<endl
        <<"2) Cifrar archivo con Cesar"<<endl
        <<"3) Cifrar archivo con XOR"<<endl
        <<"4) Revertir cifrado con Cesar"<<endl
        <<"5) Revertir cifrado con XOR"<<endl
        <<"6) Salir"<<endl
        <<"Seleccione una opcion y presione [ENTER]"<<endl;
        getline(cin,op);
        if(op=="1") {
            print();
        }
        else if(op=="2") {
            setCesar();
        }
        else if(op=="3") {
            setXOR();
        }
        else if(op=="4") {
            unSetCesar();
        }
        else if(op=="5") {
            unSetXOR();
        }
        else if(op=="6") {
            cout<<"::Fin del programa::"<<endl;
        }
        else {
            cout<<"::Opcion Invalida::"<<endl;
        }
        if(op!="6") {
            system("pause");
        }
    }while(op!="6");
}

void Menu::read()
{
    ifstream f("Documento.txt");
    if(!f.is_open()){
        cout<<"Error al abrir el archivo"<<endl;
    }
    else{
        string line;
        char c;
        result="";
        while(!f.eof()){
            f.read((char*)&c,sizeof(c));
            if(f.eof())
                break;
            result+=c;
        }
        f.close();
    }
}

void Menu::print()
{
    system("cls");
    read();
    cout<<result<<endl;

}

void Menu::setCesar()
{
    system("cls");
    read();
    for(int i(0);i<result.length();i++){
        result[i]=result[i]+3;
    }
    ofstream f("Cesar.txt");
    f<<result;
    f.close();
    ofstream f2("Documento.txt");
    f2<<result;
    f2.close();
    cout<<"Archivo cifrado con Cesar"<<endl;
}

void Menu::unSetCesar()
{
    system("cls");
    ifstream f("Cesar.txt");
    if(!f.is_open()){
        cout<<"Error al abrir el archivo"<<endl;
    }
    else{
        string line;
        char c;
        result="";
        while(!f.eof()){
            f.read((char*)&c,sizeof(c));
            if(f.eof())
                break;
            result+=c;
        }
        f.close();
        for(int i(0);i<result.length();i++){
            result[i]=result[i]-3;
        }
    }
    ofstream f2("Documento.txt");
    f2<<result;
    f2.close();
    cout<<"Archivo descifrado con Cesar"<<endl;

}

void Menu::setXOR()
{
    system("cls");
    read();
    for(int i(0);i<result.length();i++){
        unsigned a=result[i];
        unsigned r=a^claveXor;
        char c = static_cast<char>(r);
        result[i]=c;
    }
    ofstream f("XOR.txt");
    f<<result;
    f.close();
    ofstream f2("Documento.txt");
    f2<<result;
    f2.close();
    cout<<"Archivo cifrado con XOR"<<endl;
}

void Menu::unSetXOR()
{
    system("cls");
    ifstream f("XOR.txt");
    if(!f.is_open()){
        cout<<"Error al abrir el archivo"<<endl;
    }
    else{
        char c;
        result="";
        while(!f.eof()){
            f.read((char*)&c,sizeof(c));
            if(f.eof())
                break;
            result+=c;
        }
        f.close();
        for(int i(0);i<result.length();i++){
            unsigned a=result[i];
            unsigned r=a^claveXor;
            char c = static_cast<char>(r);
            result[i]=c;
        }
    }
    ofstream f2("Documento.txt");
    f2<<result;
    f2.close();
    cout<<"Archivo descifrado con XOR"<<endl;
}
