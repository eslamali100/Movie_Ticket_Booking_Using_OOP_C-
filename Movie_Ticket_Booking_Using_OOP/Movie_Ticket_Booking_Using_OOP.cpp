#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

string takePasswdFromUser();
void current_date_and_time();
void Loading_interface();
void welcome_admin_interface();
void system_interface();
void employee_options(int choice, bool& r);
void admin_options(int choice, bool& r);
void system_preform(int choice, bool& r);

class SystemFile
{
private:
    int TicketID();
    int get_number_of_movie(int Case);
    int get_number_of_ticket(int Case);
public:
    void insert_ticket(string movie_name, int number_of_individuals, string show_time, string chair_number, double price);
    void insert_movie(string movie_name, string show_time1, string show_time2, string show_time3, string show_time4);
    void display_tickets();
    void display_last_ticket();
    void display_last_information_ticket();
    void display_movie();
    void display_movie_name_only();
    void search_for_movie_and_show_time(int num_movie, int num_show_time, string& movie_name, string& show_time);
    void delete_movie(int pos);
    void Delete_ticket(string remove_ID);
    void delete_last_ticket();
    void reset_data_in_ticket_file_system();
    bool check_password();
    void modify_password();
};

class Hall {
private:
    int chair[239] = { 0 };
    double standard_ticket_price, premium_ticket_price;
public:
    Hall() {
        standard_ticket_price = 155.00;
        premium_ticket_price = 170.00;
    }
    void display() {
        int x = 0, y = 0;
        bool r = true;
        current_date_and_time();
        SetConsoleTextAttribute(h, 9);
        cout << "\n\t\t\t   ______________________________________________________________________________________________________________";
        cout << "\n\n\t\t\t\t\t\t\t\t\t SCREEN THIS WAY\n\n\n";
        cout << "\n\t\t\t\t";
        for (int i = 1; i < 239; i++) {
            if (i < 10) {
                if (chair[i] == 0) {
                    SetConsoleTextAttribute(h, 148);
                    cout << "[00" << i << "] ";
                    SetConsoleTextAttribute(h, 9);
                }
                else {
                    SetConsoleTextAttribute(h, 132);
                    cout << "[ X ] ";
                    SetConsoleTextAttribute(h, 9);
                }
            }
            else if (i < 100) {
                if (chair[i] == 0) {
                    SetConsoleTextAttribute(h, 148);
                    cout << "[0" << i << "] ";
                    SetConsoleTextAttribute(h, 9);
                }
                else {
                    SetConsoleTextAttribute(h, 132);
                    cout << "[ X ] ";
                    SetConsoleTextAttribute(h, 9);
                }
            }
            else {
                if (chair[i] == 0) {
                    if (i < 141)
                    {
                        SetConsoleTextAttribute(h, 148);
                        cout << "[" << i << "] ";
                        SetConsoleTextAttribute(h, 9);
                    }
                    else {
                        SetConsoleTextAttribute(h, 164);
                        cout << "[" << i << "] ";
                        SetConsoleTextAttribute(h, 9);
                    }
                }
                else {
                    SetConsoleTextAttribute(h, 132);
                    cout << "[ X ] ";
                    SetConsoleTextAttribute(h, 9);
                }
            }
            x++;
            if (x == 4 && r) {
                cout << "\t";
                x = 0;
                y++;
                r = false;
            }
            else if (x == 6 && !r) {
                cout << "\t   ";
                x = 0;
                y++;
                r = true;
            }if (y == 3) {
                y = 0;
                r = true;
                cout << "\n\n\t\t\t\t";
            }
        }
        cout << "\n\t\t\t   ______________________________________________________________________________________________________________\n";
        SetConsoleTextAttribute(h, 132);
        cout << "\t\t\t\t\t\t\tUnavailable";
        SetConsoleTextAttribute(h, 9);
        cout << "\t     ";
        SetConsoleTextAttribute(h, 164);
        cout << "Premium";
        SetConsoleTextAttribute(h, 9);
        cout << "\t\t";
        SetConsoleTextAttribute(h, 148);
        cout << "Standard\n";
        SetConsoleTextAttribute(h, 9);
    }

    void Interface(double& total_ticket_price, string& number_of_chair, int& number_of_individuals) {
        int num, c;
        bool r = false;
        total_ticket_price = 0;
        number_of_individuals = 0;
        string a = "y";
        while (a == "y" || a == "Y" || a == "yes" || a == "Yes" || a == "YES" || a == "yES" || a == "yEs" || a == "YeS") {
            system("cls");
            display();
            cout << endl << "Enter number of chairs:   ";
            cin >> num;
            number_of_individuals += num;
            for (int i = 0; i < num; i++) {
                system("cls");
                display();
                cout << i + 1 << "- Choose chair:   ";
                SetConsoleTextAttribute(h, 15);
                cin >> c;
                SetConsoleTextAttribute(h, 1);
                while (c > 238) {
                    system("cls");
                    display();
                    cout << "-Error! No Chair with This Number :(" << endl;
                    cout << i + 1 << "- Choose chair:   ";
                    SetConsoleTextAttribute(h, 15);
                    cin >> c;
                    SetConsoleTextAttribute(h, 1);
                }
                while (chair[c] == 1) {
                    system("cls");
                    display();
                    cout << "-Error! Chair already taken :(" << endl;
                    cout << i + 1 << "- Choose chair:   ";
                    SetConsoleTextAttribute(h, 15);
                    cin >> c;
                    SetConsoleTextAttribute(h, 9);
                }
                chair[c] = 1;
                if (c < 141)
                {
                    total_ticket_price += standard_ticket_price;
                }
                else {
                    total_ticket_price += premium_ticket_price;
                }
                if (i == num - 1)
                {
                    number_of_chair += to_string(c);
                }
                else if (i == 0 && r) {
                    number_of_chair += "," + (to_string(c)) + ",";
                    r = false;
                }
                else {
                    number_of_chair += (to_string(c) + ",");
                }
                system("cls");
            }
            display();
            cout << "Do you want to Choose more chairs :) ? (y/n)" << endl;
            do {
                SetConsoleTextAttribute(h, 15);
                cin >> a;
                SetConsoleTextAttribute(h, 1);
                r = true;
            } while (a != "y" && a != "Y" && a != "yes" && a != "Yes" && a != "YES" && a != "yES" && a != "yEs" && a != "YeS" && a != "n" && a != "N" && a != "no" && a != "No" && a != "NO" && a != "nO");
        }
    }
};

Hall H[100][4];

