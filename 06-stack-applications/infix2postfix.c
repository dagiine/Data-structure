#include "linked_list.h"
#include "linked_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
/* infix илэрхийллийг postfix илэрхийлэлд хөрвүүлэх
 * эхний параметр char* нь infix илэрхийлэл
 * хоёр дахь параметр char*-д үүссэн postfix илэрхийллийг хадгална
 * postfix илэрхийллийн уртыг буцаана */
int daraalal(char op) {
  if (op == '+' || op == '-') return 1;
  if (op == '*' || op == '/') return 2;
  return 0;
}

int infix2postfix(char *infix, char *postfix) {
    char stack[100];
    int top = -1, j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isdigit(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--;
        } else {
            while (top != -1 && daraalal(stack[top]) >= daraalal(ch)) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }
    while (top != -1) {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
    return j;
}
/* postfix илэрхийллийг бодож, хариуг олох
 * эхний параметр char* нь postfix илэрхийлэл
 * хоёр дахь параметр int нь postfix илэрхийллийн урт */
int evaluate_postfix(char *postfix, int len) {
    int stack[100], top = -1;

    for (int i = 0; i < len; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            stack[++top] = ch - '0'; // ASCII-г тоо руу хөрвүүлж стект хийнэ
        } else {
            int b = stack[top--];
            int a = stack[top--];

            switch (ch) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
            }
        }
    }

    return stack[top];
}

int main() {
  // бодлогыг хялбарчлах үүднээс тогтмол 100 урттай тэмдэгт мөр үүсгэсэн
  // мөн илэрхийлэлд зөвхөн +-*/() оператор, нэг оронтой тоо л хэрэглэнэ
  //
  // Санамж 1: гараас уншсан тэмдэгт мөр '\0' тэмдэгтээр төгсдөгийг санаарай.
  // Санамж 2: шаардлагагүй бол main() функцэд өөрчлөлт оруулахгүй байх.
  char infix[100], postfix[100];
  scanf("%s", infix);
  int j = infix2postfix(infix, postfix);
  for (int i = 0; i < j; i++) {
    printf("%c ", postfix[i]);
  }
  printf("\n");
  printf("~ %s == %d\n", infix, evaluate_postfix(postfix, j));
  return 0;
}