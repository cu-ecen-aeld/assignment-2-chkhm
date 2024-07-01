
/*
 * The application should do the same as this shell script:
 * 
 *   if [ $# -lt 2 ]; then
 *       echo "need to parameters: first parameter is a writefile and second is writestr string"
 *       exit 1
 *   fi
 *
 *   writefile=$1
 *   writestr=$2
 *
 *   mkdir -p "$(dirname $writefile)"
 *   echo "${writestr}" > ${writefile}
 *
 * 
 * - We don't have to check/ create the path
 * - However, errors should be logged with syslog using the LOG_USER facility with LOG_ERR level.
 * - Also, success messages should go to the syslog: "Writing <string> to <file>" but with LOG_USER facility,
 *   and LOG_DEBUG level.
 */

#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char **argv) {

    char *ident = NULL;

    openlog(ident, 0, LOG_USER);

    if (argc < 3) {
        syslog(LOG_ERR, "needed two parameters: first parameter is a writefile and second is a writestr");
        /* fprintf(stderr, "needed two parameters: first parameter is a writefile and second is a writestr\n"); */
        exit(1);
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];

    FILE *f = fopen(writefile, "w");

    if (f == NULL) {
        syslog(LOG_ERR, "Error opening file %s with error message %m.", writefile);
        /* perror("Error opening file"); */
        exit(1);
    }

    int bytes_written = fprintf(f, "%s\n", writestr);
    if (bytes_written < 0) {
        syslog(LOG_ERR, "Error writing string to file with error message %m");
        perror("Error writing string to file.");
        exit(1);
    }
    fclose(f);
    syslog(LOG_DEBUG, "File %s with content %s created", writefile, writestr);
    /* printf("file %s with content %s created\n", writefile, writestr); */
    
    closelog();
    return 0;
}