class Employee
{
protected:
    SystemFile f;
public:
    void booking_ticket() {
        system("cls");
        system_interface();
        f.display_movie();
        int num_movie, num_show_time, number_of_individuals;
        double price;
        string movie_name, show_time, chair_number;
        cout << "\n\t\t\t-Enter number of Movie do you want: ";
        SetConsoleTextAttribute(h, 15);
        cin >> num_movie;
        SetConsoleTextAttribute(h, 9);
        cout << "\n\t\t\t-Enter number of Show Time do you want: ";
        SetConsoleTextAttribute(h, 15);
        cin >> num_show_time;
        SetConsoleTextAttribute(h, 9);
        system("cls");
        f.search_for_movie_and_show_time(num_movie + 1, num_show_time, movie_name, show_time);
        H[num_movie - 1][num_show_time - 1].Interface(price, chair_number, number_of_individuals);
        f.insert_ticket(movie_name, number_of_individuals, show_time, chair_number, price);
        bool r = false;
        string a;
        do {
            system("cls");
            system_interface();
            f.display_last_information_ticket();
            cout << "Do you want to complete the reservation? (y/n)" << endl;
            if (r)
            {
                cout << "Error! Enter correct choice :( ." << endl;
            }
            cout << "---> Enter Answer: ";
            SetConsoleTextAttribute(h, 15);
            cin >> a;
            SetConsoleTextAttribute(h, 9);
            r = true;
        } while (a != "y" && a != "Y" && a != "yes" && a != "Yes" && a != "YES" && a != "yES" && a != "yEs" && a != "YeS" && a != "n" && a != "N" && a != "no" && a != "No" && a != "NO" && a != "nO");
        if (a == "y" || a == "Y" || a == "yes" || a == "Yes" || a == "YES" || a == "yES" || a == "yEs" || a == "YeS")
        {
            system("cls");
            system_interface();
            f.display_last_ticket();
            system("pause");
        }
        else
        {
            f.delete_last_ticket();
        }
    }
    void display_movies_currently_showing_in_cinema() {
        int choice;
        bool r1 = false;
        do {
            system("cls");
            system_interface();
            f.display_movie_name_only();
            cout << "\n\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
            cout << "\t\t\t&  [1] Display Show time.    &" << endl;
            cout << "\t\t\t&  [2] Back.                 &" << endl;
            cout << "\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
            if (r1) {
                cout << "\t\t\tError! Enter correct choice :( ." << endl;
            }
            cout << "\t\t\t----> Enter Your Choice : ";
            SetConsoleTextAttribute(h, 15);
            cin >> choice;
            SetConsoleTextAttribute(h, 9);
            if (choice == 1) {
                int ch;
                bool r2 = false;
                r1 = false;
                do {
                    system("cls");
                    system_interface();
                    f.display_movie();
                    cout << "\n\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
                    cout << "\t\t\t&   * to Back enter [1].    &" << endl;
                    cout << "\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
                    if (r2)
                    {
                        cout << "\t\t\tError! Enter correct choice :( ." << endl;
                    }
                    cout << "\t\t\t----> Enter Your Choice : ";
                    SetConsoleTextAttribute(h, 15);
                    cin >> ch;
                    SetConsoleTextAttribute(h, 9);
                    r2 = true;
                } while (ch != 1);
                continue;
            }
            else if (choice == 2) {
                return;
            }
            r1 = true;
        } while (choice != 2);
    }
    void view_ticket_booked() {
        int ch;
        bool r2 = false;
        do {
            system("cls");
            system_interface();
            f.display_tickets();
            cout << "\n\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
            cout << "\t\t\t&   * to Back enter [1].    &" << endl;
            cout << "\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
            if (r2)
            {
                cout << "\t\t\tError! Enter correct choice :( ." << endl;
            }
            cout << "\t\t\t----> Enter Your Choice : ";
            SetConsoleTextAttribute(h, 15);
            cin >> ch;
            SetConsoleTextAttribute(h, 9);
            r2 = true;
        } while (ch != 1);
    }
    void display_last_ticket() {
        int ch;
        bool r2 = false;
        do {
            system("cls");
            system_interface();
            f.display_last_ticket();
            cout << "\n\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
            cout << "\t\t\t&   * to Back enter [1].    &" << endl;
            cout << "\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
            if (r2)
            {
                cout << "\t\t\tError! Enter correct choice :( ." << endl;
            }
            cout << "\t\t\t----> Enter Your Choice : ";
            SetConsoleTextAttribute(h, 15);
            cin >> ch;
            SetConsoleTextAttribute(h, 9);
            r2 = true;
        } while (ch != 1);
    }
};

class Admin : public Employee
{
public:
    void display_and_edit_movie()
    {
        int choice;
        bool r = false;
        do {
            system("cls");
            system_interface();
            f.display_movie();
            cout << "\n\t\t\t\t\t\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
            cout << "\t\t\t\t\t\t\t\t\t&  [1] Add new movie.          &" << endl;
            cout << "\t\t\t\t\t\t\t\t\t&  [2] Delete movie.           &" << endl;
            cout << "\t\t\t\t\t\t\t\t\t&  [3] Back                    &" << endl;
            cout << "\t\t\t\t\t\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
            if (r) {
                cout << "\t\t\t\t\t\t\t\t\tError! Enter correct choice :( ." << endl;
            }
            cout << "\t\t\t\t\t\t\t\t\t----> Enter Your Choice: ";
            cin >> choice;
            if (choice == 1) {
                r = false;
                system("cls");
                system_interface();
                string movie_name, show_time1, show_time2, show_time3, show_time4;
                cout << "\t\t\t\t\t #@#@#@#@ Enter a New Movie :) @#@#@#@#";
                cout << "\t\t\t-Enter movie name : ";
                cin >> movie_name;
                cout << "\t\t\t-Enter first show time : ";
                cin >> show_time1;
                cout << "\t\t\t-Enter second show time : ";
                cin >> show_time2;
                cout << "\t\t\t-Enter third show time : ";
                cin >> show_time3;
                cout << "\t\t\t-Enter fourth show time :";
                cin >> show_time4;
                f.insert_movie(movie_name, show_time1, show_time2, show_time3, show_time4);
                continue;
            }
            else if (choice == 2) {
                r = false;
                system("cls");
                system_interface();
                f.display_movie();
                int pos;
                cout << "\n\t\t\t-Enter number of film do you want delete :";
                cin >> pos;
                f.delete_movie(pos);
                continue;
            }
            r = true;
        } while (choice != 3);
    }
    void display_and_edit_ticket()
    {
        int x;
        bool r = false;
        string movie_name; int number_of_individuals; string show_time; string chair_number; double price;
        do {
            system("cls");
            system_interface();
            f.display_tickets();
            cout << "\t\t\t**************************\n";
            cout << "\t\t\t* [1] Ticket booking.    *\n";
            cout << "\t\t\t* [2] Delete ticket.     *\n";
            cout << "\t\t\t* [3] Back               *\n";
            cout << "\t\t\t**************************\n";
            if (r) {
                cout << "\t\t\tError! Enter correct choice :( ." << endl;
            }
            cout << "\t\t\t----> Enter Your Choice: ";
            cin >> x;
            if (x == 1) {
                booking_ticket();
            }
            else if (x == 2) {
                string t;
                system("cls");
                system_interface();
                f.display_tickets();
                cout << "\t Enter id to remove a ticket : ";
                cin >> t;
                f.Delete_ticket(t);
            }
            r = true;
        } while (x != 3);
    }
    void display_last_ticket() {
        int ch;
        bool r2 = false;
        do {
            system("cls");
            system_interface();
            f.display_last_ticket();
            cout << "\n\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
            cout << "\t\t\t&   [1] Delete last Ticket. &" << endl;
            cout << "\t\t\t&   [2] Back.               &" << endl;
            cout << "\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
            if (r2)
            {
                cout << "\t\t\tError! Enter correct choice :( ." << endl;
            }
            cout << "\t\t\t----> Enter Your Choice : ";
            SetConsoleTextAttribute(h, 15);
            cin >> ch;
            SetConsoleTextAttribute(h, 9);
            if (ch == 1)
            {
                r2 = false;
                f.delete_last_ticket();
                continue;
            }
            r2 = true;
        } while (ch != 2);
    }
    void rest_and_delete_all_ticket_file()
    {
        system("cls");
        system_interface();
        if (f.check_password())
        {
            f.reset_data_in_ticket_file_system();
            cout << "\n\t\t\t\t#@#@#@#@  All Ticket System File Data Reset successfully :)  @#@#@#@#" << endl;
            system("pause");
        }
        else {
            cout << "\n\t\t\t\t#@#@#@#@  Error! No change in Ticket System File Data :(  @#@#@#@#" << endl;
            system("pause");
        }
    }
    void modify_password()
    {
        system("cls");
        system_interface();
        f.modify_password();
        system("pause");
    }
};

