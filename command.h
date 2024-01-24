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
void help_handler(uint8_t *args);

/**
 * Parses a command given in text form. Optionally can parse a Device ID if it
 * is the first token and contains_device_id is true.
 *
 * @param buf contains string buffer with command in text form
 * @param cmd command struct that will be filled based on the contents of buf
 * @param contains_device_id optional flag that enables parsing of an integer
 * Device ID, assumes the Device ID comes before the OP-Code
 */
void parse_text_command(uint8_t *buf, command *cmd, bool contains_device_id);
void print_op_code(op_code);
void print_command(command *cmd);



#endif