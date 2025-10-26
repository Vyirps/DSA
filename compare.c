#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define EMPTY '~'
#define DELETED '!'
#define MAX 211

/*********************************/
/*    USER-DEFINED DATA TYPES    */
/*********************************/
typedef struct {
    char elem;
    int frequency;
} Element;

typedef Element Dictionary[MAX];

/*********************************/
/*       HELPER FUNCTIONS        */
/*********************************/
void initDict(Dictionary D);
int hash(char elem);

/*********************************/
/*          YOUR TASKS           */
/*********************************/

void insert(Dictionary D, char elem);
void delete(Dictionary D, char elem);
bool isMember(Dictionary D, char elem);
bool isAnagram(char* s, char* t);

int main(void) {
    char s1[100], s2[100];

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    if (isAnagram(s1, s2)) {
        printf("\"%s\" and \"%s\" are anagrams.\n", s1, s2);
    } else {
        printf("\"%s\" and \"%s\" are NOT anagrams.\n", s1, s2);
    }

    return 0;
}

/*********************************/
/*       HELPER FUNCTIONS        */
/*********************************/
void initDict(Dictionary D) {
    for (int i = 0; i < MAX; i++) {
        D[i].elem = EMPTY;
        D[i].frequency = 0;
    }
}

int hash(char elem) {
    return ((int)elem) % MAX;
}

/*********************************/
/*          YOUR TASKS           */
/*********************************/


void insert(Dictionary D, char elem) {
    // TODO: Implement insert with linear probing
    int key = hash(elem);

    for(int i = 0;i < MAX; i++, key = (key + 1) % MAX){
      if(D[key].elem == EMPTY || D[key].elem == DELETED){
        D[key].elem = elem;
        D[key].frequency += 1; 
        break;
      }

      if(D[key].elem == elem){
        D[key].frequency += 1; 
        break;
        
      }
    }
}

void delete(Dictionary D, char elem) {
  int key = hash(elem);
    for(int i = 0;i < MAX; i++, key = (key + 1) % MAX){
      if(D[key].elem == elem){
        D[key].frequency -= 1;
        if(D[key].frequency == 0){
          D[key].elem = DELETED;
        }
        break;
      }
    }
}


bool isMember(Dictionary D, char elem) {
    // TODO: Implement membership check
    int key = hash(elem);
        for(int i = 0;i < MAX; i++, key = (key + 1) % MAX){
          if(D[key].elem == elem && D[key].frequency > 0 ){
            return 1; 
          }
      }
    return 0;
}




bool isAnagram(char* s, char* t) {

  if(strlen(s) != strlen(t)){
    return 0;
  }
  
  Dictionary D;
  initDict(D);
    for(int i = 0;s[i] != '\0';i++){
      insert(D, s[i]);
    }

    for(int i = 0;t[i] != '\0';i++){
      delete(D, t[i]);
    }

    for(int i = 0;t[i] != '\0';i++){
       if(isMember(D, t[i])){
         return 0;
       }
    }
    return 1;

    

  

    
    
}