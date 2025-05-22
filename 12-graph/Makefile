all: clean testGraph testMaze

graph:
	gcc main.c graph.c -o graph.out -lm

testGraph: graph
	echo "\n### TEST graph1.in\n" > result.txt
	cat test/graph1.in | ./graph.out >> result.txt
	echo "\n### TEST graph2.in\n" >> result.txt
	cat test/graph2.in | ./graph.out >> result.txt
	echo "\n### TEST graph3.in\n" >> result.txt
	cat test/graph3.in | ./graph.out >> result.txt
	cat result.txt
	diff -bB -I '#.*' test/expected.txt result.txt

testMaze: graph
	echo "\n### TEST maze1.in\n" > resultMaze.txt
	cat test/maze1.in | ./graph.out >> resultMaze.txt
	echo "\n### TEST maze2.in\n" >> resultMaze.txt
	cat test/maze2.in | ./graph.out >> resultMaze.txt
	cat resultMaze.txt
	diff -bB -I '#.*' test/expectedMaze.txt resultMaze.txt

clean:
	-rm graph.out graph graph.exe result.txt resultMaze.txt
