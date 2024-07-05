#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;


void task1() {

    cout << "Berilgan 5 ta sonning ichidan eng kichigini topuvchi dastur ishga tushdi: " << endl;

    int n, i, m=0, mini=0, c;
    for(int i=1; i<6; i++){
        int m = m + 1;
        cout << m << "-sonni kiriting: " << endl;
        cout << "n="; cin >> n;
        cout << endl;

        if(mini>n) mini = n;

    }

    cout << "Eng kichik son " << mini << " ga teng " << endl << endl;

}

void task2 () {


    cout << "Berilgan 5 ta sonning ichidan eng kattasini topuvchi dastur ishga tushdi: " << endl;

    int n, i, m=0, maxi=0, c;
    for(int i=1; i<6; i++){
        int m = m + 1;
        cout << m << "-sonni kiriting: " << endl;
        cout << "n="; cin >> n;
        cout << endl;

        if(maxi>n) maxi = n;

    }

    cout << "Eng kichik son " << maxi << " ga teng " << endl << endl;
}

/////////////////////////

void task3 () {

    cout << "Ox o'qida belgilangan A nuqtaga kiritilgan B va C nuqtalardan eng yaqinini topuvchi dastur ishga tushdi: " << endl;

    cout << "Nuqtalarning masofasini kiriting: " << endl;

    int A,B,C;

    cout << "A= "; cin >> A;
    cout << "B= "; cin >> B;
    cout << "C= "; cin >> C;

    int resultB = abs(A-B);
    int resultC = abs(A-C);

    if(resultB>resultC) cout << "Eng yaqin nuqta C" << endl;
    else cout << "Eng yaqin nuqta B" << endl;

}
///////////////////////////////////////////////////

void task4 () {
    cout << "kiritilgan haqiqiy sonni natural sonlikka tekshiruvchi dastur ishga tushdi: " << endl;

    cout << "Sonni kiriting: " << endl;
    int n; cin >> n;

    // 1 2 3 4 5 6
    // 1,2
    // 0
    // 45,5/10=4, => 4*10=40 => 45,5%10=5 => 40+5=45 => 45.5-45=0.5>0

    int a=n/10*10;
    a+=n%10;


    if((n-a)==0 && n>0) {


       cout << "Natural son\n";
    }
    else cout << "Natural son emas" << endl;
    
}


///////////////////////////////////

void task5() {

        cout << "Kiritilgan string toifali o'zgaruvchining uzunligini aniqlovchi dastur ishga tushdi" << endl;

        string text;
        cin.ignore();
        getline(cin, text,'\n');

        cout << endl;

        cout << text.length() << endl << endl;
}



void task6 () {
        cout << "Kiritilgan string toifali o'zgaruvchining ichida nechta raqam borligini aniqlovchi dastur ishga tushdi" << endl;

        string text;
        cout << "Matnni kiriting:";
        cin.ignore();
        getline(cin, text);
        cout << endl;
        int i=0, counter=0;
        for(; i<=text.size(); i++) {
            if(isdigit(text[i])) counter+=1;
        }
        cout << counter << endl << endl;

}

int main()
{
    short taskNumber = 1;
    while (taskNumber != 0)
    {
        cout << "Mantiiqiy operatorlar bo'yicha topshiriq nomerini kiriting (1-20) yoki chiqish uchun 0 ni kiriting" << endl;
        cin >> taskNumber;
        switch (taskNumber)

        {
        
        case 1:
        task1();
        break;

        case 2:
        task2();
        break;

        case 3:
        task3();
        break;

        case 4:
        task4();
        break;

        case 5:
        task5();
        break;

        case 6:
        task6();
        break;
/*
        case 7:
        task7();
        break;

        case 8:
        task8();
        break;

        case 9:
        task9();
        break;

        case 10:
        task10();
        break;

        case 11:
        task11();
        break;

        case 12:
        task12();
        break;

        case 13:
        task13();
        break;

        case 14:
        task14();
        break;

        case 15:
        task15();
        break;

        case 16:
        task16();
        break;

        case 17:
        task17();
        break;

        case 18:
        task18();
        break;

        case 19:
        task19();
        break;

        case 20:
        task20();
        break;
       

        case 21:
            task21();
            break;

        case 22:
            task22();
            break;
        */

        default:
            cout << "Topshiriq bajarildi" << endl;
        }
    }
}