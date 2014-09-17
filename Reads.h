/*
 * Copyright (c) <2008 - 2020>, University of Washington, Simon Fraser University, Bilkent University
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list
 * of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or other
 *   materials provided with the distribution.
 * - Neither the names of the University of Washington, Simon Fraser University,
 *   nor the names of its contributors may be
 *   used to endorse or promote products derived from this software without specific
 *   prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


/*
  Authors:
  Farhad Hormozdiari
  Faraz Hach
  Can Alkan
  Emails:
  farhadh AT uw DOT edu
  fhach AT cs DOT sfu DOT ca
  calkan AT cs DOT bilkent DOT edu DOT tr
*/


#ifndef __READ__
#define __READ__

#include <math.h>

// fastHASH: key_struct
// sirFAST: key_struct
typedef struct
{
  unsigned int* key_entry;
  unsigned int* key_locs;
  int key_entry_size;	// sirFAST: added
  int key_number;
  int order;
} key_struct;

typedef struct
{
  char *name;
  char *seq;
  char *rseq;
  char *qual;
  char *hits;
  int readNumber;
  short *hashValue;
  short *rhashValue;
  int *hashValSampleSize;
} Read;

int readAllReads(char *fileName1, char *fileName2, int compressed, unsigned char *fastq, unsigned char pe, Read **seqList,
									unsigned int *seqListSize, unsigned int listSize, unsigned int acclistSize);
void loadSamplingLocations(int **samplingLocs, int *samplingLocsSize);
void finalizeReads(char *fileName);
void adjustQual(Read *list, int seqCnt);


// sirFAST: readAllReadsCG
int readAllReadsCG(char *fileName1, char *fileName2, int compressed, unsigned char *fastq,
					unsigned char pe, Read **seqList, unsigned int *seqListSize); // sirFAST

int countAllReads(char * fileName1, char * fileName2, int compressed, unsigned char pairedEnd);

FILE * initUnmapped(char *fileName);
void performUnmapped(FILE * _fp_unmap);
void finalizeUnmapped(FILE * _fp_unmap);

void freeReads(Read * seqList, unsigned int seqListSize);
#endif
