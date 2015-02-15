#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define EMPTY 0
#define FULL 100

using namespace std;

typedef char data;

struct node{
	data d;
	struct node *next;
};
typedef struct node node;

struct stack{
 	int cnt; 	
 	struct node *top; 
};
typedef struct stack stack;

bool isempty(stack *stk){
	return(stk -> cnt == EMPTY);
}

bool isfull(stack *stk){
	return (stk -> cnt == FULL);
}

void initialize(stack *stk){ //baslangıc durumuna getirir.Sıfırlar.
 	stk -> cnt = 0; 		
	stk -> top = NULL; 	
}

data top(stack *stk){
	return (stk -> top -> d);
}

void push(data x, stack *stk){
    if(!isfull(stk)){
      
        node *temp = new node();
        temp -> d = x; 		
        temp -> next = stk -> top;

        
        stk -> top = temp;
        stk -> cnt++;
    }
}

//stack dolu ise ve ben push yapmak istersem overflow hatası
//stack boş ise ve ben pop yapmak istersem  underflow hatası

data pop(stack *stk){
    if(!isempty(stk)){
        data x; // will store the top data
        node *temp = stk->top;
        x = stk -> top -> d;
        stk -> top = stk -> top -> next;
        stk -> cnt--;
        delete(temp);
        return x;
    }
}

int main(){
	char str[] = "CME227";
	int i;
	stack s;
	initialize(&s); 	

	for(i = 0; str[i] != '\0'; ++i){	 
		push(str[i], &s);
    }

	cout<<"String in the stack: "<<endl;

	while (!isempty(&s))
		cout<<pop(&s);
	getch();
}
