#include "HashTable.h"
#include <algorithm> 
#include <chrono> 
#include <fstream>
using namespace std::chrono;


int main(int argc, char** argv) {
	

	FILE* fpointer;
	fpointer = fopen("results.txt", "a");
	auto start = high_resolution_clock::now();
	Hash HashObj;
	HashObj.AddItem("Andrew", "1");
	HashObj.AddItem("Ryan", "1");
	HashObj.AddItem("Andrew", "2");
	HashObj.AddItem("Andrew", "3");
	HashObj.AddItem("Andrew", "4");
	HashObj.AddItem("Andrew", "5");
	HashObj.AddItem("Leo", "1");
	HashObj.AddItem("Chandler", "1");
	HashObj.AddItem("Brandon", "1");
	HashObj.AddItem("Liam", "1");
	HashObj.AddItem("Noah", "1");
	HashObj.AddItem("Oliver", "2");
	HashObj.AddItem("William", "3");
	HashObj.AddItem("Elijah", "4");
	HashObj.AddItem("James", "5");
	HashObj.AddItem("Benjamin", "1");
	HashObj.AddItem("Lucas", "1");
	HashObj.AddItem("Mason", "1");
	
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	int time = duration.count();

	fprintf(fpointer, "%d",time);
	fprintf(fpointer, "\n");
	fclose(fpointer);

	

	return 0;
}