#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma pack(1)

typedef struct NODE { 
  char szAd[20];
  char szSoyad[20];
  short szYas;
  void *pNext; 
}NODE; 

NODE *pRoot = NULL;
void* AddNewItem(char* szAd, char* szSoyad, short szYas) { 
  NODE *pNew = malloc(sizeof(NODE));
  if( pNew!= NULL){
    memset(pNew, 0 , sizeof(NODE));
    strncpy(pNew->szAd, szAd, 20);
    strncpy(pNew->szSoyad, szSoyad, 20);
    pNew->szYas = szYas; 


    pNew->pNext = pRoot;
    pRoot = pNew; 
  }if(pNew==NULL){
    pRoot = pNew;
  }return pNew; 
}
void showList (NODE* pNode)  {
  NODE* current = pNode;
  while( current != NULL){
    printf(" Ad Soyad Yas: %s %s %i\n", current->szAd, current->szSoyad, current->szYas);
    current = current->pNext ;
  }
}
void searchItem (char name[20] ) { 
  NODE *current = pRoot;
  int counter= 1;

  while ( strcmp(name, current->szAd)){
    current =  current->pNext; 
    counter++;
  }
  printf("%d.de  buldu \n",counter );
}

void* reverseList  ( NODE* head) { 
    NODE *prev = NULL;
    NODE *next = NULL;
    while(head!= NULL){
      next = head->pNext;
      head->pNext = prev;
      prev = head;
      head =next;
    }
    head = prev;
    return head; 
}
void clearList () { 
  NODE *pSel = pRoot;
  while(pSel != NULL) { 
    pRoot = pSel -> pNext; 
    free(pSel);
    pSel = pRoot;    
  }
}
void findItem ( int index ) { 
  int k = 0;
  pRoot = reverseList(pRoot); 
  while ( k < index-1)
  {
    pRoot = pRoot->pNext;
    k++;
  }
    printf(" Ad Soyad Yas: %s %s %i\n", pRoot->szAd, pRoot->szSoyad, pRoot->szYas);
}


void deleteItem ( NODE **head, int position ){ 
  NODE *prev = *head; 
  NODE *current = *head;

  if ( *head==NULL) {
    printf("");
  }
  else if ( position == 1) {
    *head  = current-> pNext; 
    free(current) ; 
    current = NULL;
  }else {
    while ( position != 1  ){
        prev = current;
        current = current->pNext;
        position--;
    }
    prev->pNext = current->pNext;
    free(current);
    current= NULL;
  }
}

void insertItem( NODE **head ,NODE *newNode , int position) { 
  NODE *prev = *head;
    if( position == 1) {
      newNode->pNext= *head;
      *head = newNode;
    }
    else  {
      position--;   
        while(position!=1){
        prev =prev->pNext;
        position--;
        }
      newNode->pNext =prev->pNext;
      prev->pNext = newNode;
  }
}

int main( ) {
  AddNewItem("pataes", "surat",10 );
  AddNewItem("Ahmet", "Falan",20);
  AddNewItem("FDAF", "Falan",30);
  AddNewItem("yunus", "dze" ,42);
  AddNewItem("ayse", "kardelen",24);
  AddNewItem("ahmet", "ismet",31);

  NODE *NewPerson = malloc(sizeof(NODE));
  // memset(NewPerson, 0 , sizeof(NODE));
  strncpy(NewPerson->szAd, "kareteci", 20);
  strncpy(NewPerson->szSoyad, "joe", 20);
  NewPerson->szYas = 69; 
  NewPerson->pNext =NULL;


  insertItem(&pRoot , NewPerson, 1);
  showList(pRoot);
  return 0;
}