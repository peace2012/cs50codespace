// card_specs.h
#ifndef CARD_SPECS_H
#define CARD_SPECS_H

typedef struct {
    const int valid_lengths[3];
    const int amex_specs[1];
    const int mcard_specs[4];
    const int visa_specs[4];
} CardSpecs;

extern CardSpecs specs;

#endif
