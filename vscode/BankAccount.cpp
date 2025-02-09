#include <iostream>
using namespace std;


void ShowMenu();
void MakeAccount();
void DepositMoney();
void WithdrawMoney();
void ShowAllAccInfo();

enum {MAKE=1, DEPOSIT,WITHDRAW,INQUIRE,EXIT};
typedef struct {
    int accID;
    int balance;
    char cusName[20];
} Account;

Account accArr[100];
int accNum = 0;

int main(){
    int choice;
    while(1){
        ShowMenu();
        cout<<"선택: ";
        cin>>choice;

        switch(choice){
            case MAKE:
                MakeAccount();
                break;
            case DEPOSIT:
                DepositMoney();
                break;
            case WITHDRAW:
                WithdrawMoney();
                break;
            case INQUIRE:
                ShowAllAccInfo();
                break;
            case EXIT:
                return 0;
        
        }

    }
}

void ShowMenu(){
    cout<<"----Menu----"<<endl;
    cout<<"1.계좌개설"<<endl;
    cout<<"2.입금"<<endl;
    cout<<"3.출금"<<endl;
    cout<<"4.계좌정보 전체 출력"<<endl;
    cout<<"5.프로그램 종료"<<endl;
    
}

void MakeAccount(){
    int id;
    int balance;
    char name[20];
    
    cout<<"[계좌개설]"<<endl;
    cout<<"계좌ID:";
    cin>>id;
    cout<<"이름:";
    cin>>name;
    cout<<"입금액:";
    cin>>balance;

    accArr[accNum].accID = id;
    accArr[accNum].balance = balance;
    strcpy(accArr[accNum].cusName,name);
    accNum++;
}

void DepositMoney(){
    int money;
    int id;
    cout<<"계좌ID:";
    cin>>id;
    cout<<"입금액:";
    cin>>money;
    for(int i = 0; i < accNum; i++){
        if(accArr[i].accID == id){
            accArr[i].balance += money;
            cout<<"입금완료"<<endl<<endl;
            return;
        }
    }
    cout<<"유효하지 않은 ID 입니다"<<endl<<endl;

}

void WithdrawMoney(){
    int money;
    int id;
    cout<<"계좌ID:";
    cin>>id;
    cout<<"출금액:";
    cin>>money;
    for(int i = 0; i < accNum; i++){
        if(accArr[i].accID == id){
            if(accArr[i].balance < money){
                cout<<"잔액부족"<<endl<<endl;
                return;
            }
            accArr[i].balance -= money;
            cout<<"출금완료"<<endl<<endl;
            return;
        }
    }
    cout<<"유효하지 않은 ID 입니다"<<endl<<endl;
}

void ShowAllAccInfo(){
    for(int i = 0; i < accNum; i++){
        cout<<"계좌ID: "<<accArr[i].accID<<endl;
        cout<<"이름: "<<accArr[i].cusName<<endl;
        cout<<"잔액: "<<accArr[i].balance<<endl<<endl;
    }
}
