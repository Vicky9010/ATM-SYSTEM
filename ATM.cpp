#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class ATM{
private:
    string pin;
    double balance;
    const string filename = "atm_data.txt";

public:
  ATM() {
    ifstream file(filename);
    if(file){
        getline(file,pin);
        file >> balance;
        file.close();
    }
    else{
        pin ="9090";
        balance = 1000.0;
        saveToFile();
}
}
  void saveToFile(){
    ofstream file(filename);
    file << pin << endl;
    file << balance << endl;
    file.close();
}

 bool authenticate(string enteredpin){
    return (enteredpin == pin);
}

void checkbalance(){
    cout << "Your balance is: " << balance << endl;
}

void deposit(){
    double depositAmount;
    cout<<"enter the amount to deposit: ";
    cin >> depositAmount;
    if(depositAmount >0) {
        balance += depositAmount;
        cout<< "you have deopsited  : ₹ " << depositAmount <<endl;
        saveToFile();
        cout<< "your updated total balance is: ₹ " << balance <<endl;

    }
    else{
        cout<<"invalid deopisit amount"<<endl;
    }
}

void withdraw(){
    double withdrawAmount;
    cout<<"enter the amount to withdraw: ";
    cin >> withdrawAmount;
    if(withdrawAmount >0 && withdrawAmount <= balance) {
        balance -= withdrawAmount;
        cout<< "you have withdrawn : ₹" << withdrawAmount <<endl;
        saveToFile();
        cout<< "your updated total balance is: ₹" << balance <<endl;

    }
    else if(withdrawAmount > balance){
        cout<<"insufficient amount"<<endl;
    }
    else{
        cout<<"invalid withdraw amount"<<endl;
    }
}
void changepin(){
    string newpin;
    cout<<"enter new pin" <<endl;
    cin>>newpin;
    pin = newpin;
    cout<< "your pine has been changed successfully"<<endl;
    saveToFile();
}
};

int main(){
    ATM atm;
    string enteredpin;
    int choice;
    cout<<"welcone to the ATM"<<endl;
    cout<<"enter your atm pin;" <<endl;
    cin >> enteredpin;
    
    if(!atm.authenticate(enteredpin)){
        cout<<"invalid pin,enter correct pin"<<endl;
        return 0;
    }
    
    do{
        cout << " ATM MENU" << endl;
        cout << "1. check balance "<< endl;
        cout << "2. deposit Money"<<endl;
        cout << "3. withraw Money" << endl;
        cout << "4. change PIN"<< endl;
        cout << "5. exit"<< endl;
        cout << " ENTER YOUR CHOICE"<< endl;
        cin >> (choice);

        switch(choice){
            case 1:
               atm.checkbalance();
               break;

            case 2:
               atm.deposit();
               break;

            case 3:
               atm.withdraw();
               break;   
            
            case 4:
               atm.changepin();
               break;

            case 5:
               cout<<" THANK YOU FOR USING ATM , HAVE A NICE DAY"   <<endl;
               break;

             default:
                cout<< " INVALID CHOICE, PLEASE TRY AGAIN" << endl;
            
        }
    }while(choice != 5);
    return 0;
    }



