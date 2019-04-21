/////////////////////////////////////////////////////////////////////////////
//
//	File: Main.cpp
//
//	$Header: $
//
//
/////////////////////////////////////////////////////////////////////////////


#include <signal.h>
#include "QzCommon.h"
#include "QzLogger.h"
#include "QzTgaWriter.h"
#include "LeftLeaningRedBlack.h"
#include "RedBlackBasic.h"
#include "TwoThreeExterior.h"
#include "TwoThreeInterior.h"
#include "UtfData.h"


#ifdef USE_MALLOC_MACRO
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
//
//	QzAssertHandler()
//
//	Custom assertion handler.  Deals with assertions without throwing up a
//	dialog, which doesn't necessary work right when running full-screen.
//
void QzAssertHandler(const char message[], int lineNum, char file[])
{
	char *pattern = "Assert: line %1;, file %2;\n\n%3;\n";

	UtfFormat fmt;
	fmt.AddInt(lineNum);
	fmt.AddString(file);
	fmt.AddString(message);

	// Log the message.
	LogMessage(pattern, fmt);

	// Close the log file so we don't lose the assertion message.
	SafeDelete(g_pLog);

	// Use DebugBreak to launch the debugger ...
	QzDebugBreak();

	// ... or just kill the app and drop back to the desktop if no debugger
	// is attached to the process.
	raise(SIGABRT);
}


/////////////////////////////////////////////////////////////////////////////
//
//	Shuffle()
//
//	Randomizes the ordering of a sequence of numbers by using card shuffling
//	logic.
//
void Shuffle(int pArray[], int entryCount, int repeatCount)
{
	int *pOut = new int[entryCount];

	for (int repNum = 0; repNum < repeatCount; ++repNum) {
		int outPos  = 0;
		int offsetA = 0;
		int offsetB = (entryCount / 4) + (rand() % (entryCount / 2));
		int sizeA   = offsetB;
		int sizeB   = entryCount - offsetB;
		int AorB    = (rand() >> 4) & 1;

		while ((sizeA > 0) && (sizeB > 0)) {
			int pickCount = 1 + (rand() % 7);

			if (AorB) {
				while ((pickCount > 0) && (sizeA > 0)) {
					pOut[outPos++] = pArray[offsetA++];
					--pickCount;
					--sizeA;
				}
			}
			else {
				while ((pickCount > 0) && (sizeB > 0)) {
					pOut[outPos++] = pArray[offsetB++];
					--pickCount;
					--sizeB;
				}
			}

			AorB = 1 - AorB;
		}

		while (sizeA > 0) {
			pOut[outPos++] = pArray[offsetA++];
			--sizeA;
		}

		while (sizeB > 0) {
			pOut[outPos++] = pArray[offsetB++];
			--sizeB;
		}

		memcpy(pArray, pOut, entryCount * sizeof(int));
	}

	SafeDeleteArray(pOut);
}


/////////////////////////////////////////////////////////////////////////////
//
//	TestTwoThree()
//
void TestTwoThree(void)
{
	int ary[1000];
	for (int i = 0; i < ArraySize(ary); ++i) {
		ary[i] = i + 1;
	}

	srand(70121);
	Shuffle(ary, ArraySize(ary), 128);

	for (int i = 0; i < ArraySize(ary); ++i) {
		printf("%4d", ary[i]);
	}
	printf("\n\n");

	int t0 = QzGetMilliseconds();

//	TwoThreeExterior    twoThree;
//	TwoThreeInterior    twoThree;
//	RedBlackBasic       twoThree;
	LeftLeaningRedBlack twoThree;

	U08 foo = 0;

	for (int i = 0; i < ArraySize(ary); ++i) {
		VoidRef_t ref;
		ref.Key      = ary[i];
		ref.pContext = reinterpret_cast<void*>(&foo);

		twoThree.Insert(ref);
		twoThree.SanityCheck();
	}

	twoThree.Traverse();
	twoThree.LeafDepth();

#if 0
	int q = twoThree.KeyCount();

	QzAssert(ArraySize(ary) == twoThree.KeyCount());

	for (int i = ArraySize(ary) / 2; i < ArraySize(ary); ++i) {
		twoThree.Delete(ary[i]);
		twoThree.SanityCheck();
		int expect = ArraySize(ary) - 1 - (i - (ArraySize(ary) / 2));
		int actual = twoThree.KeyCount();
		QzAssert(expect == actual);
	}

	for (int i = 0; i < ArraySize(ary) / 2; ++i) {
		QzAssert(NULL != twoThree.LookUp(ary[i]));
	}

	for (int i = ArraySize(ary) / 2; i < ArraySize(ary); ++i) {
		QzAssert(NULL == twoThree.LookUp(ary[i]));
	}
#else
	int lo = 373;
	int hi = 872;

	for (int i = lo; i < hi; ++i) {
		twoThree.Delete(i+1);
		twoThree.SanityCheck();
	}
	twoThree.Traverse();

	for (int i = 0; i < lo; ++i) {
		QzAssert(NULL != twoThree.LookUp(i+1));
	}

	for (int i = hi; i < ArraySize(ary); ++i) {
		QzAssert(NULL != twoThree.LookUp(i+1));
	}

	for (int i = lo; i < hi; ++i) {
		QzAssert(NULL == twoThree.LookUp(i+1));
	}
#endif

	twoThree.Traverse();
	twoThree.LeafDepth();

	int t1 = QzGetMilliseconds();

	printf("\n%d milliseconds\n", t1 - t0);
}


