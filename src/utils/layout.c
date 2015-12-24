/*
 * layout.c
 *
 *  Created on: 24 déc. 2015
 *      Author: skartal
 */

#include "utils/layout.h"

// Initializing variables
u8 pad_notes[GRID_SIZE][GRID_SIZE];
PadCoordinate pad_coordinates[BT_LAST];
Layout current_layout = {36,3};

/**
 * Initializing pad coordinates
 */
void layout_initialize_pad_coordinates(){
	u8 current_pad = BT_PAD_FIRST;

	for (int y = 0; y < GRID_SIZE; y++){
		for (int x = 0; x < GRID_SIZE; x++){
			PadCoordinate coord = {y, x};
			pad_coordinates[current_pad] = coord;
			current_pad++;
		}
		current_pad += 2;
	}
}

/**
 * Recalculating pad notes
 */
void layout_recalculate_pad_notes(){
	u8 root_note = current_layout.root_note;
	u8 index = 0;

	for (int y = 0; y < GRID_SIZE; y++){
		for (int x = 0; x < GRID_SIZE; x++){
			pad_notes[y][x] = root_note + index;
			index++;
		}
	}
}

/**
 * Getting midi note for selected pad
 */
u8 layout_get_midi_note(u8 index){
	PadCoordinate coord = pad_coordinates[index];
	return pad_notes[coord.y][coord.x];
}
