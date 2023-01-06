#include <iostream>
#include <istream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <string>


using namespace std;
int ft;
int inch;
int weight;
int age;
string username;
string gender;
fstream file;


bool isEmpty(fstream& pFile){
    return pFile.peek() == ifstream::traits_type::eof();
}

bool fileExists(const string& fileName){
    ifstream infile(fileName);
    return infile.good();
}

void registerUser(){
    ofstream newFile;
    cout << "Create a username: ";
    cin >> username;
    if(!(fileExists(username))){
        newFile.open(username);
    }
    else{
        cout << "That username already exists, please try a different one.";
        cout << "Username: ";
        cin >>username;
        newFile.open(username);
    }
    
    cout << "\nHello " << username << ", tell me a little about yourself!" << endl;
    cout << endl;
    cout << "   What is your age: ";
    cin >> age;
    if(age <= 0){
        while(!(age > 0)){
            cout << "\033[31m" << "You've entered a negative number: '" << age << "', please try again." << "\033[0m" << endl;
            cout << "   Input your age: ";
            cin >> age;
        }
    }
    newFile << "Age: " << age << endl;

    cout << "   What is your gender (m/w): ";
    cin >> gender;
    if(!(gender == "m" || gender == "w")){
        while(!(gender == "m") || !(gender == "w")){
            cout << "\033[31m" << "You've entered an invalid answer: '" << gender << "', please try again." << "\033[0m" << endl;
            cout << "   Are you a male or female (m/w): ";
            cin >> gender;
            if(gender == "m" || gender == "w"){
                break;
            }
        }
    }
    newFile << "Gender: " << gender << endl;
    
    cout << "   What is your weight in pounds: ";
    cin >> weight;
    if(weight <= 0){
        while(!(weight > 0)){
            cout << "\033[31m" << "You've entered a negative number: '" << weight << "', please try again." << "\033[0m" << endl;
            cout << "   Input your weight in pounds: ";
            cin >> weight;
        }
    } 
    newFile << "Weight: " << weight << endl;

    cout << "   What is your height separated by a space (ft in): ";
    cin >> ft >> inch;
    if(!(ft > 0) || !(inch > 0)){
        while(!(ft > 0)||!(inch > 0)){
            cout <<  "\033[31m" << "You've entered a negative number for your height, please try again." << "\033[0m" << endl;
            cout << "   Input your height separated by a space (ft in): ";
            cin >> ft >> inch;
        }
    }
    newFile << "Height: " << ft << "' " << inch << endl;

    cout << endl;
    cout << "You have been succesfully registered!" << endl;
    newFile.close();
    cout << endl;
}

