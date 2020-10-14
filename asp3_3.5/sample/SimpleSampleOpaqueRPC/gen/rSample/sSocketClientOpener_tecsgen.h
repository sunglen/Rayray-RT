/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef sSocketClientOpener_TECSGEN_H
#define sSocketClientOpener_TECSGEN_H

/*
 * signature   :  sSocketClientOpener
 * global name :  sSocketClientOpener
 * context     :  task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_sSocketClientOpener_VDES {
    struct tag_sSocketClientOpener_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_sSocketClientOpener_VMT {
    ER             (*open__T)( const struct tag_sSocketClientOpener_VDES *edp, const char_t* serverAddr, uint16_t portNo, TMO tmo );
    ER             (*simpleOpen__T)( const struct tag_sSocketClientOpener_VDES *edp, TMO tmo );
    ER             (*close__T)( const struct tag_sSocketClientOpener_VDES *edp, TMO tmo );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_sSocketClientOpener_Defined
#define  Descriptor_of_sSocketClientOpener_Defined
typedef struct { struct tag_sSocketClientOpener_VDES *vdes; } Descriptor( sSocketClientOpener );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SSOCKETCLIENTOPENER_OPEN        (1)
#define	FUNCID_SSOCKETCLIENTOPENER_SIMPLEOPEN  (2)
#define	FUNCID_SSOCKETCLIENTOPENER_CLOSE       (3)

#endif /* sSocketClientOpener_TECSGEN_H */
