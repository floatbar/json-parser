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

int main(void) {
    char body[] = "{\"username\":\"eloquent\", \"password\":\"Eloquent_1111\"}";

    const char *username_tmp = parse(body, 0);
    const char *password_tmp = parse(body, 1);
    
    char username[strlen(username_tmp)];
    char password[strlen(password_tmp)];
    
    strcpy(username, username_tmp);
    strcpy(password, password_tmp);
    
    printf("%s\n", username);
    printf("%s", password);
    
    return 0;
}
