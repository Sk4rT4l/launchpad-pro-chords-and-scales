/*
 * scale.c
 *
 *  Created on: 24 déc. 2015
 *      Author: skartal
 */

#include "music/scale.h"

ScaleType current_scale_type = SCALE_MAJOR;
Scale scale_list[SCALE_LIST_SIZE];

void scale_list_init()
{
	Scale scale_major = {
		8,
		{1,0,1,0,1,1,0,1,0,1,0,1},
		{0,2,4,5,7,9,11}
	};
	scale_list[SCALE_MAJOR] = scale_major;
	Scale scale_minor = {
		8,
		{1,0,1,1,0,1,0,1,1,0,1,0},
		{0,2,3,5,7,8,10}
	};
	scale_list[SCALE_MINOR] = scale_minor;
	Scale scale_harmonic_minor = {
		8,
		{1,0,1,1,0,1,0,1,1,0,0,1},
		{0,2,3,5,7,8,11}
	};
	scale_list[SCALE_HARMONIC_MINOR] = scale_harmonic_minor;
	Scale scale_melodic_minor = {
		8,
		{1,0,1,1,0,1,0,1,0,1,0,1},
		{0,2,3,5,7,9,11}
	};
	scale_list[SCALE_MELODIC_MINOR] = scale_melodic_minor;
	Scale scale_ionian = {
		8,
		{1,0,1,0,1,1,0,1,0,1,0,1},
		{0,2,4,5,7,9,11}
	};
	scale_list[SCALE_IONIAN] = scale_ionian;
	Scale scale_dorian = {
		8,
		{1,0,1,1,0,1,0,1,0,1,1,0},
		{0,2,3,5,7,9,10}
	};
	scale_list[SCALE_DORIAN] = scale_dorian;
	Scale scale_phrygian = {
		8,
		{1,1,0,1,0,1,0,1,1,0,1,0},
		{0,1,3,5,7,8,10}
	};
	scale_list[SCALE_PHRYGIAN] = scale_phrygian;
	Scale scale_lydian = {
		8,
		{1,0,1,0,1,0,1,1,0,1,0,1},
		{0,2,4,6,7,9,11}
	};
	scale_list[SCALE_LYDIAN] = scale_lydian;
	Scale scale_mixolydian = {
		8,
		{1,0,1,0,1,1,0,1,0,1,1,0},
		{0,2,4,5,7,9,10}
	};
	scale_list[SCALE_MIXOLYDIAN] = scale_mixolydian;
	Scale scale_aeolian = {
		8,
		{1,0,1,1,0,1,0,1,1,0,1,0},
		{0,2,3,5,7,9,11}
	};
	scale_list[SCALE_AEOLIAN] = scale_aeolian;
	Scale scale_locrian = {
		8,
		{1,1,0,1,0,1,1,0,1,0,1,0},
		{0,1,3,5,6,8,10}
	};
	scale_list[SCALE_LOCRIAN] = scale_locrian;
	Scale scale_blues = {
		7,
		{1,0,0,1,0,1,1,1,0,0,1,0},
		{0,3,5,6,7,10}
	};
	scale_list[SCALE_BLUES] = scale_blues;
	Scale scale_harmonic_major = {
		8,
		{1,0,1,0,1,1,0,1,1,0,0,1},
		{0,2,4,5,7,8,11}
	};
	scale_list[SCALE_HARMONIC_MAJOR] = scale_harmonic_major;
	Scale scale_major_pentatonic = {
		6,
		{1,0,1,0,1,0,0,1,0,1,0,0},
		{0,2,4,7,9}
	};
	scale_list[SCALE_MAJOR_PENTATONIC] = scale_major_pentatonic;
	Scale scale_minor_pentatonic = {
		6,
		{1,0,0,1,0,1,0,1,0,0,1,0},
		{0,3,5,7,10}
	};
	scale_list[SCALE_MINOR_PENTATONIC] = scale_minor_pentatonic;
	Scale scale_pentatonic_blues = {
		6,
		{1,0,0,1,0,1,1,0,0,0,1,0},
		{0,3,5,6,10}
	};
	scale_list[SCALE_PENTATONIC_BLUES] = scale_pentatonic_blues;
}
