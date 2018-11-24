#include <string.h>
#include <stdio.h>

void doJob();

int main()
{
    doJob();
}

void doJob() {
    char input[] = "1111011111111"; // Initialization, you can promote this variable as parameter.
    char buffer[sizeof(input) + 1] = ""; // Initialization to prevent stackoverflow.
    strcat(buffer, &input); 
    strcat(buffer, "0"); // An additional zero added at the end of array to prevent mis-calculation if inputs ends with "1".
    //Initialization starts
    int startPos = -1; 
    int startTempPos = 0;
    int endPos = -1;
    int endTempPos = sizeof(input);
    //Initialization ends
    int currentMaxLength = 0;  // A buffer variable to capture existing largest "1" sequence.
    _Bool inValueOne = 0; // A flag to indicate existing value is part of "1" sequence or not.
    int oneCount = 0; // Records total number for "1", considering all "1" and all "0" cases.
    for(int x = 0; x < sizeof(buffer) - 1; x++) {
        if(buffer[x] == 49) { // ASCII Value 49 is character "1".
            oneCount++;
            if(inValueOne == 0) {
                startTempPos = x;
                inValueOne = 1;
            }
        } else {
            endTempPos = x;
            if(inValueOne) { // If the zero found is still in "1" sequence, it will perform a "settlement".
                int length = endTempPos - startTempPos;
                if(currentMaxLength < length) {
                    startPos = startTempPos;
                    endPos = endTempPos;
                    currentMaxLength = length;
                }
            }
            inValueOne = 0; //Resetting this flag to allow Line 28 re-triggered.
        }
        printf("\n%d - %d - %d", startPos, endPos, currentMaxLength); // For debug purpose.
    }
    if(oneCount == 0) {
        startPos = -1;
        endPos = -1;
        currentMaxLength = 0;
    }
    if(oneCount == sizeof(input)) {
        startPos = 0;
        endPos = sizeof(input - 1);
        currentMaxLength = sizeof(input);
    }
    printf("\n%d - %d - %d", startPos, endPos, currentMaxLength);
}
