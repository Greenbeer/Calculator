#include <stdio.h>

int main()
{
  int stack[256];
  char buf[256];
  int sp = 0;
  
  printf("Sample:\n2 3 + =\nResult = 5\n");
  while(!feof(stdin))
  {
    if(scanf ("%s", buf) != 1 )
      break;
      switch(buf[0])
      {
        case '\0':
          break;
        case '=':
          printf("Result = %d\n", stack[--sp]);
          break;
        case '+':
          stack[sp-2] = stack[sp-2] + stack[sp-1];
          sp--;
          break;
        case '-':
          stack[sp-2] = stack[sp-2] - stack[sp-1];
          sp--;
          break;
        case '*':
          stack[sp-2] = stack[sp-1] * stack[sp-2];
          sp--;
          break;
        case '/':
          stack[sp-2] = stack[sp-1] / stack[sp-2];
          sp--;
          break;
        default:
            stack[sp++] = atoi(buf);
      }
    }
    printf("Result = %d\n",stack[sp-1]);
    return 0;
}
