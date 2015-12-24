/*
 * layout.h
 *
 *  Created on: 24 déc. 2015
 *      Author: skartal
 */

#ifndef LAYOUT_H_
#define LAYOUT_H_

#include "app.h"
#include "utils/buttons.h"

#define GRID_SIZE 8

typedef struct {
	int x;
	int y;
} PadCoordinate;

typedef struct {
	// 0-127
	u8 root_note;
	// 0-10
	u8 octave;
} Layout;

extern Layout current_layout;

void layout_initialize_pad_coordinates();
void layout_recalculate_pad_notes();
u8 layout_get_midi_note(u8 index);

#endif /* LAYOUT_H_ */
