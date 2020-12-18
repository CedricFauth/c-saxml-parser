#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "saxml.h"

char *read_file(char *path) {
    FILE *fp = fopen(path, "r");
    if (!fp) {
        perror("open file failed");
        return NULL;
    }
    fseek(fp, 0L, SEEK_END);
    long length = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    char *data = malloc(sizeof(char) * (length+1));
    if (!data) {
        fprintf(stderr, "allocation failed: not enough memory %lu", length);
        return NULL;
    }
    size_t read = fread(data, sizeof(char), length, fp);
    fclose(fp);
    data[length] = '\0';
    if (read != length) {
        free(data);
        fprintf(stderr,"read failed: %lu bytes but %lu expected\n", length, read);
        return NULL;
    }
	printf("read: %zu bytes\n", read);
    return data;
}

int read_xml_document(char *path, xmlhandler *handler) {
    char *data = read_file(path);
    printf("%s\n", data);
    // TODO
    free(data);
    return 0;
}
