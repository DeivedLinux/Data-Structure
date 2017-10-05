#ifndef DATASTRUCTURE_H_
#define DATASTRUCTURE_H_

#include <stdbool.h>
#include <stdlib.h>

/*
Author: Deived William
  Date: 04/10/2017
Description:  
	Copyright Deived William
*/



#define newStaticQueue(type, size,name)          \
struct                         \
{                              \
    type obj[size];            \
    unsigned init;             \
    unsigned end;              \
    unsigned lenght;           \
    type fifo;                 \
}name;   

#define insertQueue(name, data) name.obj[name.end] = data; name.end += 1;
#define removeQueue(name)       name.fifo;


#define newStaticStack(type, size, name) \
struct                         \
{                              \
	type obj[size];            \
	unsigned top;              \
	unsigned end;              \
	unsigned lenght;           \
	type lifo;                 \
}name;

#define popStack(name)    name.lifo; name.top =+ 1;
#define pushStack(name, data)   name.obj[name.top] = data

typedef struct __List__
{
	void* information;
	void* previous;
	void* next;
}*List;

typedef struct __ArrayList__
{
	List list;

	void(*addListOrdered)(void*, struct __ArrayList__*);
	void(*addInit)(void*, struct __ArrayList__*);
	void(*addEnd)(void*, struct __ArrayList__*);
	void*(*seach)(void*, struct __ArrayList__*, bool(*isEqual)(void*, void*));
	bool(*remove)(void*, struct __ArrayList__*);
	void(*destroyList)(struct __ArrayList__*);
	unsigned size;
}*ArrayList;

typedef struct __DynamicStack__
{
	List list;

	void(*push)(void*, struct __DynamicStack__*);
	void*(*pop)(struct __DynamicStack__*);
	bool(*isEmpty)(struct __DynamicStack__*);
	void(*destroyStack)(struct __DynamicStack__*);
}*DynamicStack;

typedef struct __DynamicQueue__
{
	List list;

	void(*insert)(void*, struct __DynamicQueue__*);
	void(*get)(struct __DynamicQueue__*);
	bool(*isEmpty)(struct __DynamicQueue__*);
    void(*destroyQueue)(struct __DynamicQueue__*);
}*DynamicQueue;

typedef struct __Tree__
{
	void* father;
	void* left;
	void* right;
	void* information;
}*Tree;

typedef enum
{
	LEFT,
	RIGHT
}Side;

typedef struct __BinaryTree__
{
	Tree tree;
	void(*add)(void*, struct __BinaryTree__*);
}*BinaryTree;

ArrayList newArrayList();
void destroyArrayList(ArrayList arrayList);
BinaryTree newBinaryTree();
DynamicQueue newDynamicQueue();
DynamicStack newDynamicStack();
void destroyDynamicQueue(DynamicQueue dynamicQueue);
void destroyDynamicStack(DynamicStack dynamicStack);


#endif