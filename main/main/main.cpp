
#include <map>
#include <string>
#include "PersonalFinanceManagementSystem.h"
#include "Windows.h"

map <int, string> MonthRussian = { {1, "Январь"},
{2, "Февраль"},
{3, "Март"},
{4, "Апрель"},
{5, "Май"},
{6, "Июнь"},
{7, "Июль"},
{8, "Август"},
{9, "Сентябрь"},
{10, "Октябрь"},
{11, "Ноябрь"},
{12, "Декабрь"},
};
map <int, string> MonthEnglish = { {1, "January"},
{2, "February"},
{3, "March"},
{4, "April"},
{5, "May"},
{6, "June"},
{7, "July"},
{8, "August"},
{9, "September"},
{10, "October"},
{11, "November"},
{12, "December"},
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    int sizeWallet=0;
    int sizeCard=0;
    int sizeExpense=0;
    PersonalFinanceManagementSystem PFMS={0,0,0};

    int k;
    cout << "Введите 1, чтобы ввести свoи данные\n"
        <<"Введите 2, чтобы загрузить данные из файла\n>> ";
    cin >> k;

    if(k==1)
    {
        int sizeWallet;
        int sizeCard;
        int sizeExpense;

        cout << "Введите количество кошельков: ";
        cin >> sizeWallet;
        cout << "Введите количество карт: ";
        cin >> sizeCard;
        cout << "Введите количество трат: ";
        cin >> sizeExpense;
        cout << endl;
        
        PFMS.setWalletsSize(sizeWallet).setCardsSize(sizeCard).setExpensesSize(sizeExpense);
        cin >> PFMS;
    }
    if(k==2)
    {
        OutOfFile(PFMS);
        cout << endl<<"Данные загружены!" << endl;
    }

    while (true)
    {
        int choise;
        cout << "\nВведите 1, чтобы вывести все данные\n"
            << "Введите 2, чтобы добавить кошелек/карту/платеж\n"
            << "Введите 3, чтобы удалить кошелек/карту\n"
            << "Введите 4, чтобы составить отчет\n"
            << "Введите 5, чтобы составить Топ-3 дорогих покупок\n"
            << "Введите 6, чтобы составить Топ-3 категорий\n"
            <<"Введиете 7, чтобы пополнить карту или кошелек\n"
            <<"Введиете 8, чтобы загрузить данные в файл\n"
            << "Введите 0, чтобы выйти" << "\n>> ";
        cin >> choise;

        if (choise == 1)
        {
            system("cls");
            cout<<PFMS;
        }

        if (choise == 2)
        {            
            system("cls");
            cout << "Введите 1, чтобы добавить кошелек\n"
                << "Введте 2, чтобы добавить карту\n"
                << "Введте 3, чтобы добавить платеж\n>> ";
            cin >> k;
            
            if (k == 1)
            {
                system("cls");
                Wallet wallet = {};
                cin >> wallet;
                PFMS.addWallet(wallet);
                sizeWallet++;
            }
            if(k==2)
            {
                system("cls");
                Card card = {};
                cin >> card;
                PFMS.addCard(card);
                sizeCard++;
            }
            if(k==3)
            {
                system("cls");
                Expense expense = {};

                cout << "Список доступных методов для оплаты: " << endl;
                PFMS.showPaymentMethods();
                cin >> expense;
                PFMS.addExpense(expense);
            }

        }

        if (choise == 3)
        {
            system("cls");
            string number;
            cout << "Введите 1, чтобы удалить кошелек\n"
                << "Введите 2, чтобы удалить карту\n>> ";
            cin >> k;

            if(k==1)
            {
                cout << endl;
                PFMS.printWallets();

                cout << "Введите номер кошелька: ";
                cin >> number;

                if(PFMS.DeleteWallet(number))
                {
                    cout << "\nКошелек удален!\n";
                }
                else
                {
                    cout << "\nОшибка удаления!\n";
                }
            }
            if(k==2)
            {
                cout << endl;
                PFMS.printCards();

                cout << "Введите номер карты: ";
                cin >> number;

                if (PFMS.DeleteCard(number))
                {
                    cout << "\nКарты удалена!\n";
                }
                else
                {
                    cout << "\nОшибка удаления!\n";
                }
            }
        }

        if (choise == 4)
        {
            system("cls");
            
            Expense* expenses=new Expense[sizeExpense];

            cout << "Введите 1, если хотите отчет по всем затратам" << endl
                << "Введите 2, если хотите отчет по категориям\n>> ";
            cin >> k;

            if(k==1)
            {
                cout << "Введите 1, если хотите составить отчет на определенный день\n"
                    << "Введите 2, если хотите составить отчет на определенную неделю\n"
                    << "Введите 3, если хотите составить отчет на определенный месяц\n"
                    << "Введите 4, если хотите составить отчет за все время\n>> ";

                cin >> k;

                if (k == 1)
                {
                    Date date = {};

                    cout << "Введите дату нужного дня(через пробел): ";
                    cin >> date;

                    int sizeReport = PFMS.allReportDay(expenses, date);

                    cout << endl;
                    for (int i = 0; i < sizeReport; i++)
                    {
                        cout << expenses[i] << endl;
                    }

                    cout << "\nНажмите 1, если хотите сохранить отчет в файл\n"
                        << "Нажмите на другую цифру, если не хотите сохранить данные в файл\n>> ";
                    cin >> k;

                    if (k == 1)
                    {
                        string s = ((date.getDay() < 10) ? "0" : "");
                        string path = "Report for " + s + to_string(date.getDay()) + "." + ((date.getMonth() < 10 ? "0" : "")) + to_string(date.getMonth()) + "." + to_string(date.getYear()) + ".txt";
                        string str = "Отчет по категориям за "+s + to_string(date.getDay()) + "." + ((date.getMonth() < 10 ? "0" : "")) + to_string(date.getMonth()) + "." + to_string(date.getYear());
                        PFMS.ToFile4(expenses, path, str, sizeReport);
                    }
                }
                if (k == 2)
                {
                    Date date = {};

                    cout << "Введите дату начала нужной недели(через пробел): ";
                    cin >> date;

                    int sizeReport = PFMS.allReportWeek(expenses, date);

                    cout << endl;
                    for (int i = 0; i < sizeReport; i++)
                    {
                        cout << expenses[i]<< endl;
                    }

                    cout << "\nНажмите 1, если хотите сохранить отчет в файл\n"
                        << "Нажмите на другую цифру, если не хотите сохранить данные в файл\n>> ";
                    cin >> k;

                    if (k == 1)
                    {
                        string s = ((date.getDay() < 10) ? "0" : "");
                        string path = "Report for Week " + s + to_string(date.getDay()) + "." + ((date.getMonth() < 10 ? "0" : "")) + to_string(date.getMonth()) + "." + to_string(date.getYear()) + ".txt";
                        string str = "Отчет по категориям за "+s+ to_string(date.getDay()) + "." + ((date.getMonth() < 10 ? "0" : "")) + to_string(date.getMonth()) + "." + to_string(date.getYear());
                        PFMS.ToFile4(expenses, path, str, sizeReport);
                    }
                }
                if (k == 3)
                {
                    int month, year;

                    cout << "Введите дату месяца(месяц год(через пробел)): ";
                    cin >> month >> year;

                    int sizeReport = PFMS.allReportMonth(expenses, month, year);

                    cout << endl;
                    for (int i = 0; i < sizeReport; i++)
                    {
                        cout << expenses[i]<< endl;
                    }

                    cout << "\nНажмите 1, если хотите сохранить отчет в файл\n"
                        << "Нажмите на другую цифру, если не хотите сохранить данные в файл\n>> ";
                    cin >> k;

                    if (k == 1)
                    {
                        string path = "Report for " + MonthEnglish[month] + " " + to_string(year) + ".txt";
                        string str = "Отчет по категориям за "+MonthRussian[month] + " " + to_string(year);
                        PFMS.ToFile4(expenses, path, str, sizeReport);
                    }
                }

                if (k == 4)
                {
                    int sizeReport = PFMS.allReport(expenses);

                    cout << endl;
                    for (int i = 0; i < sizeReport; i++)
                    {
                        cout << expenses[i] << endl;
                    }

                    cout << "\nНажмите 1, если хотите сохранить отчет в файл\n"
                        << "Нажмите на другую цифру, если не хотите сохранить данные в файл\n>> ";
                    cin >> k;

                    if (k == 1)
                    {
                        PFMS.ToFile4(expenses, "Report for all time.txt", "Отчет по категориям за все время", sizeReport);
                    }
                }
            }

            if (k == 2)
            {
                cout << "Введите 1, если хотите составить отчет на определенный день\n"
                    << "Введите 2, если хотите составить отчет на определенную неделю\n"
                    << "Введите 3, если хотите составить отчет на определенный месяц\n"
                    << "Введите 4, если хотите составить отчет за все время\n>> ";

                cin >> k;

                if (k == 1)
                {
                    Date date = {};

                    cout << "Введите дату нужного дня(через пробел): ";
                    cin >> date;

                    int sizeReport = PFMS.expenseReportDay(expenses, date);

                    cout << endl;
                    for (int i = 0; i < sizeReport; i++)
                    {
                        cout << expenses[i].getCategory() << ": " << expenses[i].getPrice() << endl;
                    }

                    cout << "\nНажмите 1, если хотите сохранить отчет в файл\n"
                        << "Нажмите на другую цифру, если не хотите сохранить данные в файл\n>> ";
                    cin >> k;

                    if (k == 1)
                    {
                        string s = ((date.getDay() < 10) ? "0" : "");
                        string path = "Report category for " + s + to_string(date.getDay()) + "." + ((date.getMonth() < 10 ? "0" : "")) + to_string(date.getMonth()) + "." + to_string(date.getYear()) + ".txt";
                        string str = "Отчет по категориям за "+ s + to_string(date.getDay()) + "." + ((date.getMonth() < 10 ? "0" : "")) + to_string(date.getMonth()) + "." + to_string(date.getYear());
                        PFMS.ToFile2(expenses, path, str, sizeReport);
                    }
                }
                if (k == 2)
                {
                    Date date = {};

                    cout << "Введите дату начала нужной недели(через пробел): ";
                    cin >> date;

                    int sizeReport = PFMS.expenseReportWeek(expenses, date);

                    cout << endl;
                    for (int i = 0; i < sizeReport; i++)
                    {
                        cout << expenses[i].getCategory() << ": " << expenses[i].getPrice() << endl;
                    }

                    cout << "\nНажмите 1, если хотите сохранить отчет в файл\n"
                        << "Нажмите на другую цифру, если не хотите сохранить данные в файл\n>> ";
                    cin >> k;

                    if (k == 1)
                    {
                        string s = ((date.getDay() < 10) ? "0" : "");
                        string path = "Report category for Week " + s + to_string(date.getDay()) + "." + ((date.getMonth() < 10 ? "0" : "")) + to_string(date.getMonth()) + "." + to_string(date.getYear()) + ".txt";
                        string str = "Отчет по категориям за неделю "+ s + to_string(date.getDay()) + "." + ((date.getMonth() < 10 ? "0" : "")) + to_string(date.getMonth()) + "." + to_string(date.getYear());
                        PFMS.ToFile2(expenses, path, str, sizeReport);
                    }
                }
                if (k == 3)
                {
                    int month, year;

                    cout << "Введите дату месяца(месяц год(через пробел)): ";
                    cin >> month >> year;

                    int sizeReport = PFMS.expenseReportMonth(expenses, month, year);

                    cout << endl;
                    for (int i = 0; i < sizeReport; i++)
                    {
                        cout << expenses[i].getCategory() << ": " << expenses[i].getPrice() << endl;
                    }

                    cout << "\nНажмите 1, если хотите сохранить отчет в файл\n"
                        << "Нажмите на другую цифру, если не хотите сохранить данные в файл\n>> ";
                    cin >> k;

                    if (k == 1)
                    {
                        string path = "Report category for " + MonthEnglish[month] + " " + to_string(year) + ".txt";
                        string str = "Отчет по категориям за " + MonthRussian[month] + " " + to_string(year);
                        PFMS.ToFile2(expenses, path, str, sizeReport);
                    }
                }

                if (k == 4)
                {
                    int sizeReport = PFMS.expenseReportAllTime(expenses);

                    cout << endl;
                    for (int i = 0; i < sizeReport; i++)
                    {
                        cout << expenses[i].getCategory() << ": " << expenses[i].getPrice() << endl;
                    }

                    cout << "\nНажмите 1, если хотите сохранить отчет в файл\n"
                        << "Нажмите на другую цифру, если не хотите сохранить данные в файл\n>> ";
                    cin >> k;

                    if (k == 1)
                    {
                        PFMS.ToFile2(expenses, "Report category for all time.txt", "Отчет по категориям за все время", sizeReport);
                    }
                }
            }
            delete[] expenses;
        }

        if(choise ==5)
        {
            system("cls");

            Expense* expenses = new Expense[3];

            cout<< "Введите 1, если хотите составить топ-3 дорогих покупок на определенную неделю\n"
                << "Введите 2, если хотите составить топ-3 дорогих покупок на определенный месяц\n"
                << "Введите 3, если хотите составить топ-3 дорогих покупок за все время\n>> ";
            cin >> k;

            if (k == 1)
            {
                Date date = {};
                int cnt;

                cout << "Введите дату начала нужной недели(через пробел): ";
                cin >> date;

                cnt=PFMS.ratingPriceWeek(expenses,date);


                cout << "Топ дорогих покупок: " << endl << endl;
                if (cnt == 0)
                {
                    cout << "Категорий не найдено!" << endl << endl;
                }
                for (int i = 0; i < cnt; i++)
                {
                    cout << expenses[i] << endl;
                }

                cout << "\nНажмите 1, если хотите сохранить данные в файл\n"
                    << "Нажмите на другую цифру, если не хотите сохранить данные в файл\n>> ";
                cin >> k;

                if (k == 1)
                {
                    string s = ((date.getDay() < 10) ? "0" : "");
                    string path = "Top expenses for Week "+ s + to_string(date.getDay()) + "." + ((date.getMonth() < 10 ? "0" : "")) + to_string(date.getMonth()) + "." + to_string(date.getYear()) + ".txt";
                    string str = "Топ трат за " +s + to_string(date.getDay()) + "."+ ((date.getMonth()< 10 ? "0" : "")) + to_string(date.getMonth()) + "." + to_string(date.getYear());
                    PFMS.ToFile4(expenses, path, str, cnt);
                }
            }
            if(k==2)
            {
                int month,year,cnt;

                cout << "Введите месяц и год(через пробел): ";
                cin >> month>>year;

                cnt=PFMS.ratingPriceMonth(expenses,month,year);

                cout << "Топ дорогих покупок: " << endl << endl;
                if (cnt == 0)
                {
                    cout << "Категорий не найдено!" << endl << endl;
                }
                for (int i = 0; i < cnt; i++)
                {
                    cout << expenses[i] << endl;
                }

                cout << "\nНажмите 1, если хотите сохранить данные в файл\n"
                    << "Нажмите на другую цифру, если не хотите сохранить данные в файл\n>> ";
                cin >> k;

                if (k == 1)
                {
                    string path = "Top expenses for " + MonthEnglish[month] +" " + to_string(year)+".txt";
                    string str = "Топ трат за "+MonthRussian[month] + " " + to_string(year);
                    PFMS.ToFile4(expenses, path, str, cnt);
                }
            }
            if (k == 3)
            {
                int cnt;

                cnt=PFMS.ratingPrice(expenses);

                cout << "Топ дорогих покупок: " << endl << endl;
                if (cnt == 0)
                {
                    cout << "Категорий не найдено!" << endl << endl;
                }
                for (int i = 0; i < cnt; i++)
                {
                    cout << expenses[i] << endl;
                }

                cout << "\nНажмите 1, если хотите сохранить данные в файл\n"
                    << "Нажмите на другую цифру, если не хотите сохранить данные в файл\n>> ";
                cin >> k;

                if(k==1)
                {
                    PFMS.ToFile4(expenses, "Top expenses for all time.txt", "Топ трат за все время", cnt);
                }
            }

            delete[] expenses;
        }

        if(choise ==6)
        {
            system("cls");

            Expense* expenses = new Expense[3];

            cout << "Введите 1, если хотите составить топ-3 категорий на определенную неделю\n"
                << "Введите 2, если хотите составить топ-3 категорий на определенный месяц\n"
                << "Введите 3, если хотите составить топ-3 категорий за все время\n>> ";
            cin >> k;

            if (k == 1)
            {
                Date date;
                int cnt;

                cout << "Введите дату начала нужной недели(через пробел): ";
                cin >> date;

                cnt = PFMS.ratingCategoryWeek(expenses,date);

                cout << "Топ Категорий: " << endl << endl;

                if (cnt == 0)
                {
                    cout << "Категорий не найдено!" << endl;
                }
                for (int i = 0; i < cnt; i++)
                {
                    cout << "[" << i + 1 << "] " << expenses[i].getCategory() << ": " << expenses[i].getPrice() << endl;
                }

                cout << "\nНажмите 1, если хотите сохранить отчет в файл\n"
                    << "Нажмите на другую цифру, если не хотите сохранить данные в файл\n>> ";
                cin >> k;

                if (k == 1)
                {
                    string s = ((date.getDay() < 10) ? "0" : "");
                    string path = "Top category for Week " + s + to_string(date.getDay()) + "." + ((date.getMonth() < 10 ? "0" : "")) + to_string(date.getMonth()) + "." + to_string(date.getYear()) + ".txt";
                    string str = "Топ категорий за неделю " + s + to_string(date.getDay()) + "." + ((date.getMonth() < 10 ? "0" : "")) + to_string(date.getMonth()) + "." + to_string(date.getYear());
                    PFMS.ToFile2(expenses, path, str, cnt);
                }
            }

            if (k == 2)
            {
                int cnt,month,year;

                cout << "Введите месяц и год(через пробел): ";
                cin >> month >> year;

                cnt = PFMS.ratingCategoryMonth(expenses,month,year);

                cout << "Топ Категорий: " << endl << endl;

                if (cnt == 0)
                {
                    cout << "Категорий не найдено!" << endl;
                }
                for (int i = 0; i < cnt; i++)
                {
                    cout <<"["<<i+1<<"] " << expenses[i].getCategory() << ": " << expenses[i].getPrice() << endl;
                }

                cout << "\nНажмите 1, если хотите сохранить отчет в файл\n"
                    << "Нажмите на другую цифру, если не хотите сохранить данные в файл\n>> ";
                cin >> k;

                if (k == 1)
                {
                    string path = "Top category for " + MonthEnglish[month] + " " + to_string(year) + ".txt";
                    string str = "Топ категорий за " + MonthRussian[month] + " " + to_string(year);
                    PFMS.ToFile2(expenses, path, str, cnt);
                }
            }

            if(k==3)
            {
                int cnt;

                cnt = PFMS.ratingCategory(expenses);

                cout << "Топ Категорий: " << endl << endl;

                if(cnt==0)
                {
                    cout << "Категорий не найдено!" << endl;
                }
                for (int i = 0; i < cnt; i++)
                {
                    cout << "[" << i + 1 << "] " << expenses[i].getCategory()<<": "<<expenses[i].getPrice() << endl;
                }

                cout << "\nНажмите 1, если хотите сохранить отчет в файл\n"
                    << "Нажмите на другую цифру, если не хотите сохранить данные в файл\n>> ";
                cin >> k;

                if (k == 1)
                {
                    PFMS.ToFile2(expenses, "Top category for all time.txt", "Топ категорий за все время", cnt);
                }
            }

            delete[] expenses;
        }
        
        if(choise==7)
        {
            system("cls");
            string number;
            int balance;
            cout << "Список доступных методов для пополнения: " << endl;
            PFMS.showPaymentMethods();

            cout << "Введите номер для пополнения: ";
            cin >> number;
            cout << "Введите сумму пополнения: ";
            cin >> balance;

            if(PFMS.ReplenishmentOfPaymentMethods(number, balance))
            {
                cout << "\nПополнение прошло успешно!\n";
            }
            else
            {
                cout << "\nОшибка пополнения!\n";
            }
        }

        if(choise ==8)
        {
            ofstream ofs;
            ofs.open("Saved data.txt");

            ofs << PFMS;

            ofs.close();

            cout << "\nДанные сохранены!\n";
        }

        if(choise ==0)
        {
            break;
        }
    }

}
