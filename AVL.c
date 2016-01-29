#include "AVL.h"




/**
 * Creates a new node for the AVL Tree.
 * Takes as inputs:
 * 		- A generic pointer to an item;
 * 		- The link to the left and right sons.
 * Returns the AVLlink to the node.
 */
AVLlink newNodeAVL(void *item, AVLlink l, AVLlink r){
	AVLlink x = (AVLlink) xmalloc(sizeof(struct avlNode));
	x->item = item;
	x->l = l;
	x->r = r;
	x->height = 0;
	return x;
}

AVLlink insertAVL(AVLlink h, void *item, int (*less)(void*, void*), void* (*Key_item)(void*) ){
	if (h == NULL)
		return newNodeAVL(item, NULL, NULL);
	if (less(Key_item(item), Key_item(h->item)))
		h->l = insertAVL(h->l, item, less, Key_item);
	else 
		h->r = insertAVL(h->r, item, less, Key_item);
	h=AVLbalance(h);
	return h;
}


AVLlink deleteAVL(AVLlink h, void *key, int (*less)(void*, void*), void* (*Key_item)(void*), void (*deleteItem)(void*)){/*lessequal tem de ser definido*/
	if (h==NULL) return h;
	else if (less(key, Key_item(h->item))) h->l=deleteAVL(h->l, key, less, Key_item, deleteItem);
	else if (less(Key_item(h->item),key)) h->r=deleteAVL(h->r, key, less, Key_item, deleteItem);
	else{
		if (h->l !=NULL && h->r !=NULL){
			AVLlink aux=max(h->l);
			{void* x; x=h->item; h->item=aux->item; aux->item=x;}
			h->l= deleteAVL(h->l, Key_item(aux->item), less, Key_item, deleteItem);
		}
		else{
			AVLlink aux=h;
			if (h->l == NULL && h->r == NULL) h=NULL;
			else if (h->l==NULL) h=h->r;
			else h=h->l;
			deleteItem(aux->item);
			free(aux);
		}
	}
	h=AVLbalance(h);
	return h;
}

void* getItemAVL(AVLlink h, void *key, int (*less)(void*, void*), void* (*Key_item)(void*)){
	if (h==NULL) return NULL;
	if (less(key, Key_item(h->item))) return getItemAVL(h->l, key, less, Key_item);
	else if (less(Key_item(h->item), key)) return getItemAVL(h->r, key, less, Key_item);
	return h->item; /*se nao é maior ou menor e o que queremos*/
}



void IOtraverseAVL(AVLlink h, void (*visit)(void*)){
	if (h == NULL) return;
	IOtraverseAVL(h->l, visit);
	visit(h->item);
	IOtraverseAVL(h->r, visit);
}


AVLlink max(AVLlink h) {
	if (h==NULL || h->r==NULL) return h;
	else return max(h->r);
}

AVLlink min(AVLlink h) {
	if (h==NULL || h->l==NULL) return h;
	else return min(h->l);
}

	
/**
 * Returns the height of a node. 0 = height of empty AVL Tree.
 */	
int height(AVLlink h){
	if (h == NULL) return -1;
	return h->height;
}



AVLlink rotR(AVLlink h) {
	int height_left, height_right;
	AVLlink x = h->l;
	h->l = x->r;
	x->r = h;

	height_left = height(h->l); height_right = height(h->r);
	h->height = height_left > height_right ? height_left + 1 : height_right + 1;
	height_left = height(h->l); height_right = height(h->r);
	x->height = height_left > height_right ? height_left + 1 : height_right + 1;
	return x;
}


AVLlink rotL(AVLlink h) {
	int height_left, height_right;
	AVLlink x = h->r;
	h->r = x->l;
	x->l = h;	

	height_left = height(h->l); height_right = height(h->r);
	h->height = height_left > height_right ? height_left + 1 : height_right + 1;
	height_left = height(h->l); height_right = height(h->r);
	x->height = height_left > height_right ? height_left + 1 : height_right + 1;
	return x;
}


AVLlink rotLR(AVLlink h){ /*rotação dupla esquerda direita*/
	if (h==NULL) return h;
	h->l = rotL(h->l);
	return rotR(h);
}


AVLlink rotRL(AVLlink h){ /*rotação dupla direita esquerda*/
	if (h==NULL) return h;
	h->r = rotR(h->r);
	return rotL(h);
}




int Balance(AVLlink h) {/*Balance factor*/
	if(h == NULL) return 0;
	return height(h->l)-height(h->r);
}





AVLlink AVLbalance(AVLlink h) {
	int balanceFactor;
	int height_left, height_right;
	if (h==NULL) return h;
	balanceFactor = Balance(h);

	if(balanceFactor>1){
		if (Balance(h->l)>0) h=rotR(h);
		else h=rotLR(h);

	}
	else if(balanceFactor<-1){
		if (Balance(h->r)<0) h = rotL(h);
		else h = rotRL(h);
	}
	else{
		height_left = height(h->l); 
		height_right = height(h->r);
		h->height = height_left > height_right ? height_left + 1 : height_right + 1;
	}
	return h;
}



void clearAVL(AVLlink h, void (*deleteItem)(void*)){
	if (h == NULL) return;
	clearAVL(h->l, deleteItem);
	clearAVL(h->r, deleteItem);
	deleteItem(h->item);
	free(h);
}



int countAVL(AVLlink h) {
	if (h==NULL) return 0;
	else return countAVL(h->r) + countAVL(h->l) + 1;
}










#ifdef test_AVL

#include "AUX_Provisorio.h"
#include "CLIENT.h"
#include "AUXILIARES.h"


int main(){
	int i;
	ClientP listC[5];
	AVLlink a = initAVL();
	for(i=0; i<5; i++){
	listC[i] = newClient(i +1 );
	}

	for (i = 0; i < 5; i++){
		a= insertAVL(a,listC[i], lessClient, Key_Client);
	}

	printf("%ld\n",getClientREF((ClientP) a->item));
	return 0;
}
#endif
