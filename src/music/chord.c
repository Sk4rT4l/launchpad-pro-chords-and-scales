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
	Chord chord_augmented = {
		.size = 3,
		.notes = {1,0,0,0,1,0,0,0,1,0,0,0},
		.offsets = {0,4,8}
	};
	chord_list[CHORD_AUGMENTED] = chord_augmented;
	Chord chord_diminished = {
		.size = 3,
		.notes = {1,0,0,1,0,0,1,0,0,0,0,0},
		.offsets = {0,3,6}
	};
	chord_list[CHORD_DIMINISHED] = chord_diminished;
	Chord chord_suspended_fourth = {
		.size = 3,
		.notes = {1,0,0,0,0,1,0,1,0,0,0,0},
		.offsets = {0,5,7}
	};
	chord_list[CHORD_SUSPENDED_FOURTH] = chord_suspended_fourth;
	Chord chord_suspended_second = {
		.size = 3,
		.notes = {1,0,1,0,0,0,0,1,0,0,0,0},
		.offsets = {0,2,7}
	};
	chord_list[CHORD_SUSPENDED_SECOND] = chord_suspended_second;
	Chord chord_fifth = {
		.size = 2,
		.notes = {1,0,0,0,0,0,0,1,0,0,0,0},
		.offsets = {0,7}
	};
	chord_list[CHORD_FIFTH] = chord_fifth;
	Chord chord_major_sixth = {
		.size = 4,
		.notes = {1,0,0,0,1,0,0,1,0,1,0,0},
		.offsets = {0,4,7,9}
	};
	chord_list[CHORD_MAJOR_SIXTH] = chord_major_sixth;
	Chord chord_minor_sixth = {
		.size = 4,
		.notes = {1,0,0,1,0,0,0,1,0,1,0,0},
		.offsets = {0,3,7,9}
	};
	chord_list[CHORD_MINOR_SIXTH] = chord_minor_sixth;
	Chord chord_dominant_seventh = {
		.size = 4,
		.notes = {1,0,0,0,1,0,0,1,0,0,1,0},
		.offsets = {0,4,7,10}
	};
	chord_list[CHORD_DOMINANT_SEVENTH] = chord_dominant_seventh;
	Chord chord_major_seventh = {
		.size = 4,
		.notes = {1,0,0,0,1,0,0,1,0,0,0,1},
		.offsets = {0,4,7,11}
	};
	chord_list[CHORD_MAJOR_SEVENTH] = chord_major_seventh;
	Chord chord_minor_seventh = {
		.size = 4,
		.notes = {1,0,0,1,0,0,0,1,0,0,1,0},
		.offsets = {0,3,7,10}
	};
	chord_list[CHORD_MINOR_SEVENTH] = chord_minor_seventh;
}

/**
 * Change the current_chord_type to the next one
 */
void chord_select_next(){
	if (current_chord_type < (CHORD_LIST_SIZE - 1)){
		current_chord_type++;
	}
}

/**
 * Change the current_chord_type to the previous one
 */
void chord_select_previous(){
	if (current_chord_type > 0){
		current_chord_type--;
	}
}
