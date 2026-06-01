//LOGIN USERNAME=admin
// LOGIN PASSWORD=1234

#include <iostream>
#include<iomanip>
#include <windows.h>
#include <fstream>
using namespace std;

struct Student {
    int id;
    string name;
    int room;
    bool feePaid;
};

Student s[100];
int count = 0;
int rooms[20] = {0}; // 0 = empty, 1 = occupied

// Function prototypes
void loadData();
void loading();
void login();
bool validName(string name);

void saveData();
void addStudent();
void assignRoom();
void viewStudents();
void feeStatus();
void dashboard();
void menu();

// ================= MAIN =================
int main() {
    loadData();
    loading();
    login();
    menu();
    return 0;
}
//================LOADING SCREEN============
void loading()
{
    system("cls");
    cout<<"\n\n";
    cout<<"\t\t\t\t ==================================================\n";
    cout<<"\033[1;33m";

    cout<<"\t\t\t\t\t  WELCOME TO HOSTEL MANAGEMENT SYSTEM\n";
    cout<<"\033[0m";

    cout<<"\t\t\t\t ==================================================\n";
    cout<<"\t\t\t\t\t (Admininstrator Access Only)\n";

    cout<<"\n\t\t\t\tLoading";
    for(int i=0;i<5;i++)
    {
        cout<<".";
        Sleep(300);
    }
    cout<<"\033[0m";
    Sleep(700);

}

// ================= MENU =================
void menu() {
    int choice;

    do {
        system("cls");
        cout<<"\033[1;33m";
        cout << "\n\t\t\t\t\tHOSTEL MANAGEMENT SYSTEM\n";
        cout<<"\033[0m";
    cout<<"\n";
    cout<<"\n\t\t\t\t=========================================\n";
    cout<<"\t\t\t\t\t\tADMIN PANEL";
    cout<<"\n\t\t\t\t=========================================\n";
        


        cout << "\n1. Student Registration\n";
        cout << "2. Room Allocation\n";
        cout << "3. Student Records\n";
        cout << "4. Fee Status\n";
        cout<< "5. Dashboard\n";

        cout << "6. Save & Exit\n";
        cout<<"\033[1;31m";

        cout << "Select option: ";
        cout<<"\033[0m";

        cin >> choice;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout<<"\nInvalid input";
        }
        else
        {

        

        switch(choice) {
            case 1: addStudent(); break;
            case 2: assignRoom(); break;
            case 3: viewStudents(); break;
            case 4: feeStatus(); break;
            case 5: dashboard();break;
            case 6: saveData(); system("cls");
              cout<<"=============================================\n";
                cout<<"         DATA SAVED SUCCESSFULLY! \n";
                cout<<"=============================================\n";
               cout<<"\n\n        Thanks for using HMS!"; exit(0);
            default: cout << "Invalid choice!\n";
        }
    }
        if(choice!=6)
        {
        cout<<"\nPress enter to continue...";
        cin.ignore(1000,'\n');
        cin.get();

        }

    } while(choice != 6);
}

// ================= LOAD =================
void loadData() {
    ifstream file("hostel.txt");

    if (!file) return;

    file >> count;

    for (int i = 0; i < count; i++) {
        file >> s[i].id >> s[i].name >> s[i].room >> s[i].feePaid;
        if (s[i].room != -1)
            rooms[s[i].room] = 1;
    }

    file.close();
}

// ================= SAVE =================
void saveData() {
    ofstream file("hostel.txt");

    file << count << endl;

    for (int i = 0; i < count; i++) {
        file << s[i].id << " "
             << s[i].name << " "
             << s[i].room << " "
             << s[i].feePaid << endl;
    }

    
    file.close();
   

}

// ================= ADD STUDENT =================
void addStudent() {
    system("cls");
    cout<<"\033[1;33m";
        cout << "\n\t\t\t\t\tHOSTEL MANAGEMENT SYSTEM\n";
        cout<<"\033[0m";   
    cout<<"\n";
    cout<<"\n\t\t\t\t=========================================\n";
    cout<<"\t\t\t\t\tSTUDENT REGISTERATION";
    cout<<"\n\t\t\t\t=========================================\n";
        
    

    cout << "\nEnter ID: ";
    while(!(cin >> s[count].id))
    {
        cout<<"INVALID ID! ENTER NUMBERS ONLY\n";
        cout<<"ENTER AGAIN: ";
        cin.clear();
        cin.ignore(1000,'\n');
    }
do 
{
    cout << "Enter Name: ";
    cin >> s[count].name;
    if(!validName(s[count].name))
    {
        cout<<"INVALID NAME...letters only.\n";

    }
}
    while(!validName(s[count].name));


    s[count].room = -1; // not assigned
    s[count].feePaid = false;

    count++;
cout<<"\n=========================";
    cout << "\n  Student Added!\n";
cout<<"=========================";

}
bool validName(string name)
{
    for(int i=0;i<name.length();i++)
    {
        if(!isalpha(name[i]))
        {
            return false;
        }
    }
    return true;
}

