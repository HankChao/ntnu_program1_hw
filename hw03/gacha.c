#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gacha.h"

static int32_t total_cards;           
static int32_t group_bounds[6];       
static double group_probs[6];         
static int32_t guarantee_count;       
static int32_t current_guarantee;     
static int32_t pull_number;          
static int is_initialized = 0;   
static int32_t card;    

void initialize(int32_t n) {
    if (n <= 0) {
        printf("Error: Invalid card number\n");
        return;
    }
    
    total_cards = n;
    current_guarantee = 0;
    pull_number = 0;
    is_initialized = 1;
    srand(time(NULL));
}

int32_t set_groups(int32_t g1, int32_t g2, int32_t g3, int32_t g4, int32_t g5) {
    if (!is_initialized) return -1;
    
    if (!(1 <= g1 && g1 < g2 && g2 < g3 && g3 < g4 && g4 < g5 && g5 < total_cards)) {
        return -1;
    }

    group_bounds[0] = g1;
    group_bounds[1] = g2;
    group_bounds[2] = g3;
    group_bounds[3] = g4;
    group_bounds[4] = g5;
    group_bounds[5] = total_cards;
    
    return 0;
}

int32_t set_props(double p1, double p2, double p3, double p4, double p5) {
    if (!is_initialized) return -1;
    
    if (p1 <= 0 || p2 <= 0 || p3 <= 0 || p4 <= 0 || p5 <= 0) {
        return -1;
    }

    if (p1 >= p2 || p2 >= p3 || p3 >= p4 || p4 >= p5) {
        return -1;
    }
    
    double p6 = 1.0 - p1 - p2 - p3 - p4 - p5;
    if (p5 >= p6 || p6 <= 0) {
        return -1;
    }

    group_probs[0] = p1;
    group_probs[1] = p2;
    group_probs[2] = p3;
    group_probs[3] = p4;
    group_probs[4] = p5;
    group_probs[5] = p6;
    
    return 0;
}

int32_t set_guarantee(int32_t count) {
    if (!is_initialized || count <= 0) return -1;
    
    guarantee_count = count;
    current_guarantee = 0;  
    return 0;
}

int32_t add_pull_number(int32_t new) {
    if (!is_initialized || new < 0) return -1;
    
    pull_number += new;
    return 0;
}

int32_t get_pull_number(void) {
    if (!is_initialized) return -1;
    return pull_number;
}

static int32_t get_random_group(void) {
    double r = (double)rand() / RAND_MAX;
    double cumulative = 0;
    
    for (int i = 0; i < 6; i++) {
        cumulative += group_probs[i];
        if (r <= cumulative) {
            return i;
        }
    }
    return 5;
}

static int32_t get_random_card_from_group(int32_t group) {
    int32_t start = (group == 0) ? 1 : group_bounds[group-1] + 1;
    int32_t end = group_bounds[group];
    return start + (rand() % (end - start + 1));
}

int32_t pull(void) {
    if (!is_initialized || pull_number <= 0) return -1;
    
    pull_number--;
    current_guarantee++;
    
    if (current_guarantee >= guarantee_count) {
        current_guarantee = 0;
        card = get_random_card_from_group(0);
        printf("%d\n",card);
        return 0; 
    }
    
    int32_t group = get_random_group();
    card = get_random_card_from_group(group);
    
    if (card <= group_bounds[0]) {
        current_guarantee = 0;
    }
    
    printf("%d\n",card);

    return 0;
}

int32_t pull10(void) {
    if (!is_initialized || pull_number < 10) return -1;
    
    int32_t last_pull = 0;
    int has_group3_or_better = 0;
    
    for (int i = 0; i < 9; i++) {
        pull();
        int32_t result = card;
        if (result <= 0) return -1;
        
        if (result <= group_bounds[2]) {
            has_group3_or_better = 1;
        }
    }
    
    if (!has_group3_or_better) {
        pull_number--;
        current_guarantee++;
        
        double total_prob = group_probs[0] + group_probs[1] + group_probs[2];
        double normalized_p1 = group_probs[0] / total_prob;
        double normalized_p2 = group_probs[1] / total_prob;
        
        double r = (double)rand() / RAND_MAX;
        int32_t selected_group;
        
        if (r < normalized_p1) selected_group = 0;
        else if (r < normalized_p1 + normalized_p2) selected_group = 1;
        else selected_group = 2;
        
        last_pull = get_random_card_from_group(selected_group);
        
        if (last_pull <= group_bounds[0]) {
            current_guarantee = 0;
        }

        printf("%d\n",last_pull);
    } else {
        last_pull = pull();
    }

    return 0;
}