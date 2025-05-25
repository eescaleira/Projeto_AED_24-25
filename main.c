#include "gestor.h"
 
int main(){ 
	t_item *item_list = make_list();
	if (item_list == NULL) {
		printf("Failed to create item list\n");
		return -1;
	}
    print_menu(item_list);
	return 0;
}