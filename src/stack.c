#include "C:\Users\peder\OneDrive - Aarhus universitet\Programmering for Computerteknologi\Assignment 7\assignment-7-Daniel6702\include\stack.h"

void initialize(stack* s){
    //s = malloc(sizeof(stack));
    s->head = NULL; //creates empty stack
}

void push(int x, stack* s){
    node *temp; //create temporary node (the new element)
    temp = (node*) malloc(sizeof(node));
    temp->data = x; //add assigned data to this element

    if (s->head == NULL) { //if empty, top becomes new element
      s->head = temp;
      s->head->next = NULL;
    } else {
      temp->next = s->head; //Put new element on top of stack
      s->head = temp;
    }
}

int pop(stack* s){
    node *temp;
    int data;
    if (empty(s) == false) {
      temp = s->head;
      data = s->head->data; //save data of top element
      s->head = s->head->next; //top equal to previous element (down the list)
      free(temp); //deallocates memory
    }
    return data;
}

bool empty(stack* s)
{
  if (s->head == NULL) { //if the first/top element equal NULL then empty
    return true;
  } else {
    return false;
  }
}

bool full(stack* s) {
    node *temp; //only possible to create new node if allocated memory "heap" isnt full
                //if this operation fail, temp will be NULL and stack must be full
    if (temp == NULL) {
      return true;
    } else {
      return false;
    }
}

void printout(node *p) {
  while (p != NULL) {
     printf("%d", p->data);
     p = p->next;
     if(p != NULL)
         printf("-->");
  }
  printf("\n");
}

/*                            Test Cases                              */
void testA(stack* s) {
  initialize(s);
  bool empt = empty(s); //uses function to determine if function is empty
  assert(empt == true); //assert result
}

void testB(stack* s) {
  initialize(s);
  int x = 5;
  push(x,s); //add element x
  int y = pop(s); //remove element 
  testA(s); //stack should be empty again
  assert(y == x); //y should be x
}

void testC(stack* s) {
  initialize(s);
  int x0 = 5, x1 = 15;
  push(x0,s); //add element x0 (5)
  push(x1,s); //add element x1 (15)
  int y0 = pop(s); //removes elements again
  int y1 = pop(s);
  testA(s); //check if empty again
  assert(x0 == y1 && x1  == y0);
}

int main(void) {
  stack *stack = malloc(sizeof(stack));;

  testA(stack); 

  testB(stack);

  testC(stack);

  //The program runs without any errors

  printf("done");

  return 0;
}
