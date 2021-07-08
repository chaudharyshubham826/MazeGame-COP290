#include<iostream>
using namespace std;


class Time
{
public:
        Time(int h, int m, int s);
        void Display12();
        void Display24();



private:
        int cHour; //0 - 23
        int cMinutes;
        int cSeconds;

};

Time::Time(int h, int m, int s): cHour(h), cMinutes(m), cSeconds(s)
{
    
}

void Time::Display12(){

    if(cHour > 12){
        cout<< cHour-12 << ":" << cMinutes << ":" << cSeconds << " pm" << endl;
    }
    else{
        cout<< cHour << ":" << cMinutes << ":" << cSeconds << " am" << endl;
    }
}

void Time::Display24(){
    cout<< cHour << ":" << cMinutes << ":" << cSeconds << endl;
}




int main(int argc, char* argv[]){
    Time time = Time(13, 55, 49);
    // time.Init(13, 55, 49);
    time.Display12();
    time.Display24();

    return 0;
}