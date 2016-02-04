/*
 * chord.h
 *
 *  Created on: 29 déc. 2015
 *      Author: skartal
 */

#ifndef CHORD_H_
#define CHORD_H_

#include "app.h"
#include "utils/global.h"

#define CHORD_LIST_SIZE 2

// TODO Add all chords
typedef enum {
	CHORD_MAJOR,
	CHORD_MINOR,
	CHORD_AUGMENTED,
	CHORD_DIMINISHED,
	CHORD_SUSPENDED_FOURTH,
	CHORD_SUSPENDED_SECOND,
	CHORD_FIFTH,
	CHORD_MAJOR_SIXTH,
	CHORD_MINOR_SIXTH,
	CHORD_DOMINANT_SEVENTH,
	CHORD_MAJOR_SEVENTH,
	CHORD_MINOR_SEVENTH
} ChordType;

typedef struct {
	int size;
	int notes[OCTAVE_LENGTH];
	int offsets[OCTAVE_LENGTH];
} Chord;

extern ChordType current_chord_type;
extern Chord chord_list[CHORD_LIST_SIZE];

void chord_list_init();
void chord_select_next();
void chord_select_previous();

#endif /* CHORD_H_ */