int main() {
    Loading_interface();
    int choice;
    bool r = false;
    do {
        system("cls");
        system_interface();
        cout << "\n\n\t\t\t\t\t\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
        cout << "\t\t\t\t\t\t\t\t\t&  [1] Enter as \"Employee\".     &" << endl;
        cout << "\t\t\t\t\t\t\t\t\t&  [2] Enter as \"Admin\".        &" << endl;
        cout << "\t\t\t\t\t\t\t\t\t&  [3] Exit.                    &" << endl;
        cout << "\t\t\t\t\t\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
        if (r) {
            cout << "\t\t\t\t\t\t\t\t\tError! Enter correct choice :( ." << endl;
        }
        cout << "\t\t\t\t\t\t\t\t\t----> Enter Your Choice : ";
        SetConsoleTextAttribute(h, 15);
        cin >> choice;
        SetConsoleTextAttribute(h, 9);
        r = true;
        system_preform(choice, r);
    } while (choice != 3);
}

void system_preform(int choice, bool& r)
{
    SystemFile f;
    if (choice == 1)
    {
        int ch;
        r = false;
        bool R = false;
        do {
            system("cls");
            system_interface();
            cout << "\n\n\t\t\t\t\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
            cout << "\t\t\t\t\t\t\t\t&  [1] Ticket booking.                              &" << endl;
            cout << "\t\t\t\t\t\t\t\t&  [2] View the names of the movies available.      &" << endl;
            cout << "\t\t\t\t\t\t\t\t&  [3] View reserved tickets.                       &" << endl;
            cout << "\t\t\t\t\t\t\t\t&  [4] View last ticket.                            &" << endl;
            cout << "\t\t\t\t\t\t\t\t&  [5] Back.                                        &" << endl;
            cout << "\t\t\t\t\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
            if (R) {
                cout << "\t\t\t\t\t\t\t\tError! Enter correct choice :( ." << endl;
            }
            cout << "\t\t\t\t\t\t\t\t----> Enter Your Choice : ";
            SetConsoleTextAttribute(h, 15);
            cin >> ch;
            SetConsoleTextAttribute(h, 9);
            R = true;
            employee_options(ch, R);
        } while (ch != 5);
    }
    else if (choice == 2) {
        system("cls");
        system_interface();
        r = false;
        if (f.check_password())
        {
            system("cls");
            welcome_admin_interface();
            int ch;
            bool R = false;
            do {
                system("cls");
                system_interface();
                cout << "\n\n\t\t\t\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
                cout << "\t\t\t\t\t\t\t&  [1] Ticket booking.                                          &" << endl;
                cout << "\t\t\t\t\t\t\t&  [2] View and edit the names of the movies available.         &" << endl;
                cout << "\t\t\t\t\t\t\t&  [3] View reserved tickets and Edit on them.                  &" << endl;
                cout << "\t\t\t\t\t\t\t&  [4] View last ticket and delete it if you want.              &" << endl;
                cout << "\t\t\t\t\t\t\t&  [5] Reset Ticket system file.                                &" << endl;
                cout << "\t\t\t\t\t\t\t&  [6] Change Password.                                         &" << endl;
                cout << "\t\t\t\t\t\t\t&  [7] Back.                                                    &" << endl;
                cout << "\t\t\t\t\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
                if (R) {
                    cout << "\t\t\t\t\t\t\t\tError! Enter correct choice :( ." << endl;
                }
                cout << "\t\t\t\t\t\t\t----> Enter Your Choice : ";
                SetConsoleTextAttribute(h, 15);
                cin >> ch;
                SetConsoleTextAttribute(h, 9);
                R = true;
                admin_options(ch, R);
            } while (ch != 7);
        }
    }
}

void employee_options(int choice, bool& r)
{
    Employee e;
    if (choice == 1) {
        r = false;
        e.booking_ticket();
    }
    else if (choice == 2) {
        r = false;
        e.display_movies_currently_showing_in_cinema();
    }
    else if (choice == 3) {
        r = false;
        e.view_ticket_booked();
    }
    else if (choice == 4) {
        r = false;
        e.display_last_ticket();
    }
}

void admin_options(int choice, bool& r) {
    Admin a;
    if (choice == 1) {
        r = false;
        a.booking_ticket();
    }
    else if (choice == 2) {
        r = false;
        a.display_and_edit_movie();
    }
    else if (choice == 3) {
        r = false;
        a.display_and_edit_ticket();
    }
    else if (choice == 4) {
        r = false;
        a.display_last_ticket();
    }
    else if (choice == 5) {
        r = false;
        a.rest_and_delete_all_ticket_file();
    }
    else if (choice == 6) {
        r = false;
        a.modify_password();
    }
}

string takePasswdFromUser() {
    char sp = '*';
    string passwd = "";
    char ch_ipt;
    while (true) {
        ch_ipt = getch();
        if (ch_ipt == 13) {
            cout << endl;
            return passwd;
        }
        else if (ch_ipt == 8 && passwd.length() != 0) {
            passwd.pop_back();
            cout << "\b \b";
            continue;
        }
        else if (ch_ipt == 8 && passwd.length() == 0) {
            continue;
        }
        passwd.push_back(ch_ipt);
        SetConsoleTextAttribute(h, 15);
        cout << sp;
        SetConsoleTextAttribute(h, 9);
    }
}

void current_date_and_time() {
    time_t now = time(nullptr);
    string  date_and_time = ctime(&now);
    cout << "\t\t\t----> Current Date & Time : ";
    SetConsoleTextAttribute(h, 15);
    cout << date_and_time << endl;
    SetConsoleTextAttribute(h, 9);
}

