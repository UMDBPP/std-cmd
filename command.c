#include "command.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pico/stdlib.h"

const char *op_code_strings[] = {"nop",  "test", "text", "vent", "reset",
                                 "pos",  "term", "ack",  "nack", "err",
                                 "stat", "get",  "set"};

void parse_text_command(uint8_t *buf, command *cmd) {
    static char whitespace[] = " \t\f\r\v\n";
    char *token;
    int device_id = 0;

    token = strtok(buf, whitespace);

    device_id = atoi(token);

    cmd->device_id = device_id;

    token = strtok(buf, whitespace);

    if (strcmp(token, op_code_strings[TEXT]) == 0) {
        cmd->op = TEXT;
        cmd->handler = &text_handler;
    } else if (strcmp(token, op_code_strings[RESET]) == 0) {
        cmd->op = RESET;
        cmd->handler = &reset_handler;
    } else if (strcmp(token, op_code_strings[STAT]) == 0) {
        cmd->op = STAT;
        cmd->handler = &stat_handler;
    } else if (strcmp(token, op_code_strings[TEST]) == 0) {
        cmd->op = TEST;
        cmd->handler = &test_handler;
    } else if (strcmp(token, op_code_strings[VENT]) == 0) {
        cmd->op = VENT;
        cmd->handler = &vent_handler;
    } else if (strcmp(token, op_code_strings[POS]) == 0) {
        cmd->op = POS;
        cmd->handler = &pos_handler;
    } else if (strcmp(token, op_code_strings[TERM]) == 0) {
        cmd->op = TERM;
        cmd->handler = &term_handler;
    } else if (strcmp(token, op_code_strings[GET]) == 0) {
        cmd->op = GET;
        cmd->handler = &get_handler;
    } else if (strcmp(token, op_code_strings[SET]) == 0) {
        cmd->op = SET;
        cmd->handler = &set_handler;
    } else {
        cmd->op = NOP;
        cmd->handler = &no_op_handler;
    }

    // for (token = strtok(buf, whitespace); token !=)
}

void print_op_code(op_code op) {
    switch (op) {
        case NOP:
            printf("%s\n", op_code_strings[NOP]);
            break;
        case TEST:
            printf("%s\n", op_code_strings[TEST]);
            break;
        case TEXT:
            printf("%s\n", op_code_strings[TEXT]);
            break;
        case VENT:
            printf("%s\n", op_code_strings[VENT]);
            break;
        case RESET:
            printf("%s\n", op_code_strings[RESET]);
            break;
        case POS:
            printf("%s\n", op_code_strings[POS]);
            break;
        case TERM:
            printf("%s\n", op_code_strings[TERM]);
            break;
        case ACK:
            printf("%s\n", op_code_strings[ACK]);
            break;
        case NACK:
            printf("%s\n", op_code_strings[NACK]);
            break;
        case ERR:
            printf("%s\n", op_code_strings[ERR]);
            break;
        case STAT:
            printf("%s\n", op_code_strings[STAT]);
            break;
        case GET:
            printf("%s\n", op_code_strings[GET]);
            break;
        case SET:
            printf("%s\n", op_code_strings[SET]);
            break;
        default:
            printf("Invalid Op Code\n");
    }
}