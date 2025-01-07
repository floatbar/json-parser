#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *parse(char body[], int pos) {
    const int size = strlen(body);
    char temp[size];

    int j = 0;
    
    for (int i = 1; i < size - 1; i++) {
        if (body[i] != '\"') {
            temp[j++] = body[i];
        }
    }
    
    temp[j] = '\0';
    
    char *elements = strtok(temp, ",");
    int index = -1;
    
    while (elements != NULL) {
        index++;
        if (index == pos) {
            char *pairs = strtok(elements, ":");
            return strtok(NULL, ":");
        }
        elements = strtok(NULL, ",");
    }
}

int main() {
    char body[] = "{\"username\": \"eloquent\", \"password\": \"Eloquent_1111\"}";

    const char *username = parse(body, 0);
    const char *password = parse(body, 1);

    printf("%s", username);
    printf("%s", password);
    
    return 0;
}
