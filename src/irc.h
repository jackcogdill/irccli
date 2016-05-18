#ifndef IRC_H
#define IRC_H

#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <glob.h>

#include "util.h"
#include "xterm.h"
#include "pcre_util.h"
#include "sock_util.h"

// Lovingly used from
// https://mybuddymichael.com/writings/a-regular-expression-for-irc-messages.html
// (slightly modified)
static const char *irc_regex = "^(?:[:](\\S+) )?(\\S+)(?: (?!:)(.+?))?(?: (?!:)(.+?))?(?: [:](.+?))?\\R?$";

// Channels names are strings (beginning with a '&' or '#' character)
// of length up to 200 characters.
// (https://tools.ietf.org/html/rfc1459#section-1.3)
static char current_channel[256];
static char nick[512];
static char user[512];
static char real[512];

// List of channels currently connected to
static char **channels;
static int csize = 0; // Number of channels in channels array

void irc_nick();
void irc_user();

int irc_parse(char src[512], char ***output);
int irc_receive(char *buffer, int R);
int irc_send(char *buffer);

void irc_clean();

#endif
