#include <iostream>
#include <cstdlib>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]){
	

	long n;
	if(argc >= 2){
		
		n = strtol(argv[1], NULL, 10);
	}
	int PID = getpid();
	
	for(int i = 1; i <= n; i ++){
		cout<<"Process: "<< PID << " " << i << "\n";
	}
	
	return n;
}
