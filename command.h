#ifndef COMMAND_H
#define COMMAND_H

#include "pico/stdlib.h"

typedef enum Commands {
    NOP = 0,
    TEST,
    TEXT,
    VENT,
    RESET,
    POS,
    TERM,
    ACK,
    NACK,
    ERR,
    STAT,
    GET,
    SET
} op_code;

typedef struct Command {
    uint8_t device_id;
    op_code op;
    uint8_t params[7];
    void (*handler)(uint8_t *args);
} command;

// User-defined for now
void no_op_handler(uint8_t *args);
void test_handler(uint8_t *args);
void text_handler(uint8_t *args);
void vent_handler(uint8_t *args);
void reset_handler(uint8_t *args);
void pos_handler(uint8_t *args);
void term_handler(uint8_t *args);
void ack_handler(uint8_t *args);
void nack_handler(uint8_t *args);
void err_handler(uint8_t *args);
void stat_handler(uint8_t *args);
void get_handler(uint8_t *args);
void set_handler(uint8_t *args);

void parse_text_command(uint8_t *, command *);
void print_op_code(op_code);

#endif