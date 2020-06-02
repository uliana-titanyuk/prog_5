#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[128];
    unsigned int group;
    double rating;
} Student;



Student** mass(FILE* input, int size) {
    char str[128];
    char sep[2] = " ";
    char* istr;
    Student** arrStud;
    arrStud = (Student**)malloc(size * sizeof(Student*));
    if (arrStud == NULL) {
        printf("Error! Can't allocate memory!\n");
    }
    for (int i = 0; i < size; i++) {
        fgets(str, sizeof(str), input);
        arrStud[i] = (Student*)malloc(sizeof(Student));
        istr = strtok(str, sep);
        strcpy(arrStud[i]->name, istr);
        istr = strtok(NULL, sep);
        arrStud[i]->group = atoi(istr);
        istr = strtok(NULL, sep);
        arrStud[i]->rating = atof(istr);
    }
    return arrStud;
}



int func(FILE* input) {
    FILE* output;
    Student** arrstud;
    Student** temp;
    char str[514];
    int size = 1;
    int m = 0;
    int s = 0;
    while (fgets(str, 514, input)) {
        size++;
    }
    s = size;
    rewind(input);
    arrstud = mass(input, size);
    if (arrstud == NULL) {
        return -1;
    }
    else {
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if ((strcmp(arrstud[i]->name, arrstud[j]->name) == 0) && (arrstud[i]->group == arrstud[j]->group)) {
                    if (arrstud[i]->rating < arrstud[j]->rating) {
                        arrstud[i]->rating = arrstud[j]->rating;
                    }
                    m++;
                    free(arrstud[j]);
                    for (int s = j; s < size - 1; s++) {
                        arrstud[s] = arrstud[s + 1];
                    }
                    j--;
                    size--;
                }
            }
        }
        if (m != 0) {
            temp = (Student**)realloc(arrstud, (s - m) * sizeof(Student*));
            if (temp) {
                arrstud = temp;
            }
        }
        output = fopen("res.txt", "w");
        for (int i = 0; i < s - m; i++) {
            fprintf(output, "%s ", arrstud[i]->name);
            fprintf(output, "%d ", arrstud[i]->group);
            fprintf(output, "%lf\n", arrstud[i]->rating);
        }
        for (int i = 0; i < s - m; i++) {
            free(arrstud[i]);
        }
        free(arrstud);
        fclose(output);
        return 0;
    }
}


void AutoTest(void) {
    FILE* input;
    FILE* output;
    char t[514];
    char str[64];
    char st[] = "Sam 123 5.000000";
    input = fopen("test.txt", "r++");
    if (!input) {
        printf("Error! Cannot open file !\n");
    }
    else {
        if (fgets(t, 514, input) == NULL) {
            printf("Error! Cannot read from file!\n");
            fclose(input);
        }
        else {
            func(input);
            fclose(input);
            output = fopen("res.txt", "r");
            fgets(str, sizeof(str), output);
            if (strcmp(st, str) == 0) {
                printf("Autotest passed\n");
            }
            else {
                printf("Autotest failed\n");
            }
            fclose(output);
        }
    }
}




int main(void) {
    FILE* input;
    char t[514];
    int f;
    input = fopen("text.txt", "r");
    AutoTest();
    if (!input) {
        printf("Error! Cannot open file !\n");
        return -1;
    }
    else {
        if (fgets(t, 514, input) == NULL) {   //
            printf("Error! Cannot read from file!\n");
            fclose(input);
            return -1;
        }
        else {
            f = func(input);
            if (f == 0) {
                return 0;
            }
            else {
                return -1;
            }
            fclose(input);
        }
    }
}