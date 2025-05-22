all: clean testBST

bst:
	gcc main.c binary_search_tree.c -o bst.out

testBST: bst
	echo "\n### TEST bst1.in\n" > result.txt
	cat test/bst1.in | ./bst.out >> result.txt
	echo "\n### TEST bst2.in\n" >> result.txt
	cat test/bst2.in | ./bst.out >> result.txt
	echo "\n### TEST bst3.in\n" >> result.txt
	cat test/bst3.in | ./bst.out >> result.txt
	cat result.txt
	diff -bB -I '#.*' test/expected.txt result.txt

clean:
	-rm bst.out bst bst.exe result.txt
