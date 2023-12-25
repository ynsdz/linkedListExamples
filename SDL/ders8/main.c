#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma pack(1)

typedef struct TESTNODE
{
  char szAd[21];
  char szSoyad[21];
  void *pNext;
}TESTNODE;

void* pRoot = NULL;
void* AddHeadItem( char* szAd, char* szSoyad){
  TESTNODE *pNew = malloc ( sizeof( TESTNODE));

  if (pNew != NULL)
  {
    memset(pNew, 0 , sizeof(TESTNODE));
    strncpy(pNew->szAd , szAd , 20);
    strncpy(pNew->szSoyad , szSoyad , 20);

    pNew->pNext = pRoot;
    pRoot = pNew;
  }
  if(pNew==NULL){
    pRoot = pNew;
  }
  return pNew;
}

void ClearList ( ) { 
  TESTNODE *pSel = pRoot;
  while ( pSel != NULL) { 
    pRoot = pSel -> pNext; 
    free(pSel);
    pSel = pRoot; 
  }
}
void showList () { 
 TESTNODE *pNode = pRoot; 
  while ( pNode != NULL){
    printf(" Ad Soyad: %s %s \n" , pNode->szAd , pNode->szSoyad);
    pNode = pNode-> pNext; 
  }
}

int main( ) {
// Linked List ornegi
  AddHeadItem("Ahmet", "Falan");
  AddHeadItem("FDAF", "Falan");
  AddHeadItem("yunus", "dze");
  AddHeadItem("ahmet", "ismit");
  AddHeadItem("ayse", "kardelen");
  AddHeadItem("fatma", "huseiyn");


  showList();
  ClearList();

// Array ornegi random acces 
  /* TESTNODE *p = (TESTNODE* )malloc(sizeof(TESTNODE) * 1000);
  if( p != NULL){
    memset(p, 0, sizeof(TESTNODE)*1000);
    for ( int i = 0; i< 10; i++){
      sprintf(p[i].szAd, "Ad %d", (i+1));
      sprintf(p[i].szSoyad, "Soyad %d", (i+1));
    }

    for(int i =0; i<10; i++){
      printf("Ad Soyad: %s %s \n ", p[i].szAd, p[i].szSoyad);
    }
    free(p);
  }*/ 
  return 0;
}