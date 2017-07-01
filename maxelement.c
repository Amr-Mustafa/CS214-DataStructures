#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAXSTACK 100000

typedef long long StackEntry;
typedef struct stack {
    int top;
    int max_top;
    StackEntry current_max;
    StackEntry entry[MAXSTACK];
    StackEntry max_entry[MAXSTACK];
} Stack;

void CreateStack (Stack *ps) {
    ps->top = 0;
    ps->max_top = 0;
    ps->current_max = 0;
}

void Push (StackEntry e, Stack *ps) {
    ps->entry[ps->top++] = e;
    if (e > ps->current_max) {
       ps->current_max = e;
       ps->max_entry[ps->max_top++] = e;
    }
}

void Pop (StackEntry *e, Stack *ps) {
   if (ps->entry[ps->top - 1] == ps->current_max) {
      *e = ps->entry[ps->top - 1];
      ps->top--;
      ps->max_top--;
      if (ps->max_top > 0)
         ps->current_max = ps->max_entry[ps->max_top - 1];
      else
         ps->current_max = 0;
   } else {
      *e = ps->entry[ps->top - 1];
      ps->top--;
   }
}

void Max (StackEntry *e, Stack *ps) {
    *e = ps->max_entry[ps->max_top - 1];
}

int main() {
    long long n;
    StackEntry x, y, max;
    int type;
    Stack s;
    CreateStack(&s);
    
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &type);
        switch (type) {
            case 1:
               scanf("%lld", &x);
               Push(x, &s);
               break;
            case 2:
               Pop(&y, &s);
               break;
            case 3:
               Max(&max, &s);
               printf("%lld\n", max);
               break;
        }
    } 
    return 0;
}
