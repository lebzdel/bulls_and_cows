#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#include "Func_heads.h"
#include "PC_play.h"

using namespace std;

const int setSize = 10000;

int main()
{
    setlocale(LC_ALL, "ru");
    int move = 1;

    ofstream log("log.txt");

    bool badNum[setSize];

    int a, b, c, d;

    int bulls_count = 0, cows_count = 0; // Счетчик для игрока
    int bulls = 0, cows = 0; // Счетчик для компьютера
    int pc_test_int = 0;

    srand(time(0));


    memset(badNum, 0, sizeof(badNum));
    for (int i = 0; i < setSize; i++)
        badNum[i] = !IsValid(i);



    char* number_string;
    number_string = Begining_Number();
    log << "--------------------------------------" << endl;
    log << " Число, загаданное компьютером : " << number_string[0] << number_string[1] << number_string[2] << number_string[3] << endl;
    log << "--------------------------------------" << endl;

    char* us_number_string = new char[4];
    cout << "----------------------------------" << endl;
    cout << " Загадайте 4-значное число : ";
    cin >> us_number_string;
    cout << "----------------------------------" << endl << endl;

    log << "----------------------------------" << endl;
    log << " Число, загаданное игроком : " << us_number_string << endl;
    log << "----------------------------------" << endl << endl;


    log << "Ход " << move << "." << endl;

    cout << "Ваш ход." << endl;
    char* us_test_string;
    cout << "--------------------------------" << endl;
    us_test_string = Get_Number();

    log << "-------------------------" << endl;
    log << " Игрок делает ход : " << us_test_string << endl;

    bool flag = false;


    while (not End(number_string, us_test_string) && bulls != 4) {

        Sravn(number_string, us_test_string, bulls_count, cows_count);

        cout << " Быков : " << bulls_count << '\n';
        cout << " Коров : " << cows_count << '\n' << '\n';
        cout << "--------------------------------" << endl << endl;

        log << " Быков : " << bulls_count << endl;
        log << " Коровы : " << cows_count << endl;
        log << "-------------------------" << endl;

        bulls_count = 0;
        cows_count = 0;


        /// /////////////////////////////
        cout << "Ход компьютера." << endl;



        for (pc_test_int = 0; pc_test_int < setSize && badNum[pc_test_int]; pc_test_int++);
        if (pc_test_int >= setSize) {
            cout << endl << "Загаданное число невозможно!" << endl;
            flag = true;
            break;
        }

        log << "-----------------------------" << endl;
        log << " Компьютер делает ход : " << pc_test_int << endl;


        cout << "------------------" << endl;
        cout << " Мое число : " << pc_test_int << endl;
        cout << " Быков : ";
        cin >> bulls;
        cout << " Коров : ";
        cin >> cows;
        cout << "------------------" << endl << endl;

        log << " Быков : " << bulls << endl;
        log << " Коровы : " << cows << endl;

        int ch_bulls = 0, ch_cows = 0;


        char* pc_test_string = new char[4];
        pc_test_string[0] = '0' + pc_test_int / 1000;
        pc_test_string[1] = '0' + pc_test_int % 1000 / 100;
        pc_test_string[2] = '0' + pc_test_int % 100 / 10;
        pc_test_string[3] = '0' + pc_test_int % 10;

        Sravn(us_number_string, pc_test_string, ch_bulls, ch_cows);
        if (ch_bulls != bulls || ch_cows != cows) {
            log << endl << " Неверно : " << endl;
            log << "   Быков : " << ch_bulls << endl;
            log << "   Коров : " << ch_cows << endl;
        }
        log << "-----------------------------" << endl << endl;

        if (bulls == 4) { break; }

        for (int i = 0; i < setSize; i++)
            badNum[i] = badNum[i] || !Matches(i, pc_test_int, bulls, cows);
        /// //////////////////////////////

        move++;
        log << "Ход " << move << "." << endl;


        cout << "Ваш ход." << endl;
        cout << "--------------------------------" << endl;
        us_test_string = Get_Number();

        log << "-------------------------" << endl;
        log << " Игрок делает ход : " << us_test_string << endl;
    }

    if (not flag) {
        if (bulls == 4) {
            cout << '\n' << "Повезет в другой раз!" << '\n';
            cout << "Мое число : " << number_string[0] << number_string[1] << number_string[2] << number_string[3] << endl << endl;
            log << "Победа компьютера." << endl;
        }
        else {
            cout << '\n' << "Поздравляю с победой!" << '\n';
            log << "Победа игрока." << endl;
        }
    }
    else {
        cout << '\n' << "Техническое поражение!" << '\n';
        log << "Загадано невозможное число, техническое поражение." << endl;
    }

    system("pause");
    cout << "Для продолжения работы программы нажмите любую клавишу...";
    cin.get();

    log.close();
}
