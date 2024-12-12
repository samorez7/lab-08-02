#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

void remove_extra_spaces(const char* input_file, const char* output_file) {
    FILE* in_file = fopen(input_file, "r");
    FILE* out_file = fopen(output_file, "w");

    if (in_file == NULL || out_file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), in_file)) {
        int i = 0, j = 0;
        int in_space = 0;

        while (line[i] != '\0') {
            // Check for spaces
            if (line[i] == ' ') {
                if (!in_space) {
                    line[j++] = line[i]; // Keep one space
                    in_space = 1; // Set flag to indicate we are in space
                }
            }
            else {
                line[j++] = line[i]; // Copy non-space characters
                in_space = 0; // Reset space flag
            }
            i++;
        }
        line[j] = '\0'; // Null-terminate the modified string

        // Write the modified line to the output file
        fputs(line, out_file);
    }

    fclose(in_file);
    fclose(out_file);
}

int main() {
    const char* input_file = "input.txt"; // Input file name
    const char* output_file = "output.txt"; // Output file name

    remove_extra_spaces(input_file, output_file);

    printf("Extra spaces removed and written to %s\n", output_file);
    return 0;
}