void Loading_interface()
{
    SetConsoleTextAttribute(h, 15);
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t                       :-=+***++=-:" << endl;
    cout << "\t\t\t\t\t\t\t                   -++++=+=======++=+++=:" << endl;
    cout << "\t\t\t\t\t\t\t               .+*+==*#@@@@@@%+==+#@@#+==+*=" << endl;
    cout << "\t\t\t\t\t\t\t             .**::#@@@@@@@@#.       *@@@@#--%=" << endl;
    cout << "\t\t\t\t\t\t\t            =#-+@@@%@@@@@@@          %@@@@@%-=%=" << endl;
    cout << "\t\t\t\t\t\t\t          :#==@*:    .-*@@@          #@@@@@@@#--#." << endl;
    cout << "\t\t\t\t\t\t\t         =@:*@+         *@@*        =@@@@@%@@@@*:%." << endl;
    cout << "\t\t\t\t\t\t\t        -%.+@@.         -@@@@*=--=+%@@#-     -*+.:-:::::" << endl;
    cout << "\t\t\t\t\t\t\t        @.*@@@*         #@@**@@@@@@@%+  .:--=-=#*##*+%*=+%*%" << endl;
    cout << "\t\t\t\t\t\t\t       =*-@@@@@%-.   .=%@@#  +@%..::==*==#*%@@@@@##@@@@:@@@+" << endl;
    cout << "\t\t\t\t\t\t\t       *-*@@@@@@@@@%@@@@#%%+===-==+#*%%@@@=:-@@@@  #@@@:@@@+" << endl;
    cout << "\t\t\t\t\t\t\t       %.#@@@@%++++#@#+-:-==+#*%%#@@*  #@%   @@@ # -@@@:@@@*" << endl;
    cout << "\t\t\t\t\t\t\t       %:#@@@:     .-=-#=#%@@@    @@*  =@+   @@@ #  %@@=*@@@." << endl;
    cout << "\t\t\t\t\t\t\t       +--*+::--:+=#*#%@@@  @@  @#@@*   @    @@*    .@@@:@@@%" << endl;
    cout << "\t\t\t\t\t\t\t    .:-==--#+#*%%@#@@* .%@  @@    @@*        @@*@@%%%%%%*:=*+=" << endl;
    cout << "\t\t\t\t\t\t\t:=+: **%%@@@#*#@@  @@*  .@  @@  @@@@*-@-+%@@@###++*==*=+-:" << endl;
    cout << "\t\t\t\t\t\t\t #%%#-@@@@  *@%@@  @@* =    @@    %@%@@*###=+--=-=." << endl;
    cout << "\t\t\t\t\t\t\t :@@@**@@*  @@@@@  @@* @    @@+#@##*#==     =%*:#+" << endl;
    cout << "\t\t\t\t\t\t\t  #@@@:@@=  @@@@@  @@* @@##@@@%=*---:==---+@@:-%-" << endl;
    cout << "\t\t\t\t\t\t\t  =@@@-@@*  @@+@@  @@%#@@##+== :=*#@@@@@@@%=-#+." << endl;
    cout << "\t\t\t\t\t\t\t  +@@@-@@@%=._@@@@@*#+*+=    .=%@@@@@@@*==+*=" << endl;
    cout << "\t\t\t\t\t\t\t  *@@@:@@@@%%*#-*++=-:@@=#@@@@@@@%#*=:-*%+:" << endl;
    cout << "\t\t\t\t\t\t\t                -*-=-::.=+++++++==+++++++-" << endl;
    cout << "\t\t\t\t\t\t\t                    ::.=++++++==+++++-" << endl;
    cout << "\t\t\t\t\t\t\t                       :-=+***++-:" << endl;
    SetConsoleTextAttribute(h, 14);
    cout << "\n\n\n\n\t\t\t\t\t\t\t\tLoading";
    char x = 219;
    for (int i = 0; i < 35; ++i) {
        Sleep(100);
        SetConsoleTextAttribute(h, i);
        cout << x;
    }
    SetConsoleTextAttribute(h, 9);
    system("cls");
}

void welcome_admin_interface()
{
    current_date_and_time();
    cout << "\t\t\t\t\t                                    :=+##%%%%%%%%%%%#*=:" << endl;
    cout << "\t\t\t\t\t                                 -*@@@@@@@@@@@@@@@@@@@@#:" << endl;
    cout << "\t\t\t\t\t                               -%@@@@@@@@@@@@@@@@@@@%@@%#+-" << endl;
    cout << "\t\t\t\t\t                             .#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=" << endl;
    cout << "\t\t\t\t\t                             %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#" << endl;
    cout << "\t\t\t\t\t                            %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#" << endl;
    cout << "\t\t\t\t\t                           +@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-" << endl;
    cout << "\t\t\t\t\t                          .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*" << endl;
    cout << "\t\t\t\t\t                          +@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%" << endl;
    cout << "\t\t\t\t\t                          #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "\t\t\t\t\t                          %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "\t\t\t\t\t                          #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "\t\t\t\t\t                          -@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#" << endl;
    cout << "\t\t\t\t\t                           %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=" << endl;
    cout << "\t\t\t\t\t                          :%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*" << endl;
    cout << "\t\t\t\t\t                          *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "\t\t\t\t\t                          +@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "\t\t\t\t\t                          .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#" << endl;
    cout << "\t\t\t\t\t                           +@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:" << endl;
    cout << "\t\t\t\t\t                            *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%." << endl;
    cout << "\t\t\t\t\t                             :+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+" << endl;
    cout << "\t\t\t\t\t                               +@@@@@@@@@@@@@@@@@@@@@@@@@@@-" << endl;
    cout << "\t\t\t\t\t                                %@@@@@@@@@@@@@@@@@@@@@@@@@=" << endl;
    cout << "\t\t\t\t\t                                 %@@@@@@@@@@@@@@@@@@@@@@@+" << endl;
    cout << "\t\t\t\t\t                                  #@@@@@@@@@@@@@@@@@@@@@=" << endl;
    cout << "\t\t\t\t\t                                   =@@@@@@@@@@@@@@@@@@@:" << endl;
    cout << "\t\t\t\t\t                                   .@@@@@@@@@@@@@@@@@@-" << endl;
    cout << "\t\t\t\t\t                                   #@@@@@@@@@@@@@@@@@@*" << endl;
    cout << "\t\t\t\t\t                              .:-*@@@@@@@@@@@@@@@@@@@@@%+=:." << endl;
    cout << "\t\t\t\t\t                        .-+*%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%#*=:" << endl;
    cout << "\t\t\t\t\t                    -+#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%*=." << endl;
    cout << "\t\t\t\t\t                :+%@@@@@@@@@@@@@@@@@@@@@@@@%++#@@@@@@@@@@@@@@@@@@@@@@@@@*-" << endl;
    cout << "\t\t\t\t\t             .=%@@@@@@@@@@@@@@@@@@@@@@@@@=.    .=%@@@@@@@@@@@@@@@@@@@@@@@@@*:" << endl;
    cout << "\t\t\t\t\t           .+@@@@@@@@@@@@@@@@@@@@@@@@@@%         .%@@@@@@@@@@@@@@@@@@@@@@@@@@#:" << endl;
    cout << "\t\t\t\t\t          =@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#=.  .-*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*" << endl;
    cout << "\t\t\t\t\t         +@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=  :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#" << endl;
    cout << "\t\t\t\t\t         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=    :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-" << endl;
    cout << "\t\t\t\t\t        .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*      +@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=" << endl;
    cout << "\t\t\t\t\t        .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.       %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=" << endl;
    cout << "\t\t\t\t\t        .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*        =@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=" << endl;
    cout << "\t\t\t\t\t         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.        .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:" << endl;
    cout << "\t\t\t\t\t         -@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%          %@@@@@@@@@@@@@@@@@@@@@@@@@@@#=" << endl;
    cout << "\t\t\t\t\t           -*@@@@@@@@@@@@@@@@@@@@@@@@@@#          *@@@@@@@@@@@@@@@@@@@@@@%*+:" << endl;
    cout << "\t\t\t\t\t              .-=*#@@@@@@@@@@@@@@@@@@@@@+=-------=%@@@@@@@@@@@@@@@%#*=-." << endl;
    cout << "\t\t\t\t\t                     .::-=++**##%%%%%%%%%%%%%%%%%%%%%##**++=--:." << endl;
    cout << "\n\n\t\t        -##= =##- +##         =@@.                                             =###:       -@@:              --  %" << endl;
    Sleep(400);
    cout << "\t\t         @@% @@@%.@@* -*#%#*: =@@. -*#%#*: =#%%#=  *#=*%#=+#%*. .+#%#*-       :@@%@@.  :*%##@@: ##=#%#=*##+  ##- *#=*##+" << endl;
    Sleep(400);
    cout << "\t\t         +@@*@*@@#@@:-@@*  @@.=@@.-@@-    *@%  %@* %@%  @@  @@+ @@#  @@-      %@# @@#  @@*  @@:.@@  %@@  @@: @@+ %@%  @@:" << endl;
    Sleep(400);
    cout << "\t\t          @@@@.=@@@# -@@=-+##.=@@.-@@-    *@%  %@* %@#  @@  @@+ @@#--##-     *@@@@@@@= @@*  @@:.@@  #@%  @@: @@+ %@%  @@:" << endl;
    Sleep(400);
    cout << "\t\t          =**+  ***:  :*###*: -**  -*###+. =*##*=  +*+  **  **- .+###*=     :**-   *** :*##=**. **  +**  **. **- **=  **:\n\n" << endl;
    Sleep(500);
}

