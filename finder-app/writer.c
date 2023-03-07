/**
 * @file writer.c
 * @author your name (you@domain.com)
 * @brief writes to a file and keeps a log
 */
#include <stdio.h>
#include <syslog.h>

int main(int argc, char *argv[]) {

    // Start the logging
    openlog(NULL, LOG_CONS, LOG_USER);

    // Check for at least two command line arguments
    if (argc < 3) {
        syslog(LOG_ERR, "Not enough arguments provided.");
        closelog();
        return 1;
    }

    // Get the filename and string to write
    const char * WRITEFILE = argv[1];
    const char * WRITESTR = argv[2];

    // Open the file, write the string, and close the file
    syslog(LOG_DEBUG, "Writing %s to %s", WRITESTR, WRITEFILE);
    int writeResult;
    int closeResult;
    FILE * writeFile;
    writeFile = fopen(WRITEFILE, "w");
    writeResult = fputs(WRITESTR, writeFile);
    closeResult = fclose(writeFile);

    // Report an error if one occurred
    if (writeResult <= 0) {
        syslog(LOG_ERR, "File write unsuccessful.");
        closelog();
        return 1;
    }
    if (closeResult == EOF) {
        syslog(LOG_ERR, "File close unsuccessful.");
        closelog();
        return 1;
    }

    closelog();
    return 0;
}
