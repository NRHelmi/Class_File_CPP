#include "file.h"

int main()
{   
	fichier f1("text1.txt","w+",15), f2("text2.txt","w+",15);
	fichier f3;
	system("clear");
	f1.write_text();
	f2.write_text();
	
	f3=f1+f2;
	f3.set_mode("r");
    f3.view_file();

	return(0);
}