void system_interface()
{
    current_date_and_time();
    SetConsoleTextAttribute(h, 12);
    cout << "\t                        .:::." << endl;
    cout << "\t                    .+%@@@@@@@*-" << endl;
    cout << "\t     :+#@@@@%*-    *@@+:    .-#@%:" << endl;
    cout << "\t    *@@+:..:=#@%: #@#          -@@:" << endl;
    cout << "\t   #@*        -@@-@@.           *@*" << endl;
    cout << "\t  .@@.         %@+@@.           *@*" << endl;
    cout << "\t   @@=        :@@:#@#          -@@:" << endl;
    cout << "\t   .%@*:    .+@@=  *@%+:    .-#@%:" << endl;
    cout << "\t    :@@@@@@@@@@@%%%%@@@@@@@@@@@-     .=#%=\t\t\t\t\t                         :+####=. ## =:      *#: ####### ::          =      +." << endl;
    cout << "\t   *@@@@@@@@@@@@@@@@@@@@@@@@@@@#  .=#@@@@@.\t\t\t\t\t                       :#@%+=+*%* @@ #@#:    #@: @@      :@+       .#%     =@%" << endl;
    cout << "\t  .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*#@@@@@@@@.\t\t\t\t\t                      .@@+        @@ #@@@%-  #@: @@      :@@#.    =@@%    -@@@#" << endl;
    cout << "\t  :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.\t\t\t\t\t                      =@@.        @@ *@% #@% %@: @@@@@@# :@@@@=  *@@@%   :@@=#@*" << endl;
    cout << "\t  :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.\t\t\t\t\t                      .%@*.       @@ *@#  :#@@@: @@      :@%  @#@@  @%  .@@%  @@+" << endl;
    cout << "\t  :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.\t\t\t\t\t                       .*@@####@# @% *@#    :#@- @@      :@%  =@%: +@# .%@*=+++@@=" << endl;
    cout << "\t  :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.\t\t\t\t\t                         :+####=. += -+=      :: ####### .++       -+= -+=     :++" << endl;
    cout << "\t  .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*#@@@@@@@@." << endl;
    cout << "\t   *@@@@@@@@@@@@@@@@@@@@@@@@@@@#  .=#@@@@@." << endl;
    cout << "\t    :*%%@@@@@@@@@@@@@@@@@@@%%*-      .=#%=" << endl;
    cout << "\n\n\n";
    SetConsoleTextAttribute(h, 9);
}

int SystemFile::TicketID() {
    ifstream xin;
    xin.open("TicketID.txt");
    string temp;
    while (getline(xin, temp)) {}
    ofstream fout;
    fout.open("LastID.txt");
    fout << temp;
    fout.close();
    ifstream fin;
    fin.open("LastID.txt");
    int x;
    fin >> x;
    fin.close();
    if (x < 1000)
    {
        fout.open("LastID.txt");
        x = 1000;
        fout << x;
        fout.close();
    }
    return x;
}

void SystemFile::insert_ticket(string movie_name, int number_of_individuals, string show_time, string chair_number, double price)
{
    int ID = TicketID() + 1;
    ofstream outID;
    outID.open("TicketID.txt", ios::app);
    outID << endl << ID;
    ofstream outName;
    outName.open("MovieName.txt", ios::app);
    outName << endl << movie_name;
    ofstream outnum_of_ind;
    outnum_of_ind.open("NumberOfIndividuals.txt", ios::app);
    outnum_of_ind << endl << number_of_individuals;
    ofstream outshow_time;
    outshow_time.open("ShowTimeInTicket.txt", ios::app);
    outshow_time << endl << show_time;
    ofstream outPeople;
    outPeople.open("ChairNumbers.txt", ios::app);
    outPeople << endl << chair_number;
    ofstream outPrice;
    outPrice.open("TicketPrice.txt", ios::app);
    outPrice << endl << price;
    get_number_of_ticket(1);
}

void SystemFile::insert_movie(string movie_name, string show_time1, string show_time2, string show_time3, string show_time4) {
    ofstream out_movie;
    out_movie.open("Movie_ShowTime.txt", ios::app);
    out_movie << "#" << endl << movie_name << endl << show_time1 << endl << show_time2 << endl << show_time3 << endl << show_time4 << endl;
}

void SystemFile::display_tickets()
{
    SetConsoleTextAttribute(h, 148);
    cout << "\t\t\t\t\t\t   ID          Name of Movie      Number of People      Show Time       Price of Ticket";
    SetConsoleTextAttribute(h, 9);
    cout << "\n\t\t\t\t\t\t***************************************************************************************";
    cout << "\n";
    int n = get_number_of_ticket(0);
    int ID;
    ifstream inID;
    inID.open("TicketID.txt");
    string movie_name;
    ifstream inName;
    inName.open("MovieName.txt");
    int number_of_individuals;
    ifstream in_num_ind;
    in_num_ind.open("NumberOfIndividuals.txt");
    string show_time;
    ifstream inshow_time;
    inshow_time.open("ShowTimeInTicket.txt");
    double Price;
    ifstream inPrice;
    inPrice.open("TicketPrice.txt");
    for (int i = 0; i < n; i++) {
        inID >> ID;
        inName >> movie_name;
        in_num_ind >> number_of_individuals;
        inshow_time >> show_time;
        inPrice >> Price;
        if (i + 1 < 10) {
            cout << "\t\t\t\t\t\t" << i + 1 << "- " << ID << "\t\t" << movie_name;
            if (movie_name.length() < 7) {
                cout << "\t\t\t" << number_of_individuals << "\t\t  "
                    << show_time << "\t\t     " << Price << " EGP" << endl;
            }
            else {
                cout << "\t\t" << number_of_individuals << "\t\t  "
                    << show_time << "\t\t     " << Price << " EGP" << endl;
            }
        }
        else {
            cout << "\t\t\t\t\t\t" << i + 1 << "- " << ID << "\t" << movie_name;
            if (movie_name.length() < 7) {
                cout << "\t\t\t" << number_of_individuals << "\t\t  "
                    << show_time << "\t\t     " << Price << " EGP" << endl;
            }
            else {
                cout << "\t\t" << number_of_individuals << "\t\t  "
                    << show_time << "\t\t     " << Price << " EGP" << endl;
            }
        }
    }
    cout << "\t\t\t\t\t\t***************************************************************************************";
    cout << "\n\t\t\t\t\t\t --->The number of Tickets is : " << get_number_of_ticket(0) << endl;
}

