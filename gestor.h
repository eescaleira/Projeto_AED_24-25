#ifndef GESTOR_H
#define GESTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>

typedef enum {
	BOOK,
	MAGAZINE,
	NEWSPAPER,
	CD,
	DVD,
	VIDEO,
	OTHER
} t_item_type;

typedef enum {
	ADD,
	REMOVE,
	RESERVE,
	CANCEL,
	LIST,
	SEARCH
} t_action;


typedef struct s_client{
	int id;
	char *name;
	char *surname;
	char *phone;
}	t_client;

typedef struct s_item{
	int id;
	int type;
	char *title;
	char *publisher;
	bool reserved;
	t_client *client;
	struct s_item *prev;
	struct s_item *next;
}	t_item;

t_item *make_list(void);
t_item *create_item(char *title, int id, int type, char *publisher);
#endif