// ================= ASSIGN ROOM =================
void assignRoom() {
    system("cls");

    int id;
    cout<<"\033[1;33m";
        cout << "\n\t\t\t\t\tHOSTEL MANAGEMENT SYSTEM\n";
        cout<<"\033[0m";
    cout<<"\n";
    cout<<"\n\t\t\t\t=========================================\n";
    cout<<"\t\t\t\t\t\tROOM ALLOCATION";
    cout<<"\n\t\t\t\t=========================================\n";
    
    
    cout << "\nEnter Student ID: ";
     while(!(cin >>id))
    {
        cout<<"INVALID ID! ENTER NUMBERS ONLY\n";
        cout<<"ENTER AGAIN: ";
        cin.clear();
        cin.ignore(1000,'\n');
    }
    

    for (int i = 0; i < count; i++) {
        if (s[i].id == id) {

            if (s[i].room != -1) {
                    

                    cout<<"\n\n\t\t\tStudent already has a room "<<s[i].room<<endl;


 
                
                return;
            }

            for (int r = 0; r < 20; r++) {
                if (rooms[r] == 0) {
                    rooms[r] = 1;
                    s[i].room = r;

                    cout << "\n-------------------------------------\n";
                    cout<<"\nStudent ID : "<<s[i].id;
                    cout<<"\nStudent Name : "<<s[i].name;
                    cout<<"\nAssigned Room : "<<r;
                    cout << "\n-------------------------------------\n";
                    cout<<"\n\t\t\tROOM ASSIGNED SUCCESSFULLY!";





                    return;
                }
            }

            cout << "\n-------------------------------------\n";

            cout << "         No rooms available!\n";
            cout << "\n-------------------------------------\n";


            return;
        }
    }
     cout << "\n-------------------------------------\n";


     cout << "         Student not found!\n";
     cout << "\n-------------------------------------\n";


}

// ================= VIEW =================
void viewStudents() {
    system("cls");
    cout<<"\033[1;33m";
        cout << "\n\t\t\t\t\tHOSTEL MANAGEMENT SYSTEM\n";
        cout<<"\033[0m";
    cout<<"\n";
    cout<<"\n\t\t\t\t=========================================\n";
    cout<<"\t\t\t\t\t\tSTUDENTS LIST";
    cout<<"\n\t\t\t\t=========================================\n";
    cout<<left<<setw(12)<<"\nID"<<setw(16)<<"NAME"<<setw(18)<<"ROOM"<<setw(12)<<"FEE STATUS";
    cout<<"\n---------------------------------------------------------\n";
    
    


    for (int i = 0; i < count; i++) {
        cout<<left<<setw(12)<< s[i].id<<setw(16) << s[i].name;
             
             if( s[i].room==-1)
             cout<<setw(18)<<"NOT Assigned";
            else
            cout<<setw(18)<<s[i].room;

        if (s[i].feePaid)
            cout <<setw(12)<< "Paid";
        else
            cout <<setw(12)<< "UNPaid";


        cout << endl;
    }
}

// ================= FEE =================
void feeStatus() {
    system("cls");

    int id;
    cout<<"=============================================\n";
    cout<<"                  FEE STATUS     \n";
    cout<<"=============================================\n";

    cout << "Enter Student ID: ";
     while(!(cin >> id))
    {
        cout<<"INVALID ID! ENTER NUMBERS ONLY\n";
        cout<<"ENTER AGAIN: ";
        cin.clear();
        cin.ignore(1000,'\n');
    }

    for (int i = 0; i < count; i++) {
        if (s[i].id == id) {
            int choice;
            cout << "1. Mark as paid\n2. Mark as Unpaid\nChoice: ";
            cin >> choice;

            if (choice == 1) {
                s[i].feePaid = true;
                cout<<"\n==================\n";
                cout << "   Paid";
                cout<<"\n==================";

            } else {
                s[i].feePaid = false;
                cout<<"\n==================\n";

                cout << "   Unpaid";
                cout<<"\n==================\n";

            }
            return;
        }
    }

    cout << "Student not found!\n";
}
//==============DASHBOARD=====================
void dashboard()
{
    system("cls");
    
    
    int occupied=0;
    int empty=0;
    int unpaid=0;
    for(int i=0;i<20;i++)
    {
        if(rooms[i]==1)
        occupied++;
    else 
    empty++;
    }
    //unpaid fee count
    for(int i=0;i<count;i++)
    {
    if(s[i].feePaid==false)
    unpaid++;
    }
    cout<<"\033[1;33m";
        cout << "\n\t\t\t\t\tHOSTEL MANAGEMENT SYSTEM\n";
        cout<<"\033[0m";
    cout<<"\n";
    cout<<"\n\t\t\t\t=========================================\n";
    cout<<"\t\t\t\t\t\tDASHBOARD";
    cout<<"\n\t\t\t\t=========================================\n";
    
    
cout<<"\nTotal Students : "<<count;
cout<<"\nOccupied Rooms : "<<occupied;
cout<<"\nEmpty Rooms : "<<empty;
cout<<"\nUnpaid Fees : "<<unpaid;
    cout<<"\n\n=============================================\n";



}
void login()
{
    system("cls");

    string username;
    string password;
    while(true)
    {
        system("cls");
        cout<<"\033[1;33m";
        cout << "\n\t\t\t\t\tHOSTEL MANAGEMENT SYSTEM\n";
        cout<<"\033[0m";
    cout<<"\n";
    cout<<"\n\t\t\t\t=========================================\n";
    cout<<"\t\t\t\t\t\tLOGIN SYSTEM";
    cout<<"\n\t\t\t\t=========================================\n";
    

        
cout<<"\nEnter username: ";
cin>>username;
cout<<"\nEnter Password: ";
cin>>password;
//correct username and password
if(username=="admin"&&password=="1234")
{
    cout<<"\nLogin SUccessful!\n";
    Sleep(1000);
    system("cls");
    break;
}
else{
    cout<<"\nInvalid Username or Password!\n";
    cout<<"\nPress Enter to TRy again.....";
    cin.ignore();
    cin.get();
}

}
}