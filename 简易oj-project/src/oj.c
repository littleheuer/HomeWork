#include <stdio.h>
#include "run.h"

int main()
{
	const char *name_program = "./program";
	const char *name_in = "./in.txt";
	const char *name_out = "./out.txt";
	const char *name_right = "./right.txt";
	run(name_program, name_in, name_out);
	FILE *fpright = fopen(name_right, "r");
	FILE *fpout = fopen(name_out, "r");

	// Input your code here.
    int flag = 1;
    char ch1, ch2;
    int re1, re2;
    while(flag) {
        re1 = fscanf(fpright,"%c", &ch1);
        re2 = fscanf(fpout, "%c", &ch2);
        if(re1 == EOF || re2 == EOF) break;
        if(ch1 != ch2) flag = 0;
    }
    if(flag) {
        if(re1 != EOF || re2 != EOF) {
            if(re1 != EOF) {
                re2 = fscanf(fpout, "%c", &ch2);
                flag = (re2 == EOF) ? 1 : 0;
            } else {
                re1 = fscanf(fpright, "%c", &ch1);
                flag = (re1 == EOF) ? 1 : 0;
            }
        }
    }
    printf("%s\n", flag ? "Accept" : "Wrong");
	fclose(fpout);
	fclose(fpright);
	return 0;
}