void SystemFile::display_last_ticket()
{
    int n = get_number_of_ticket(0);
    int ID;
    ifstream inID;
    inID.open("TicketID.txt");
    string movie_name;
    ifstream inName;
    inName.open("MovieName.txt");
    int number_of_individuals;
    ifstream inPlace;
    inPlace.open("NumberOfIndividuals.txt");
    string show_time;
    ifstream in_show_time;
    in_show_time.open("ShowTimeInTicket.txt");
    string chair_number;
    ifstream in_chair_number;
    in_chair_number.open("ChairNumbers.txt");
    double Price;
    ifstream inPrice;
    inPrice.open("TicketPrice.txt");

    for (int i = 0; i < n; i++)
    {
        inID >> ID;
        inName >> movie_name;
        inPlace >> number_of_individuals;
        in_show_time >> show_time;
        in_chair_number >> chair_number;
        inPrice >> Price;
    }
    cout << "\n\n\n\n\t\t\t________________________________________________________________________\n";
    cout << "\t\t\t|                                                                       |\n";
    cout << "\t\t\t|   Dear Customer,                                                      |\n";
    cout << "\t\t\t|                      Congratulation!! Your tickets has been booked.   |\n";
    cout << "\t\t\t|                                                                       |\n";
    cout << "\t\t\t|                  THE DETAILS:                                         |\n";
    cout << "\t\t\t|                            MOVIE Name: " << movie_name;
    if (movie_name.length() < 7) {
        cout << "\t\t\t\t|\n";
    }
    else {
        cout << "\t\t\t|\n";
    }
    cout << "\t\t\t|                            Number of individual: " << number_of_individuals << "\t\t\t|\n";
    cout << "\t\t\t|                            SHOW STARTS: " << show_time << "\t\t\t\t|\n";
    cout << "\t\t\t|                            THE SEAT NUMBERS ARE: ";
    if (chair_number.length() < 4) {
        cout << chair_number << "\t\t\t|\n";
    }
    else if (chair_number.length() < 13) {
        cout << chair_number << "\t\t|\n";
    }
    else {
        cout << chair_number << "\t|\n";
    }
    cout << "\t\t\t|                            Price of ticket: " << Price << " EGP\t\t\t|\n";
    cout << "\t\t\t|                                                     ";
    SetConsoleTextAttribute(h, 148);
    cout << "QR CODE";
    SetConsoleTextAttribute(h, 9);
    cout << "           |\n";
    cout << "\t\t\t|                                                       ..++>>>         |\n";
    cout << "\t\t\t|                                                       ..__***         |\n";
    cout << "\t\t\t|                                                       &%^>>>>         |\n";
    cout << "\t\t\t|                                                       :::::::         |\n";
    cout << "\t\t\t|_______________________________________________________________________|\n";
}

void SystemFile::display_last_information_ticket()
{
    int n = get_number_of_ticket(0);
    int ID;
    ifstream inID;
    inID.open("TicketID.txt");
    string movie_name;
    ifstream inName;
    inName.open("MovieName.txt");
    int number_of_individuals{};
    ifstream inPlace;
    inPlace.open("NumberOfIndividuals.txt");
    string show_time;
    ifstream in_show_time;
    in_show_time.open("ShowTimeInTicket.txt");
    string chair_number;
    ifstream in_chair_number;
    in_chair_number.open("ChairNumbers.txt");
    double Price{};
    ifstream inPrice;
    inPrice.open("TicketPrice.txt");

    for (int i = 0; i < n; i++) {
        inID >> ID;
        inName >> movie_name;
        inPlace >> number_of_individuals;
        in_show_time >> show_time;
        in_chair_number >> chair_number;
        inPrice >> Price;
    }
    cout << "\t\t\t\t\t #@#@#@#@ Here Is The Information About Your Tickets Booking @#@#@#@#" << endl;
    cout << "\t\t\t --->MOVIE Name: " << movie_name << endl;
    cout << "\t\t\t --->Number of individual: " << number_of_individuals << endl;
    cout << "\t\t\t --->SHOW STARTS: " << show_time << endl;
    cout << "\t\t\t --->THE SEAT NUMBERS ARE: " << chair_number << endl;
    cout << "\t\t\t --->Price of ticket: " << Price << " EGP" << endl;
}

void SystemFile::display_movie() {
    cout << "\t\t\t*************************************************************************************************************************************" << endl;
    cout << "\t\t\t*";
    SetConsoleTextAttribute(h, 148);
    cout << "         Movie Names           Show Time (1)         Show Time (2)             Show Time (3)             Show Time (4)             ";
    SetConsoleTextAttribute(h, 9);
    cout << "*" << endl;
    string x;
    int i = 0, a = 0;
    bool r = false;
    ifstream in_x;
    in_x.open("Movie_ShowTime.txt");
    while (getline(in_x, x)) {
        if (r) {
            cout << "\t\t\t*\t";
            SetConsoleTextAttribute(h, 4);
            cout << "[" << i << "]";
            SetConsoleTextAttribute(h, 9);
            cout << " ";
            r = false;
        }
        if (x == "#") {
            if (a == 0)
            {
                cout << "\t\t\t*************************************************************************************************************************************";
            }
            cout << endl;
            i++;
            r = true;
            a = 0;
            continue;
        }
        else {
            if (i < 10 && a == 0)
            {
                cout << "  ";
            }
            else if (a == 0)
            {
                cout << " ";
            }
            else {
                cout << "  ";
            }
            if (x.length() < 10) {
                cout << x << "\t            ";
            }
            else
            {
                cout << x << "\t    ";
            }
            if (a == 4)
            {
                cout << "*";
            }
            a++;
        }
    }
    cout << endl << "\t\t\t*************************************************************************************************************************************" << endl;
    cout << "\t\t\t---> " << get_number_of_movie(1) << " films in theaters" << endl;
}

void SystemFile::display_movie_name_only()
{
    cout << "\t\t\t\t\t\t\t\t\t*************************************" << endl;
    cout << "\t\t\t\t\t\t\t\t\t*";
    SetConsoleTextAttribute(h, 148);
    cout << "             Movie Names           ";
    SetConsoleTextAttribute(h, 9);
    cout << "*" << endl;
    string x;
    int i = 0, a = 0;
    bool r = false;
    ifstream in_x;
    in_x.open("Movie_ShowTime.txt");
    while (getline(in_x, x)) {
        if (r) {
            cout << "\t\t\t\t\t\t\t\t\t*\t";
            SetConsoleTextAttribute(h, 4);
            cout << "[" << i << "]";
            SetConsoleTextAttribute(h, 9);
            cout << " ";
            r = false;
        }
        if (x == "#") {
            if (a == 0)
            {
                cout << "\t\t\t\t\t\t\t\t\t*************************************";
            }
            cout << endl;
            i++;
            r = true;
            a = 0;
            continue;
        }
        else {
            if (i < 10 && a == 0) {
                if (x.length() < 10) {
                    cout << "  " << x << "\t            *";
                }
                else {
                    cout << "  " << x << "\t    *";
                }
            }
            else if (a == 0) {
                if (x.length() < 10) {
                    cout << " " << x << "\t            *";
                }
                else {
                    cout << " " << x << "\t    *";
                }
            }
            a++;
        }
    }
    cout << endl << "\t\t\t\t\t\t\t\t\t*************************************" << endl;
    cout << "\t\t\t\t\t\t\t\t\t---> " << get_number_of_movie(1) << " films in theaters" << endl;
}

