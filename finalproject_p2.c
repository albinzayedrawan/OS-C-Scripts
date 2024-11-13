#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    pid_t pid = fork();

    // Error handling for fork
    if (pid < 0) {
        printf("Fork failed.\n");
    }
    // Child process
    else if (pid == 0) {
        // Get the current system time
        time_t dateDetails = time(NULL);
        struct tm* systemInfo = localtime(&dateDetails);

        // Print the day of the week
        char* weekDays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        int dayOfWeek = systemInfo->tm_wday;

        printf("Today's date is: %s\n", weekDays[dayOfWeek]);
    }
    // Parent process
    else {
        wait(NULL);
	
	//Print full date format 
        printf("Today's full date format is:\n");
        execl("/bin/date", "RetsysDateDetails", NULL);
    }

    return 0;
}