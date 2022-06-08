#include "../include/linkedlist.h"
#include <stdlib.h>
#include <string.h>

static Node* _head = NULL;
static Node* _tail = NULL;
static Node* _cur_node = NULL;

bool empty()
{
    return _head == NULL;
}

size_t size()
{
    Node* it = NULL;
    size_t count = 0;
    if(empty()) return 0;
    
    it = _head;
    count = 1;
    while(it != _tail){
        ++count;
        it = it->next;
    }

    return count;
}

void print()
{
    print_file(stdout);
}

void print_file(FILE* stream)
{
    Node* it = _head;
    fprintf(stream, "LinkedList [");
    
    while(it != NULL){
        fprintf(stream, " %s", it->data);
        it = it->next;
    }

    fputs(" ]\n", stream);
}

void clear()
{
    Node* it = NULL;
    if(empty()) return;

    it = _tail;
    while(it != _head){
        it = it->prev;
        free(it->next->data);
        free(it->next);
    }
    free(it->data);
    free(it);

    _tail = NULL;
    _head = NULL;
    _cur_node = NULL;
}

static Node* CreateNode(size_t n, char new_data[])
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL)
        return NULL;
    
    new_node->next = NULL;
    new_node->data = (char*)malloc(sizeof(char) * n);

    if(new_node->data == NULL){
        free(new_node);
        return NULL;
    }

    strncpy(new_node->data, new_data, n);
    new_node->prev = NULL;
    return new_node;
}

Node* append_left(size_t n, char new_data[])
{
    Node* new_node = CreateNode(n, new_data);
    if(new_node == NULL) return NULL;
    if(empty()){
        _tail = new_node;
    }else{
        _head->prev = new_node;
        new_node->next = _head;
    }
    _head = new_node;
    return _cur_node = new_node;
}

Node* insert_after(Node* cur_node, Node* new_node)
{
    if(cur_node == NULL || new_node == NULL || cur_node == new_node)
        return NULL;

    if(new_node == _head){
        _head = _head->next;
        _head->prev = NULL;
    }else if(new_node == _tail){
        _tail = _tail->prev;
        _tail->next = NULL;
    }else if(new_node->next != NULL){
        new_node->next->prev = new_node->prev;
        new_node->prev->next = new_node->next;
    }

    if(cur_node->next != NULL)
        cur_node->next->prev = new_node;
    new_node->next = cur_node->next;
    new_node->prev = cur_node;
    cur_node->next = new_node;
    if(cur_node == _tail)
        _tail = new_node;
    return _cur_node = new_node;
}

Node* append(size_t n, char new_data[])
{
    Node* new_node = CreateNode(n, new_data);
    if(empty()) {
        _head = new_node;
        _tail = new_node;
        return _cur_node = new_node;
    }
    return insert_after(_tail, new_node);
}

Node* delete_node(Node* cur_node)
{
    Node* result = NULL;
    if(cur_node == NULL)
        return NULL;

    if(cur_node == _head)
        _head = _head->next;
    else
        cur_node->prev->next = cur_node->next;
    
    if(cur_node == _tail){
        _tail = _tail->prev;
        result = _tail;
    }else{
        cur_node->next->prev = cur_node->prev;
        result = cur_node->next;
    }

    free(cur_node->data);
    free(cur_node);

    return result;
}

Node* delete_by_data(char* data)
{
    Node* it = _head;
    while(it != NULL){
        Node* cur = it;
        it = it->next;
        if(strcmp(cur->data, data) == 0) {
            if(_cur_node == cur)
                _cur_node = delete_node(cur);
            else
                delete_node(cur);
        }
    }
    return NULL;
}

Node* get_node(size_t index)
{
    Node* it = _head;
    while(it != NULL && index--)
        it = it->next;
    return it;
}

Node* first()
{
    return _cur_node = _head;
}

Node* last()
{
    return _cur_node = _tail;
}

Node* next()
{
    if(_cur_node == NULL) return NULL;
    if(_cur_node->next == NULL) return _cur_node;
    return _cur_node = _cur_node->next;
}

Node* prev()
{
    if(_cur_node == NULL) return NULL;
    if(_cur_node->prev == NULL) return _cur_node;
    return _cur_node = _cur_node->prev;
}
