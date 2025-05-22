all: clean testBinaryTree

binaryTree:
	gcc main.c binary_tree.c -o binary_tree.out

demoBinaryTree:
	gcc test/main.c binary_tree.c -o demo_binary_tree.out

testBinaryTree: demoBinaryTree
	./demo_binary_tree.out > result.txt
	cat result.txt
	diff -bB -I '#.*' test/expected.txt result.txt

clean:
	-rm *.out *.exe result*.txt binary_tree demo_binary_tree
