#pragma once
#include "block.h"

class block_chain {
	block** Blist;
	int block_no;
public:
	block_chain() {
		block_no = 0;
		Blist = nullptr;
	}
	void add_block(block* B) {
		if (block_no == 0) {
			//adding transaction to block 
			Blist = new block * [block_no + 1];
			Blist[block_no] = B;
			block_no++;
		}
		else if (block_no > 0) {
			//creating a temp transaction array
			block** temp;
			temp = new block * [block_no + 1];
			int i;
			//copy address into the temp array
			for (i = 0; i < block_no; i++) {
				temp[i] = Blist[i];
			}
			// add new trabsaction
			temp[i] = B;
			//deleting older transaction array
			delete[]Blist;
			Blist = temp;
			temp = nullptr;
			block_no++;
		}
	}
	void print_block_chain() {
		for (int i = 0; i < block_no; i++) {
			cout << "BLOCK NO : " << i << endl;
			cout << endl;
			if (i == 0) {
				Blist[i]->print_block(1);
			}
			else {
				Blist[i]->print_block(3);
			}
		}
	}
};