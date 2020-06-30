#include<stdio.h>
#include<string.h>

struct statetransition{
    char input;
    char output;
    char *nextstate;
    int move;
    //0-->Left
    //1-->right
};


struct state{
    char *stateno;
    int transitionnumber;
    struct statetransition  transitions[10];
    int accept;
    int reject;
};

struct turing{
    struct state states[50];
    int statenumber;
    char* initstate;
    char* currentstate;
    int head;
    
};

struct state createstate(char* sno,int A,int R)
{
    struct state s1;
    s1.stateno=sno;
    s1.accept=A;
    s1.reject=R;
    s1.transitionnumber=0;

    // printf("State Created with following information:\n");
    // printf("State Name: %s\t State Accept: %d\t State Reject: %d\n",s1.stateno,s1.accept,s1.reject);
    return s1;

}

struct statetransition createtransition(char ip,char op,char* nstate,int move)
{
    struct statetransition s1;
    s1.input=ip;
    s1.output=op;
    s1.nextstate=nstate;
    s1.move=move;
    // printf("Transition created \n");
    return s1;
}

void addtransitiontostate(struct state *s1, struct statetransition *t1)
{
  if(s1->transitionnumber<10)
  {
      s1->transitions[s1->transitionnumber]=*t1;
      s1->transitionnumber++;
    //   printf("Transition added to the %s state with following information:\n",s1->stateno);
    //   printf("%c-->%c, %s ,%d\n",t1->input,t1->output,t1->nextstate,t1->move);
  }
}

void addstatetoturingmachine(struct turing *m1,struct state *s1)
{
    if(m1->statenumber<50)
    {
        m1->states[m1->statenumber]=*s1;
        m1->statenumber++;
        // printf("State added to turing machine with following information:\n");
        // printf("State Name: %s\n",s1->stateno);
    }
}

void Turingstep(struct turing *Machine,char *tape,int *step)
{
    char* currstate=Machine->currentstate;
    int head=Machine->head;
    char input=tape[head];
    int nos=Machine->statenumber;
    struct state current;
    for(int i=0;i<nos;i++)
    {
        if(Machine->states[i].stateno==currstate)
        {
            current=Machine->states[i];
        }
    }

    int not=current.transitionnumber;
    struct statetransition currenttransition;
    for(int i=0;i<not;i++)
    {
        if(current.transitions[i].input==input)
        {
            currenttransition=current.transitions[i];
        }
    }

    char output=currenttransition.output;
    int move=currenttransition.move;
    char* nextstate=currenttransition.nextstate;
    
    char direction;
    tape[head]=output;
    if(move==0)
    {
        direction='L';
        head--;
    }
    else
    {
        direction='R';
        head++;
    }
    
    Machine->currentstate=nextstate;
    Machine->head=head;
    printf("%d: (%s, %c)->(%s, %c, %c) \n",*step,currstate,input,nextstate,output,direction);
    // printf("%d: %c %c %c \n",*step,input,output,direction);

}

void runturingmachine(struct turing *Machine,char *tape)
{
    printf("Running Turing Machine M on Tape T\n");
    int step=0;
    while(1)
    {
        Turingstep(Machine,tape,&step);
        step++;
        char* currstate=Machine->currentstate;
        int nos=Machine->statenumber;
        struct state current;
        for(int i=0;i<nos;i++)
        {
            if(Machine->states[i].stateno==currstate)
            {
                current=Machine->states[i];
            }
        }

        if(current.accept==1)
        {
            printf("Turing Machine Accepted the result\n");
            printf("Answer:");
            for(int i=0;i<200;i++)
            {
                if(tape[i]!='_')
                {
                    printf("%c",tape[i]);
                }
            }
            break;
        }

        if(current.reject==1)
        {
            printf("Turing Machine Rejected the result\n");
            break;
        }
        

    }
}



