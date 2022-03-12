#include "modelKernels.h"
L1_CL_MEM AT_L1_POINTER model_L1_Memory;
L2_MEM AT_L2_POINTER model_L2_Memory;
AT_HYPERRAM_POINTER model_L3_Memory;
static AT_HYPERRAM_T HyperRam;
static AT_HYPERFLASH_FS_T HyperFlash;
void S1_Op_input_1_formatterBody(
		unsigned char * __restrict__ In,
		signed char * __restrict__ Out0,
		signed char * __restrict__ Out1,
		signed char * __restrict__ Out2)

{
	/* Shared L1: 48384 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT DmaR_Evt1;
	AT_L2_EVENT DmaW_Evt1;
	AT_L2_EVENT DmaW_Evt2;
	AT_L2_EVENT DmaW_Evt3;
	KerNormRGB888_fps_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _C_Out0;
	unsigned int _SP_Out0, _SC_Out0;
	unsigned int _C_Out1;
	unsigned int _SP_Out1, _SC_Out1;
	unsigned int _C_Out2;
	unsigned int _SP_Out2, _SC_Out2;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 13]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 13 logical tiles, 13 physical tiles
			Total Size: 150528 [Tile0, 13:[672x18, 11:672x18, 672x8], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 13:[672x18, 11:672x18, 672x8], 1]
		Tile0: [0, 12096, 12096], Tile1: [12096, 12096, 12096], Tile2; [24192, 12096, 12096]
	Ker Arg: Out0, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 0
		KerArgItSpace: 13 logical tiles, 13 physical tiles
			Total Size: 50176 [Tile0, 13:[224x18, 11:224x18, 224x8], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 13:[224x18, 11:224x18, 224x8], 1]
		Tile0: [0, 4032, 4032], Tile1: [4032, 4032, 4032], Tile2; [8064, 4032, 4032]
	Ker Arg: Out1, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 0
		KerArgItSpace: 13 logical tiles, 13 physical tiles
			Total Size: 50176 [Tile0, 13:[224x18, 11:224x18, 224x8], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 13:[224x18, 11:224x18, 224x8], 1]
		Tile0: [0, 4032, 4032], Tile1: [4032, 4032, 4032], Tile2; [8064, 4032, 4032]
	Ker Arg: Out2, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 0
		KerArgItSpace: 13 logical tiles, 13 physical tiles
			Total Size: 50176 [Tile0, 13:[224x18, 11:224x18, 224x8], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 13:[224x18, 11:224x18, 224x8], 1]
		Tile0: [0, 4032, 4032], Tile1: [4032, 4032, 4032], Tile2; [8064, 4032, 4032]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W = (unsigned short int) (224);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+0+0), 12096, 0, &DmaR_Evt1);
	_N_In=0;
	_C_Out0=0; _SC_Out0=4032;
	_SP_Out0=0;
	_C_Out1=0; _SC_Out1=4032;
	_SP_Out1=0;
	_C_Out2=0; _SC_Out2=4032;
	_SP_Out2=0;
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<13; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==12), T0Ind_NextLast = ((T0Ind+1)==12);
		/*================================= Prepare Tiles ===================================*/
		_SN_In = 0;
		if (!(T0Ind_Last)) {
			_N_In = _N_In + (12096); _SN_In = ((T0Ind_NextLast)?5376:12096); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, &DmaR_Evt1); /* Wait previous DMA read In */
		if (_SN_In) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+0+12096*((T0Ind_Total+1)%2)),
					_SN_In, 0, &DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (unsigned char *__restrict__) (model_L1_Memory+0+12096*((T0Ind_Total)%2));
		KerArg0->Out0 = (signed char *__restrict__) (model_L1_Memory+24192+4032*((T0Ind_Total)%2));
		KerArg0->Out1 = (signed char *__restrict__) (model_L1_Memory+32256+4032*((T0Ind_Total)%2));
		KerArg0->Out2 = (signed char *__restrict__) (model_L1_Memory+40320+4032*((T0Ind_Total)%2));
		KerArg0->H = (unsigned short int) (T0Ind_Last?8:18);
		AT_FORK(gap_ncore(), (void *) CNN_NormRGB888_offset_fps, (void *) KerArg0);
		__CALL(CNN_NormRGB888_offset_fps, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out0) AT_L2_WAIT(0, &DmaW_Evt1); /* Wait previous DMA write Out0 */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out0+_C_Out0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+24192+4032*((T0Ind_Total)%2)),
				_SC_Out0, 1, &DmaW_Evt1);
		if (_SP_Out1) AT_L2_WAIT(0, &DmaW_Evt2); /* Wait previous DMA write Out1 */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out1+_C_Out1), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+32256+4032*((T0Ind_Total)%2)),
				_SC_Out1, 1, &DmaW_Evt2);
		if (_SP_Out2) AT_L2_WAIT(0, &DmaW_Evt3); /* Wait previous DMA write Out2 */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out2+_C_Out2), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+40320+4032*((T0Ind_Total)%2)),
				_SC_Out2, 1, &DmaW_Evt3);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_Out0 = _SC_Out0;
		_SP_Out1 = _SC_Out1;
		_SP_Out2 = _SC_Out2;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out0 = 0;
		if (!(T0Ind_Last)) {
			_C_Out0 = _C_Out0 + (4032); _SC_Out0 = ((T0Ind_NextLast)?1792:4032); 
		}
		_SC_Out1 = 0;
		if (!(T0Ind_Last)) {
			_C_Out1 = _C_Out1 + (4032); _SC_Out1 = ((T0Ind_NextLast)?1792:4032); 
		}
		_SC_Out2 = 0;
		if (!(T0Ind_Last)) {
			_C_Out2 = _C_Out2 + (4032); _SC_Out2 = ((T0Ind_NextLast)?1792:4032); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, &DmaW_Evt1); /* Wait previous DMA write Out0 */
	AT_L2_WAIT(0, &DmaW_Evt2); /* Wait previous DMA write Out1 */
	AT_L2_WAIT(0, &DmaW_Evt3); /* Wait previous DMA write Out2 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void S2_Conv2d_32x3x3x3_MaxPool_2x2_Relu(
		signed char * __restrict__ In,
		signed char * __restrict__ Filter,
		int * __restrict__ Bias,
		signed char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		unsigned char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 40332 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT DmaR_Evt1;
	AT_L2_EVENT DmaR_Evt2;
	AT_L2_EVENT DmaR_Evt3;
	AT_L2_EVENT DmaR_Evt4;
	AT_L2_EVENT DmaR_Evt5;
	AT_L2_EVENT DmaR_Evt6;
	AT_L2_EVENT DmaW_Evt1;
	AT_HYPERRAM_CL_EVENT UchanHR1;
	KerSetBias_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;
	KerConv_SQ8_T S_KerArg1, *KerArg1 = &S_KerArg1;
	KerConvLinReduct_SQ8_T S_KerArg2, *KerArg2 = &S_KerArg2;
	KerPool_SQ8_T S_KerArg3, *KerArg3 = &S_KerArg3;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _P_Out, _C_Out;
	unsigned int _SPP_Out, _SP_Out, _SC_Out;
	unsigned int _LPP_Out, _LP_Out, _LC_Out;
	unsigned int _N_Filter;
	unsigned int _SN_Filter;
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _LN_In;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 32, Tiled: 1][Tile0 Dim: 55][D0 Dim: Init: 3, Tiled: 1]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -2, Max Pipe Depth: 0
		KerArgItSpace: 55 logical tiles, 55 physical tiles
			Total Size: 96800 [D1, [0 x 96800, 96800]][Tile0, 55:[55x1, 53:55x1, 55x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 96800, 96800]][Tile0, 55:[55x1, 53:55x1, 55x1], 1]
		Tile0: [0, 1760, 55], Tile1: [55, 1760, 55], Tile2; [110, 1760, 55]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 128 [D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 32 [D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 32 [D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Filter, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 55 logical tiles, 1 physical tiles
			Total Size: 864 [D1, [0 x 864, 864]][D0, [0 x 864, 864]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 864, 864]][D0, [0 x 864, 864]]
		Tile0: [0, 864, 27], Tile1: [0, 864, 27], Tile2; [0, 864, 27]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 55 logical tiles, 55 physical tiles
			Total Size: 150528 [D0, [0 x 150528, 150528]][Tile0, 55:[224x5, 53:224x5, 224x5], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 55:[224x5, 53:224x5, 224x5], 1][D0, [0 x 150528, 150528]]
		Tile0: [0, 3360, 1120], Tile1: [896, 3360, 1120], Tile2; [1792, 3360, 1120]
	Ker Arg: ConvOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 55 logical tiles, 1 physical tiles
			Total Size: 1548800 [D1, [0 x 1548800, 1548800]][Tile0, 55:[110x2, 53:110x2, 110x2], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 1548800, 1548800]][Tile0, 55:[110x2, 53:110x2, 110x2], 4]
		Tile0: [0, 28160, 880], Tile1: [0, 28160, 880], Tile2; [0, 28160, 880]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 55 logical tiles, 1 physical tiles
			Total Size: 9 [Tile0, 55:[9x1, 53:9x1, 9x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 55:[9x1, 53:9x1, 9x1], 1]
		Tile0: [0, 9, 9], Tile1: [0, 9, 9], Tile2; [0, 9, 9]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Out = (int * __restrict__) (model_L1_Memory+12160);
	KerArg0->W = (unsigned short int) (110);
	KerArg0->H = (unsigned short int) (2);
	KerArg0->Feat = (unsigned short int) (32);
	KerArg0->Bias = (void * __restrict__) (model_L1_Memory+6720);
	KerArg1->W = (unsigned short int) (224);
	KerArg1->UsedW = (unsigned short int) (221);
	KerArg1->H = (unsigned short int) (5);
	KerArg1->UsedH = (unsigned short int) (5);
	KerArg1->InFeatures = (unsigned short int) (3);
	KerArg1->OutFeatures = (unsigned short int) (32);
	KerArg1->TotalInFeatures = (unsigned short int) (3);
	KerArg1->Out = (int * __restrict__) (model_L1_Memory+12160);
	KerArg1->Pad = (v4s) 0;
	KerArg2->In = (int *__restrict__) (model_L1_Memory+12160);
	KerArg2->Out = (void *__restrict__) (model_L1_Memory+12160);
	KerArg2->Feat = (unsigned short int) (32);
	KerArg2->W = (unsigned short int) (110);
	KerArg2->H = (unsigned short int) (2);
	KerArg2->Scale = (unsigned char *__restrict__) (model_L1_Memory+6848);
	KerArg2->ScaleN = (unsigned char *__restrict__) (model_L1_Memory+6880);
	KerArg2->Infos = (signed char *__restrict__) (model_L1_Memory+40320);
	KerArg3->In = (signed char * __restrict__) (model_L1_Memory+12160);
	KerArg3->W = (unsigned short int) (110);
	KerArg3->UsedW = (unsigned short int) (110);
	KerArg3->H = (unsigned short int) (2);
	KerArg3->UsedH = (unsigned short int) (2);
	KerArg3->Feat = (unsigned short int) (32);
	KerArg3->Pad = (v4s) 0;
	KerArg3->PoolMax = (unsigned char) (1);
	KerArg3->DoScale = (unsigned char) (0);
	KerArg3->Infos = (signed char * __restrict__) (model_L1_Memory+40320);
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=1760; _LC_Out=55;
	_SPP_Out=0; _SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+6720), 128, 0, &DmaR_Evt1);
	AT_L2_WAIT(0, &DmaR_Evt1); /* Wait previous DMA read Bias */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+6848), 32, 0, &DmaR_Evt2);
	AT_L2_WAIT(0, &DmaR_Evt2); /* Wait previous DMA read Scale */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+6880), 32, 0, &DmaR_Evt3);
	AT_L2_WAIT(0, &DmaR_Evt3); /* Wait previous DMA read ScaleN */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+6912+0), 864, 0, &DmaR_Evt4);
	_N_Filter=0;
	AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+0+0), 3360, 50176, 1120, 0, &DmaR_Evt5);
	_N_In=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+40320), 9, 0, &DmaR_Evt6);
	AT_L2_WAIT(0, &DmaR_Evt6); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1, D1Ind_NextLast = 1;
		/*================================= Prepare Tiles ===================================*/
		_SN_Filter = 0;
		
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, &DmaR_Evt4); /* Wait previous DMA read Filter */
		if (_SN_Filter) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+_N_Filter), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+6912+864*((D1Ind_Total+1)%2)),
					_SN_Filter, 0, &DmaR_Evt4);
		}
		/*============================= End Read Tiles ======================================*/
		for (T0Ind=0; T0Ind<55; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==54), T0Ind_NextLast = ((T0Ind+1)==54);
			/*====================== Call Kernel LOC_D0_PROLOG =========================*/
			KerArg0->NormBias = (unsigned char) (((char *)(model_L1_Memory+40320))[5]);
			AT_FORK(gap_ncore(), (void *) KerParSetBiasB32_SQ8, (void *) KerArg0);
			__CALL(KerParSetBiasB32_SQ8, KerArg0);
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1, D0Ind_NextLast = 1;
				/*================================= Prepare Tiles ===================================*/
				_SN_In = 0;
				if (!(T0Ind_Last)) {
					_N_In = _N_In + (896); _LN_In = (1120); _SN_In = (3*_LN_In); 
				} else if (!(1)) {
					_N_In = _N_In + (-48384); _LN_In = (1120); _SN_In = (3*_LN_In); 
				}
				/*============================= End Prepare Tiles ===================================*/
				/*================================= Read Tiles ======================================*/
				AT_L2_WAIT(0, &DmaR_Evt5); /* Wait previous DMA read In */
				if (_SN_In) {
					AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+0+3360*((D0Ind_Total+1)%2)),
							_SN_In, 50176, _LN_In, 0, &DmaR_Evt5);
				}
				/*============================= End Read Tiles ======================================*/
				/*====================== Call Kernel LOC_D0 =========================*/
				KerArg1->In = (signed char * __restrict__) (model_L1_Memory+0+3360*((D0Ind_Total)%2));
				KerArg1->Filter = (signed char * __restrict__) (model_L1_Memory+6912+864*((D1Ind_Total)%2));
				AT_FORK(gap_ncore(), (void *) KerParConv3x3Stride2_SQ8, (void *) KerArg1);
				__CALL(KerParConv3x3Stride2_SQ8, KerArg1);
				/*================================= Update Arg Pipeline =============================*/
				/*============================= End Update Arg Pipeline =============================*/
				D0Ind_Total++;
			} /* End iteration on D0 */
			/*====================== Call Kernel LOC_D0_EPILOG =========================*/
			AT_FORK(gap_ncore(), (void *) KerParReductIO_CC_SQ8, (void *) KerArg2);
			__CALL(KerParReductIO_CC_SQ8, KerArg2);
			KerArg3->Out = (signed char * __restrict__) (model_L1_Memory+8640+1760*((T0Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) KerParPool2x2Stride2_ReLU_SQ8, (void *) KerArg3);
			__CALL(KerParPool2x2Stride2_ReLU_SQ8, KerArg3);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, &DmaW_Evt1); /* Wait previous DMA write Out */
			if (_SPP_Out) AT_HYPERRAM_CL_WAIT(&HyperRam, &UchanHR1); /* Wait previous uDMA write Out */
			if (_SP_Out) AT_HYPERRAM_CL_COPY2D(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory+170468+1760*((T0Ind_Total+-1)%2)),
						_SP_Out, 3025, _LP_Out, 1, &UchanHR1);
			AT_L2_COPY(0, ((AT_HYPERRAM_EXT_ADDR_TYPE) model_L2_Memory+170468+1760*((T0Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+8640+1760*((T0Ind_Total)%2)),
					_SC_Out, 1, &DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_Out = _SP_Out;_LPP_Out = _LP_Out;
			_P_Out = _C_Out;_SP_Out = _SC_Out;_LP_Out = _LC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (55); _LC_Out = (55); _SC_Out = (32*_LC_Out); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
		/*================================= Update Arg Pipeline =============================*/
		/*============================= End Update Arg Pipeline =============================*/
		D1Ind_Total++;
	} /* End iteration on D1 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, &DmaW_Evt1); /* Wait previous DMA write Out */
	if (_SPP_Out) AT_HYPERRAM_CL_WAIT(&HyperRam, &UchanHR1); /* Wait previous uDMA write Out */
	AT_HYPERRAM_CL_COPY2D(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory+170468+1760*((T0Ind_Total+-1)%2)), _SP_Out, 3025, _LP_Out, 1, &UchanHR1);
	AT_HYPERRAM_CL_WAIT(&HyperRam, &UchanHR1); /* Wait current uDMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void S3_Conv2d_64x32x3x3_MaxPool_2x2_Relu(
		signed char * __restrict__ In,
		signed char * __restrict__ Filter,
		int * __restrict__ Bias,
		signed char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		unsigned char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 47436 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT DmaR_Evt1;
	AT_L2_EVENT DmaR_Evt2;
	AT_L2_EVENT DmaR_Evt3;
	AT_L2_EVENT DmaR_Evt4;
	AT_L2_EVENT DmaR_Evt5;
	AT_L2_EVENT DmaR_Evt6;
	AT_L2_EVENT DmaW_Evt1;
	AT_HYPERRAM_CL_EVENT UchanHR1;
	KerSetBias_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;
	KerConv_SQ8_T S_KerArg1, *KerArg1 = &S_KerArg1;
	KerConvLinReduct_SQ8_T S_KerArg2, *KerArg2 = &S_KerArg2;
	KerPool_SQ8_T S_KerArg3, *KerArg3 = &S_KerArg3;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _LP_Out, _LC_Out;
	unsigned int _N_Filter;
	unsigned int _SN_Filter;
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	unsigned int _LN_In, _LNN_In;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 64, Tiled: 2][Tile0 Dim: 26][D0 Dim: Init: 32, Tiled: 3]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 0
		KerArgItSpace: 52 logical tiles, 52 physical tiles
			Total Size: 43264 [D1, [1 x 27040, 16224]][Tile0, 26:[26x1, 24:26x1, 26x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [1 x 27040, 16224]][Tile0, 26:[26x1, 24:26x1, 26x1], 1]
		Tile0: [0, 1040, 26], Tile1: [26, 1040, 26], Tile2; [52, 1040, 26]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			Total Size: 256 [D1, [1 x 160, 96]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [1 x 160, 96]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			Total Size: 64 [D1, [1 x 40, 24]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [1 x 40, 24]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			Total Size: 64 [D1, [1 x 40, 24]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [1 x 40, 24]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Filter, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 156 logical tiles, 2 physical tiles
			Total Size: 18432 [D1, [1 x 11520, 6912]][D0, [2 x 4320, 2880]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [1 x 11520, 6912]][D0, [2 x 4320, 2880]]
		Tile0: [0, 11520, 288], Tile1: [11520, 6912, 288], Tile2; [0, 11520, 288]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 78 logical tiles, 78 physical tiles
			Total Size: 96800 [D0, [2 x 36300, 24200]][Tile0, 26:[55x4, 24:55x4, 55x4], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 26:[55x4, 24:55x4, 55x4], 1][D0, [2 x 36300, 24200]]
		Tile0: [0, 2640, 220], Tile1: [36300, 2640, 220], Tile2; [72600, 1760, 220]
	Ker Arg: ConvOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 52 logical tiles, 1 physical tiles
			Total Size: 692224 [D1, [1 x 432640, 259584]][Tile0, 26:[52x2, 24:52x2, 52x2], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [1 x 432640, 259584]][Tile0, 26:[52x2, 24:52x2, 52x2], 4]
		Tile0: [0, 16640, 416], Tile1: [0, 16640, 416], Tile2; [0, 16640, 416]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 26 logical tiles, 1 physical tiles
			Total Size: 9 [Tile0, 26:[9x1, 24:9x1, 9x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 26:[9x1, 24:9x1, 9x1], 1]
		Tile0: [0, 9, 9], Tile1: [0, 9, 9], Tile2; [0, 9, 9]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Out = (int * __restrict__) (model_L1_Memory+30784);
	KerArg0->W = (unsigned short int) (52);
	KerArg0->H = (unsigned short int) (2);
	KerArg1->W = (unsigned short int) (55);
	KerArg1->UsedW = (unsigned short int) (54);
	KerArg1->H = (unsigned short int) (4);
	KerArg1->UsedH = (unsigned short int) (4);
	KerArg1->TotalInFeatures = (unsigned short int) (32);
	KerArg1->Out = (int * __restrict__) (model_L1_Memory+30784);
	KerArg1->Pad = (v4s) 0;
	KerArg2->In = (int *__restrict__) (model_L1_Memory+30784);
	KerArg2->Out = (void *__restrict__) (model_L1_Memory+30784);
	KerArg2->W = (unsigned short int) (52);
	KerArg2->H = (unsigned short int) (2);
	KerArg2->Infos = (signed char *__restrict__) (model_L1_Memory+47424);
	KerArg3->In = (signed char * __restrict__) (model_L1_Memory+30784);
	KerArg3->W = (unsigned short int) (52);
	KerArg3->UsedW = (unsigned short int) (52);
	KerArg3->H = (unsigned short int) (2);
	KerArg3->UsedH = (unsigned short int) (2);
	KerArg3->Pad = (v4s) 0;
	KerArg3->PoolMax = (unsigned char) (1);
	KerArg3->DoScale = (unsigned char) (0);
	KerArg3->Infos = (signed char * __restrict__) (model_L1_Memory+47424);
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=1040; _LC_Out=26;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+5280), 256, 0, &DmaR_Evt1);
	AT_L2_WAIT(0, &DmaR_Evt1); /* Wait previous DMA read Bias */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+5536), 64, 0, &DmaR_Evt2);
	AT_L2_WAIT(0, &DmaR_Evt2); /* Wait previous DMA read Scale */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+5600), 64, 0, &DmaR_Evt3);
	AT_L2_WAIT(0, &DmaR_Evt3); /* Wait previous DMA read ScaleN */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+5664+0), 11520, 0, &DmaR_Evt4);
	_N_Filter=0;
	AT_HYPERRAM_CL_COPY2D(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) In+0), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory+63204+0), 2640, 3025, 220, 0, &UchanHR1);
	AT_HYPERRAM_CL_WAIT(&HyperRam, &UchanHR1); /* Wait previous uDMA read In */
	AT_HYPERRAM_CL_COPY2D(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) In+36300), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory+63204+2640), 2640, 3025, 220, 0, &UchanHR1);
	AT_L2_COPY(0, ((AT_HYPERRAM_EXT_ADDR_TYPE) model_L2_Memory+63204+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+0+0), 2640, 0, &DmaR_Evt5);
	_NN_In=36300; _SN_In=2640;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+47424), 9, 0, &DmaR_Evt6);
	AT_L2_WAIT(0, &DmaR_Evt6); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D1Ind=0; D1Ind<2; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
		int D1Ind_Last = (D1Ind==1), D1Ind_NextLast = ((D1Ind+1)==1);
		/*================================= Prepare Tiles ===================================*/
		_SN_Filter = 0;
		if (!(D1Ind_Last)) {
			_N_Filter = _N_Filter + (11520); _SN_Filter = ((1)?6912:11520); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, &DmaR_Evt4); /* Wait previous DMA read Filter */
		if (_SN_Filter) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+_N_Filter), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+5664+11520*((D1Ind_Total+1)%2)),
					_SN_Filter, 0, &DmaR_Evt4);
		}
		/*============================= End Read Tiles ======================================*/
		for (T0Ind=0; T0Ind<26; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==25), T0Ind_NextLast = ((T0Ind+1)==25), T0Ind_NextNextLast = ((T0Ind+2)==25);
			/*====================== Call Kernel LOC_D0_PROLOG =========================*/
			KerArg0->Feat = (unsigned short int) (D1Ind_Last?24:40);
			KerArg0->Bias = (void * __restrict__) (model_L1_Memory+5280+((D1Ind)*160));
			KerArg0->NormBias = (unsigned char) (((char *)(model_L1_Memory+47424))[5]);
			AT_FORK(gap_ncore(), (void *) KerParSetBiasB32_SQ8, (void *) KerArg0);
			__CALL(KerParSetBiasB32_SQ8, KerArg0);
			for (D0Ind=0; D0Ind<3; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
				int D0Ind_Last = (D0Ind==2), D0Ind_NextLast = ((D0Ind+1)==2), D0Ind_NextNextLast = ((D0Ind+2)==2);
				/*================================= Prepare Tiles ===================================*/
				_SNN_In = 0;
				if (!(D0Ind_Last)) {
					if (!(D0Ind_NextLast)) {
						_NN_In = _NN_In + (36300); _LNN_In = (220); _SNN_In = (((1)?8:12)*_LNN_In); 
					} else if (!(T0Ind_Last)) {
						_NN_In = _NN_In + (110)+(-72600); _LNN_In = (220); _SNN_In = (12*_LNN_In); 
					} else if (!(D1Ind_Last)) {
						_NN_In = _NN_In + (-2750)+(-72600); _LNN_In = (220); _SNN_In = (12*_LNN_In); 
					}
				} else if (!(T0Ind_Last)) {
					_NN_In = _NN_In + (36300); _LNN_In = (220); _SNN_In = (12*_LNN_In); 
				} else if (!((D1Ind_Last))) {
					_NN_In = _NN_In + (36300); _LNN_In = (220); _SNN_In = (12*_LNN_In); 
				}
				/*============================= End Prepare Tiles ===================================*/
				/*================================= Read Tiles ======================================*/
				AT_HYPERRAM_CL_WAIT(&HyperRam, &UchanHR1); /* Wait previous uDMA read In */
				if (_SNN_In) {
					AT_HYPERRAM_CL_COPY2D(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory+63204+2640*((D0Ind_Total)%2)),
							_SNN_In, 3025, _LNN_In, 0, &UchanHR1);
				}
				AT_L2_WAIT(0, &DmaR_Evt5); /* Wait previous DMA read In */
				if (_SN_In) {
					AT_L2_COPY(0, ((AT_HYPERRAM_EXT_ADDR_TYPE) model_L2_Memory+63204+2640*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+0+2640*((D0Ind_Total+1)%2)),
							_SN_In, 0, &DmaR_Evt5);
				}
				/*============================= End Read Tiles ======================================*/
				/*====================== Call Kernel LOC_D0 =========================*/
				KerArg1->In = (signed char * __restrict__) (model_L1_Memory+0+2640*((D0Ind_Total)%2));
				KerArg1->InFeatures = (unsigned short int) (D0Ind_Last?8:12);
				KerArg1->OutFeatures = (unsigned short int) (D1Ind_Last?24:40);
				KerArg1->Filter = (signed char * __restrict__) (model_L1_Memory+5664+((D0Ind)*108)+11520*((D1Ind_Total)%2));
				AT_FORK(gap_ncore(), (void *) KerParConv3x3Stride1_SQ8, (void *) KerArg1);
				__CALL(KerParConv3x3Stride1_SQ8, KerArg1);
				/*================================= Update Arg Pipeline =============================*/
				_SN_In = _SNN_In;_LN_In = _LNN_In;
				/*============================= End Update Arg Pipeline =============================*/
			} /* End iteration on D0 */
			/*====================== Call Kernel LOC_D0_EPILOG =========================*/
			KerArg2->Feat = (unsigned short int) (D1Ind_Last?24:40);
			KerArg2->Scale = (unsigned char *__restrict__) (model_L1_Memory+5536+((D1Ind)*40));
			KerArg2->ScaleN = (unsigned char *__restrict__) (model_L1_Memory+5600+((D1Ind)*40));
			AT_FORK(gap_ncore(), (void *) KerParReductIO_CC_SQ8, (void *) KerArg2);
			__CALL(KerParReductIO_CC_SQ8, KerArg2);
			KerArg3->Feat = (unsigned short int) (D1Ind_Last?24:40);
			KerArg3->Out = (signed char * __restrict__) (model_L1_Memory+28704+1040*((T0Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) KerParPool2x2Stride2_ReLU_SQ8, (void *) KerArg3);
			__CALL(KerParPool2x2Stride2_ReLU_SQ8, KerArg3);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, &DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+28704+1040*((T0Ind_Total)%2)),
					_SC_Out, 676, _LC_Out, 1, &DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;_LP_Out = _LC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (26); _LC_Out = (26); _SC_Out = (((D1Ind_Last)?24:40)*_LC_Out); 
			} else if (!(D1Ind_Last)) {
				_C_Out = _C_Out + (27040)+(-650); _LC_Out = (26); _SC_Out = (((1)?24:40)*_LC_Out); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
		/*================================= Update Arg Pipeline =============================*/
		/*============================= End Update Arg Pipeline =============================*/
	} /* End iteration on D1 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, &DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void S4_Linear_3x26x26x64(
		signed char * __restrict__ In,
		signed char * __restrict__ Filter,
		int * __restrict__ Bias,
		signed char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		unsigned char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 48768 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT DmaR_Evt1;
	AT_L2_EVENT DmaR_Evt2;
	AT_L2_EVENT DmaR_Evt3;
	AT_L2_EVENT DmaR_Evt4;
	AT_L2_EVENT DmaR_Evt5;
	AT_L2_EVENT DmaR_Evt6;
	AT_L2_EVENT DmaW_Evt1;
	AT_HYPERRAM_CL_EVENT UchanHR1;
	KerSetBias_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;
	KerLinear_SQ8_T S_KerArg1, *KerArg1 = &S_KerArg1;
	KerConvLinReduct_SQ8_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _NN_Filter;
	unsigned int _SN_Filter, _SNN_Filter;
	unsigned int _LN_Filter, _LNN_Filter;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 3, Tiled: 1][Tile0 Dim: 8]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 8 logical tiles, 8 physical tiles
			Total Size: 43264 [Tile0, 8:[1x6089, 6:1x6089, 1x641], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 8:[1x6089, 6:1x6089, 1x641], 1]
		Tile0: [0, 6089, 6089], Tile1: [6089, 6089, 6089], Tile2; [12178, 6089, 6089]
	Ker Arg: Filter, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 8 logical tiles, 8 physical tiles
			Total Size: 129792 [D0, [0 x 129792, 129792]][Tile0, 8:[1x6089, 6:1x6089, 1x641], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 129792, 129792]][Tile0, 8:[1x6089, 6:1x6089, 1x641], 1]
		Tile0: [0, 18267, 6089], Tile1: [18267, 18267, 6089], Tile2; [36534, 18267, 6089]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 12 [D0, [0 x 12, 12]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 12, 12]]
		Tile0: [0, 12, 12], Tile1: [0, 12, 12], Tile2; [0, 12, 12]
	Ker Arg: LinOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 12 [D0, [0 x 12, 12]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 12, 12]]
		Tile0: [0, 12, 12], Tile1: [0, 12, 12], Tile2; [0, 12, 12]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 3 [D0, [0 x 3, 3]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 3, 3]]
		Tile0: [0, 3, 3], Tile1: [0, 3, 3], Tile2; [0, 3, 3]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 3 [D0, [0 x 3, 3]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 3, 3]]
		Tile0: [0, 3, 3], Tile1: [0, 3, 3], Tile2; [0, 3, 3]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 3 [D0, [0 x 3, 3]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 3, 3]]
		Tile0: [0, 3, 3], Tile1: [0, 3, 3], Tile2; [0, 3, 3]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 8 logical tiles, 1 physical tiles
			Total Size: 9 [Tile0, 8:[1x1, 6:1x1, 1x1], 9]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 8:[1x1, 6:1x1, 1x1], 9]
		Tile0: [0, 9, 9], Tile1: [0, 9, 9], Tile2; [0, 9, 9]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Out = (int * __restrict__) (model_L1_Memory+48732);
	KerArg0->W = (unsigned short int) (1);
	KerArg0->H = (unsigned short int) (1);
	KerArg0->Feat = (unsigned short int) (3);
	KerArg0->Bias = (void * __restrict__) (model_L1_Memory+48720);
	KerArg1->Out = (void * __restrict__) (model_L1_Memory+48732);
	KerArg1->OutDim = (unsigned short int) (3);
	KerArg1->Infos = (signed char *__restrict__) (model_L1_Memory+48756);
	KerArg2->In = (int *__restrict__) (model_L1_Memory+48732);
	KerArg2->Out = (void *__restrict__) (model_L1_Memory+48744);
	KerArg2->Feat = (unsigned short int) (3);
	KerArg2->W = (unsigned short int) (1);
	KerArg2->H = (unsigned short int) (1);
	KerArg2->Scale = (unsigned char *__restrict__) (model_L1_Memory+48748);
	KerArg2->ScaleN = (unsigned char *__restrict__) (model_L1_Memory+48752);
	KerArg2->Infos = (signed char *__restrict__) (model_L1_Memory+48756);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+0+0), 6089, 0, &DmaR_Evt1);
	_N_In=0;
	AT_HYPERRAM_CL_COPY(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) Filter+0), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory+63208+0), 18267, 0, &UchanHR1);
	AT_HYPERRAM_CL_WAIT(&HyperRam, &UchanHR1); /* Wait previous uDMA read Filter */
	AT_HYPERRAM_CL_COPY(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) Filter+18267), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory+63208+18268), 18267, 0, &UchanHR1);
	AT_L2_COPY(0, ((AT_HYPERRAM_EXT_ADDR_TYPE) model_L2_Memory+63208+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+12184+0), 18267, 0, &DmaR_Evt2);
	_NN_Filter=18267; _SN_Filter=18267;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+48720), 12, 0, &DmaR_Evt3);
	AT_L2_WAIT(0, &DmaR_Evt3); /* Wait previous DMA read Bias */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+48748), 3, 0, &DmaR_Evt4);
	AT_L2_WAIT(0, &DmaR_Evt4); /* Wait previous DMA read Scale */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+48752), 3, 0, &DmaR_Evt5);
	AT_L2_WAIT(0, &DmaR_Evt5); /* Wait previous DMA read ScaleN */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+48756), 9, 0, &DmaR_Evt6);
	AT_L2_WAIT(0, &DmaR_Evt6); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1, D0Ind_NextNextLast = 1;
		/*====================== Call Kernel LOC_LOOP_PROLOG =========================*/
		KerArg0->NormBias = (unsigned char) (((char *)(model_L1_Memory+48756))[5]);
		AT_FORK(gap_ncore(), (void *) KerParSetBiasB32_SQ8, (void *) KerArg0);
		__CALL(KerParSetBiasB32_SQ8, KerArg0);
		for (T0Ind=0; T0Ind<8; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==7), T0Ind_NextLast = ((T0Ind+1)==7), T0Ind_NextNextLast = ((T0Ind+2)==7);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (6089); _SN_In = ((T0Ind_NextLast)?641:6089); 
			} else if (!(1)) {
				_N_In = _N_In + (-42623); _SN_In = (6089); 
			}
			_SNN_Filter = 0;
			if (!(T0Ind_Last)) {
				if (!(T0Ind_NextLast)) {
					_NN_Filter = _NN_Filter + (18267); _LNN_Filter = ((T0Ind_NextNextLast)?641:6089); _SNN_Filter = (3*_LNN_Filter); 
				}
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, &DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+0+6092*((T0Ind_Total+1)%2)),
						_SN_In, 0, &DmaR_Evt1);
			}
			AT_HYPERRAM_CL_WAIT(&HyperRam, &UchanHR1); /* Wait previous uDMA read Filter */
			if (_SNN_Filter) {
				AT_HYPERRAM_CL_COPY(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) Filter+_NN_Filter), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory+63208+18268*((T0Ind_Total)%2)),
						_SNN_Filter, 0, &UchanHR1);
			}
			AT_L2_WAIT(0, &DmaR_Evt2); /* Wait previous DMA read Filter */
			if (_SN_Filter) {
				AT_L2_COPY(0, ((AT_HYPERRAM_EXT_ADDR_TYPE) model_L2_Memory+63208+18268*((T0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+12184+18268*((T0Ind_Total+1)%2)),
						_SN_Filter, 0, &DmaR_Evt2);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_LOOP =========================*/
			KerArg1->In = (signed char * __restrict__) (model_L1_Memory+0+6092*((T0Ind_Total)%2));
			KerArg1->Weights = (signed char * __restrict__) (model_L1_Memory+12184+18268*((T0Ind_Total)%2));
			KerArg1->InDim = (unsigned short int) (T0Ind_Last?641:6089);
			KerArg1->TotalInDim = (unsigned short int) (T0Ind_Last?641:6089);
			AT_FORK(gap_ncore(), (void *) KerParLinearLayer_SQ8, (void *) KerArg1);
			__CALL(KerParLinearLayer_SQ8, KerArg1);
			/*================================= Update Arg Pipeline =============================*/
			_SN_Filter = _SNN_Filter;_LN_Filter = _LNN_Filter;
			/*============================= End Update Arg Pipeline =============================*/
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_LOOP_EPILOG =========================*/
		AT_FORK(gap_ncore(), (void *) KerParReduct_CC_SQ8, (void *) KerArg2);
		__CALL(KerParReduct_CC_SQ8, KerArg2);
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+48744), 3, 1, &DmaW_Evt1);
	AT_L2_WAIT(0, &DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void S5_SoftMax(
		signed char * __restrict__ In,
		short int * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 24 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT DmaR_Evt1;
	AT_L2_EVENT DmaR_Evt2;
	AT_L2_EVENT DmaW_Evt1;
	KerSoftMax_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 3 [Tile0, 1:[1x3], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x3], 1]
		Tile0: [0, 3, 3], Tile1: [0, 3, 3], Tile2; [0, 3, 3]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 6 [Tile0, 1:[1x3], 2]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x3], 2]
		Tile0: [0, 6, 6], Tile1: [0, 6, 6], Tile2; [0, 6, 6]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 9 [Tile0, 1:[9x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[9x1], 1]
		Tile0: [0, 9, 9], Tile1: [0, 9, 9], Tile2; [0, 9, 9]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (signed char *__restrict__) (model_L1_Memory+0);
	KerArg0->N = (unsigned short int) (3);
	KerArg0->Out = (short int *__restrict__) (model_L1_Memory+4);
	KerArg0->Infos = (signed char *__restrict__) (model_L1_Memory+12);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+0), 3, 0, &DmaR_Evt1);
	AT_L2_WAIT(0, &DmaR_Evt1); /* Wait previous DMA read In */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+12), 9, 0, &DmaR_Evt2);
	AT_L2_WAIT(0, &DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->Norm = (unsigned short int) (((char *)(model_L1_Memory+12))[0]);
		AT_FORK(gap_ncore(), (void *) KerParSoftMax_SQ8, (void *) KerArg0);
		__CALL(KerParSoftMax_SQ8, KerArg0);
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+4), 6, 1, &DmaW_Evt1);
	AT_L2_WAIT(0, &DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
int modelCNN_Construct()

{
	AT_HYPERFLASH_FS_FC_EVENT UchanHF1;
	AT_HYPERRAM_FC_EVENT UchanHR2;
	AT_HYPERRAM_CONF_T HyperRamConf;
	AT_HYPERFLASH_FS_CONF_T HyperFlashConf;
	int Error;
	AT_HYPERRAM_CONF_INIT(&HyperRamConf, AT_MEM_L3_HRAM, 0);
	AT_HYPERFLASH_FS_CONF_INIT(&HyperFlashConf, AT_MEM_L3_HFLASH, 0);
	AT_HYPERRAM_OPEN(&HyperRam, &HyperRamConf, &Error);
	if (Error) return 1;
	AT_HYPERFLASH_FS_OPEN(&HyperFlash, &HyperFlashConf, "model_L3_Flash_Const.dat", &Error);
	if (Error) return 1;
	model_L3_Memory = (AT_HYPERRAM_POINTER) AT_HYPERRAM_ALLOC(&HyperRam, 226592);
	if (model_L3_Memory == 0) return 2;
	model_L2_Memory = (AT_L2_POINTER) AT_L2_ALLOC(0, 173987);
	if (model_L2_Memory == 0) return 3;
	model_L1_Memory = (AT_L1_POINTER) AT_L1_ALLOC(0, 48768);
	if (model_L1_Memory == 0) return 4;
	/* Moving S4_Weights, size 129792 from HyperFlash at 0 to (size 129792) HyperRam at 0..129791 */
	{
		int Size = 129792, Base = 0;
		while (Size) {
			int Chunk = Min(Size, 1024);
			AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 0+Base), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 0), Chunk, 0, &UchanHF1);
			AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
			AT_HYPERRAM_FC_COPY(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) model_L3_Memory + 0+Base), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory + 0), Chunk, 1, &UchanHR2);
			AT_HYPERRAM_FC_WAIT(&HyperRam, &UchanHR2);
			Base += Chunk;
			Size -= Chunk;
		}
	}
	/* Moving S2_Infos, size 9 from HyperFlash at 149664 to (size 9) L2 at 19872..19880 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 149664), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19872), 9, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S2_Weights, size 864 from HyperFlash at 148224 to (size 864) L2 at 18432..19295 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 148224), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 18432), 864, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S2_Biases, size 128 from HyperFlash at 149344 to (size 128) L2 at 19552..19679 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 149344), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19552), 128, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S2_Mul_scale, size 32 from HyperFlash at 149600 to (size 32) L2 at 19808..19839 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 149600), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19808), 32, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S2_Mul_shift, size 32 from HyperFlash at 149632 to (size 32) L2 at 19840..19871 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 149632), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19840), 32, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S3_Infos, size 9 from HyperFlash at 149676 to (size 9) L2 at 19884..19892 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 149676), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19884), 9, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S3_Weights, size 18432 from HyperFlash at 129792 to (size 18432) L2 at 0..18431 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 129792), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 0), 18432, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S3_Biases, size 256 from HyperFlash at 149088 to (size 256) L2 at 19296..19551 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 149088), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19296), 256, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S3_Mul_scale, size 64 from HyperFlash at 149472 to (size 64) L2 at 19680..19743 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 149472), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19680), 64, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S3_Mul_shift, size 64 from HyperFlash at 149536 to (size 64) L2 at 19744..19807 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 149536), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19744), 64, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S4_Infos, size 9 from HyperFlash at 149688 to (size 9) L2 at 19896..19904 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 149688), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19896), 9, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S4_Biases, size 12 from HyperFlash at 149700 to (size 12) L2 at 19908..19919 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 149700), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19908), 12, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S4_Mul_scale, size 3 from HyperFlash at 149724 to (size 3) L2 at 19932..19934 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 149724), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19932), 3, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S4_Mul_shift, size 3 from HyperFlash at 149728 to (size 3) L2 at 19936..19938 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 149728), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19936), 3, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S5_Infos, size 9 from HyperFlash at 149712 to (size 9) L2 at 19920..19928 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 149712), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19920), 9, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	return 0;
}
int modelCNN_Destruct()

{
	AT_HYPERRAM_FREE(&HyperRam, model_L3_Memory, 226592);
	AT_L2_FREE(0, model_L2_Memory, 173987);
	AT_L1_FREE(0, model_L1_Memory, 48768);
	AT_HYPERRAM_CLOSE(&HyperRam);
	AT_HYPERFLASH_FS_CLOSE(&HyperFlash);
	return 0;
}
unsigned int AT_GraphPerf[5];
unsigned int AT_GraphOperInfosNames[5] = {
	225792,
	10938400,
	50056448,
	129792,
	3,
};
char *AT_GraphNodeNames[5] = {
	"S1_Op_input_1_formatterBody",
	"S2_Conv2d_32x3x3x3_MaxPool_2x2_Relu",
	"S3_Conv2d_64x32x3x3_MaxPool_2x2_Relu",
	"S4_Linear_3x26x26x64",
	"S5_SoftMax",
};
int modelCNN(
		unsigned char * __restrict__ Input_1,
		signed short * __restrict__ Output_1)

{
	AT_GraphPerf[0] = gap_cl_readhwtimer();
	S1_Op_input_1_formatterBody(
		((unsigned char * __restrict__) Input_1), /* In */
		((signed char * __restrict__) (model_L2_Memory+19940)), /* Out0 */
		((signed char * __restrict__) ((model_L2_Memory+19940) + 50176)), /* Out1 */
		((signed char * __restrict__) ((model_L2_Memory+19940) + 100352)) /* Out2 */
	);
	AT_GraphPerf[0] = gap_cl_readhwtimer() - AT_GraphPerf[0];
	AT_GraphPerf[1] = gap_cl_readhwtimer();
	S2_Conv2d_32x3x3x3_MaxPool_2x2_Relu(
		((signed char * __restrict__) (model_L2_Memory+19940)), /* In */
		((signed char * __restrict__) (model_L2_Memory+18432)), /* Filter */
		((signed int * __restrict__) (model_L2_Memory+19552)), /* Bias */
		((signed char * __restrict__) (model_L3_Memory+129792)), /* Out */
		((unsigned char * __restrict__) (model_L2_Memory+19808)), /* Scale */
		((signed char * __restrict__) (model_L2_Memory+19840)), /* ScaleN */
		((signed char * __restrict__) (model_L2_Memory+19872)) /* Infos */
	);
	AT_GraphPerf[1] = gap_cl_readhwtimer() - AT_GraphPerf[1];
	AT_GraphPerf[2] = gap_cl_readhwtimer();
	S3_Conv2d_64x32x3x3_MaxPool_2x2_Relu(
		((signed char * __restrict__) (model_L3_Memory+129792)), /* In */
		((signed char * __restrict__) (model_L2_Memory+0)), /* Filter */
		((signed int * __restrict__) (model_L2_Memory+19296)), /* Bias */
		((signed char * __restrict__) (model_L2_Memory+19940)), /* Out */
		((unsigned char * __restrict__) (model_L2_Memory+19680)), /* Scale */
		((signed char * __restrict__) (model_L2_Memory+19744)), /* ScaleN */
		((signed char * __restrict__) (model_L2_Memory+19884)) /* Infos */
	);
	AT_GraphPerf[2] = gap_cl_readhwtimer() - AT_GraphPerf[2];
	AT_GraphPerf[3] = gap_cl_readhwtimer();
	S4_Linear_3x26x26x64(
		((signed char * __restrict__) (model_L2_Memory+19940)), /* In */
		((signed char * __restrict__) (model_L3_Memory+0)), /* Filter */
		((signed int * __restrict__) (model_L2_Memory+19908)), /* Bias */
		((signed char * __restrict__) (model_L2_Memory+63204)), /* Out */
		((unsigned char * __restrict__) (model_L2_Memory+19932)), /* Scale */
		((signed char * __restrict__) (model_L2_Memory+19936)), /* ScaleN */
		((signed char * __restrict__) (model_L2_Memory+19896)) /* Infos */
	);
	AT_GraphPerf[3] = gap_cl_readhwtimer() - AT_GraphPerf[3];
	AT_GraphPerf[4] = gap_cl_readhwtimer();
	S5_SoftMax(
		((signed char * __restrict__) (model_L2_Memory+63204)), /* In */
		((signed short * __restrict__) Output_1), /* Out */
		((signed char * __restrict__) (model_L2_Memory+19920)) /* Infos */
	);
	AT_GraphPerf[4] = gap_cl_readhwtimer() - AT_GraphPerf[4];
	return 0;
}
