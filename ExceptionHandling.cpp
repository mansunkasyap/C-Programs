//
//  main.cpp
//  exception-handling
//
//  Created by Ayush kanyal on 13/08/24.
//

#include <iostream>
#include "cmath"
using namespace std;

//int  divide(int a, int b)
//{
//    try {
//        return a/b;
//    } catch () {
//
//    }
//}


///*Create a custom exception class NegativeNumberException that is thrown when a negative number is used in a function that calculates the square root. Write a function calculateSquareRoot that throws this e*/xception when it encounters a negative input

class NegativeNumberException : public exception
{
private:
    string msg;
public:
    
    NegativeNumberException(const string msg){
        this -> msg = msg;
    }
//    string getMsg(){
//        return this->msg;
//    }
    const char * what() const noexcept override{
        return  this -> msg.c_str();
    }
};

class SquareRoot : public NegativeNumberException
{
private:
    int number;
public:
    
    SquareRoot(int number):NegativeNumberException("Negative Number Exception")
    {
        this ->  number = number;
    }
    
    int  calculateSquareRoot()
    {
        try{
            if(this->number > 0) {
                return (int)sqrt(this ->number);
            }
            throw NegativeNumberException("NegativeNumberNotAllowed");
        }catch(NegativeNumberException c){
            cout<< c.what()<<endl;
        }
        return 0;
    }
    
};



int main(int argc, const char * argv[]) {
//    int a = 0 , b = 0;
//    cin>>a>>b;
//    try{
//        if(b==0)
//        {
//            throw 9;
//        }
//        int d = a/b;
//        cout<<d<< endl;
//    }
//    catch(int a){
//        cout<<a<<endl;
//    }
    SquareRoot sq1(-16);

    
        cout<< sq1.calculateSquareRoot();
    
    return 0;
}
