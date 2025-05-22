all: clean testBST

bst:
	gcc main.c binary_search_tree.c -o bst.out

testBST: bst
	cat test/bst1.in | ./bst.out > result.txt
	cat test/bst2.in | ./bst.out >> result.txt
	cat test/bst3.in | ./bst.out >> result.txt
	cat result.txt
	diff -bB -I '#.*' test/expected.txt result.txt

clean:
	-rm bst.out result.txt
