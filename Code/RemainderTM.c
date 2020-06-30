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
    //printf("Transition created \n");
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
    // printf("%d: (%s, %c)->(%s, %c, %c) \n",*step,currstate,input,nextstate,output,direction);
    printf("%d: %c %c %c \n",*step,input,output,direction);

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
        int head=Machine->head;
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
    struct state qi=createstate("qi",0,0);
    struct state q10=createstate("q10",0,0);
    struct state q11=createstate("q11",0,0);
    struct state q12=createstate("q12",0,0);
    struct state q13=createstate("q13",0,0);
    struct state q14=createstate("q14",0,0);
    struct state q15=createstate("q15",0,0);
    struct state q16=createstate("q16",0,0);
    // struct state q17=createstate("q17",0,0);
    struct state q18=createstate("q18",0,0);
    struct state q19=createstate("q19",0,0);
    // struct state q20=createstate("q20",0,0);
    struct state q21=createstate("q21",0,0);
    struct state q22=createstate("q22",0,0);
    struct state q23=createstate("q23",0,0);
    struct state q24=createstate("q24",0,0);
    struct state q25=createstate("q25",0,0);
    struct state q26=createstate("q26",0,0);
    struct state q27=createstate("q27",0,0);
    struct state q28=createstate("q28",0,0);
    struct state q29=createstate("q29",0,0);
    struct state q30=createstate("q30",0,0);    
    struct state qf=createstate("qf",1,0);
   
    struct  statetransition q0_0 = createtransition('0','0',"q0",1);
    struct  statetransition q0_1 = createtransition('1','1',"q0",1);
    struct  statetransition q0_H = createtransition('#','#',"q1",0);
    struct  statetransition q1_0 = createtransition('0','B',"q3",0);
    struct  statetransition q1_1 = createtransition('1','A',"q2",0);
    struct  statetransition q1_B = createtransition('_','_',"q9",1);
    struct  statetransition q2_0 = createtransition('0','0',"q2",0);
    struct  statetransition q2_1 = createtransition('1','1',"q2",0);
    struct  statetransition q2_B = createtransition('_','_',"q4",0);
    struct  statetransition q3_0 = createtransition('0','0',"q3",0);
    struct  statetransition q3_1 = createtransition('1','1',"q3",0);
    struct  statetransition q3_B = createtransition('_','_',"q6",0);
    struct  statetransition q4_0 = createtransition('0','0',"q4",0);
    struct  statetransition q4_1 = createtransition('1','1',"q4",0);
    struct  statetransition q4_B = createtransition('_','1',"q5",1);
    struct  statetransition q5_0 = createtransition('0','0',"q5",1);
    struct  statetransition q5_1 = createtransition('1','1',"q5",1);
    struct  statetransition q5_B = createtransition('_','_',"q8",1);
    struct  statetransition q6_0 = createtransition('0','0',"q6",0);
    struct  statetransition q6_1 = createtransition('1','1',"q6",0);
    struct  statetransition q6_B = createtransition('_','0',"q7",1);
    struct  statetransition q7_0 = createtransition('0','0',"q7",1);
    struct  statetransition q7_1 = createtransition('1','1',"q7",1);
    struct  statetransition q7_B = createtransition('_','_',"q8",1);
    struct  statetransition q8_1 = createtransition('1','1',"q8",1);
    struct  statetransition q8_0 = createtransition('0','0',"q8",1);
    struct  statetransition q8_A = createtransition('A','A',"q1",0);
    struct  statetransition q8_B = createtransition('B','B',"q1",0);
    struct  statetransition q9_A = createtransition('A','1',"q9",1);
    struct  statetransition q9_B = createtransition('B','0',"q9",1);
    struct  statetransition q9_H = createtransition('#','#',"qi",0);
    struct  statetransition qi_1 = createtransition('1','1',"qi",0);
    struct  statetransition qi_0 = createtransition('0','0',"qi",0);
    struct  statetransition qi_B = createtransition('_','_',"q10",1);
    struct  statetransition q10_0 = createtransition('0','0',"q10",1);
    struct  statetransition q10_1 = createtransition('1','1',"q10",1);
    struct  statetransition q10_H = createtransition('#','#',"q10",1);
    struct  statetransition q10_B = createtransition('_','_',"q11",0);
    struct  statetransition q11_0 = createtransition('0','y',"q13",0);
    struct  statetransition q11_1 = createtransition('1','x',"q12",0);
    struct  statetransition q12_0 = createtransition('0','0',"q12",0);
    struct  statetransition q12_1 = createtransition('1','1',"q12",0);
    struct  statetransition q12_H = createtransition('#','#',"q14",0);
    struct  statetransition q13_0 = createtransition('0','0',"q13",0);
    struct  statetransition q13_1 = createtransition('1','1',"q13",0);
    struct  statetransition q13_H = createtransition('#','#',"q21",0);
    struct  statetransition q14_0 = createtransition('0','X',"q15",0);
    struct  statetransition q14_1 = createtransition('1','Y',"q16",0);
    struct  statetransition q14_X = createtransition('X','X',"q14",0);
    struct  statetransition q14_Y = createtransition('Y','Y',"q14",0);
    struct  statetransition q14_B = createtransition('_','_',"q28",1);
    struct  statetransition q15_0 = createtransition('0','1',"q15",0);
    struct  statetransition q15_1 = createtransition('1','0',"q19",0);
    struct  statetransition q15_B = createtransition('_','_',"q28",1);
    struct  statetransition q16_0 = createtransition('0','0',"q16",1);
    struct  statetransition q16_1 = createtransition('1','1',"q16",1);
    struct  statetransition q16_x = createtransition('x','x',"q18",0);
    struct  statetransition q16_y = createtransition('y','y',"q18",0);
    struct  statetransition q16_X = createtransition('X','X',"q16",1);
    struct  statetransition q16_Y = createtransition('Y','Y',"q16",1);
    struct  statetransition q16_B = createtransition('_','_',"q16",1);
    struct  statetransition q16_H = createtransition('#','#',"q16",1);
    struct  statetransition q18_0 = createtransition('0','y',"q13",0);
    struct  statetransition q18_1 = createtransition('1','x',"q12",0);
    struct  statetransition q18_H = createtransition('#','#',"q27",1);
    struct  statetransition q19_0 = createtransition('0','0',"q16",1);
    struct  statetransition q19_1 = createtransition('1','1',"q16",1);
    struct  statetransition q19_B = createtransition('_','_',"q16",1);
    struct  statetransition q21_0 = createtransition('0','Y',"q16",0);
    struct  statetransition q21_1 = createtransition('1','X',"q16",0);
    struct  statetransition q21_X = createtransition('X','X',"q21",0);
    struct  statetransition q21_Y = createtransition('Y','Y',"q21",0);
    struct  statetransition q21_B = createtransition('_','_',"q28",1);
    struct  statetransition q22_0 = createtransition('0','0',"q22",0);
    struct  statetransition q22_1 = createtransition('1','1',"q22",0);
    struct  statetransition q22_x = createtransition('x','1',"q22",0);
    struct  statetransition q22_y = createtransition('y','0',"q22",0);
    struct  statetransition q22_X = createtransition('X','1',"q22",0);
    struct  statetransition q22_Y = createtransition('Y','0',"q22",0);
    struct  statetransition q22_B = createtransition('_','_',"q23",0);
    struct  statetransition q22_H = createtransition('#','#',"q22",0);
    struct  statetransition q23_B = createtransition('_','_',"q23",0);
    struct  statetransition q23_1 = createtransition('1','_',"q24",0);
    struct  statetransition q23_0 = createtransition('0','_',"q24",0);
    struct  statetransition q24_1 = createtransition('1','_',"q24",0);
    struct  statetransition q24_0 = createtransition('0','_',"q24",0);
    struct  statetransition q24_B = createtransition('_','_',"q25",1);
    struct  statetransition q25_B = createtransition('_','_',"q25",1);
    struct  statetransition q25_1 = createtransition('1','1',"q26",0);
    struct  statetransition q25_0 = createtransition('0','0',"q26",0);
    struct  statetransition q26_B = createtransition('_','_',"q0",1);
    struct  statetransition q27_x = createtransition('x','x',"q27",1);
    struct  statetransition q27_y = createtransition('y','y',"q27",1);
    struct  statetransition q27_B = createtransition('_','_',"q22",0);
    struct  statetransition q28_1 = createtransition('1','_',"q28",1);
    struct  statetransition q28_0 = createtransition('0','_',"q28",1);
    struct  statetransition q28_x = createtransition('x','_',"q28",1);
    struct  statetransition q28_y = createtransition('y','_',"q28",1);
    struct  statetransition q28_X = createtransition('X','_',"q28",1);
    struct  statetransition q28_Y = createtransition('Y','_',"q28",1);
    struct  statetransition q28_H = createtransition('#','_',"q28",1);
    struct  statetransition q28_B = createtransition('_','_',"q29",0);
    struct  statetransition q29_0 = createtransition('0','0',"q30",0);
    struct  statetransition q29_1 = createtransition('1','1',"q30",0);
    struct  statetransition q29_B = createtransition('_','_',"q29",0);
    struct  statetransition q30_1 = createtransition('1','1',"q30",0);
    struct  statetransition q30_0 = createtransition('0','0',"q30",0);
    struct  statetransition q30_B = createtransition('_','_',"qf",1);
    
    


    addtransitiontostate(&qi,&qi_0);
    addtransitiontostate(&qi,&qi_1);
    addtransitiontostate(&qi,&qi_B);
    addtransitiontostate(&q0,&q0_0);
    addtransitiontostate(&q1,&q1_0);
    addtransitiontostate(&q0,&q0_1);
    addtransitiontostate(&q0,&q0_H);
    addtransitiontostate(&q1,&q1_1);
    addtransitiontostate(&q1,&q1_B);
    addtransitiontostate(&q2,&q2_0);
    addtransitiontostate(&q2,&q2_1);
    addtransitiontostate(&q2,&q2_B);
    addtransitiontostate(&q3,&q3_0);
    addtransitiontostate(&q3,&q3_1);
    addtransitiontostate(&q3,&q3_B);
    addtransitiontostate(&q4,&q4_0);
    addtransitiontostate(&q4,&q4_1);
    addtransitiontostate(&q4,&q4_B);
    addtransitiontostate(&q5,&q5_0);
    addtransitiontostate(&q5,&q5_1);
    addtransitiontostate(&q5,&q5_B);
    addtransitiontostate(&q6,&q6_0);
    addtransitiontostate(&q6,&q6_1);
    addtransitiontostate(&q6,&q6_B);
    addtransitiontostate(&q7,&q7_0);
    addtransitiontostate(&q7,&q7_1);
    addtransitiontostate(&q7,&q7_B);
    addtransitiontostate(&q8,&q8_0);
    addtransitiontostate(&q8,&q8_1);
    addtransitiontostate(&q8,&q8_A);
    addtransitiontostate(&q8,&q8_B);
    addtransitiontostate(&q9,&q9_A);
    addtransitiontostate(&q9,&q9_B);
    addtransitiontostate(&q9,&q9_H);
    addtransitiontostate(&q10,&q10_0);
    addtransitiontostate(&q10,&q10_1);
    addtransitiontostate(&q10,&q10_B);
    addtransitiontostate(&q10,&q10_H);
    addtransitiontostate(&q11,&q11_0);
    addtransitiontostate(&q11,&q11_1);
    addtransitiontostate(&q12,&q12_0);
    addtransitiontostate(&q12,&q12_1);
    addtransitiontostate(&q12,&q12_H);
    addtransitiontostate(&q13,&q13_0);
    addtransitiontostate(&q13,&q13_1);
    addtransitiontostate(&q13,&q13_H);
    addtransitiontostate(&q14,&q14_0);
    addtransitiontostate(&q14,&q14_1);
    addtransitiontostate(&q14,&q14_B);
    addtransitiontostate(&q14,&q14_X);
    addtransitiontostate(&q14,&q14_Y);
    addtransitiontostate(&q15,&q15_0);
    addtransitiontostate(&q15,&q15_1);
    addtransitiontostate(&q15,&q15_B);
    addtransitiontostate(&q16,&q16_0);
    addtransitiontostate(&q16,&q16_1);
    addtransitiontostate(&q16,&q16_B);
    addtransitiontostate(&q16,&q16_H);
    addtransitiontostate(&q16,&q16_X);
    addtransitiontostate(&q16,&q16_x);
    addtransitiontostate(&q16,&q16_Y);
    addtransitiontostate(&q16,&q16_y);
    addtransitiontostate(&q18,&q18_0);
    addtransitiontostate(&q18,&q18_1);
    addtransitiontostate(&q18,&q18_H);
    addtransitiontostate(&q19,&q19_0);
    addtransitiontostate(&q19,&q19_1);
    addtransitiontostate(&q19,&q19_B);
    addtransitiontostate(&q21,&q21_0);
    addtransitiontostate(&q21,&q21_1);
    addtransitiontostate(&q21,&q21_B);
    addtransitiontostate(&q21,&q21_X);
    addtransitiontostate(&q21,&q21_Y);
    addtransitiontostate(&q22,&q22_0);
    addtransitiontostate(&q22,&q22_1);
    addtransitiontostate(&q22,&q22_B);
    addtransitiontostate(&q22,&q22_H);
    addtransitiontostate(&q22,&q22_X);
    addtransitiontostate(&q22,&q22_x);
    addtransitiontostate(&q22,&q22_Y);
    addtransitiontostate(&q22,&q22_y);
    addtransitiontostate(&q23,&q23_0);
    addtransitiontostate(&q23,&q23_1);
    addtransitiontostate(&q23,&q23_B);
    addtransitiontostate(&q24,&q24_0);
    addtransitiontostate(&q24,&q24_1);
    addtransitiontostate(&q24,&q24_B);
    addtransitiontostate(&q25,&q25_0);
    addtransitiontostate(&q25,&q25_1);
    addtransitiontostate(&q25,&q25_B);
    addtransitiontostate(&q26,&q26_B);
    addtransitiontostate(&q27,&q27_B);
    addtransitiontostate(&q27,&q27_x);
    addtransitiontostate(&q27,&q27_y);
    addtransitiontostate(&q28,&q28_0);
    addtransitiontostate(&q28,&q28_1);
    addtransitiontostate(&q28,&q28_B);
    addtransitiontostate(&q28,&q28_H);
    addtransitiontostate(&q28,&q28_X);
    addtransitiontostate(&q28,&q28_x);
    addtransitiontostate(&q28,&q28_Y);
    addtransitiontostate(&q28,&q28_y);
    addtransitiontostate(&q29,&q29_0);
    addtransitiontostate(&q29,&q29_1);
    addtransitiontostate(&q29,&q29_B);
    addtransitiontostate(&q30,&q30_0);
    addtransitiontostate(&q30,&q30_1);
    addtransitiontostate(&q30,&q30_B);
    
    

    // printf("%d",q0.transitionnumber);
    // Add all the states to the Turing Machine:
    addstatetoturingmachine(&Machine,&q0);
    addstatetoturingmachine(&Machine,&q1);
    addstatetoturingmachine(&Machine,&q2);
    addstatetoturingmachine(&Machine,&q3);
    // addstatetoturingmachine(&Machine,&qf);
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
    addstatetoturingmachine(&Machine,&q15);
    addstatetoturingmachine(&Machine,&q16);
    addstatetoturingmachine(&Machine,&q18);
    addstatetoturingmachine(&Machine,&q19);
    addstatetoturingmachine(&Machine,&q21);
    addstatetoturingmachine(&Machine,&q22);
    addstatetoturingmachine(&Machine,&q23);
    addstatetoturingmachine(&Machine,&q24);
    addstatetoturingmachine(&Machine,&q25);
    addstatetoturingmachine(&Machine,&q26);
    addstatetoturingmachine(&Machine,&q27);
    addstatetoturingmachine(&Machine,&q28);
    addstatetoturingmachine(&Machine,&q29);
    addstatetoturingmachine(&Machine,&q30);
    addstatetoturingmachine(&Machine,&qf);
    addstatetoturingmachine(&Machine,&qi);
    
    runturingmachine(&Machine,tape);
    
}
