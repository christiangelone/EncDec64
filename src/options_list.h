/*
 * list.h
 *
 *  Created on: Mar 24, 2017
 *      Author: christian
 */

#ifndef LIST_H_
#define LIST_H_

#include <stdio.h>
//hay que probar este intento de lista

typedef struct{
	char * key;
	char * value;
} option;

typedef struct options {
    option opt;
    struct options * next;
} options;

options * head = NULL;
options * current = NULL;
int not_initialized = 1;

void add_option_to_option_list(option opt){
	if(not_initialized){
		head = malloc(sizeof(options));
		head->opt = opt;
		current = head->next;
		not_initialized = 0;
	}else{
		current = malloc(sizeof(options));
		current->opt = opt;
		current = current->next;
	}
	return;
}

options * get_option_list(){
	return head;
}

void delete_option_list(){
	while(head != NULL){
		options * tmp = head;
		head = head->next;
		free(tmp);
	}
	current = NULL;
	return;
}

#endif /* LIST_H_ */
