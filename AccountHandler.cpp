#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

void AccountHandler::ShowMenu() const{
    cout<<"------MENU------"<<endl;
    cout<<"1. 계좌 개설"<<endl;
    cout<<"2. 입 금"<<endl;
    cout<<"3. 출 금"<<endl;
    cout<<"4. 계좌정보 전체 출력"<<endl;
    cout<<"5. 프로그램 종료"<<endl;
}

void AccountHandler:: MakeAccount(){
    int sel;
    cout<<"[계좌종류입력]"<<endl;
    cout<<"1.보통예금계좌 ";
    cout<<"2.신용신뢰계좌 "<<endl;
    cout<<"선택: ";
    cin>>sel;
    if(sel==NORMAL){
        MakeNormalAccount();
    } else{
        MakeCreditAccount();
    }
}
void AccountHandler:: DepositMoney(){
    int money;
    int id;
    cout<<"[입 금]"<<endl;
    cout<<"계좌ID: "; cin>>id;
    cout<<"입금액: "; cin>>money;

    for(int i = 0; i < accNum; i++){
        if(accArr[i] -> GetAccID() == id){
            accArr[i] -> Deposit(money);
            cout<<"입금 완료"<<endl;
            return;
        }
    }
    cout<<"유효하지 않는 ID입니다"<<endl<<endl;

}
void AccountHandler:: WithdrawMoney(){
    int money;
    int id;
    cout<<"[출 금]"<<endl;
    cout<<"계좌ID: "; cin>>id;
    cout<<"출금액: "; cin>>money;
    for(int i = 0; i < accNum; i++){
        if(accArr[i] -> GetAccID() == id){
            if(accArr[i] -> Withdraw(money) == 0){
                cout<<"잔액 부족"<<endl;
                return;
            }
            cout<<"출금 완료"<<endl<<endl;
            return;
        }
    }
    cout<<"유효하지 않는 ID입니다"<<endl<<endl;
}
void AccountHandler:: ShowAllAccInfo () const{
    for(int i = 0; i < accNum; i++){
        accArr[i] -> ShowAccInfo();
        cout<<endl;
    }
}

void AccountHandler::MakeNormalAccount(){
    int id;
    char name[NAME_LEN];
    int balance;
    int interRate;

    cout<<"[보통예금계좌 개설]"<<endl;
    cout<<"계좌ID: ";cin>>id;
    cout<<"이 름: ";cin>>name;
    cout<<"입금액: ";cin>>balance;
    cout<<"이자율: ";cin>>interRate;
    cout<<endl;

    accArr[accNum++] = new NormalAccount(id,balance,name,interRate);
}

void AccountHandler::MakeCreditAccount(){
    int id;
    char name[NAME_LEN];
    int balance;
    int interRate;
    int creditLevel;

    cout<<"[신용신뢰계좌 개설]"<<endl;
    cout<<"계좌ID: "; cin>>id;
    cout<<"이 름: ";cin>>name;
    cout<<"입금액: ";cin>>balance;
    cout<<"이자율: ";cin>>interRate;
    cout<<"신용등급(1toA, 2toB, 3toC): ";cin>>creditLevel;
    cout<<endl;

    switch(creditLevel){
        case 1:
            accArr[accNum++] = new HighCreditAccount(id,balance,name, interRate,LEVEL_A);
        case 2:
            accArr[accNum++] = new HighCreditAccount(id,balance,name, interRate,LEVEL_B);
        case 3:
            accArr[accNum++] = new HighCreditAccount(id,balance,name, interRate,LEVEL_C);
    
    }
}

AccountHandler:: AccountHandler(): accNum(0){}
AccountHandler:: ~AccountHandler(){
    for(int i = 0; i < accNum; i++){
        delete accArr[i];
    }
}