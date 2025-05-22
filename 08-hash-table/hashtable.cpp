#include "hashtable.h"
#include <iostream>

using namespace std;

void printStudent(struct Student *s) {
  cout << s->id << " " << s->fname << " " << s->lname << " " << s->major << " "
       << s->level << " " << s->gpa << endl;
}

void printList(struct Student *l) {
  cout << "#Students (" << length(l) << "):" << endl;
  while (l != NULL) {
    cout << "#\t - ";
    printStudent(l);
    l = l->next;
  }
}

void printHash(Student **hasharray, int size) {
  for (int i = 0; i < size; i++) {
    if (hasharray[i] == NULL)
      continue;
    cout << "#" << i << endl;
    printList(hasharray[i]);
  }
}

void makeEmpty(Student *l) {
  Student *ptr;
  while (l != NULL) {
    ptr = l->next;
    l->level = 0;
    l->gpa = 0;
    l->next = NULL;
    delete l;
    l = ptr;
  }
}

Student *find(Student *l, string id) {
  while (l != NULL) {
    if (l->id == id) {
      return l;
    }
    l = l->next;
  }
  return NULL;
}

int findI(Student *l, string id) {
  int index = 0;
  while (l != NULL) {
    if (l->id == id)
      return index;
    l = l->next;
    index++;
  }
  return -1;
}

int hashf(string id) {
  long hash = 0;
  for (char c : id)
    hash = (hash * 13 + c) % 10000;
  return hash;
}

void hashInsert(Student **hasharray, Student *l) {
  int index = hashf(l->id);
  l->next = hasharray[index];
  hasharray[index] = l;
}

void hashInsert(Student **hasharray, string id, string fname, string lname,
                string major, int level, float gpa) {
  // TODO: хэрэгжүүлэх
  Student *t = new Student;
  t->id = id;
  t->fname = fname;
  t->lname = lname;
  t->major = major;
  t->gpa = gpa;
  t->level = level;
  hashInsert(hasharray, t);
}

Student *search(Student **hasharray, string id) {
  int index = hashf(id);
  return find(hasharray[index], id); 
}

void remove(Student **l, int j) {
  if (*l == NULL) 
    return; 

  if (j == 0) {
    Student *temp = *l;
    *l = (*l)->next; 
    delete temp;
    return;
  }

  Student *prev = *l;
  for (int i = 0; i < j - 1 && prev->next != NULL; i++) {
    prev = prev->next;
  }

  if (prev->next == NULL) 
    return;

  Student *temp = prev->next;
  prev->next = temp->next;
  delete temp;
}

void hashRemove(Student **hasharray, string id) {
  int index = hashf(id);
  removeById(&hasharray[index], id);
}

void removeById(Student **l, string id) {
  // TODO: хэрэгжүүлэх
  int j = findI(*l, id);
  if (j > -1) {
    remove(l, j);
  }
}

Student *findKth(Student *l, int k) {
  int i = 0;
  while (l != NULL) {
    if (i == k)
      return l;
    l = l->next;
    i++;
  }
  return NULL;
}

int length(Student *l) {
  int c = 0;
  while (l != NULL) {
    c++;
    l = l->next;
  }
  return c;
}