void myInfo(){
    ifstream in;
    ofstream out;
    string line;
    string choice;
    int option;
    in.open(username);
    cout << endl;
    cout << "Summary " << endl;
    cout << endl;
    cout << "   Username: " << username << endl;
    while(getline(in,line)){
        cout << "   " <<line << endl;
        }
    in.close();
    
    cout << "\nWould you like to update any of the current information? (y/n): ";
    cin >> choice;
    if(!(choice == "y" || choice == "n")){
        while(!(choice == "y" || choice == "n")){
            cout << "\033[31m" << "You've entered an invalid answer: '" << choice << "', please try again." << "\033[0m" << endl;
            cout << "Would you like to update any of the current information? (y/n) ";
            cin >> choice;
        }
    }
    
    cout << endl;

    if(choice == "y"){
        
        cout << "Which would you like to update? " << endl;
        cout << "   1) Age" << endl;
        cout << "   2) Gender" << endl;
        cout << "   3) Weight" << endl;
        cout << "   4) Height" << endl;

        cout << "Option: ";
        cin >> option;

        switch (option){
            case 1: 
                cout << "Input new age: ";
                cin >> age;
                if(age <= 0){
                    while(!(age > 0)){
                        cout << "\033[31m" << "You've entered a negative number: '" << age << "', please try again." << "\033[0m" << endl;
                        cout << "   Input your age: ";
                        cin >> age;
                    }
                }
                cout << "Age has been updated!";
                break;
            
            case 2:
                cout << "Input new gender: ";
                cin >> gender;
                if(!(gender == "m" || gender == "w")){
                    while(!(gender == "m") || !(gender == "w")){
                        cout << "\033[31m" << "You've entered an invalid answer: '" << gender << "', please try again." << "\033[0m" << endl;
                        cout << "   Are you a male or female (m/w): ";
                        cin >> gender;
                        if(gender == "m" || gender == "w"){
                            break;
                        }
                    }
                 }
                 cout << "Gender has been updated!";
                 break;

            case 3:
                cout << "Input new weight: ";
                cin >> weight;
                if(weight <= 0){
                    while(!(weight > 0)){
                        cout << "\033[31m" << "You've entered a negative number: '" << weight << "', please try again." << "\033[0m" << endl;
                        cout << "   Input your weight in pounds: ";
                        cin >> weight;
                    }
                }
                cout << "Weight has been updated!";
                break;
            
            case 4:
                cout << "Input new height separated by a space (ft in): ";
                cin >> ft >> inch;
                if(!(ft > 0) || !(inch > 0)){
                    while(!(ft > 0)||!(inch > 0)){
                        cout <<  "\033[31m" << "You've entered a negative number for your height, please try again." << "\033[0m" << endl;
                        cout << "   Input your height separated by a space (ft in): ";
                        cin >> ft >> inch;
                    }
                }
                cout << "Height has been updated!";
                break;
            default:
            break;
        }
        out.open(username);
        out << "Age: " << age << endl;
        out << "Gender: " << gender << endl;
        out << "Weight: " << weight << endl;
        out << "Height: " << ft << "' " << inch << endl;
        out.close();

        in.open(username);
        cout << endl;
        cout << "Summary " << endl;
        cout << endl;
        cout << "   Username: " << username << endl;
        while(getline(in,line)){
        cout << "   " <<line << endl;
        }
        in.close();
    }

    
    }

