#ifndef _Double_H

#include <stdio.h>
#include <stdlib.h>

struct node;
struct ht;

struct node* create_n();

struct ht* create_ht();

void insert_at_head(int x, struct ht*);
void insert_at_tail(int x, struct ht*);

void delete_at_head(struct ht*);
void delete_at_tail(struct ht*);

void check_from_head(struct ht*);
void check_from_tail(struct ht*);

#endif