void main()
{
    char tape[200];
    for (int i = 0; i < 200; i++)
    {
        tape[i]='_';
    }
    
    printf("Enter the input for Turing Machine:-");
    char ip[50];
    scanf("%s",ip);

    int len=strlen(ip);
    for (int i = 0; i < len; i++)
    {
        tape[100+i]=ip[i];
    }

    // for (int i = 0; i < 200; i++)
    // {
    //     printf("%d-->%c\t",i,tape[i]);
    // }

    struct turing Machine;
    Machine.statenumber=0;
    Machine.head=100;
    Machine.initstate="q0";
    Machine.currentstate="q0";
    
    printf("Turing Machine created...Adding features to it\n");

    //Intializing the states:

    struct state q0=createstate("q0",0,0);
    struct state q1=createstate("q1",0,0);
    struct state q2=createstate("q2",0,0);
    struct state q3=createstate("q3",0,0);
    struct state q4=createstate("q4",0,0);
    struct state q5=createstate("q5",0,0);
    struct state q6=createstate("q6",0,0);
    struct state q7=createstate("q7",0,0);
    struct state q8=createstate("q8",0,0);
    struct state q9=createstate("q9",0,0);
    struct state q10=createstate("q10",0,0);
    struct state q11=createstate("q11",0,0);
    struct state q12=createstate("q12",0,0);
    struct state q13=createstate("q13",0,0);
    struct state q14=createstate("q14",0,0);
    struct state q15=createstate("q15",0,0);
    struct state q16=createstate("q16",0,0);
    struct state qf=createstate("qf",1,0);
   
    //Initializing the transition function: 
    struct  statetransition q0_0 = createtransition('0','0',"q1",0);
    // printf("%c\t%c\t%s\t%d",q0_0.input,q0_0.output,q0_0.nextstate,q0_0.move);
    struct  statetransition q0_1 = createtransition('1','1',"q1",0);
    struct  statetransition q1_B = createtransition('_','_',"q2",0);
    struct  statetransition q2_B = createtransition('_','0',"q3",1);
    struct  statetransition q3_B = createtransition('_','_',"q4",1);
    struct  statetransition q4_0 = createtransition('0','0',"q4",1);
    struct  statetransition q4_1 = createtransition('1','1',"q4",1);
    struct  statetransition q4_H = createtransition('#','#',"q5",1);
    struct  statetransition q5_0 = createtransition('0','0',"q5",1);
    struct  statetransition q5_H = createtransition('#','#',"q5",1);
    struct  statetransition q5_1 = createtransition('1','0',"q7",1);
    struct  statetransition q5_B = createtransition('_','_',"q6",0);
    struct  statetransition q6_0 = createtransition('0','_',"q6",0);
    struct  statetransition q6_1 = createtransition('1','_',"q6",0);
    struct  statetransition q6_H = createtransition('#','_',"q6",0);
    struct  statetransition q6_B = createtransition('_','_',"q14",0);
    struct  statetransition q7_1 = createtransition('1','1',"q7",1);
    struct  statetransition q7_0 = createtransition('0','0',"q7",1);
    struct  statetransition q7_H = createtransition('#','#',"q8",1);
    struct  statetransition q8_0 = createtransition('0','0',"q8",1);
    struct  statetransition q8_1 = createtransition('1','0',"q7",1);
    struct  statetransition q8_H = createtransition('#','#',"q8",1);
    struct  statetransition q8_B = createtransition('_','_',"q9",0);
    struct  statetransition q9_0 = createtransition('0','0',"q9",0);
    struct  statetransition q9_1 = createtransition('1','1',"q9",0);
    struct  statetransition q9_H = createtransition('#','#',"q9",0);
    struct  statetransition q9_B = createtransition('_','_',"q10",0);
    struct  statetransition q10_B = createtransition('_','1',"q11",1);
    struct  statetransition q10_0 = createtransition('0','1',"q11",1);
    struct  statetransition q10_1 = createtransition('1','0',"q12",0);
    struct  statetransition q11_1 = createtransition('1','1',"q11",1);
    struct  statetransition q11_0 = createtransition('0','0',"q11",1);
    struct  statetransition q11_B = createtransition('_','_',"q4",1);
    struct  statetransition q12_1 = createtransition('1','0',"q12",0);
    struct  statetransition q12_0 = createtransition('0','1',"q13",1);
    struct  statetransition q12_B = createtransition('_','1',"q13",1);
    struct  statetransition q13_1 = createtransition('1','1',"q13",1);
    struct  statetransition q13_0 = createtransition('0','0',"q13",1);
    struct  statetransition q13_B = createtransition('_','_',"q4",1);
    struct  statetransition q14_0 = createtransition('0','0',"q14",0);
    struct  statetransition q14_1 = createtransition('1','1',"q14",0);
    struct  statetransition q14_B = createtransition('_','_',"qf",1);
    


    //add all the transtion functions to the respective states

    addtransitiontostate(&q0,&q0_0);
    addtransitiontostate(&q0,&q0_1);
    addtransitiontostate(&q1,&q1_B);
    addtransitiontostate(&q2,&q2_B);
    addtransitiontostate(&q3,&q3_B);
    addtransitiontostate(&q4,&q4_0);
    addtransitiontostate(&q4,&q4_1);
    addtransitiontostate(&q4,&q4_H);
    addtransitiontostate(&q5,&q5_0);
    addtransitiontostate(&q5,&q5_1);
    addtransitiontostate(&q5,&q5_H);
    addtransitiontostate(&q5,&q5_B);
    addtransitiontostate(&q6,&q6_0);
    addtransitiontostate(&q6,&q6_1);
    addtransitiontostate(&q6,&q6_H);
    addtransitiontostate(&q6,&q6_B);
    addtransitiontostate(&q7,&q7_0);
    addtransitiontostate(&q7,&q7_1);
    addtransitiontostate(&q7,&q7_H);
    addtransitiontostate(&q8,&q8_0);
    addtransitiontostate(&q8,&q8_1);
    addtransitiontostate(&q8,&q8_H);
    addtransitiontostate(&q8,&q8_B);
    addtransitiontostate(&q9,&q9_0);
    addtransitiontostate(&q9,&q9_1);
    addtransitiontostate(&q9,&q9_H);
    addtransitiontostate(&q9,&q9_B);
    addtransitiontostate(&q10,&q10_0);
    addtransitiontostate(&q10,&q10_1);
    addtransitiontostate(&q10,&q10_B);
    addtransitiontostate(&q11,&q11_0);
    addtransitiontostate(&q11,&q11_1);
    addtransitiontostate(&q11,&q11_B);
    addtransitiontostate(&q12,&q12_0);
    addtransitiontostate(&q12,&q12_1);
    addtransitiontostate(&q12,&q12_B);
    addtransitiontostate(&q13,&q13_0);
    addtransitiontostate(&q13,&q13_1);
    addtransitiontostate(&q13,&q13_B);
    addtransitiontostate(&q14,&q14_0);
    addtransitiontostate(&q14,&q14_1);
    addtransitiontostate(&q14,&q14_B);
    

    // printf("%d",q0.transitionnumber);
    // Add all the states to the Turing Machine:
    addstatetoturingmachine(&Machine,&q0);
    addstatetoturingmachine(&Machine,&q1);
    addstatetoturingmachine(&Machine,&q2);
    addstatetoturingmachine(&Machine,&q3);
    addstatetoturingmachine(&Machine,&qf);
    addstatetoturingmachine(&Machine,&q4);
    addstatetoturingmachine(&Machine,&q5);
    addstatetoturingmachine(&Machine,&q6);
    addstatetoturingmachine(&Machine,&q7);
    addstatetoturingmachine(&Machine,&q8);
    addstatetoturingmachine(&Machine,&q9);
    addstatetoturingmachine(&Machine,&q10);
    addstatetoturingmachine(&Machine,&q11);
    addstatetoturingmachine(&Machine,&q12);
    addstatetoturingmachine(&Machine,&q13);
    addstatetoturingmachine(&Machine,&q14);

    runturingmachine(&Machine,tape);
    
}
