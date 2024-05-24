#include <iostream>  
#include <ctime>  
#include <string>

using namespace std;

time_t now = time(0); 
tm* ltm = localtime(&now);  

void printDate(); // All Done
void printTime(); // All Done
void printName(string userName);

int main() {  

    string question, userName;
    bool nameBool = false;

    do {
        
        cout << "How can I help you ??" << endl;
        cin.ignore();
        getline(cin, question);

        string nameStr = "name";
        string timeStr = "time";
        string dateStr = "date";
    
        size_t nameStrBool = question.find(nameStr);
        size_t timeStrBool = question.find(timeStr);
        size_t dateStrBool = question.find(dateStr);

        if(nameStrBool != string::npos) {

            if(nameBool==false) {
                cout << "Please Tell your name, I will remember it :: " << endl;
                cin.ignore();
                getline(cin, userName);
                nameBool = true;

            } else {
                printName(userName);
            }

        } else if(timeStrBool != string::npos) {

            printTime();

        } else if(dateStrBool != string::npos){

            printDate();

        } else {
            cout << "I am unable to understand you, Please Try Again.." << endl;
        }

    }while(question != "0");
} 

void printDate() {

    int month = 1+ltm->tm_mon;
    string monthName;

    switch (month) {
        case 1:
            monthName = "January";
            break;
        case 2:
            monthName = "February";
            break;
        case 3:
            monthName = "March";
            break;
        case 4:
            monthName = "April";
            break;
        case 5:
            monthName = "May";
            break;
        case 6:
            monthName = "June";
            break;
        case 7:
            monthName = "July";
            break;
        case 8:
            monthName = "August";
            break;
        case 9:
            monthName = "September";
            break;
        case 10:
            monthName = "October";
            break;
        case 11:
            monthName = "November";
            break;
        case 12:
            monthName = "December";
            break;
        default:
            monthName = "Invalid month";
            break;
    }

    cout << "Date :: " << ltm->tm_mday << "-"
         << monthName << "-"
         << 1900 + ltm->tm_year << endl; 
  
}
void printTime() {
    int hours = ltm->tm_hour;
    string session;
    (hours>12) ? session="PM" : session="AM";
    (hours>12) ? hours-=12 : hours; 

    cout << "Time :: " << hours << ":"  
         << ltm->tm_min <<" " << session << endl;
}
void printName(string userName) {
    cout << "Your beautiful name is :: " << userName << endl; 
}