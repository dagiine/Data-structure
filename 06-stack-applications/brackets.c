#include "linked_list.h"
#include "linked_stack.h"
#include <stdio.h>
#include <stdlib.h>

/* хаалт зөв нээгдэж, хаагдсан эсэхийг шалгана
 * зөв бол 1, буруу бол 0 утга буцаана
 * жишээ: {([])} -> 1 буюу зөв
 * жишээ 2: ([{}) -> 0 буюу буруу, дөрвөлжин хаалт "]" хаагдаагүй */
int isPerfect(char open, char close) {
  return (open == '(' && close == ')') ||
         (open == '{' && close == '}') || 
         (open == '[' && close == ']');
}

int checkBrackets(char *expression) {
  char stack[1000];
  int top = -1;
  for (int i = 0; expression[i] != '\0'; i++) {
    char ch = expression[i];

    if (ch == '(' || ch == '{' || ch == '[') {
        stack[++top] = ch;
    } 
    else if (ch == ')' || ch == '}' || ch == ']') {
        if (top == -1) 
          return 0;

        if (!isPerfect(stack[top--], ch)) {
            return 0;
        }
    }
  }
  return (top == -1);
}

int main() {
  // {}, [], () хаалтуудыг шалгана
  // алдаагүй бол "ALDAAGUI", алдаатай бол "ALDAATAI" гэж хэвлэнэ
  //
  // Санамж 1: гараас уншсан тэмдэгт мөр '\0' тэмдэгтээр төгсдөгийг санаарай
  // Санамж 2: шаардлагагүй бол main() функцэд өөрчлөлт оруулахгүй байх.
  char exp[1000];
  scanf("%s", exp);
  if (checkBrackets(exp)) {
    printf("ALDAAGUI\n");

  } else {
    printf("ALDAATAI\n");
  }
  return 0;
}