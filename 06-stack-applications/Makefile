all: clean testBrackets testDec2bin testInfix2postfix

brackets:
	gcc brackets.c linked_stack.c linked_list.c -o brackets.out

dec2bin:
	gcc dec2bin.c linked_stack.c linked_list.c -o dec2bin.out

infix2postfix:
	gcc infix2postfix.c linked_stack.c linked_list.c -o infix2postfix.out

testBrackets: brackets
	echo "" > resultBrackets.txt
	cat test/brackets1.in | ./brackets.out >> resultBrackets.txt
	cat test/brackets2.in | ./brackets.out >> resultBrackets.txt
	cat test/brackets3.in | ./brackets.out >> resultBrackets.txt
	cat test/brackets4.in | ./brackets.out >> resultBrackets.txt
	cat resultBrackets.txt
	diff -bB -I '#.*' test/expectedBrackets.txt resultBrackets.txt

testDec2bin: dec2bin
	echo "" > resultDec2bin.txt
	echo $(cat test/dec2bin1.in)
	cat test/dec2bin1.in | ./dec2bin.out >> resultDec2bin.txt
	cat test/dec2bin2.in | ./dec2bin.out >> resultDec2bin.txt
	cat test/dec2bin3.in | ./dec2bin.out >> resultDec2bin.txt
	cat test/dec2bin4.in | ./dec2bin.out >> resultDec2bin.txt
	cat test/dec2bin5.in | ./dec2bin.out >> resultDec2bin.txt
	cat test/dec2bin6.in | ./dec2bin.out >> resultDec2bin.txt
	cat resultDec2bin.txt
	diff -bB -I '#.*' test/expectedDec2bin.txt resultDec2bin.txt

testInfix2postfix: infix2postfix
	echo "" > resultInfix2postfix.txt
	cat test/infix2postfix1.in | ./infix2postfix.out >> resultInfix2postfix.txt
	cat test/infix2postfix2.in | ./infix2postfix.out >> resultInfix2postfix.txt
	cat test/infix2postfix3.in | ./infix2postfix.out >> resultInfix2postfix.txt
	cat test/infix2postfix4.in | ./infix2postfix.out >> resultInfix2postfix.txt
	cat resultInfix2postfix.txt
	diff -bB -I '#.*' test/expectedInfix2postfix.txt resultInfix2postfix.txt

testInfix2postfixConversion: infix2postfix
	echo "" > resultInfix2postfix.txt
	cat test/infix2postfix1.in | ./infix2postfix.out >> resultInfix2postfix.txt
	cat test/infix2postfix2.in | ./infix2postfix.out >> resultInfix2postfix.txt
	cat test/infix2postfix3.in | ./infix2postfix.out >> resultInfix2postfix.txt
	cat test/infix2postfix4.in | ./infix2postfix.out >> resultInfix2postfix.txt
	cat resultInfix2postfix.txt
	diff -bB -I '[#~].*' test/expectedInfix2postfixConversion.txt resultInfix2postfix.txt

clean:
	-rm *.out result*.txt *.exe brackets dec2bin infix2postfix
