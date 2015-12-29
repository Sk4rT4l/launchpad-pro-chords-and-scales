/*
 * scale.h
 *
 *  Created on: 24 déc. 2015
 *      Author: skartal
 */

#ifndef SCALE_H_
#define SCALE_H_

#include "app.h"
#include "utils/global.h"

// Update it when adding scales
#define SCALE_LIST_SIZE 6

// 27 scales
typedef enum {
	SCALE_MAJOR,
	SCALE_MINOR,
	SCALE_HARMONIC_MINOR,
	SCALE_MELODIC_MINOR,
	SCALE_IONIAN,
	SCALE_DORIAN,
	SCALE_PHRYGIAN,
	SCALE_LYDIAN,
	SCALE_MIXOLYDIAN,
	SCALE_AEOLIAN,
	SCALE_LOCRIAN,
	SCALE_BLUES,
	SCALE_HARMONIC_MAJOR,
	SCALE_MAJOR_PENTATONIC,
	SCALE_MINOR_PENTATONIC,
	SCALE_PENTATONIC_BLUES,
	SCALE_MAJOR_BEBOP,
	SCALE_DOMINANT_BEBOP,
	SCALE_ALTERED,
	SCALE_HALF_DIMINISHED,
	SCALE_DIMINISHED_WHOLE_HALF,
	SCALE_DIMINISHED_HALF_WHOLE,
	SCALE_ACOUSTIC,
	SCALE_WHOLE_TONE,
	SCALE_CHROMATIC,
	SCALE_HUNGARIAN_MINOR,
	SCALE_DOUBLE_HARMONIC
} ScaleType;

typedef struct {
	int size;
	int notes[OCTAVE_LENGTH];
	int offsets[OCTAVE_LENGTH];
} Scale;

extern ScaleType current_scale_type;
extern Scale scale_list[SCALE_LIST_SIZE];

void scale_list_init();

#endif /* SCALE_H_ */
