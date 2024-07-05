// //C++ program for the converging-pointers
// //data cleanup algorithm
// #include <iostream>


// using namespace std;

// void task(){

//     const int MAXLIST = 50;
//     //maximum list size
//     int n;
//     //max number of data elements in list
//     int data[MAXLIST]; //create the empty list
//     int i;
//     //index variable
//     int left, right;
//     //algorithm pointers into the list
//     int legit;
//     //counts number of legitimate (non-zero)
//     //data values
//     //Get the values for n and the n data items
//     cout << "How many numbers are in the list? ";
//     cout << "(maximum is " << MAXLIST << ") ";
//     cin >> n;
//     i = 0;
//     cout << "Enter the first number: ";
//     cin >> data[i];
//     while (i < n - 1)
//     {
//         i = i + 1;
//         cout << "Enter next number: ";
//         cin >> data[i];
//     }
//     //Set the value of legit, left, and right
//     legit = n - 1;
//     left = 0;
//     right = n - 1;
//     cout << endl;
//     cout << "The original list is" << endl;
//     i = 0;
//     while (i <= legit)
//     {
//         cout << data[i] << " ";
//         i = i + 1;
//     }
//     cout << endl << endl;
//     //move the pointers together,
//     //swapping value at right for 0 at left
//     while (left < right)
//     {
//         if (data[left] != 0)
//             left = left + 1;
//         else{
//             legit = legit - 1;
//             data[left] = data[right];
//             right = right - 1;
//         }
//     }
//     if (data[left] == 0)
//         legit = legit - 1;
//         //final output
//         cout << "The cleaned list is" << endl;
//         i = 0;
//     while (i <= legit)
//     {
//         cout << data[i] << " ";
//         i = i + 1;
//     }
//     cout << endl << endl;

// }


// int main(){


//     task();

//     return 0;
// }





#include <iostream>


int main(){

    int n=45.5;
    cout << n/10;
    cout << n%10;



    return 0;
}