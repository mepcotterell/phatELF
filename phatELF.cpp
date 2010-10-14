/**
 * phatELF.cpp
 * @author Michael Cotterell <mepcotterell@gmail.com>
 * @see LICENSE
 */

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main(int argc, char **argv, char **env) {

	printf("2423\n");

	char cmdbuf[1024];

	/**
	 * The command below is credited to dummy00001 (http://stackoverflow.com/users/360695/dummy00001)
	 * source: http://stackoverflow.com/questions/3925075/how-do-you-extract-only-the-contents-of-an-elf-section
	 */
	sprintf(cmdbuf, "objdump -h %s | grep .phat | awk '{print \"dd if='%s' of='/tmp/2423.out' bs=1 count=$[0x\" $3 \"] skip=$[0x\" $6 \"]\"}' | bash 2> /dev/null", argv[0], argv[0]);

	system(cmdbuf);
	system("chmod +x /tmp/2423.out");
	
	execvpe("/tmp/2423.out", argv, env);
	
	return (EXIT_SUCCESS);

}
