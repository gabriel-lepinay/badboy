#ifndef LAYOUT_HPP
#define LAYOUT_HPP

typedef struct layout_s {
    char us[2];
    char fr[2];
} layout_t;

const layout_t layout_k[7] = {
    {"q", "a"},
    {"a", "q"},
    {"w", "z"},
    {"z", "w"},
    {":", "m"},
    {"m", ":"},
};

const int layout_tab[3] = {0, 1, 2};

char *us_to_fr(char* str);
char *fr_to_us(char* str);

#endif