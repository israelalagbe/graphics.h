#ifndef ERROR_H
#define ERROR_H
#include <cstdio>
using namespace std;
class error{	
	 FILE * f;
	public:
		error(){
		    if ((f = fopen ("error.txt","a")) == NULL)	printf("\nCan't Open error file");
		    else{
		    log("---------Opening Error report-----------");
		}
		}
		error(const char * fname){
		    if ((f = fopen (fname,"a")) == NULL)	printf("\nCan't Open error file");
		    else{
		    log("---------Opening Error report-----------");
		}
		}
	void close(){
		log("---------Closing Error report-----------");
		if(f!=NULL) fclose(f);
	};
	void log(const char * message){
		if(f!=NULL) fprintf(f,"\n%s\n",message);
	};
		void log(int message){
		if(f!=NULL) fprintf(f,"\n%i\n",message);
	};
	 void log(double message){
	if(f!=NULL) fprintf(f,"\n%d\n",message);
	};
	~error(){
    this->close();
	};
};
#endif
