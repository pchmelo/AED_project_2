#include <iostream>
#include "Menu.h"


using namespace std;

int Menu::Terminal() {

    int cap;

    cout << endl;
    cout << "\033[1;34m ______    __        __    ______    __   __   ________         _______           _______    ______    _____     __       ___\033[0m";
    cout << endl;
    cout << "\033[1;34m|  ____|  |  |      |  |  |  ____|  |  | |  | |___  ___|       |  ___  |         |  ___  |  |  ____|  |  ___ |  |  |     /   |\033[0m";
    cout << endl;
    cout << "\033[1;34m|  |___   |  |      |  |  |  | __   |  |_|  |    |  |    ___   |  | |  |   ___   |  |_|  |  |  |___   |  | | |  |  |    / _  |\033[0m";
    cout << endl;
    cout << "\033[1;34m|  ____|  |  |      |  |  |  ||_ |  |   _   |    |  |   |___|  |  | |  |  |___|  |  _____|  |  ____|  |  | | |  |  |   / /_| |\033[0m";
    cout << endl;
    cout << "\033[1;34m|  |      |  |___   |  |  |  |__||  |  | |  |    |  |          |  |_|  |         |  |       |  |___   |  |_/ /  |  |  / ___  |\033[0m";
    cout << endl;
    cout << "\033[1;34m|__|      |______|  |__|  |______|  |__| |__|    |__|          |_______|         |__|       |______|  |_____/   |__| /_/  |__|\033[0m";
    cout << endl;
    cout << endl;

    cout << "\033[1;34mPlease choose a number for the desired functionality or perish:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << " Check something" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " Check something 2" << endl;
    cout << "\033[1;36m[ 3 ]\033[0m" << " Check" << endl;
    cout << "\033[1;36m[ 4 ]\033[0m" << " Door" << endl;
    cout << "\033[1;36m[ 5 ]\033[0m" << " Number" << endl;
    cout << "\033[1;36m[ 6 ]\033[0m" << " 2" << endl;
    cout << "\033[1;36m[ 7 ]\033[0m" << " Please help" << endl;
    cout << "\033[1;33m[ 8 ]\033[0m" << " Details" << endl;
    cout << "\033[1;33m[ 9 ]\033[0m" << " Credits IDK" << endl;
    cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    int decision;
    cin >> decision;
    cout << endl;

    while (true) {

        switch (decision) {
            case 1:

                break;

            case 2:

                break;

            case 3:

                break;

            case 4:

                break;

            case 5:

                break;

            case 6:

                break;

            case 7:

                break;

            case 8:

                cout << "\033[1;36m[ 1 ]\033[0m" << " Travel the world naked" << endl;
                cout << "\033[1;36m[ 2 ]\033[0m" << " Jump over a puddle of water" << endl;
                cout << "\033[1;36m[ 3 ]\033[0m" << " Die" << endl;
                cout << "\033[1;36m[ 4 ]\033[0m" << " Fly" << endl;
                cout << "\033[1;36m[ 5 ]\033[0m" << " Recreate the classic roman empire" << endl;
                cout << "\033[1;33m[ 9 ]\033[0m" << " Go back" << endl;
                cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;

                cout << endl << "\033[1;34mDecision: \033[0m";
                cin >> decision;
                cout << endl;

                switch (decision) {
                    case 1:

                        break;

                    case 2:

                        break;

                    case 3:

                        break;

                    case 4:

                        break;

                    case 5:

                        break;

                    case 9:

                        break;

                    case 0:

                        cerr << "Program closed" << endl;
                        return 0;

                    default:

                        cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                        break;
                }
                break;

            case 9:

                cout << "\033[1;36m[ 1 ]\033[0m" << " Populate Ethiopia" << endl;
                cout << "\033[1;36m[ 2 ]\033[0m" << " Check under the egg" << endl;
                cout << "\033[1;33m[ 9 ]\033[0m" << " Go back" << endl;
                cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;

                cout << endl << "\033[1;34mDecision: \033[0m";
                cin >> decision;
                cout << endl;

                switch (decision) {
                    case 1:

                        break;

                    case 2:

                        break;

                    case 9:

                        break;

                    case 0:

                        cerr << "Program closed" << endl;
                        return 0;

                    default:

                        cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                        break;
                }
                break;

            case 0:

                cerr << "Program closed" << endl;
                return 0;

            default:

                cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                break;
        }

        cout << "\033[1;34mWish to do anything else?\033[0m\n";
        cout << "\033[1;36m[ 1 ]\033[0m" << " Check student schedule" << endl;
        cout << "\033[1;36m[ 2 ]\033[0m" << " Check class schedule" << endl;
        cout << "\033[1;36m[ 3 ]\033[0m" << " Check students of a given class, UC or year" << endl;
        cout << "\033[1;36m[ 4 ]\033[0m" << " Check number of students in a given minimum number of UCs" << endl;
        cout << "\033[1;36m[ 5 ]\033[0m" << " Check occupation of a given class, UC or year" << endl;
        cout << "\033[1;36m[ 6 ]\033[0m" << " Check the UCs with greatest number of students" << endl;
        cout << "\033[1;36m[ 7 ]\033[0m" << " Check the classes with the greatest number of students" << endl;
        cout << "\033[1;33m[ 8 ]\033[0m" << " Make changes" << endl;
        cout << "\033[1;33m[ 9 ]\033[0m" << " Technical options" << endl;
        cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
        cout << endl;

        cout << "\033[1;34mDecision: \033[0m";
        cin >> decision;
        cout << endl;
    }
}