void SystemFile::search_for_movie_and_show_time(int num_movie, int num_show_time, string& movie_name, string& show_time) {
    string x;
    int i = 1, z = 0;
    bool r = true;
    ifstream in_x;
    in_x.open("Movie_ShowTime.txt");
    while (getline(in_x, x)) {
        if (i == num_movie)
        {
            if (r)
            {
                movie_name = x;
                r = false;
            }
            if (z == num_show_time)
            {
                show_time = x;
                break;
            }
            z++;
            continue;
        }
        if (x == "#")
        {
            i++;
        }
    }
}

void SystemFile::delete_movie(int pos) {
    string x;
    ofstream Out_x;
    Out_x.open("Temp_Movie_ShowTime.txt", ios::app);
    ifstream in_x;
    in_x.open("Movie_ShowTime.txt");
    int i = 0, z = get_number_of_movie(1);
    while (getline(in_x, x)) {
        if (x == "#" && i == z - 1 && i == pos - 1) {
            i++;
            continue;
        }
        if (i != pos) {
            Out_x << x << endl;
        }
        if (x == "#")
        {
            i++;
        }
    }
    in_x.close();
    Out_x.close();
    remove("Movie_ShowTime.txt");
    rename("Temp_Movie_ShowTime.txt", "Movie_ShowTime.txt");
}

int SystemFile::get_number_of_movie(int Case) {
    if (Case == 0) {
        ifstream in;
        in.open("NumberOfMovie.txt");
        int x;
        in >> x;
        return x;
    }
    else if (Case == 1) {
        string x;
        ifstream in_x;
        in_x.open("Movie_ShowTime.txt");
        ofstream Out_x;
        Out_x.open("NumberOfMovie.txt");
        int count = 0;
        while (getline(in_x, x)) {
            if (x == "#")
            {
                count++;
            }
        }
        Out_x << count;
        in_x.close();
        Out_x.close();
        return count;
    }
    return 0;
}

int SystemFile::get_number_of_ticket(int Case) {
    if (Case == 0) {
        ifstream in;
        in.open("NumberOfTicket.txt");
        int x;
        in >> x;
        return x;
    }
    else if (Case == 1) {
        ifstream in;
        in.open("NumberOfTicket.txt");
        int x;
        in >> x;
        ofstream out;
        out.open("NumberOfTicket.txt");
        int y;
        y = x + 1;
        out << y;
        return x;
    }
    else if (Case == -1) {
        ifstream in;
        in.open("NumberOfTicket.txt");
        int x;
        in >> x;
        ofstream out;
        out.open("NumberOfTicket.txt");
        int y;
        y = x - 1;
        out << y;
        return x;
    }
}

void SystemFile::Delete_ticket(string remove_ID)
{
    int count = 0;
    ifstream getID;
    getID.open("TicketID.txt");
    string line;
    while (getline(getID, line))
    {
        if (remove_ID == line)
        {
            break;
        }
        count++;
    }
    getID.close();

    string ID;
    ofstream Out_ID;
    Out_ID.open("TempTicketID.txt", ios::app);
    ifstream in_ID;
    in_ID.open("TicketID.txt");

    string movie_name;
    ofstream Out_movie_name;
    Out_movie_name.open("TempMovieName.txt", ios::app);
    ifstream in_movie_name;
    in_movie_name.open("MovieName.txt");

    string number_of_individuals;
    ofstream Out_number_of_individuals;
    Out_number_of_individuals.open("TempNumberOfIndividuals.txt", ios::app);
    ifstream in_number_of_individuals;
    in_number_of_individuals.open("NumberOfIndividuals.txt");

    string show_time;
    ofstream Out_show_time;
    Out_show_time.open("TempShowTimeInTicket.txt", ios::app);
    ifstream in_show_time;
    in_show_time.open("ShowTimeInTicket.txt");

    string chair_number;
    ofstream Out_chair_number;
    Out_chair_number.open("TempChairNumbers.txt", ios::app);
    ifstream in_chair_number;
    in_chair_number.open("ChairNumbers.txt");

    string price;
    ofstream Out_Price;
    Out_Price.open("TempTicketPrice.txt", ios::app);
    ifstream in_Price;
    in_Price.open("TicketPrice.txt");

    int i = 0;
    while (getline(in_ID, ID)) {
        if (i == count) {
            i++;
            continue;
        }
        else {
            Out_ID << ID << endl;
            i++;
        }
    }
    in_ID.close();
    Out_ID.close();
    remove("TicketID.txt");
    rename("TempTicketID.txt", "TicketID.txt");

    i = 0;
    while (getline(in_movie_name, movie_name)) {
        if (i == count) {
            i++;
            continue;
        }
        else {
            Out_movie_name << movie_name << endl;
            i++;
        }
    }
    in_movie_name.close();
    Out_movie_name.close();
    remove("MovieName.txt");
    rename("TempMovieName.txt", "MovieName.txt");

    i = 0;
    while (getline(in_number_of_individuals, number_of_individuals)) {
        if (i == count) {
            i++;
            continue;
        }
        else {
            Out_number_of_individuals << number_of_individuals << endl;
            i++;
        }
    }
    in_number_of_individuals.close();
    Out_number_of_individuals.close();
    remove("NumberOfIndividuals.txt");
    rename("TempNumberOfIndividuals.txt", "NumberOfIndividuals.txt");

    i = 0;
    while (getline(in_show_time, show_time)) {
        if (i == count) {
            i++;
            continue;
        }
        else {
            Out_show_time << show_time << endl;
            i++;
        }
    }
    in_show_time.close();
    Out_show_time.close();
    remove("ShowTimeInTicket.txt");
    rename("TempShowTimeInTicket.txt", "ShowTimeInTicket.txt");

    i = 0;
    while (getline(in_chair_number, chair_number)) {
        if (i == count) {
            i++;
            continue;
        }
        else {
            Out_chair_number << chair_number << endl;
            i++;
        }
    }
    in_chair_number.close();
    Out_chair_number.close();
    remove("ChairNumbers.txt");
    rename("TempChairNumbers.txt", "ChairNumbers.txt");

    i = 0;
    while (getline(in_Price, price)) {
        if (i == count) {
            i++;
            continue;
        }
        else {
            Out_Price << price << endl;
            i++;
        }
    }
    in_Price.close();
    Out_Price.close();
    remove("TicketPrice.txt");
    rename("TempTicketPrice.txt", "TicketPrice.txt");
    get_number_of_ticket(-1);
}

