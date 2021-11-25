#include <iostream>
#include <string>
#include <time.h>
#include "TrafficControl.h"
#include "TrafficManagement.h"

#define PRINT_DEBUG
using namespace std;

void test1(TrafficLight &r1_a, TrafficLight &r1_b, TrafficLight &r2_a, TrafficLight &r2_b )
{
    if(r1_a.getStatus() != r1_b.getStatus()){
        cout << "TEST 1 Failed" << endl;
        exit(EXIT_FAILURE);
    }
}

int main()
{
    TrafficLight R1_A, R1_B;
    TrafficLight R2_A, R2_B;
    TrafficFlow obj;
    time_t st;
    ControlState previous_state = INIT;
    ControlState curr_state = INIT;
    
    string str_ControlState[4] = { "INIT", "RED", "GREEN", "AMBER" };
    string str_LightColor[3] = { "RED", "GREEN", "AMBER" };
    
#ifdef PRINT_DEBUG
    cout << "State    |    Road#1 Right Side (A)    |    Road#1 Right Side (B)    |    Road#2 Right Side (A)    |    Road#2 Right Side (B)\n";
#endif
    
    while(1)
    {
        curr_state = obj.stateMachine(R1_A, R1_B, R2_A, R2_B);
        test1(R1_A, R1_B, R2_A, R2_B);
#ifdef PRINT_DEBUG
        if (curr_state != previous_state)
        {
            st = time(NULL);
            cout << str_ControlState[(int)previous_state] << "    |    " <<
            str_LightColor[(int)R1_A.getStatus()] << "            |        " <<
            str_LightColor[(int)R1_B.getStatus()] << "        |        " <<
            str_LightColor[(int)R2_A.getStatus()] << "        |        " <<
            str_LightColor[(int)R2_B.getStatus()] << "        |        " << asctime(localtime(&st))<<endl;
            previous_state = curr_state;
        }
#endif
    }
}