/////////////////////////////////////////////////////////////////////////////
//
//	Performance()
//
void Performance(void)
{
	srand(4310987);

	const int limit = 800000;
//	const int limit = 100000;
	const int delta = 1000;

	int *pKeys = new int[limit];

	for (int i = 0; i < limit; ++i) {
		pKeys[i] = rand() ^ (rand() << 15);
	}

	TwoThreeExterior    sort1;
	TwoThreeInterior    sort2;
	RedBlackBasic       sort3;
	LeftLeaningRedBlack sort4;

	int inserts[limit/delta][4];
	int lookups[limit/delta][4];
	int deletes[limit/delta][4];
	U64 t0, t1, t2, t3;
	U64 freq = QzPrecisionClockFrequency();


	SafeZeroArray(inserts);
	SafeZeroArray(lookups);
	SafeZeroArray(deletes);

	int dummy;
	VoidRef_t ref;
	ref.pContext = &dummy;

	for (int top = delta; top <= limit; top += delta) {
		int index = (top / delta) - 1;

		sort1.FreeAll();
		t0 = QzPrecisionClockRead();
		for (int i = 0; i < top; ++i) {
			ref.Key = pKeys[i];
			sort1.Insert(ref);
		}
		t1 = QzPrecisionClockRead();
		inserts[index][0] = int((t1 - t0) / (freq / 1000));
		for (int i = 0; i < top; ++i) {
			sort1.LookUp(pKeys[i]);
		}
		t2 = QzPrecisionClockRead();
		lookups[index][0] = int((t2 - t1) / (freq / 1000));
		for (int i = 0; i < top; ++i) {
			sort1.Delete(pKeys[i]);
		}
		t3 = QzPrecisionClockRead();
		deletes[index][0] = int((t3 - t2) / (freq / 1000));
		QzAssert(sort1.IsEmpty());

		sort2.FreeAll();
		t0 = QzPrecisionClockRead();
		for (int i = 0; i < top; ++i) {
			ref.Key = pKeys[i];
			sort2.Insert(ref);
		}
		t1 = QzPrecisionClockRead();
		inserts[index][1] = int((t1 - t0) / (freq / 1000));
		for (int i = 0; i < top; ++i) {
			sort2.LookUp(pKeys[i]);
		}
		t2 = QzPrecisionClockRead();
		lookups[index][1] = int((t2 - t1) / (freq / 1000));
		for (int i = 0; i < top; ++i) {
			sort2.Delete(pKeys[i]);
		}
		t3 = QzPrecisionClockRead();
		deletes[index][1] = int((t3 - t2) / (freq / 1000));
		QzAssert(sort2.IsEmpty());

		sort3.FreeAll();
		t0 = QzPrecisionClockRead();
		for (int i = 0; i < top; ++i) {
			ref.Key = pKeys[i];
			sort3.Insert(ref);
		}
		t1 = QzPrecisionClockRead();
		inserts[index][2] = int((t1 - t0) / (freq / 1000));
		for (int i = 0; i < top; ++i) {
			sort3.LookUp(pKeys[i]);
		}
		t2 = QzPrecisionClockRead();
		lookups[index][2] = int((t2 - t1) / (freq / 1000));
		for (int i = 0; i < top; ++i) {
			sort3.Delete(pKeys[i]);
		}
		t3 = QzPrecisionClockRead();
		deletes[index][2] = int((t3 - t2) / (freq / 1000));
		QzAssert(sort3.IsEmpty());

		sort4.FreeAll();
		t0 = QzPrecisionClockRead();
		for (int i = 0; i < top; ++i) {
			ref.Key = pKeys[i];
			sort4.Insert(ref);
		}
		t1 = QzPrecisionClockRead();
		inserts[index][3] = int((t1 - t0) / (freq / 1000));
		for (int i = 0; i < top; ++i) {
			sort4.LookUp(pKeys[i]);
		}
		t2 = QzPrecisionClockRead();
		lookups[index][3] = int((t2 - t1) / (freq / 1000));
		for (int i = 0; i < top; ++i) {
			sort4.Delete(pKeys[i]);
		}
		t3 = QzPrecisionClockRead();
		deletes[index][3] = int((t3 - t2) / (freq / 1000));
		QzAssert(sort4.IsEmpty());

		printf("%3d: %4d %4d %4d %4d :: %4d %4d %4d %4d :: %4d %4d %4d %4d\n", index,
			inserts[index][0],
			inserts[index][1],
			inserts[index][2],
			inserts[index][3],
			lookups[index][0],
			lookups[index][1],
			lookups[index][2],
			lookups[index][3],
			deletes[index][0],
			deletes[index][1],
			deletes[index][2],
			deletes[index][3]);
	}

	int width  = limit / delta;
	int height = 1200;

	int *pFrame = new int[width * height];

	QzTgaWriter writer;

	int colors[4] = { 0x0000FF, 0x00FF00, 0xFF0000, 0x808080 };

	memset(pFrame, 0, width * height * 4);
	for (int y = 50; y < height; y += 50) {
		for (int x = 0; x < width; ++x) {
			pFrame[(width * (height - y - 1)) + x] = 0x303030;
		}
	}
	for (int x = 50; x < width; x += 50) {
		for (int y = 0; y < height; ++y) {
			pFrame[(width * (height - y - 1)) + x] = 0x303030;
		}
	}
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (inserts[i][j] < height) {
				pFrame[(width * (height - inserts[i][j] - 1)) + i] = colors[j];
			}
		}
	}
	writer.Initialize(width, height, 32, TgaFormat_TrueColor);
	writer.StartEncoding();
	writer.WriteFrame(reinterpret_cast<U08*>(pFrame), width * 4);
	writer.SaveFile(reinterpret_cast<const Utf08_t*>("BalancedTreeInserts.tga"));

	memset(pFrame, 0, width * height * 4);
	for (int y = 50; y < height; y += 50) {
		for (int x = 0; x < width; ++x) {
			pFrame[(width * (height - y - 1)) + x] = 0x303030;
		}
	}
	for (int x = 50; x < width; x += 50) {
		for (int y = 0; y < height; ++y) {
			pFrame[(width * (height - y - 1)) + x] = 0x303030;
		}
	}
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (lookups[i][j] < height) {
				pFrame[(width * (height - lookups[i][j] - 1)) + i] = colors[j];
			}
		}
	}
	writer.Initialize(width, height, 32, TgaFormat_TrueColor);
	writer.StartEncoding();
	writer.WriteFrame(reinterpret_cast<U08*>(pFrame), width * 4);
	writer.SaveFile(reinterpret_cast<const Utf08_t*>("BalancedTreeLookups.tga"));

	memset(pFrame, 0, width * height * 4);
	for (int y = 50; y < height; y += 50) {
		for (int x = 0; x < width; ++x) {
			pFrame[(width * (height - y - 1)) + x] = 0x303030;
		}
	}
	for (int x = 50; x < width; x += 50) {
		for (int y = 0; y < height; ++y) {
			pFrame[(width * (height - y - 1)) + x] = 0x303030;
		}
	}
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (deletes[i][j] < height) {
				pFrame[(width * (height - deletes[i][j] - 1)) + i] = colors[j];
			}
		}
	}
	writer.Initialize(width, height, 32, TgaFormat_TrueColor);
	writer.StartEncoding();
	writer.WriteFrame(reinterpret_cast<U08*>(pFrame), width * 4);
	writer.SaveFile(reinterpret_cast<const Utf08_t*>("BalancedTreeDeletes.tga"));

	SafeDeleteArray(pFrame);
	SafeDeleteArray(pKeys);
}



/////////////////////////////////////////////////////////////////////////////
//
//	main()
//
void main(void)
{
	QzSystemInit();
	UtfInitialize();

	QzLogger *pLog = new QzLogger("QzTwoThree");
	g_pLog = pLog;

	// Only enable file logging if the memory logging option is not available.
	// This typically means the logger utility has not been started.
	if (!g_pLog->MemoryLoggingAvailable()) {
		g_pLog->Open(reinterpret_cast<const Utf08_t*>("trace.txt"));
	}


	TestTwoThree();
//	Performance();


	g_pLog = NULL;

	SafeDelete(pLog);

	UtfUninitialize();
	QzSystemUninit();

#ifdef USE_MALLOC_MACRO
	if (_CrtDumpMemoryLeaks()) {
		printf("ERROR: MEMORY LEAKS DETECTED\n");
	}
#endif
}


