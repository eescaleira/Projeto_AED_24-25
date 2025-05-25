#include "gestor.h"

void free_item(t_item *item) {
	if (item) {
		free(item->title);
		free(item->publisher);
		free(item->client);
		free(item);
	}
}

void free_client(t_client *client) {
	if (client) {
		free(client->name);
		free(client->surname);
		free(client);
	}
}

void free_list(t_item *head) {
	t_item *current = head;
	t_item *next;

	while (current) {
		next = current->next;
		if(current->client) {
			free_client(current->client);
		}
		free_item(current);
		current = next;
	}
}