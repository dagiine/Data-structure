all: clean testArray testLinked

array:
	gcc prog_array.c -o prog_array.out
linked:
	gcc prog_linked.c -o prog_linked.out

demoArray:
	gcc test/demo_array.c array_list.c -o demo_array.out
demoLinked:
	gcc test/demo_linked.c linked_list.c -o demo_linked.out

testArray: demoArray
	./demo_array.out > resultArray.txt
	cat resultArray.txt
	diff -bB -I '#.*' test/expectedArray.txt resultArray.txt
testLinked: demoLinked
	./demo_linked.out > resultLinked.txt
	cat resultLinked.txt
	diff -bB -I '#.*' test/expectedLinked.txt resultLinked.txt

clean:
	-rm *.out *.exe result*.txt prog_array prog_linked demo_array demo_linked array linked
