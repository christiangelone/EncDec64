/*
 * list.h
 *
 *  Created on: Mar 24, 2017
 *      Author: christian
 */

#ifndef LIST_H_
#define LIST_H_

#include "options.h"

typedef struct options {
    option opt;
    struct options * next;
} options;

options * head = NULL;
options * current = NULL;

void add_option_to_front_of_options_list(option opt){

	options * new = (struct options *) malloc(sizeof(options));
	new->opt = opt;

	new->next = head;
	head = new;
}

void add_option_to_rear_of_options_list(option opt){

	options * new = (struct options *) malloc(sizeof(options));
	new->opt = opt;
	new->next = NULL;

	if(head == NULL && current == NULL){
		head = current = new;
	}else{
		current->next = new;
		current = new;
	}
}

void fill_options_list(int argc, char *argv[]){
	int i = 1;
	while(i < argc){
		option opt;
		opt.key = argv[i];
		if(i+1 < argc){
			opt.value = argv[i + 1];
		}else{
			opt.value = NULL;
		}
		add_option_to_rear_of_options_list(opt);
		i += 2;
	}
}

options * get_options_list(){
	return head;
}

int size_of_options_list(){
	options * tmp = head;
	int i = 0;
	while(tmp != NULL){
		tmp = tmp->next;
		i++;
	}
	return i;
}


option get_option_from_options_list(int index){
	options * tmp = head;
	int	i = 0;
	while(tmp != NULL && i < index ){
		tmp = tmp->next;
		i++;
	}
	return tmp->opt;
}

int is_option_key_present_in_options_list(option opt){
	int is_present = 0;

	int i = 0;
	while(i < size_of_options_list()){
		option opt_from_list = get_option_from_options_list(i);
		if(optcmp_key(opt_from_list,opt)){
			is_present = 1;
			return is_present;
		}
		i++;
	}
	return is_present;
}

char * get_option_value_from_options_list(option opt){

	char * value = NULL;

	int i = 0;
	while(i < size_of_options_list()){
		option opt_from_list = get_option_from_options_list(i);
		if(optcmp_key(opt_from_list,opt)){
			value = opt_from_list.value;
			return value;
		}
		i++;
	}
	return value;
}

int is_empty_options_list(){
	return head == NULL;
}

void delete_options_list(){
	while(head != NULL){
		options * tmp = head;
		head = head->next;
		free(tmp);
	}
	current = NULL;
	return;
}

#endif /* LIST_H_ */
