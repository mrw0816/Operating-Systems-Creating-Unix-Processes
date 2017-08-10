#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <sys/wait.h>
#include <stdio.h>


using namespace std;

int main(int argc, char *argv[]){


	
	pid_t pid;
	pid = fork();
	
	if(pid < 0){
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}

	if(pid == 0){
			
		execl("./counter","counter", "5", (char*) NULL);
	}else{
		cout<<"Child PID: "<<pid<<endl;
		cout<<"Parent PID: "<<getpid()<<endl;
		int status;
		int w = waitpid(pid, &status, 0);

		if(WIFEXITED(status)){
			cout<<"Process " << pid << " exited with status: "<< WEXITSTATUS	(status)<<endl;	
			exit(EXIT_SUCCESS);
		}else if( w == -1 ){
			perror("Error with waitpid()");
			exit(EXIT_FAILURE);
		}else{
			perror("Child did not exit properly");
			exit(EXIT_FAILURE);
		}
	}


}
