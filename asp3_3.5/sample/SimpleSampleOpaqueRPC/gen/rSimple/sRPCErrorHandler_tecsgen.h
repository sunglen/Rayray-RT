/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef sRPCErrorHandler_TECSGEN_H
#define sRPCErrorHandler_TECSGEN_H

/*
 * signature   :  sRPCErrorHandler
 * global name :  sRPCErrorHandler
 * context     :  task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_sRPCErrorHandler_VDES {
    struct tag_sRPCErrorHandler_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_sRPCErrorHandler_VMT {
    ER             (*errorOccured__T)( const struct tag_sRPCErrorHandler_VDES *edp, int16_t func_id, ER er, int16_t state );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_sRPCErrorHandler_Defined
#define  Descriptor_of_sRPCErrorHandler_Defined
typedef struct { struct tag_sRPCErrorHandler_VDES *vdes; } Descriptor( sRPCErrorHandler );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SRPCERRORHANDLER_ERROROCCURED   (1)

#endif /* sRPCErrorHandler_TECSGEN_H */
