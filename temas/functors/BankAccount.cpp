#include "BankAccount.hpp"

BankAccount::BankAccount(std::string number,tm fecha_){
    id=number;
    fecha.tm_mday=fecha_.tm_mday;
    fecha.tm_mon=fecha_.tm_mon;
    assert(fecha.tm_mon>=1 && fecha.tm_mon<=12);
    fecha.tm_year=fecha_.tm_year;
    validaciones();
}

BankAccount::~BankAccount(){
    id.~string();
    fecha={0};
}

bool operator == (const BankAcccountComparatorById& b1,const BankAcccountComparatorById& b2){
    return (b1.getId().compare(b2.getId())==0);
}

bool operator != (const BankAcccountComparatorById& b1,const BankAcccountComparatorById& b2){
    return (!(b1==b2));
}

bool operator < (const BankAcccountComparatorById& b1,const BankAcccountComparatorById& b2){
    return (b1.getId().compare(b2.getId())<0);
}

bool operator > (const BankAcccountComparatorById& b1,const BankAcccountComparatorById& b2){
    return (b2<b1);
}

bool operator <= (const BankAcccountComparatorById& b1,const BankAcccountComparatorById& b2){
    return (b1 < b2 || b1==b2);
}

bool operator >= (const BankAcccountComparatorById& b1,const BankAcccountComparatorById& b2){
    return (b1 > b2 || b1==b2);
}

bool operator == (const BankAccountComparatorByCreationDate& b1,const BankAccountComparatorByCreationDate& b2){
    return (b1.dia()==b2.dia() && b1.mes()==b2.mes() && b1.ano()==b2.ano());
}

bool operator != (const BankAccountComparatorByCreationDate& b1,const BankAccountComparatorByCreationDate& b2){
    return (!(b1==b2));
}

bool operator < (const BankAccountComparatorByCreationDate& b1,const BankAccountComparatorByCreationDate& b2){
    if(b1.ano()<b2.ano()){
        return true;
    }
    if(b1.ano()==b1.ano() && b1.mes()<b2.mes()){
        return true;
    }
    if(b1.ano()==b1.ano() && b1.mes()==b2.mes() && b1.dia()<b2.dia()){
        return true;
    }

    return false;
}

bool operator > (const BankAccountComparatorByCreationDate& b1,const BankAccountComparatorByCreationDate& b2){
    return (b2<b1);
}

bool operator <= (const BankAccountComparatorByCreationDate& b1,const BankAccountComparatorByCreationDate& b2){
    return (b1<b2 || b1==b2);
}

bool operator >= (const BankAccountComparatorByCreationDate& b1,const BankAccountComparatorByCreationDate& b2){
    return (b1>b2 || b1==b2);
}

void BankAccount::validaciones()
{
		if ((fecha.tm_mon==1 || fecha.tm_mon==3 || fecha.tm_mon==5 || fecha.tm_mon==7 || fecha.tm_mon==8 || fecha.tm_mon==10 || fecha.tm_mon==12) && (fecha.tm_mday < 1 || fecha.tm_mday > 31)) throw BankAccount::Invalida("NO EXISTE EL DIA");
		if ((fecha.tm_mon==4 || fecha.tm_mon==6 || fecha.tm_mon==9 || fecha.tm_mon==11) && (fecha.tm_mday< 1 || fecha.tm_mday > 30)) throw BankAccount::Invalida("NO EXISTE EL DIA");
		if ((fecha.tm_mon==2 && (fecha.tm_year%4==0 && (fecha.tm_year % 400 == 0 || fecha.tm_year % 100 != 0))) && (fecha.tm_mday < 1 || fecha.tm_mday> 29)) throw BankAccount::Invalida("EXISTE EL DIA BISIESTO");
		if ((fecha.tm_mon==2 && !(fecha.tm_year%4==0 && (fecha.tm_year % 400 == 0 || fecha.tm_year % 100 != 0))) && (fecha.tm_mday < 1 || fecha.tm_mday > 28)) throw BankAccount::Invalida("NO EXISTE EL DIA BISIESTO");
}