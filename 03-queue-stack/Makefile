all: clean testArrayQueue testLinkedQueue testArrayStack testLinkedStack

arrayQueue:
	gcc array_queue.c array_list.c -o array_queue.out
linkedQueue:
	gcc linked_queue.c linked_list.c -o linked_queue.out
arrayStack:
	gcc array_stack.c array_list.c -o array_stack.out
linkedStack:
	gcc linked_stack.c linked_list.c -o linked_stack.out

testArrayQueue: arrayQueue
	cat test/test.in | ./array_queue.out > resultArrayQueue.txt
	cat resultArrayQueue.txt
	diff -bB -I '#.*' test/expectedQueue.txt resultArrayQueue.txt
testLinkedQueue: linkedQueue
	cat test/test.in | ./linked_queue.out > resultLinkedQueue.txt
	cat resultLinkedQueue.txt
	diff -bB -I '#.*' test/expectedQueue.txt resultLinkedQueue.txt
testArrayStack: arrayStack
	cat test/test.in | ./array_stack.out > resultArrayStack.txt
	cat resultArrayStack.txt
	diff -bB -I '#.*' test/expectedStack.txt resultArrayStack.txt
testLinkedStack: linkedStack
	cat test/test.in | ./linked_stack.out > resultLinkedStack.txt
	cat resultLinkedStack.txt
	diff -bB -I '#.*' test/expectedStack.txt resultLinkedStack.txt

clean:
	-rm *.out *.exe result*.txt array_queue linked_queue array_stack linked_stack array linked
