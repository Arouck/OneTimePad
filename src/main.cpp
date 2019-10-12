#include <iostream>
#include "Controller.hpp"

using namespace std;

int main()
{
    Controller c;
    int option;

    while(c.getOption() != 2) {
        c.printMainMenu();
        cin >> option;
        c.setOption(option);

        switch(c.getOption()){
            case 1:
                c.options();

            case 2:
                break;

            default:
                cout << "Opcao invalida!" << endl;
        }
    }

    return 0;
}