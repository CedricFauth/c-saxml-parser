#include <stdio.h>
#include "saxml.h"

void start_doc(void *ctx) { }

void end_doc(void *ctx) { }

void start_elem(char *key, char **args, void *ctx) { }

void end_elem(char *key, char **args, void *ctx) { }

void character(char *key, void *ctx) { }

int main(void) {
    xmlhandler handler;
    handler.start_doc_handler = &start_doc;
    handler.end_doc_handler = &end_doc;
    handler.start_elem_handler = &start_elem;
    handler.end_elem_handler = &end_elem;
    handler.character_handler = &character;
    handler.ctx = NULL;

    read_xml_document("tests/test.xml", &handler);

    printf("Hello World\n");
}
