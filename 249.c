#include <stdio.h>
#include <string.h>

typedef struct employee {
  int id;
  char first_name[32];
  char last_name[32];
  int boss_id;
}Employee;

Employee w[32];
int people;

int who(char fname[32], char lname[32]){
  for(int i=0 ; i<people ; i++){
    if(strcmp(w[i].first_name, fname) == 0 && strcmp(w[i].last_name, lname) == 0) return i;
  }
  return -1;
}

int isboss(int a, int b){
  for(int i=0 ; i<people ; i++){
    if(w[a].boss_id == w[i].id){
      if(b == i) return 1;
      if(a == i) return 0;
      return isboss(i , b);
    }
  }
}

int bigboss(int a){
  for(int i=0 ; i<people ; i++){
    if(w[a].boss_id == w[i].id){
      if(a == i) return a;
      return bigboss(i);
    }
  }
}

int main(){

  scanf("%d", &people);
  for(int i=0 ; i<people ; i++)
    scanf("%d %s %s %d", &w[i].id, w[i].first_name, w[i].last_name, &w[i].boss_id);

  int m;
  scanf("%d", &m);
  for(int i=0 ; i<m ; i++){
    char fname1[32], lname1[32], fname2[32], lname2[32];
    scanf("%s %s %s %s", fname1, lname1, fname2, lname2);

    int a = who(fname1, lname1);
    int b = who(fname2, lname2);

    if(isboss(a, b)){ printf("subordinate\n"); }
    else{
      if(isboss(b, a)){ printf("supervisor\n"); }
      else{
        if(bigboss(a) == bigboss(b)){ printf("colleague\n"); }
        else{
          printf("unrelated\n");
        }
      }
    }
  }

  return 0;
}