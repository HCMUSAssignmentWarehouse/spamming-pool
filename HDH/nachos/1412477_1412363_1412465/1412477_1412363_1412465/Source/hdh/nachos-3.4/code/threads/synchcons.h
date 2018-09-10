//	DH KHOA HOC TU NHIEN
// 	HE DIEU HANH TH2014/3
// 	DOAN HIEU TAM		-	1412477
// 	TRAN THI NHA		-	1412363
// 	NGUYEN DINH SON		-	1412465
//
//	FILE synchcons.h
//	Khai bao cac interface cua lop SynchConsole

// CAE - MULTI - SYNCHCONSOLE DEFINITION

#include "console.h"

class SynchConsole {
public:
	SynchConsole();				// A SynchConsole Constructor
	SynchConsole(char *in, char *out);	// Same with fn pointers
	~SynchConsole();			// Delete a console instance

	int Read(char *into, int numBytes);	// Read synch line
						// Ends in EOLN or ^A
	int Write(char *from, int numBytes);	// Write a synchronous line
private:
	Console		*cons;			// Pointer to an async console
};

// CAE - MULTI - END SECTION

