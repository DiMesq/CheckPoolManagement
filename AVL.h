#ifndef _AVL_H_
#define _AVL_H_

#include <stdio.h>
#include <stdlib.h>
#include "Xmalloc.h"




/**
 * Defines the type avlNode, where AVLlink is the pointer to the structure
 * The type contains:
 * 			- a pointer to the item of the node;
 *			- the pointer to the left and right nodes;
 */
typedef struct avlNode{
	void *item;
	struct avlNode *l, *r;
	int height;
}*AVLlink;


/**
 * Returns an empty AVL Tree.
*/
#define initAVL() NULL

/**
 * Checks if the tree is empty.
 * Takes an AVLlink as input.
 * Returns 1 if the Tree is empty (can be used with sub trees), 0 if not.
 */
#define emptyAVL(A) (!(A))


/**
 * Creates a new node for the AVL Tree.
 * Takes as inputs:
 * 		- A generic pointer to an item;
 * 		- The link to the left and right sons.
 * Returns the AVLlink to the node.
 */
AVLlink newNodeAVL(void *item, AVLlink l, AVLlink r);



/**
 * Inserts a new element to the AVL Tree.
 * This element will be insert respecting the rules of AVL Trees.
 * The inputs are:
 *		- the AVLlink of the tree;
 *		- a generic pointer to the item to be inserted;
 *		- a function to compare the keys from items;
 *		- a function that returns a generic pointer to the key of an item.
 * Returns the new head of the Tree.
 */
AVLlink insertAVL(AVLlink h, void *item, int (*less)(void*, void*), void* (*Key_item)(void*));


/**
 * Removes the element in a Tree which key matches the given key.
 * The element is removed respecting the rules of AVL Trees.
 * The inputs are:
 *		- the AVLlink of the tree;
 *		- a generic pointer to the key to find;
 *		- a function to compare the keys from items;
 *		- a function that returns a generic pointer to the key of an item;
 *		- a function that frees the item.
 * Returns the new head of the Tree.
 */
AVLlink deleteAVL(AVLlink h, void *key, int (*less)(void*, void*), void* (*Key_item)(void*), void (*deleteItem)(void*));


/**
 * Searches the element in a Tree which key matches the given key.
 * The inputs are:
 *		- the AVLlink of the tree;
 *		- a generic pointer to the key to find;
 *		- a function to compare the keys from items;
 *		- a function that returns a generic pointer to the key of an item;

 */
void* getItemAVL(AVLlink h, void *key, int (*less)(void*, void*), void* (*Key_item)(void*));


void IOtraverseAVL(AVLlink h, void (*visit)(void*));


AVLlink max(AVLlink h) ;

AVLlink min(AVLlink h) ;

int height(AVLlink h);

AVLlink rotR(AVLlink h) ;

AVLlink rotL(AVLlink h) ;

AVLlink rotLR(AVLlink h);/*rotação dupla esquerda direita*/

AVLlink rotRL(AVLlink h);/*rotação dupla direita esquerda*/

int Balance(AVLlink h) ;/*Balance factor*/

AVLlink AVLbalance(AVLlink h) ;

void clearAVL(AVLlink h, void (*deleteItem)(void*));

int countAVL(AVLlink h);

#endif
