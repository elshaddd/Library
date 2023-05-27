#include "cmp.h"

int cost_vozr(const void *a, const void *b) {
    struct book *pa = *(struct book **) a;
    struct book *pb = *(struct book **) b;
    return (pa->cost == pb->cost) ? strcmp(pa->author, pb->author) : pa->cost - pb->cost;
}

int cost_ymen(const void *a, const void *b) {
    struct book *pa = *(struct book **) a;
    struct book *pb = *(struct book **) b;
    return (pa->cost == pb->cost) ? strcmp(pa->author, pb->author) : pb->cost - pa->cost;
}

int kolvo_vozr(const void *a, const void *b) {
    struct book *pa = *(struct book **) a;
    struct book *pb = *(struct book **) b;
    return pa->kolvo - pb->kolvo;
}

int kolvo_ymen(const void *a, const void *b) {
    struct book *pa = *(struct book **) a;
    struct book *pb = *(struct book **) b;
    return (pa->kolvo == pb->kolvo) ? strcmp(pa->author, pb->author) : pb->kolvo - pa->kolvo;
}

int av_vozr(const void *p1, const void *p2) {
    return strcmp((*(struct book **) p1)->author, (*(struct book **) p2)->author);
}

int av_ymen(const void *p1, const void *p2) {
    return strcmp((*(struct book **) p2)->author, (*(struct book **) p1)->author);
}

int name_vozr(const void *p1, const void *p2) {
    return strcmp((*(struct book **) p1)->name, (*(struct book **) p2)->name);
}

int name_ymen(const void *p1, const void *p2) {
    return strcmp((*(struct book **) p2)->name, (*(struct book **) p1)->name);
}