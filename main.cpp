#include <bits/stdc++.h>
using namespace std;

//Moath Wajeeh AbdAlbaqi 1210125 sec 1........


struct qnode{
    char name[10];
    int arraival_time;
    int burst_time;
    int comesbackafter;
    int priority;
    int index;
    int remainingtime;
    int remainingpri;
    int finishtime;
    int fixedarrival;
};
typedef struct qnode* node;


void processes_creation(node processes[6]);
void del(vector <node>&,string);
bool comparator(node& x,node& y);
bool comparatorfortimer(node x,node y);
bool comparatorforpriority(node x,node y);
void FCFS(node[],vector<node> readyq,vector<node> waitingq,stack<node> cpu);
void SJF(node processes[7],vector<node> readyq,vector<node> waitingq,stack<node> cpu);
void SRTF(node processes[7],vector<node> readyq,vector<node> waitingq,stack<node> cpu);
void RR(node processes[7],vector<node> readyq,vector<node> waitingq,stack<node> cpu);
void PrePS(node processes[7],vector<node> readyq,vector<node> waitingq,stack<node> cpu);
void NPrePS(node processes[7],vector<node> readyq,vector<node> waitingq,stack<node> cpu);


int main() {

    stack <node> cpu;
    vector <node> readyq,waitingq;

    node processes [7];

    cout<<"\n----------Scheduling Algorithms Simulator------------";
    int key=-1;
    while(key !=7){
        cout<<"\nChoose one of these:\n1-First Come First Served.\n2-Shortest Job First.\n3-Shortest Remaining Time First.\n4-Round Robin, with q = 5.\n5-Preemptive Priority Scheduling, with aging every 5 seconds in ready q.\n6-Non-Preemptive Priority Scheduling, with aging every 5 seconds in ready q.\n7-Exit.\n";
        cin>>key;
        switch (key) {
            case 1:processes_creation(processes);FCFS(processes,readyq,waitingq,cpu);cout<<"\n";break;
            case 2:processes_creation(processes);SJF(processes,readyq,waitingq,cpu);cout<<"\n";break;
            case 3:processes_creation(processes);SRTF(processes,readyq,waitingq,cpu);cout<<"\n";break;
            case 4:processes_creation(processes);RR(processes,readyq,waitingq,cpu);cout<<"\n";break;
            case 5:processes_creation(processes);PrePS(processes,readyq,waitingq,cpu);cout<<"\n";break;
            case 6:processes_creation(processes);NPrePS(processes,readyq,waitingq,cpu);cout<<"\n";break;
            case 7:cout<<"Good Bye!";break;
            default:cout<<"Wrong choice.\n";
        }
    }


    return 0;
}

void processes_creation(node processes[6]){
    processes[0]=(node)(malloc(sizeof(struct qnode)));strcpy(processes[0]->name,"p1");processes[0]->arraival_time=0;processes[0]->burst_time=10;processes[0]->comesbackafter=2;processes[0]->priority=3;processes[0]->index=0;processes[0]->remainingtime=0;processes[0]->remainingpri=3;processes[0]->finishtime=0;processes[0]->fixedarrival=0;
    processes[1]=(node)(malloc(sizeof(struct qnode)));strcpy( processes[1]->name,"p2"); processes[1]->arraival_time=1; processes[1]->burst_time=8; processes[1]->comesbackafter=4; processes[1]->priority=2;processes[1]->index=1;processes[1]->remainingtime=0;processes[1]->remainingpri=2;processes[1]->finishtime=0;processes[1]->fixedarrival=1;
    processes[2]=(node)(malloc(sizeof(struct qnode)));strcpy(processes[2]->name,"p3");processes[2]->arraival_time=3;processes[2]->burst_time=14;processes[2]->comesbackafter=6;processes[2]->priority=3;processes[2]->index=2;processes[2]->remainingtime=0;processes[2]->remainingpri=3;processes[2]->finishtime=0;processes[2]->fixedarrival=3;
    processes[3]=(node)(malloc(sizeof(struct qnode)));strcpy(processes[3]->name,"p4");processes[3]->arraival_time=4;processes[3]->burst_time=7;processes[3]->comesbackafter=8;processes[3]->priority=1;processes[3]->index=3;processes[3]->remainingtime=0;processes[3]->remainingpri=1;processes[3]->finishtime=0;processes[3]->fixedarrival=4;
    processes[4]=(node)(malloc(sizeof(struct qnode)));strcpy( processes[4]->name,"p5"); processes[4]->arraival_time=6; processes[4]->burst_time=5; processes[4]->comesbackafter=3; processes[4]->priority=0;processes[4]->index=4;processes[4]->remainingtime=0;processes[4]->remainingpri=0;processes[4]->finishtime=0;processes[4]->fixedarrival=6;
    processes[5]=(node)(malloc(sizeof(struct qnode)));strcpy(processes[5]->name,"p6");processes[5]->arraival_time=7;processes[5]->burst_time=4;processes[5]->comesbackafter=6;processes[5]->priority=1;processes[5]->index=5;processes[5]->remainingtime=0;processes[5]->remainingpri=1;processes[5]->finishtime=0;processes[5]->fixedarrival=7;
    processes[6]=(node)(malloc(sizeof(struct qnode)));strcpy(processes[6]->name,"p7");processes[6]->arraival_time=8;processes[6]->burst_time=6;processes[6]->comesbackafter=9;processes[6]->priority=2;processes[6]->index=6;processes[6]->remainingtime=0;processes[6]->remainingpri=2;processes[6]->finishtime=0;processes[6]->fixedarrival=8;
}