void calculateDCI(){
    double bmr;
    int activity;
    double amr;
    int height = (ft * 12)  + inch;
    
    if(fileExists(username)){
        file.open(username);
    }
    
    cout << "\nDaily Caloric Intake\n";

    cout << endl;

    if(gender == "w"){
        bmr = 65.5 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
    }
    if(gender == "m"){
        bmr = 66 + (6.2 * weight) + (12.7 * height) - (6.76 * age);
    }
    
    cout << "What is your current activity level choose from the options below: " << endl;
    cout << "   1) Sedentary (little or no exercise)" << endl;
    cout << "   2) Lightly active (1 - 3 days per week of exercise)" << endl;
    cout << "   3) Moderately active (3 - 5 days per week of exercise)" << endl;
    cout << "   4) Active (6 - 7 days per week of exercise)" << endl;
    cout << "   5) Very active ( 6 - 7 days per week of INTENSIVE exercise)" << endl;

    cout << "Option: ";
    cin >> activity;
    if(1 > activity || activity > 5){
        while(!(activity >= 1)|| !(activity <= 5)){
            cout << "\033[31m" << "You've entered an invalid answer. Please try again" << "\033[0m" << endl;
            cout << "Option: ";
            cin >> activity;
        }
    }
    switch (activity){
        case 1:
            amr = bmr * 1.2;
            break;
        case 2:
            amr = bmr * 1.375;
            break;
        case 3:
            amr = bmr * 1.55;
            break;
        case 4:
            amr = bmr * 1.725;
            break;
        case 5:
            amr = bmr * 1.9;
            break;
    }
    
    cout << endl;
    cout << "The daily caloric intake you need in order to maintain your current weight is: " << "\033[32m"  << amr << "\033[0m" << endl;
    cout << endl; 
    file.close();
}
void calculateBMI(){
    double bmi;
    int height = (ft * 12)  + inch;
    cout << "\nBody Mass Index (BMI)\n";
    
    cout << endl;
    
    bmi = (weight * 703) / (height*height);
    cout << "   Body mass index: " << bmi <<  endl;

    if(bmi <= 18.5){
        cout << "\n In accordance with your age, weight, and height your body mass index indicates that you are currently ";
        cout << "\033[31m" << "UNDERWEIGHT" << "\033[0m";
    }
    if(18.5 <= bmi && bmi <= 24.9){
        cout << "\n In accordance with your age, weight, and height your body mass index indicates that you are currently ";
        cout << "\033[32m" << "HEALTHY" << "\033[0m";
    }
    if(25.0 <= bmi && bmi <= 29.9 ){
        cout << "\n In accordance with your age, weight, and height your body mass index indicates that you are currently ";
        cout << "\033[31m" << "OVERWEIGHT" << "\033[0m";
    }
    if(bmi >= 30.0){
        cout << "\n In accordance with your age, weight, and height your body mass index indicates that you are currently ";
        cout << "\033[31m" << "OBSESE" << "\033[0m" ;
    }
    cout << endl;
}
void showMenu(){
    int choice;
    cout << endl;
    cout << "Please pick an option from the following: " << endl;
    cout << endl;
    cout << "|-----------------------------------------|" << endl;
    cout << "|      1) Body Mass Index (BMI)           |" << endl;
    cout << "|      2) Daily Caloric Intake (DCI)      |" << endl;
    cout << "|      3) My Info                         |" << endl;
    cout << "|      4) Exit menu                       |" << endl;
    cout << "|-----------------------------------------|" << endl;
    cout << "Option: ";
    cin >> choice;
    cin.clear();

    switch (choice) {
        case 1 :
            calculateBMI();
            break;

        case 2 :
            calculateDCI();
            break;
        
        case 3 :
            myInfo();
            break;
        
        case 4 :
            break;

        default:
            break;
    }
}

int main(){
    string line;
    string ans;
    ifstream in;
    cout << "\nHello welcome to PathToFitness. \n";
    cout << endl;
    cout << "Are you a previous user? (y/n): ";
    cin >> ans;
    if(!(ans == "y" || ans == "n")){
        while(!(ans == "y" || ans == "n")){
            cout << "\033[31m" << "You have entered an invalid answer, please try again." << "\033[0m" << endl;
            cout << "Are you a previous user? (y/n): ";
            cin >> ans;
            if(ans == "y" || ans == "n"){
                break;
            }
        }    
    }
    cout << endl;

    if(ans == "n"){
        registerUser();
    }
    if(ans == "y"){
        cout << "Input your name: ";
        cin >> username;
        if(!(fileExists(username))){
            cerr << "That file does not exist!";
            return 1;
        }
        in.open(username);
        while(getline(in,line)){
            if(line.substr(0,3) == "Age"){
                age = stoi(line.substr(line.find(" ") + 1));
            }
            if(line.substr(0,3) == "Gen"){
                gender = line.substr(line.find(" ") + 1);
            }
            if(line.substr(0,3) == "Hei"){
                ft =stoi(line.substr(line.find(" ") + 1, 11));
                inch = stoi(line.substr(line.find(" ") + 4));
            }
            if(line.substr(0,3) == "Wei"){
                weight = stoi(line.substr(line.find(" ") + 1));
            }
        }
        in.close();
    }
    cout << "\033[96m" <<"\nWelcome " << username << "\033[0m" << endl;

    bool repeat = true;
    char ch;
    while(repeat){
        showMenu();
        cout << endl;
        cout << "Do you want to return to the main menu? (y/n): ";
        cin >> ch;
        if(ch == 'y'){
            continue;
        }
        if(ch == 'n'){
            repeat = false;
        }
        
    }
    
    cout << endl;
    cout  << "Shutting Down.." << endl;;
    return 0;


}