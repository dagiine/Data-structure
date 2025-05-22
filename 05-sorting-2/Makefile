all: clean testQuickSort testMergeSort

quickSort:
	gcc quick_sort.c -o quickSort.out

mergeSort:
	gcc merge_sort.c -o mergeSort.out

testQuickSort: quickSort
	echo "" > resultQS.txt
	echo "# Test 1:" >> resultQS.txt
	cat test/test1.in | ./quickSort.out >> resultQS.txt
	echo "# Test 2:" >> resultQS.txt
	cat test/test2.in | ./quickSort.out >> resultQS.txt
	echo "# Test 3:" >> resultQS.txt
	cat test/test3.in | ./quickSort.out >> resultQS.txt
	echo "# Test 4:" >> resultQS.txt
	cat test/test4.in | ./quickSort.out >> resultQS.txt
	echo "# Test 5:" >> resultQS.txt
	cat test/test5.in | ./quickSort.out >> resultQS.txt
	echo "# Test 6:" >> resultQS.txt
	cat test/test6.in | ./quickSort.out >> resultQS.txt
	echo "# Test 7:" >> resultQS.txt
	cat test/test7.in | ./quickSort.out >> resultQS.txt
	cat resultQS.txt
	diff -bB -I '#.*' test/expected.txt resultQS.txt

testMergeSort: mergeSort
	echo "" > resultMS.txt
	echo "# Test 1:" >> resultMS.txt
	cat test/test1.in | ./mergeSort.out >> resultMS.txt
	echo "# Test 2:" >> resultMS.txt
	cat test/test2.in | ./mergeSort.out >> resultMS.txt
	echo "# Test 3:" >> resultMS.txt
	cat test/test3.in | ./mergeSort.out >> resultMS.txt
	echo "# Test 4:" >> resultMS.txt
	cat test/test4.in | ./mergeSort.out >> resultMS.txt
	echo "# Test 5:" >> resultMS.txt
	cat test/test5.in | ./mergeSort.out >> resultMS.txt
	echo "# Test 6:" >> resultMS.txt
	cat test/test6.in | ./mergeSort.out >> resultMS.txt
	echo "# Test 7:" >> resultMS.txt
	cat test/test7.in | ./mergeSort.out >> resultMS.txt
	cat resultMS.txt
	diff -bB -I '#.*' test/expected.txt resultMS.txt

clean:
	-rm *.out *.txt *.exe quickSort mergeSort