void FCFS(node processes[7],vector<node> readyq,vector<node> waitingq,stack<node> cpu){
    int checkburst=0;
    int checkwait[7]={-1};
    for (int f=0;f<7;f++)checkwait[f]=-1;
    vector <node> temp;
    cout<<"0->";
    double forwaitingtime[7]={0};

    for(int i=0;i<=200;i++){
        for (int j=0;j<7;j++) { //first time ready queue.....
            if (processes[j]->arraival_time == i) {
                readyq.push_back(processes[j]);
            }
        }

        if(!cpu.empty()){if(checkburst != cpu.top()->burst_time){checkburst++;}

        }
        if(!cpu.empty()){//checking burst time
            if(checkburst == cpu.top()->burst_time){cout<<"("<<cpu.top()->name<<")->"<<i<<"->";
                waitingq.push_back(cpu.top());waitingq.back()->finishtime=i;
                cpu.pop();
                checkburst=0;
            }
        }
        if(cpu.empty()){//if there is not a processes in the cpu, let another process in.

            if(!readyq.empty()){
                cpu.push(readyq.front());
                readyq.erase(readyq.begin());
                //this is to check the waiting time ....
                if(strcmp(cpu.top()->name,"p1")==0)forwaitingtime[0]+=((i)-cpu.top()->arraival_time);
                else if(strcmp(cpu.top()->name,"p2")==0)forwaitingtime[1]+=((i)-cpu.top()->arraival_time);
                else if(strcmp(cpu.top()->name,"p3")==0)forwaitingtime[2]+=((i)-cpu.top()->arraival_time);
                else if(strcmp(cpu.top()->name,"p4")==0)forwaitingtime[3]+=((i)-cpu.top()->arraival_time);
                else if(strcmp(cpu.top()->name,"p5")==0)forwaitingtime[4]+=((i)-cpu.top()->arraival_time);
                else if(strcmp(cpu.top()->name,"p6")==0)forwaitingtime[5]+=((i)-cpu.top()->arraival_time);
                else if(strcmp(cpu.top()->name,"p7")==0)forwaitingtime[6]+=((i)-cpu.top()->arraival_time);
            }
        }

        if(!waitingq.empty()){
            temp = waitingq;
            for (int j=0;j<temp.size();j++){
                if(strcmp(temp[j]->name,"p1")==0)checkwait[0]++;
                else if(strcmp(temp[j]->name,"p2")==0)checkwait[1]++;
                else if(strcmp(temp[j]->name,"p3")==0)checkwait[2]++;
                else if(strcmp(temp[j]->name,"p4")==0)checkwait[3]++;
                else if(strcmp(temp[j]->name,"p5")==0){checkwait[4]++;}
                else if(strcmp(temp[j]->name,"p6")==0)checkwait[5]++;
                else checkwait[6]++;

            }


            //now the wait time in waiting queue is ready, now i need to check if any process needs to leave.
            for (int j=0;j<temp.size();j++){

                if(strcmp(temp[j]->name,"p1")==0) {if(checkwait[0]>=2){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p1");checkwait[0]=-1;}}
                else if(strcmp(temp[j]->name,"p2")==0){ if(checkwait[1]>=4){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p2");checkwait[1]=-1; }}
                else if(strcmp(temp[j]->name,"p3")==0){ if(checkwait[2]>=6){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p3");checkwait[2]=-1;}}
                else if(strcmp(temp[j]->name,"p4")==0){ if(checkwait[3]>=8){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p4");checkwait[3]=-1;}}
                else if(strcmp(temp[j]->name,"p5")==0){ if(checkwait[4]>=3){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p5");checkwait[4]=-1;}}
                else if(strcmp(temp[j]->name,"p6")==0){ if(checkwait[5]>=6){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p6");checkwait[5]=-1;}}
                else { if(checkwait[6]>=9){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p7");checkwait[6]=-1;}}

            }
        }
        if(i==200){
            cout<<"("<<cpu.top()->name<<")->"<<i;
        }
    }

    double waitingavg=0;
    for(int f=0;f<7;f++)waitingavg += forwaitingtime[f];
    waitingavg /= 7.0;
    cout<<"\nAverage waiting time="<<waitingavg<<"."<<endl;
    double turnaroundavg=0;
    for(int f=0;f<7;f++){
        turnaroundavg+=(processes[f]->finishtime - processes[f]->fixedarrival+1);
    }
    turnaroundavg/=7.0;
    cout<<"Average turnaround time="<<turnaroundavg<<".";
}


void SJF(node processes[7],vector<node> readyq,vector<node> waitingq,stack<node> cpu){

    int checkburst=0;
    int checkwait[7];
    for (int f=0;f<7;f++)checkwait[f]=-1;

    vector <node> temp;
    cout<<"0->";
    int forwaitingtime[7]={0};
    for(int i=0;i<=200;i++){
        for (int j=0;j<7;j++) { //first time ready queue.....
            if (processes[j]->arraival_time == i) {
                readyq.push_back(processes[j]);
            }
        }

        if(!cpu.empty()){if(checkburst != cpu.top()->burst_time){checkburst++;}}
        if(!cpu.empty()){//checking burst time
            if(checkburst == cpu.top()->burst_time){cout<<"("<<cpu.top()->name<<")->"<<i<<"->";
                waitingq.push_back(cpu.top());waitingq.back()->finishtime=i;
                cpu.pop();
                checkburst=0;
            }

        }

        if(!waitingq.empty()){
            temp = waitingq;
            for (int j=0;j<temp.size();j++){
                if(strcmp(temp[j]->name,"p1")==0)checkwait[0]++;
                else if(strcmp(temp[j]->name,"p2")==0)checkwait[1]++;
                else if(strcmp(temp[j]->name,"p3")==0)checkwait[2]++;
                else if(strcmp(temp[j]->name,"p4")==0)checkwait[3]++;
                else if(strcmp(temp[j]->name,"p5")==0){checkwait[4]++;}
                else if(strcmp(temp[j]->name,"p6")==0)checkwait[5]++;
                else checkwait[6]++;

            }


            //now the wait time in waiting queue is ready, now i need to check if any process needs to leave.
            for (int j=0;j<temp.size();j++){

                if(strcmp(temp[j]->name,"p1")==0) {if(checkwait[0]>=2){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p1");checkwait[0]=-1;}}
                else if(strcmp(temp[j]->name,"p2")==0){ if(checkwait[1]>=4){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p2");checkwait[1]=-1; }}
                else if(strcmp(temp[j]->name,"p3")==0){ if(checkwait[2]>=6){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p3");checkwait[2]=-1;}}
                else if(strcmp(temp[j]->name,"p4")==0){ if(checkwait[3]>=8){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p4");checkwait[3]=-1;}}
                else if(strcmp(temp[j]->name,"p5")==0){ if(checkwait[4]>=3){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p5");checkwait[4]=-1;}}
                else if(strcmp(temp[j]->name,"p6")==0){ if(checkwait[5]>=6){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p6");checkwait[5]=-1;}}
                else { if(checkwait[6]>=9){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p7");checkwait[6]=-1;}}

            }
        }
        if(cpu.empty()){//if there is not a processes in the cpu, let another process in.

            if(!readyq.empty()){
                //before adding the first element to cpu, we have to sort the q. to get the shortest job first.
                sort(readyq.begin(),readyq.end(),comparator);
                cpu.push(readyq.front());
                readyq.erase(readyq.begin());
            }
        }

        if(!readyq.empty()){
            for(int f=0;f<readyq.size();f++){
                if(strcmp(readyq[f]->name,"p1")==0 && i<10)forwaitingtime[0]++;
                    // else if(strcmp(readyq[f]->name,"p2")==0)forwaitingtime[1]++;
                    // else if(strcmp(readyq[f]->name,"p3")==0)forwaitingtime[2]++;
                    // else if(strcmp(readyq[f]->name,"p4")==0)forwaitingtime[3]++;
                else if(strcmp(readyq[f]->name,"p5")==0 && i<199)forwaitingtime[4]++;
                else if(strcmp(readyq[f]->name,"p6")==0&& i<194)forwaitingtime[5]++;
                else if(strcmp(readyq[f]->name,"p7")==0)forwaitingtime[6]++;
            }
        }

        if(i==200){
            cout<<"("<<cpu.top()->name<<")->"<<i;
        }
    }
    double waitingavg=0;
    for(int f=0;f<7;f++)waitingavg += forwaitingtime[f];
    waitingavg /= 7.0;
    cout<<"\nAverage waiting time="<<waitingavg<<"."<<endl;
    double turnaroundavg=0;
    for(int f=0;f<7;f++){
        turnaroundavg+=(processes[f]->finishtime - processes[f]->fixedarrival+1);
    }
    turnaroundavg/=7.0;
    cout<<"Average turnaround time="<<turnaroundavg<<".";
}


void SRTF(node processes[7],vector<node> readyq,vector<node> waitingq,stack<node> cpu){
    int checkburst[7]={0};
    int checkwait[7];
    for(int i=0;i<7;i++)checkwait[i]=-1;
    vector<node> temp;

    node checktoprint;
    checktoprint=processes[6];
    int forwaitingtime[7]={0};
    int flag=0;
    for(int i=0;i<=200;i++){

        for (int j=0;j<7;j++) { //first time ready queue.....
            if (processes[j]->arraival_time == i) {
                readyq.push_back(processes[j]);
            }
        }

        if(cpu.empty()){//if there is no processes in the cpu, let another process in.
            //one
            if(!readyq.empty()){
                //before adding the first element to cpu, we have to sort the q. to get the shortest job first.
                sort(readyq.begin(),readyq.end(),comparatorfortimer);
                cpu.push(readyq.front());
                readyq.erase(readyq.begin());flag=1;
            }
        }


        if(flag==1){
            if(strcmp(cpu.top()->name,"p1")==0)forwaitingtime[0]+=((i)-cpu.top()->arraival_time);
            else if(strcmp(cpu.top()->name,"p2")==0)forwaitingtime[1]+=((i)-cpu.top()->arraival_time-1);
            else if(strcmp(cpu.top()->name,"p3")==0)forwaitingtime[2]+=((i)-cpu.top()->arraival_time-1);
            else if(strcmp(cpu.top()->name,"p4")==0)forwaitingtime[3]+=((i)-cpu.top()->arraival_time-1);
            else if(strcmp(cpu.top()->name,"p5")==0)forwaitingtime[4]+=((i)-cpu.top()->arraival_time-1);
            else if(strcmp(cpu.top()->name,"p6")==0)forwaitingtime[5]+=((i)-cpu.top()->arraival_time-1);
            else if(strcmp(cpu.top()->name,"p7")==0)forwaitingtime[6]+=((i)-cpu.top()->arraival_time);flag=0;
        }

        if(!readyq.empty()){
            sort(readyq.begin(),readyq.end(), comparatorfortimer);
            if(!cpu.empty()){//two...
                if(strcmp(cpu.top()->name,"p1")==0){if((readyq.front()->burst_time)<(cpu.top()->burst_time-checkburst[0])){readyq.push_back(cpu.top());readyq.back()->remainingtime=checkburst[0];cpu.pop();cpu.push(readyq.front());readyq.erase(readyq.begin());flag=1;}}
                else if(strcmp(cpu.top()->name,"p2")==0){if((readyq.front()->burst_time)<(cpu.top()->burst_time-checkburst[1])){readyq.push_back(cpu.top());readyq.back()->remainingtime=checkburst[1];cpu.pop();cpu.push(readyq.front());readyq.erase(readyq.begin());flag=1;}}
                else if(strcmp(cpu.top()->name,"p3")==0){if((readyq.front()->burst_time)<(cpu.top()->burst_time-checkburst[2])){readyq.push_back(cpu.top());readyq.back()->remainingtime=checkburst[2];cpu.pop();cpu.push(readyq.front());readyq.erase(readyq.begin());flag=1;}}
                else if(strcmp(cpu.top()->name,"p4")==0){if((readyq.front()->burst_time)<(cpu.top()->burst_time-checkburst[3])){readyq.push_back(cpu.top());readyq.back()->remainingtime=checkburst[3];cpu.pop();cpu.push(readyq.front());readyq.erase(readyq.begin());flag=1;}}
                else if(strcmp(cpu.top()->name,"p5")==0){if((readyq.front()->burst_time)<(cpu.top()->burst_time-checkburst[4])){readyq.push_back(cpu.top());readyq.back()->remainingtime=checkburst[4];cpu.pop();cpu.push(readyq.front());readyq.erase(readyq.begin());flag=1;}}
                else if(strcmp(cpu.top()->name,"p6")==0){if((readyq.front()->burst_time)<(cpu.top()->burst_time-checkburst[5])){readyq.push_back(cpu.top());readyq.back()->remainingtime=checkburst[5];cpu.pop();cpu.push(readyq.front());readyq.erase(readyq.begin());flag=1;}}
                else if(strcmp(cpu.top()->name,"p7")==0){if((readyq.front()->burst_time)<(cpu.top()->burst_time-checkburst[6])){readyq.push_back(cpu.top());readyq.back()->remainingtime=checkburst[6];cpu.pop();cpu.push(readyq.front());readyq.erase(readyq.begin());flag=1;}}

            }
        }


        if(checktoprint!=cpu.top()){
            checktoprint=cpu.top();
            cout<<i<<"->("<<cpu.top()->name<<")->";
        }

        if(!cpu.empty()) {//checking burst time

            if (strcmp(cpu.top()->name, "p1") == 0)checkburst[0]++;
            else if (strcmp(cpu.top()->name, "p2") == 0)checkburst[1]++;
            else if (strcmp(cpu.top()->name, "p3") == 0)checkburst[2]++;
            else if (strcmp(cpu.top()->name, "p4") == 0)checkburst[3]++;
            else if (strcmp(cpu.top()->name, "p5") == 0)checkburst[4]++;
            else if (strcmp(cpu.top()->name, "p6") == 0){checkburst[5]++;}
            else if (strcmp(cpu.top()->name, "p7") == 0){checkburst[6]++;}
        }

        if(!cpu.empty()){
            if(strcmp(cpu.top()->name,"p1")==0){if(checkburst[0] == cpu.top()->burst_time){checkburst[0]=0;waitingq.push_back(cpu.top());cpu.pop();flag=0;}}
            else if(strcmp(cpu.top()->name,"p2")==0){if(checkburst[1] == cpu.top()->burst_time){checkburst[1]=0;waitingq.push_back(cpu.top());cpu.pop();flag=0;}}
            else if(strcmp(cpu.top()->name,"p3")==0){if(checkburst[2] == cpu.top()->burst_time){checkburst[2]=0;waitingq.push_back(cpu.top());cpu.pop();flag=0;}}
            else if(strcmp(cpu.top()->name,"p4")==0){if(checkburst[3] == cpu.top()->burst_time){checkburst[3]=0;waitingq.push_back(cpu.top());cpu.pop();flag=0;}}
            else if(strcmp(cpu.top()->name,"p5")==0){if(checkburst[4] == cpu.top()->burst_time){checkburst[4]=0;waitingq.push_back(cpu.top());cpu.pop();flag=0;}}
            else if(strcmp(cpu.top()->name,"p6")==0){if(checkburst[5] == cpu.top()->burst_time){checkburst[5]=0;waitingq.push_back(cpu.top());cpu.pop();flag=0;}}
            else if(strcmp(cpu.top()->name,"p7")==0){if(checkburst[6] == cpu.top()->burst_time){checkburst[6]=0;waitingq.push_back(cpu.top());cpu.pop();flag=0;}}
        }
        //this is to check if the processes must leave the waiting q and return back to ready q....
        if(!waitingq.empty()){
            temp = waitingq;
            for (int j=0;j<temp.size();j++){
                if(strcmp(temp[j]->name,"p1")==0)checkwait[0]++;
                else if(strcmp(temp[j]->name,"p2")==0)checkwait[1]++;
                else if(strcmp(temp[j]->name,"p3")==0)checkwait[2]++;
                else if(strcmp(temp[j]->name,"p4")==0)checkwait[3]++;
                else if(strcmp(temp[j]->name,"p5")==0){checkwait[4]++;}
                else if(strcmp(temp[j]->name,"p6")==0)checkwait[5]++;
                else checkwait[6]++;
            }


            //now the wait time in waiting queue is ready, now i need to check if any process needs to leave.
            for (int j=0;j<temp.size();j++){

                if(strcmp(temp[j]->name,"p1")==0) {if(checkwait[0]>=2){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p1");checkwait[0]=-1;}}
                else if(strcmp(temp[j]->name,"p2")==0){ if(checkwait[1]>=4){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p2");checkwait[1]=-1; }}
                else if(strcmp(temp[j]->name,"p3")==0){ if(checkwait[2]>=6){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p3");checkwait[2]=-1;}}
                else if(strcmp(temp[j]->name,"p4")==0){ if(checkwait[3]>=8){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p4");checkwait[3]=-1;}}
                else if(strcmp(temp[j]->name,"p5")==0){ if(checkwait[4]>=3){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p5");checkwait[4]=-1;}}
                else if(strcmp(temp[j]->name,"p6")==0){ if(checkwait[5]>=6){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p6");checkwait[5]=-1;}}
                else { if(checkwait[6]>=9){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p7");checkwait[6]=-1;}}
            }
        }

        if(i==200)cout<<i;
    }
    double waitingavg=0;
    for(int f=0;f<7;f++)waitingavg += forwaitingtime[f];
    waitingavg /= 7.0;
    cout<<"\nAverage waiting time="<<waitingavg<<"."<<endl;
    double turnaroundavg=0;
    for (int f=0;f<7;f++)forwaitingtime[f] += processes[f]->burst_time;
    for(int f=0;f<7;f++)turnaroundavg += forwaitingtime[f];
    turnaroundavg/=7.0;
    cout<<"Average turnaround time="<<turnaroundavg<<".";
}


void RR(node processes[7],vector<node> readyq,vector<node> waitingq,stack<node> cpu){
    int q=5;
    int checkburst[7]={0};
    int checkwait[7];
    for(int i=0;i<7;i++)checkwait[i]=-1;
    vector<node> temp;

    node checktoprint;
    checktoprint=processes[6];
    int forwaitingtime[7]={0};
    int flag=0;
    for(int i=0;i<=200;i++){

        for (int j=0;j<7;j++) { //first time ready queue.....
            if (processes[j]->arraival_time == i) {
                readyq.push_back(processes[j]);
            }
        }

        if(cpu.empty()){//if there is no processes in the cpu, let another process in.

            if(!readyq.empty()){

                cpu.push(readyq.front());
                readyq.erase(readyq.begin());
                flag=1;
            }
        }
        if(!readyq.empty()){
            for(int f=0;f<readyq.size();f++){
                if(strcmp(readyq[f]->name,"p1")==0 &&i<191)forwaitingtime[0]++;
                else if(strcmp(readyq[f]->name,"p2")==0&&i<180)forwaitingtime[1]++;
                else if(strcmp(readyq[f]->name,"p3")==0&&i<186)forwaitingtime[2]++;
                else if(strcmp(readyq[f]->name,"p4")==0)forwaitingtime[3]++;
                else if(strcmp(readyq[f]->name,"p5")==0&&i<175)forwaitingtime[4]++;
                else if(strcmp(readyq[f]->name,"p6")==0&&i<195)forwaitingtime[5]++;
                else if(strcmp(readyq[f]->name,"p7")==0&&i<181)forwaitingtime[6]++;
            }
        }

        if(checktoprint!=cpu.top()&&i!=200){
            checktoprint=cpu.top();
            cout<<i<<"->("<<cpu.top()->name<<")->";
        }

        if(!cpu.empty()) {//checking burst time
            if (strcmp(cpu.top()->name, "p1") == 0)checkburst[0]++;
            else if (strcmp(cpu.top()->name, "p2") == 0)checkburst[1]++;
            else if (strcmp(cpu.top()->name, "p3") == 0)checkburst[2]++;
            else if (strcmp(cpu.top()->name, "p4") == 0)checkburst[3]++;
            else if (strcmp(cpu.top()->name, "p5") == 0)checkburst[4]++;
            else if (strcmp(cpu.top()->name, "p6") == 0){checkburst[5]++;}
            else if (strcmp(cpu.top()->name, "p7") == 0){checkburst[6]++;}
        }

        if(!cpu.empty()){
            if(strcmp(cpu.top()->name,"p1")==0){if(checkburst[0] == cpu.top()->burst_time){checkburst[0]=0;waitingq.push_back(cpu.top());cpu.pop();waitingq.back()->finishtime=i;flag =0;}}
            else if(strcmp(cpu.top()->name,"p2")==0){if(checkburst[1] == cpu.top()->burst_time){checkburst[1]=0;waitingq.push_back(cpu.top());cpu.pop();waitingq.back()->finishtime=i;flag =0;}}
            else if(strcmp(cpu.top()->name,"p3")==0){if(checkburst[2] == cpu.top()->burst_time){checkburst[2]=0;waitingq.push_back(cpu.top());cpu.pop();waitingq.back()->finishtime=i;flag =0;}}
            else if(strcmp(cpu.top()->name,"p4")==0){if(checkburst[3] == cpu.top()->burst_time){checkburst[3]=0;waitingq.push_back(cpu.top());cpu.pop();waitingq.back()->finishtime=i;flag =0;}}
            else if(strcmp(cpu.top()->name,"p5")==0){if(checkburst[4] == cpu.top()->burst_time){checkburst[4]=0;waitingq.push_back(cpu.top());cpu.pop();waitingq.back()->finishtime=i;flag =0;}}
            else if(strcmp(cpu.top()->name,"p6")==0){if(checkburst[5] == cpu.top()->burst_time){checkburst[5]=0;waitingq.push_back(cpu.top());cpu.pop();waitingq.back()->finishtime=i;flag =0;}}
            else if(strcmp(cpu.top()->name,"p7")==0){if(checkburst[6] == cpu.top()->burst_time){checkburst[6]=0;waitingq.push_back(cpu.top());cpu.pop();waitingq.back()->finishtime=i;flag =0;}}
        }

        if(!cpu.empty()){
            if(strcmp(cpu.top()->name,"p1")==0){if(checkburst[0]%q == 0){readyq.push_back(cpu.top());cpu.pop();readyq.back()->finishtime=i;flag =0;}}
            else if(strcmp(cpu.top()->name,"p2")==0){if(checkburst[1]%q == 0){readyq.push_back(cpu.top());cpu.pop();readyq.back()->finishtime=i;flag =0;}}
            else if(strcmp(cpu.top()->name,"p3")==0){if(checkburst[2]%q == 0){readyq.push_back(cpu.top());cpu.pop();readyq.back()->finishtime=i;flag =0;}}
            else if(strcmp(cpu.top()->name,"p4")==0){if(checkburst[3]%q == 0){readyq.push_back(cpu.top());cpu.pop();readyq.back()->finishtime=i;flag =0;}}
            else if(strcmp(cpu.top()->name,"p5")==0){if(checkburst[4]%q == 0){readyq.push_back(cpu.top());cpu.pop();readyq.back()->finishtime=i;flag =0;}}
            else if(strcmp(cpu.top()->name,"p6")==0){if(checkburst[5]%q == 0){readyq.push_back(cpu.top());cpu.pop();readyq.back()->finishtime=i;flag =0;}}
            else if(strcmp(cpu.top()->name,"p7")==0){if(checkburst[6]%q == 0){readyq.push_back(cpu.top());cpu.pop();readyq.back()->finishtime=i;flag =0;}}
        }

        if(!waitingq.empty()){
            temp = waitingq;
            for (int j=0;j<temp.size();j++){
                if(strcmp(temp[j]->name,"p1")==0)checkwait[0]++;
                else if(strcmp(temp[j]->name,"p2")==0)checkwait[1]++;
                else if(strcmp(temp[j]->name,"p3")==0)checkwait[2]++;
                else if(strcmp(temp[j]->name,"p4")==0)checkwait[3]++;
                else if(strcmp(temp[j]->name,"p5")==0){checkwait[4]++;}
                else if(strcmp(temp[j]->name,"p6")==0)checkwait[5]++;
                else checkwait[6]++;
            }

            //now the wait time in waiting queue is ready, now i need to check if any process needs to leave.
            for (int j=0;j<temp.size();j++){
                if(strcmp(temp[j]->name,"p1")==0) {if(checkwait[0]>=2){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p1");checkwait[0]=-1;}}
                else if(strcmp(temp[j]->name,"p2")==0){ if(checkwait[1]>=4){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p2");checkwait[1]=-1; }}
                else if(strcmp(temp[j]->name,"p3")==0){ if(checkwait[2]>=6){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p3");checkwait[2]=-1;}}
                else if(strcmp(temp[j]->name,"p4")==0){ if(checkwait[3]>=8){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p4");checkwait[3]=-1;}}
                else if(strcmp(temp[j]->name,"p5")==0){ if(checkwait[4]>=3){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p5");checkwait[4]=-1;}}
                else if(strcmp(temp[j]->name,"p6")==0){ if(checkwait[5]>=6){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p6");checkwait[5]=-1;}}
                else { if(checkwait[6]>=9){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p7");checkwait[6]=-1;}}
            }
        }
        if(i==200)cout<<i;
    }
    double waitingavg=0;
    for(int f=0;f<7;f++)waitingavg += forwaitingtime[f];
    waitingavg /= 7.0;
    cout<<"\nAverage waiting time="<<waitingavg<<"."<<endl;
    double turnaroundavg=0;
    for(int f=0;f<7;f++){
        turnaroundavg+=(processes[f]->finishtime - processes[f]->fixedarrival+1);
    }
    turnaroundavg/=7.0;
    cout<<"Average turnaround time="<<turnaroundavg<<".";
}


void PrePS(node processes[7],vector<node> readyq,vector<node> waitingq,stack<node> cpu){

    int aging=5;
    int checkburst[7]={0};
    int checkwait[7];
    for(int i=0;i<7;i++)checkwait[i]=-1;
    vector<node> temp;
    int checkwaitforreadytopriority[7];
    for(int f=0;f<7;f++)checkwaitforreadytopriority[f]=-1;
    node checktoprint;
    checktoprint=processes[6];
    int forwaitingtime[7]={0};

    for(int i=0;i<=200;i++){

        for (int j=0;j<7;j++) { //first time ready queue.....
            if (processes[j]->arraival_time == i) {
                readyq.push_back(processes[j]);
            }
        }
        //this is to increment the time of the processes to check after 5 second to make change at priority...
        if(!readyq.empty()) {
            temp = readyq;
            for (int j=0;j<temp.size();j++){
                if (strcmp(temp[j]->name,"p1") == 0)checkwaitforreadytopriority[0]++;
                else if (strcmp(temp[j]->name,"p2") == 0)checkwaitforreadytopriority[1]++;
                else if (strcmp(temp[j]->name,"p3") == 0)checkwaitforreadytopriority[2]++;
                else if (strcmp(temp[j]->name,"p4") == 0){checkwaitforreadytopriority[3]++;}
                else if (strcmp(temp[j]->name,"p5") == 0)checkwaitforreadytopriority[4]++;
                else if (strcmp(temp[j]->name,"p6") == 0)checkwaitforreadytopriority[5]++;
                else if (strcmp(temp[j]->name,"p7") == 0)checkwaitforreadytopriority[6]++;
            }

            temp = readyq;
            for (int j = 0; j<temp.size(); j++) {
                if (strcmp(temp[j]->name, "p1") == 0){if(checkwaitforreadytopriority[0]==aging){checkwaitforreadytopriority[0]=0;if(processes[0]->remainingpri>0)processes[0]->remainingpri--;}}
                else if (strcmp(temp[j]->name, "p2") == 0){if(checkwaitforreadytopriority[1]==aging){checkwaitforreadytopriority[1]=0;if(processes[1]->remainingpri>0)processes[1]->remainingpri--;}}
                else if (strcmp(temp[j]->name, "p3") == 0){if(checkwaitforreadytopriority[2]==aging){checkwaitforreadytopriority[2]=0;if(processes[2]->remainingpri>0)processes[2]->remainingpri--;}}
                else if (strcmp(temp[j]->name, "p4") == 0){if(checkwaitforreadytopriority[3]==aging){checkwaitforreadytopriority[3]=0;if(processes[3]->remainingpri>0)processes[3]->remainingpri--;}}
                else if (strcmp(temp[j]->name, "p5") == 0){if(checkwaitforreadytopriority[4]==aging){checkwaitforreadytopriority[4]=0;if(processes[4]->remainingpri>0)processes[4]->remainingpri--;}}
                else if (strcmp(temp[j]->name, "p6") == 0){if(checkwaitforreadytopriority[5]==aging){checkwaitforreadytopriority[5]=0;if(processes[5]->remainingpri>0)processes[5]->remainingpri--;}}
                else if (strcmp(temp[j]->name, "p7") == 0){if(checkwaitforreadytopriority[6]==aging){checkwaitforreadytopriority[6]=0;if(processes[6]->remainingpri>0)processes[6]->remainingpri--;}}

            }
        }



        if(cpu.empty()){//if there is no processes in the cpu, let another process in.

            if(!readyq.empty()){
                //before adding the first element to cpu, we have to sort the q.
                sort(readyq.begin(),readyq.end(), comparatorforpriority);
                cpu.push(readyq.front());
                readyq.erase(readyq.begin());
            }
        }

        if(!readyq.empty()){
            for(int f=0;f<readyq.size();f++){
                if(strcmp(readyq[f]->name,"p1")==0&&i<184)forwaitingtime[0]++;
                else if(strcmp(readyq[f]->name,"p2")==0&&i<192)forwaitingtime[1]++;
                else if(strcmp(readyq[f]->name,"p3")==0)forwaitingtime[2]++;
                else if(strcmp(readyq[f]->name,"p4")==0&&i<174)forwaitingtime[3]++;
                else if(strcmp(readyq[f]->name,"p5")==0&&i<161)forwaitingtime[4]++;
                else if(strcmp(readyq[f]->name,"p6")==0&&i<156)forwaitingtime[5]++;
                else if(strcmp(readyq[f]->name,"p7")==0&&i<167)forwaitingtime[6]++;
            }
        }

        if(!readyq.empty()){
            sort(readyq.begin(),readyq.end(), comparatorforpriority);
            if(!cpu.empty()){
                if(strcmp(cpu.top()->name,"p1")==0){if((readyq.front()->remainingpri)<(cpu.top()->remainingpri)){readyq.push_back(cpu.top());cpu.pop();readyq.back()->finishtime=i;cpu.push(readyq.front());readyq.erase(readyq.begin());}}
                else if(strcmp(cpu.top()->name,"p2")==0){if((readyq.front()->remainingpri)<(cpu.top()->remainingpri)){readyq.push_back(cpu.top());cpu.pop();readyq.back()->finishtime=i;cpu.push(readyq.front());readyq.erase(readyq.begin());}}
                else if(strcmp(cpu.top()->name,"p3")==0){if((readyq.front()->remainingpri)<(cpu.top()->remainingpri)){readyq.push_back(cpu.top());cpu.pop();readyq.back()->finishtime=i;cpu.push(readyq.front());readyq.erase(readyq.begin());}}
                else if(strcmp(cpu.top()->name,"p4")==0){if((readyq.front()->remainingpri)<(cpu.top()->remainingpri)){readyq.push_back(cpu.top());cpu.pop();readyq.back()->finishtime=i;cpu.push(readyq.front());readyq.erase(readyq.begin());}}
                else if(strcmp(cpu.top()->name,"p5")==0){if((readyq.front()->remainingpri)<(cpu.top()->remainingpri)){readyq.push_back(cpu.top());cpu.pop();readyq.back()->finishtime=i;cpu.push(readyq.front());readyq.erase(readyq.begin());}}
                else if(strcmp(cpu.top()->name,"p6")==0){if((readyq.front()->remainingpri)<(cpu.top()->remainingpri)){readyq.push_back(cpu.top());cpu.pop();readyq.back()->finishtime=i;cpu.push(readyq.front());readyq.erase(readyq.begin());}}
                else if(strcmp(cpu.top()->name,"p7")==0){if((readyq.front()->remainingpri)<(cpu.top()->remainingpri)){readyq.push_back(cpu.top());cpu.pop();readyq.back()->finishtime=i;cpu.push(readyq.front());readyq.erase(readyq.begin());}}
            }
        }

        if(checktoprint!=cpu.top()){
            checktoprint=cpu.top();
            cout<<i<<"->("<<cpu.top()->name<<")->";
        }

        if(!cpu.empty()) {//checking burst time

            if (strcmp(cpu.top()->name, "p1") == 0)checkburst[0]++;
            else if (strcmp(cpu.top()->name, "p2") == 0)checkburst[1]++;
            else if (strcmp(cpu.top()->name, "p3") == 0)checkburst[2]++;
            else if (strcmp(cpu.top()->name, "p4") == 0)checkburst[3]++;
            else if (strcmp(cpu.top()->name, "p5") == 0)checkburst[4]++;
            else if (strcmp(cpu.top()->name, "p6") == 0){checkburst[5]++;}
            else if (strcmp(cpu.top()->name, "p7") == 0){checkburst[6]++;}
        }

        if(!cpu.empty()){

            if(strcmp(cpu.top()->name,"p1")==0){if(checkburst[0] == cpu.top()->burst_time){checkburst[0]=0;waitingq.push_back(cpu.top());cpu.pop();waitingq.back()->finishtime=i;}}
            else if(strcmp(cpu.top()->name,"p2")==0){if(checkburst[1] == cpu.top()->burst_time){checkburst[1]=0;waitingq.push_back(cpu.top());cpu.pop();waitingq.back()->finishtime=i;}}
            else if(strcmp(cpu.top()->name,"p3")==0){if(checkburst[2] == cpu.top()->burst_time){checkburst[2]=0;waitingq.push_back(cpu.top());cpu.pop();waitingq.back()->finishtime=i;}}
            else if(strcmp(cpu.top()->name,"p4")==0){if(checkburst[3] == cpu.top()->burst_time){checkburst[3]=0;waitingq.push_back(cpu.top());cpu.pop();waitingq.back()->finishtime=i;}}
            else if(strcmp(cpu.top()->name,"p5")==0){if(checkburst[4] == cpu.top()->burst_time){checkburst[4]=0;waitingq.push_back(cpu.top());cpu.pop();waitingq.back()->finishtime=i;}}
            else if(strcmp(cpu.top()->name,"p6")==0){if(checkburst[5] == cpu.top()->burst_time){checkburst[5]=0;waitingq.push_back(cpu.top());cpu.pop();waitingq.back()->finishtime=i;}}
            else if(strcmp(cpu.top()->name,"p7")==0){if(checkburst[6] == cpu.top()->burst_time){checkburst[6]=0;waitingq.push_back(cpu.top());cpu.pop();waitingq.back()->finishtime=i;}}

        }



        if(!waitingq.empty()){
            temp = waitingq;
            for (int j=0;j<temp.size();j++){
                if(strcmp(temp[j]->name,"p1")==0)checkwait[0]++;
                else if(strcmp(temp[j]->name,"p2")==0)checkwait[1]++;
                else if(strcmp(temp[j]->name,"p3")==0)checkwait[2]++;
                else if(strcmp(temp[j]->name,"p4")==0)checkwait[3]++;
                else if(strcmp(temp[j]->name,"p5")==0){checkwait[4]++;}
                else if(strcmp(temp[j]->name,"p6")==0)checkwait[5]++;
                else checkwait[6]++;
            }


            //now the wait time in waiting queue is ready, now i need to check if any process needs to leave.
            for (int j=0;j<temp.size();j++){
                if(strcmp(temp[j]->name,"p1")==0) {if(checkwait[0]>=2){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p1");checkwait[0]=-1;}}
                else if(strcmp(temp[j]->name,"p2")==0){ if(checkwait[1]>=4){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p2");checkwait[1]=-1; }}
                else if(strcmp(temp[j]->name,"p3")==0){ if(checkwait[2]>=6){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p3");checkwait[2]=-1;}}
                else if(strcmp(temp[j]->name,"p4")==0){ if(checkwait[3]>=8){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p4");checkwait[3]=-1;}}
                else if(strcmp(temp[j]->name,"p5")==0){ if(checkwait[4]>=3){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p5");checkwait[4]=-1;}}
                else if(strcmp(temp[j]->name,"p6")==0){ if(checkwait[5]>=6){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p6");checkwait[5]=-1;}}
                else { if(checkwait[6]>=9){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p7");checkwait[6]=-1;}}
            }
        }
        if(i==200)cout<<i;
    }
    double waitingavg=0;
    for(int f=0;f<7;f++)waitingavg += forwaitingtime[f];
    waitingavg /= 7.0;
    cout<<"\nAverage waiting time="<<waitingavg<<"."<<endl;
    double turnaroundavg=0;
    for(int f=0;f<7;f++){
        turnaroundavg+=(processes[f]->finishtime - processes[f]->fixedarrival+1);
    }
    turnaroundavg/=7.0;
    cout<<"Average turnaround time="<<turnaroundavg<<".";
}


void NPrePS(node processes[7],vector<node> readyq,vector<node> waitingq,stack<node> cpu){
    int aging=5;
    int checkburst=0;
    int checkwait[7];
    for (int f=0;f<7;f++)checkwait[f]=-1;
    int checkpriority[7];
    for(int f=0;f<7;f++)checkpriority[f]=processes[f]->priority;
    vector <node> temp;
    cout<<"0->";
    int checkwaitforreadytopriority[7]={0};
    for(int f=0;f<7;f++)checkwaitforreadytopriority[f]=-1;

    int forwaitingtime[7]={0};

    for(int i=0;i<=200;i++){

        for (int j=0;j<7;j++) { //first time ready queue.....
            if (processes[j]->arraival_time == i) {
                readyq.push_back(processes[j]);
            }
        }

        if(!cpu.empty()){if(checkburst != cpu.top()->burst_time){checkburst++;}}
        if(!cpu.empty()){//checking burst time
            if(checkburst == cpu.top()->burst_time){cout<<"("<<cpu.top()->name<<")->"<<i<<"->";
                waitingq.push_back(cpu.top());waitingq.back()->finishtime=i;
                cpu.pop();
                checkburst=0;
            }
        }

        if(!readyq.empty()) {
            temp = readyq;
            for (int j=0;j<temp.size();j++){
                if (strcmp(temp[j]->name,"p1") == 0)checkwaitforreadytopriority[0]++;
                else if (strcmp(temp[j]->name,"p2") == 0)checkwaitforreadytopriority[1]++;
                else if (strcmp(temp[j]->name,"p3") == 0)checkwaitforreadytopriority[2]++;
                else if (strcmp(temp[j]->name,"p4") == 0){checkwaitforreadytopriority[3]++;}
                else if (strcmp(temp[j]->name,"p5") == 0)checkwaitforreadytopriority[4]++;
                else if (strcmp(temp[j]->name,"p6") == 0)checkwaitforreadytopriority[5]++;
                else if (strcmp(temp[j]->name,"p7") == 0)checkwaitforreadytopriority[6]++;

            }
            temp = readyq;
            for (int j = 0; j<temp.size(); j++) {
                if (strcmp(temp[j]->name, "p1") == 0){if(checkwaitforreadytopriority[0]==aging){checkwaitforreadytopriority[0]=0;if(processes[0]->remainingpri>0)processes[0]->remainingpri--;}}
                else if (strcmp(temp[j]->name, "p2") == 0){if(checkwaitforreadytopriority[1]==aging){checkwaitforreadytopriority[1]=0;if(processes[1]->remainingpri>0)processes[1]->remainingpri--;}}
                else if (strcmp(temp[j]->name, "p3") == 0){if(checkwaitforreadytopriority[2]==aging){checkwaitforreadytopriority[2]=0;if(processes[2]->remainingpri>0)processes[2]->remainingpri--;}}
                else if (strcmp(temp[j]->name, "p4") == 0){if(checkwaitforreadytopriority[3]==aging){checkwaitforreadytopriority[3]=0;if(processes[3]->remainingpri>0)processes[3]->remainingpri--;}}
                else if (strcmp(temp[j]->name, "p5") == 0){if(checkwaitforreadytopriority[4]==aging){checkwaitforreadytopriority[4]=0;if(processes[4]->remainingpri>0)processes[4]->remainingpri--;}}
                else if (strcmp(temp[j]->name, "p6") == 0){if(checkwaitforreadytopriority[5]==aging){checkwaitforreadytopriority[5]=0;if(processes[5]->remainingpri>0)processes[5]->remainingpri--;}}
                else if (strcmp(temp[j]->name, "p7") == 0){if(checkwaitforreadytopriority[6]==aging){checkwaitforreadytopriority[6]=0;if(processes[6]->remainingpri>0)processes[6]->remainingpri--;}}
            }
        }

        if(!waitingq.empty()){
            temp = waitingq;
            for (int j=0;j<temp.size();j++){
                if(strcmp(temp[j]->name,"p1")==0)checkwait[0]++;
                else if(strcmp(temp[j]->name,"p2")==0)checkwait[1]++;
                else if(strcmp(temp[j]->name,"p3")==0)checkwait[2]++;
                else if(strcmp(temp[j]->name,"p4")==0)checkwait[3]++;
                else if(strcmp(temp[j]->name,"p5")==0){checkwait[4]++;}
                else if(strcmp(temp[j]->name,"p6")==0)checkwait[5]++;
                else checkwait[6]++;
            }

            //now the wait time in waiting queue is ready, now i need to check if any process needs to leave.
            for (int j=0;j<temp.size();j++){
                if(strcmp(temp[j]->name,"p1")==0) {if(checkwait[0]>=2){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p1");checkwait[0]=-1;}}
                else if(strcmp(temp[j]->name,"p2")==0){ if(checkwait[1]>=4){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p2");checkwait[1]=-1; }}
                else if(strcmp(temp[j]->name,"p3")==0){ if(checkwait[2]>=6){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p3");checkwait[2]=-1;}}
                else if(strcmp(temp[j]->name,"p4")==0){ if(checkwait[3]>=8){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p4");checkwait[3]=-1;}}
                else if(strcmp(temp[j]->name,"p5")==0){ if(checkwait[4]>=3){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p5");checkwait[4]=-1;}}
                else if(strcmp(temp[j]->name,"p6")==0){ if(checkwait[5]>=6){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p6");checkwait[5]=-1;}}
                else { if(checkwait[6]>=9){temp[j]->arraival_time=i;readyq.push_back(temp[j]); del(waitingq,"p7");checkwait[6]=-1;}}
            }
        }


        if(cpu.empty()){//if there is no processes in the cpu, let another process in.

            if(!readyq.empty()){
                //before adding the first element to cpu, we have to sort the q.
                sort(readyq.begin(),readyq.end(), comparatorforpriority);
                cpu.push(readyq.front());
                readyq.erase(readyq.begin());
                if(strcmp(cpu.top()->name,"p1")==0)forwaitingtime[0]+=((i)-cpu.top()->arraival_time);
                else if(strcmp(cpu.top()->name,"p2")==0)forwaitingtime[1]+=((i)-cpu.top()->arraival_time);
                else if(strcmp(cpu.top()->name,"p3")==0)forwaitingtime[2]+=((i)-cpu.top()->arraival_time);
                else if(strcmp(cpu.top()->name,"p4")==0)forwaitingtime[3]+=((i)-cpu.top()->arraival_time);
                else if(strcmp(cpu.top()->name,"p5")==0)forwaitingtime[4]+=((i)-cpu.top()->arraival_time);
                else if(strcmp(cpu.top()->name,"p6")==0)forwaitingtime[5]+=((i)-cpu.top()->arraival_time);
                else if(strcmp(cpu.top()->name,"p7")==0)forwaitingtime[6]+=((i)-cpu.top()->arraival_time);
            }
        }

        if(i==200){
            cout<<"("<<cpu.top()->name<<")->"<<i;
        }
    }
    double waitingavg=0;
    for(int f=0;f<7;f++)waitingavg += forwaitingtime[f];
    waitingavg /= 7.0;
    cout<<"\nAverage waiting time="<<waitingavg<<"."<<endl;
    double turnaroundavg=0;
    for(int f=0;f<7;f++){
        turnaroundavg+=(processes[f]->finishtime - processes[f]->fixedarrival+1);
    }
    turnaroundavg/=7.0;
    cout<<"Average turnaround time="<<turnaroundavg<<".";
}

void del(vector <node> & q,string name){
    for(int i=0;i<q.size();i++){
        if(q[i]->name==name){
            q.erase(q.begin()+i);
        }
    }
}
bool comparator(node& x,node& y){
    return x->burst_time < y->burst_time;
}
bool comparatorfortimer(node x,node y){
    return (((x->burst_time) - (x->remainingtime))<((y->burst_time) - (y->remainingtime)));
}
bool comparatorforpriority(node x,node y){
    if(x->remainingpri == y->remainingpri)
        return x->arraival_time < y->arraival_time;
    return x->remainingpri < y->remainingpri;
}