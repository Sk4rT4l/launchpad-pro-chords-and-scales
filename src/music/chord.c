/*
 * chord.c
 *
 *  Created on: 29 déc. 2015
 *      Author: skartal
 */

#include "music/chord.h"

ChordType current_chord_type = CHORD_MAJOR;
Chord chord_list[CHORD_LIST_SIZE];

void chord_list_init()
{
	Chord chord_major = {
		.size = 3,
		.notes = {1,0,0,0,1,0,0,1,0,0,0,0},
		.offsets = {0,4,7}
	};
	chord_list[CHORD_MAJOR] = chord_major;
	Chord chord_minor = {
		.size = 3,
		.notes = {1,0,0,1,0,0,0,1,0,0,0,0},
		.offsets = {0,3,7}
	};
	chord_list[CHORD_MINOR] = chord_minor;
}
