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
    if (fseek(fp, 0L, SEEK_END) == -1) {
		perror("fseek failed");
        fclose(fp);
		return NULL;
	}
    long length = ftell(fp);
	if (length == -1L) {
		perror("ftell failed");
        fclose(fp);
		return NULL;
	}
    if (fseek(fp, 0L, SEEK_SET) == -1) {
		perror("fseek failed");
        fclose(fp);
		return NULL;
	}
    char *data = malloc(sizeof(char) * (length+1));
    if (!data) {
        fprintf(stderr, "allocation failed: not enough memory %lu", length);
        fclose(fp);
        return NULL;
    }
    size_t read = fread(data, sizeof(char), length, fp);
    data[length] = '\0';
    if (read != length) {
        fclose(fp);
        free(data);
        fprintf(stderr,"read failed: %lu bytes but %lu expected\n", length, read);
        return NULL;
    }
    fclose(fp);
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
