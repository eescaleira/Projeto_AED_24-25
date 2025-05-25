#include "gestor.h"
 
int main(){ 
	t_item *item_list = make_list();
	if (item_list == NULL) {
		printf("Failed to create item list\n");
		return -1;
	}
    t_item *temp = item_list;
    print_menu(item_list);
    printf("\n\n");
    temp = orderByIdItem (item_list);
    while (temp) {
        print_item(temp);
        temp = temp->next;
    }
	return 0;
}