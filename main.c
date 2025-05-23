#include "gestor.h"

int main(){
	t_item *item_list = make_list();
	if (item_list == NULL) {
		fprintf(stderr, "Failed to create item list\n");
		return EXIT_FAILURE;
	}
	while(item_list != NULL){
		printf("Item ID: %i\n", item_list->id);
		item_list = item_list->next;
	}
	return 0;
}