void SystemFile::delete_last_ticket()
{
    int count = 0;
    ifstream getID;
    getID.open("TicketID.txt");
    string line, remove_ID = to_string(TicketID());
    while (getline(getID, line))
    {
        if (remove_ID == line)
        {
            break;
        }
        count++;
    }
    getID.close();
    string ID;
    ofstream Out_ID;
    Out_ID.open("TempTicketID.txt", ios::app);
    ifstream in_ID;
    in_ID.open("TicketID.txt");

    string movie_name;
    ofstream Out_movie_name;
    Out_movie_name.open("TempMovieName.txt", ios::app);
    ifstream in_movie_name;
    in_movie_name.open("MovieName.txt");

    string number_of_individuals;
    ofstream Out_number_of_individuals;
    Out_number_of_individuals.open("TempNumberOfIndividuals.txt", ios::app);
    ifstream in_number_of_individuals;
    in_number_of_individuals.open("NumberOfIndividuals.txt");

    string show_time;
    ofstream Out_show_time;
    Out_show_time.open("TempShowTimeInTicket.txt", ios::app);
    ifstream in_show_time;
    in_show_time.open("ShowTimeInTicket.txt");

    string chair_number;
    ofstream Out_chair_number;
    Out_chair_number.open("TempChairNumbers.txt", ios::app);
    ifstream in_chair_number;
    in_chair_number.open("ChairNumbers.txt");

    string price;
    ofstream Out_Price;
    Out_Price.open("TempTicketPrice.txt", ios::app);
    ifstream in_Price;
    in_Price.open("TicketPrice.txt");

    int i = 0;
    while (getline(in_ID, ID)) {
        if (i == count) {
            i++;
            continue;
        }
        else {
            Out_ID << ID << endl;
            i++;
        }
    }
    in_ID.close();
    Out_ID.close();
    remove("TicketID.txt");
    rename("TempTicketID.txt", "TicketID.txt");

    i = 0;
    while (getline(in_movie_name, movie_name)) {
        if (i == count) {
            i++;
            continue;
        }
        else {
            Out_movie_name << movie_name << endl;
            i++;
        }
    }
    in_movie_name.close();
    Out_movie_name.close();
    remove("MovieName.txt");
    rename("TempMovieName.txt", "MovieName.txt");

    i = 0;
    while (getline(in_number_of_individuals, number_of_individuals)) {
        if (i == count) {
            i++;
            continue;
        }
        else {
            Out_number_of_individuals << number_of_individuals << endl;
            i++;
        }
    }
    in_number_of_individuals.close();
    Out_number_of_individuals.close();
    remove("NumberOfIndividuals.txt");
    rename("TempNumberOfIndividuals.txt", "NumberOfIndividuals.txt");

    i = 0;
    while (getline(in_show_time, show_time)) {
        if (i == count) {
            i++;
            continue;
        }
        else {
            Out_show_time << show_time << endl;
            i++;
        }
    }
    in_show_time.close();
    Out_show_time.close();
    remove("ShowTimeInTicket.txt");
    rename("TempShowTimeInTicket.txt", "ShowTimeInTicket.txt");

    i = 0;
    while (getline(in_chair_number, chair_number)) {
        if (i == count) {
            i++;
            continue;
        }
        else {
            Out_chair_number << chair_number << endl;
            i++;
        }
    }
    in_chair_number.close();
    Out_chair_number.close();
    remove("ChairNumbers.txt");
    rename("TempChairNumbers.txt", "ChairNumbers.txt");

    i = 0;
    while (getline(in_Price, price)) {
        if (i == count) {
            i++;
            continue;
        }
        else {
            Out_Price << price << endl;
            i++;
        }
    }
    in_Price.close();
    Out_Price.close();
    remove("TicketPrice.txt");
    rename("TempTicketPrice.txt", "TicketPrice.txt");
    get_number_of_ticket(-1);
}

void SystemFile::reset_data_in_ticket_file_system() {
    ofstream Out_ID;
    Out_ID.open("TempTicketID.txt", ios::app);
    Out_ID.close();
    remove("TicketID.txt");
    rename("TempTicketID.txt", "TicketID.txt");

    ofstream Out_movie_name;
    Out_movie_name.open("TempMovieName.txt", ios::app);
    Out_movie_name.close();
    remove("MovieName.txt");
    rename("TempMovieName.txt", "MovieName.txt");

    ofstream Out_number_of_individuals;
    Out_number_of_individuals.open("TempNumberOfIndividuals.txt", ios::app);
    Out_number_of_individuals.close();
    remove("NumberOfIndividuals.txt");
    rename("TempNumberOfIndividuals.txt", "NumberOfIndividuals.txt");

    ofstream Out_show_time;
    Out_show_time.open("TempShowTimeInTicket.txt", ios::app);
    Out_show_time.close();
    remove("ShowTimeInTicket.txt");
    rename("TempShowTimeInTicket.txt", "ShowTimeInTicket.txt");

    ofstream Out_chair_number;
    Out_chair_number.open("TempChairNumbers.txt", ios::app);
    Out_chair_number.close();
    remove("ChairNumbers.txt");
    rename("TempChairNumbers.txt", "ChairNumbers.txt");

    ofstream Out_Price;
    Out_Price.open("TempTicketPrice.txt", ios::app);
    Out_Price.close();
    remove("TicketPrice.txt");
    rename("TempTicketPrice.txt", "TicketPrice.txt");

    ofstream Out_last_ID;
    Out_last_ID.open("TempLastID.txt", ios::app);
    Out_last_ID.close();
    remove("LastID.txt");
    rename("TempLastID.txt", "LastID.txt");

    ofstream Out_Number_Of_Ticket;
    Out_Number_Of_Ticket.open("TempNumberOfTicket.txt", ios::app);
    Out_Number_Of_Ticket << 0;
    Out_Number_Of_Ticket.close();
    remove("NumberOfTicket.txt");
    rename("TempNumberOfTicket.txt", "NumberOfTicket.txt");
}

bool SystemFile::check_password() {
    ifstream in;
    int counter = 3;
    string x;
    in.open("AdminPassword.txt");
    in >> x;
    string str;
    while (counter)
    {
        if (counter == 3)
        {
            cout << "\t\t\t---->if you want to exit Enter 'x' or 'X' :)" << endl;
        }
        cout << "\t\t\t-Please enter The Password (you have " << counter << " Attempts left) : ";
        str = takePasswdFromUser();
        if (x == str)
        {
            system("cls");
            system_interface();
            cout << "\t\t\t        Correct Password :) " << endl;
            return true;
        }
        else if (str == "x" || str == "X")
        {
            break;
        }
        else {
            system("cls");
            system_interface();
            cout << "\t\t\t        Wrong Password :( " << endl;
        }
        counter--;
    }
    return false;
}

void SystemFile::modify_password() {
    if (check_password())
    {
        ofstream out;
        string x, y;
        bool m = false;
        out.open("AdminPassword.txt");
        do {
            system("cls");
            system_interface();
            if (m)
            {
                cout << "\t\t\t   ---->Error! The passwords do not match :(" << endl;
            }
            cout << "\t\t\t-Enter New Password : ";
            x = takePasswdFromUser();
            cout << "\t\t\t-Enter New Password Again : ";
            y = takePasswdFromUser();
            m = true;
        } while (x != y);
        out << x;
        cout << "\n\t\t\t\t#@#@#@#@  Password Updated successfully :)  @#@#@#@#" << endl;
    }
    else
    {
        cout << "\n\t\t\t\t#@#@#@#@  No change in Password :(  @#@#@#@#" << endl;
    }
}