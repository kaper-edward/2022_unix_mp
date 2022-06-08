#include "../include/linkedlist.h"
#include "../include/textfilewriter.h"
#include <stdio.h>
#include <string.h>

typedef struct Command
{
	const char* name;
	void (*run)();
}Command;

void command_add();
void command_del();
void command_list();
void command_next();
void command_prev();
void command_move();
void command_play();
void command_clear();
void command_quit();
void command_load();
void command_save();

static char buffer[256];
static Node* current_node;

void add_initial_musics()
{
	int N;
	scanf("%d", &N);
	while(N--) command_add();
}

void process_commands()
{
	static Command commands[] = {
		{ "add", command_add },
		{ "del", command_del },
		{ "list", command_list },
		{ "next", command_next },
		{ "prev", command_prev },
		{ "move", command_move },
		{ "play", command_play },
		{ "clear", command_clear },
		{ "quit", command_quit },
		{ "load", command_load },
		{ "save", command_save },
	};
	size_t i;
	size_t commands_end = sizeof(commands)/sizeof(*commands);

	int M;
	scanf("%d", &M);
	while(M--){
		scanf("%s", buffer);
		for(i=0; i!=commands_end; ++i)
			if(strcmp(commands[i].name, buffer) == 0){
				commands[i].run();
				break;
			}

		if(i == commands_end)
			puts("Unknown command");
	}
}

int main()
{
	add_initial_musics();
	process_commands();
}

void command_add()
{
	scanf("%s", buffer);
	Node* p = current_node = append_left(256, buffer);
}

void command_del()
{
	scanf("%s", buffer);
	delete_by_data(buffer);
}

void command_list()
{
	print();
}

void command_next()
{
	current_node = next();
}

void command_prev()
{
	current_node = prev();
}

void command_move()
{
	int pos;
	scanf("%d", &pos);
	Node* p = current_node = insert_after(get_node(pos), current_node);
}

void command_play()
{
	printf("%s is now playing!\n", current_node->data);
}

void command_clear()
{
	puts("LinkedList is cleared!");
	clear();
}

#include "stdlib.h"

void command_quit()
{
	command_clear();
	puts("quit!");
	exit(0);
}

void command_load()
{
	scanf("%s", buffer);
	read_file(buffer);
}

void command_save()
{
	scanf("%s", buffer);
	write_file(buffer);
}
