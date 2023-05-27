#include "cmp.h"

int cost_ascending(const void *a, const void *b) {
    struct book *pa = *(struct book **) a;
    struct book *pb = *(struct book **) b;
    return (pa->cost == pb->cost) ? strcmp(pa->author, pb->author) : pa->cost - pb->cost;
}

int cost_descending(const void *a, const void *b) {
    struct book *pa = *(struct book **) a;
    struct book *pb = *(struct book **) b;
    return (pa->cost == pb->cost) ? strcmp(pa->author, pb->author) : pb->cost - pa->cost;
}

int amount_ascending(const void *a, const void *b) {
    struct book *pa = *(struct book **) a;
    struct book *pb = *(struct book **) b;
    return pa->amount - pb->amount;
}

int amount_descending(const void *a, const void *b) {
    struct book *pa = *(struct book **) a;
    struct book *pb = *(struct book **) b;
    return (pa->amount == pb->amount) ? strcmp(pa->author, pb->author) : pb->amount - pa->amount;
}

int author_ascending(const void *p1, const void *p2) {
    return strcmp((*(struct book **) p1)->author, (*(struct book **) p2)->author);
}

int author_descending(const void *p1, const void *p2) {
    return strcmp((*(struct book **) p2)->author, (*(struct book **) p1)->author);
}

int name_ascending(const void *p1, const void *p2) {
    return strcmp((*(struct book **) p1)->name, (*(struct book **) p2)->name);
}

int name_descending(const void *p1, const void *p2) {
    return strcmp((*(struct book **) p2)->name, (*(struct book **) p1)->name);
}