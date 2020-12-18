#ifndef SAXML_C
#define SAXML_C

#include <stdio.h>
#include <stdbool.h>

typedef void (*doc_callback)(void *ctx);
typedef void (*elem_callback)(char *value,char **args, void *ctx);
typedef void (*char_callback)(char *value, void *ctx);


typedef struct {
    doc_callback start_doc_handler;
    doc_callback end_doc_handler;
    elem_callback start_elem_handler;
    elem_callback end_elem_handler;
    char_callback character_handler;
    void *ctx;
} xmlhandler;

int read_xml_document(char *path, xmlhandler *handler);

#endif
