all: clean testHashTable

hashTable:
	g++ -std=c++11 main.cpp hashtable.cpp -o hashTable.out

testHashTable: hashTable
	./hashTable.out >> result.txt
	cat result.txt
	diff -bB -I '#.*' test/expected.txt result.txt

clean:
	-rm hashTable.out result.txt
