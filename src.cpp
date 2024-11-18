#include<iostream>
#include <cstdlib>
#include <time.h> 
using namespace ::std;

class Process {
public:

    int PID;        // Process ID
    int duration;   // CPU time required
    int R1, R2, R3; // Resource requirements
    int inUse;

    // Constructor
    Process(int id, int d, int r1, int r2, int r3,int i_u){
        PID = id;  
        duration= d;
        R1 = r1;
        R2 = r2;
        R3 = r3;
        inUse=i_u=0;


    }
};

int main (){
    srand(static_cast<unsigned>(time(0))); /* initialize random seed: */

    const int size = 3;
    int availableResources[size] = {10, 10, 10}; // initial avaliable resource
    int totalTime = 30;

    Process P1 (1, 4, 2, 3, 5, 0);
    Process P2 (2, 2, 3, 4, 2, 0);
    Process P3 (3, 5, 5, 3, 3, 0);
    Process arrOfProcesses[size]=  {P1,P2,P3};

    for (int i= 0; i < 3;i++){
        int a = 0;
        cout << "Enter Duration of Process"<<arrOfProcesses[i].PID<<":";
        cin >> a;
        arrOfProcesses[i].duration = a;
    } 


    cout<<"P1("<<arrOfProcesses[0].duration<<","<<arrOfProcesses[0].R1<<","<<arrOfProcesses[0].R2<<","<<arrOfProcesses[0].R3<<")"<<endl;
    cout<<"P2("<<arrOfProcesses[1].duration<<","<<arrOfProcesses[1].R1<<","<<arrOfProcesses[1].R2<<","<<arrOfProcesses[1].R3<<")"<<endl;
    cout<<"P3("<<arrOfProcesses[2].duration<<","<<arrOfProcesses[2].R1<<","<<arrOfProcesses[2].R2<<","<<arrOfProcesses[2].R3<<")"<<endl;

    cout<<"Available Resource : ("<<availableResources[0]<<","<<availableResources[1]<<","<<availableResources[2]<<")"<<endl;

    int pid = 4;
    cout<<"----------------------------------------------------------------------------------"<<endl;

    for (int i = 1 ; i < totalTime+1; i++){        
        // Display the content of the priority queue
        cout << "Time: " << i <<endl;
        cout<<"Priority Queue: F(";
        for (int i = 0; i < 3 ;i++){
            cout << "P" << arrOfProcesses[i].PID << ":" << arrOfProcesses[i].duration ;

            if(i!=2) {
                cout << ",";
            }
        }

        cout << "), ";
        cout<<"Available resources : R(" << availableResources[0] << "," << availableResources[1] << "," << availableResources[2] << ")"<<endl;

        // Sort the priority queue()
        // for each processes in priority queue compare the durations

        // Execution of Priority queue 
        for (int i = 0; i < size; i++) {

            for (int i = 0; i < size - 1; i++) {
                for (int j = i + 1; j < size; j++) {
                    if (arrOfProcesses[i].duration > arrOfProcesses[j].duration) {
                        swap(arrOfProcesses[i], arrOfProcesses[j]);
                    }

                }
            }

            if (arrOfProcesses[i].inUse == 0) {

                
                if (arrOfProcesses[i].R1 <= availableResources[0] &&
                    arrOfProcesses[i].R2 <= availableResources[1] &&
                    arrOfProcesses[i].R3 <= availableResources[2]) {

                    // check the avaliable resource for each processes in priority queue
                    availableResources[0] = availableResources[0] - arrOfProcesses[i].R1;
                    availableResources[1] = availableResources[1] - arrOfProcesses[i].R2;
                    availableResources[2] = availableResources[2] - arrOfProcesses[i].R3;
                    arrOfProcesses[i].inUse = 1;
                    arrOfProcesses[i].duration--;
                    cout << "Recently executed process : P" << arrOfProcesses[i].PID << endl;
                }
            }

            else if (arrOfProcesses[i].inUse == 1) {

                if (arrOfProcesses[i].duration > 0) {
                    arrOfProcesses[i].duration--;
                    //cout << "P" << arrOfProcesses[i].PID << " is running" << endl;
                }

                // checking priority queue for finished processes()
                else if (arrOfProcesses[i].duration <= 0) {
                    cout << "Recently finished process : P" << arrOfProcesses[i].PID<< endl;
                    // print RecentlyFinishedProcess as arrOfProcess[i];

                    availableResources[0] = availableResources[0] + arrOfProcesses[i].R1;
                    availableResources[1] = availableResources[1] + arrOfProcesses[i].R2;// avalibeleResource = avalibeleResource + arrOfProcess[i].resource
                    availableResources[2] = availableResources[2] + arrOfProcesses[i].R3;

                    arrOfProcesses[i].inUse = 0;
                    arrOfProcesses[i].PID = pid;
                    pid++;

                    arrOfProcesses[i].duration = rand() % 7 + 1; // set the arrOfProcess[i] as another random process (we can make a function called makeRand(arrOfProcess[i]))
                    arrOfProcesses[i].R1 = rand() % 7 + 1;
                    arrOfProcesses[i].R2 = rand() % 7 + 1;
                    arrOfProcesses[i].R3 = rand() % 7 + 1;

                    /*cout<<"New Process: "<<
                    "P" << arrOfProcesses[i].PID<<
                    "("<<arrOfProcesses[i].duration<<
                    ","<<arrOfProcesses[i].R1<<
                    ","<<arrOfProcesses[i].R2<<
                    ","<<arrOfProcesses[i].R3<<")"<<endl;*/
                }
            }

        }
        cout<<"----------------------------------------------------------------------------------"<<endl;
    }  
    return 0;
}