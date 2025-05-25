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
	char	*name;
	char	*surname;
	int 	phone;
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
void print_item(t_item *item);
int list_length(t_item* head);
t_item* get_node_at(t_item* head, int index);

t_item* orderByIdItem(t_item* head);
t_item* orderbyname(t_item* head) ;
t_item* binary_search_by_id(t_item* head, int id);
void add_item(t_item *head, t_item *new_item);
void print_menu(t_item *item_list);
void remove_item(t_item *head, t_item *item_to_remove);
void client_info(t_item *item);
void free_client(t_client *client);
void print_list(t_item *head);
void free_list(t_item *head);
#endif