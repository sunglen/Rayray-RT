/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef sUnmarshalerMain_TECSGEN_H
#define sUnmarshalerMain_TECSGEN_H

/*
 * signature   :  sUnmarshalerMain
 * global name :  sUnmarshalerMain
 * context     :  task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_sUnmarshalerMain_VDES {
    struct tag_sUnmarshalerMain_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_sUnmarshalerMain_VMT {
    ER             (*main__T)( const struct tag_sUnmarshalerMain_VDES *edp );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_sUnmarshalerMain_Defined
#define  Descriptor_of_sUnmarshalerMain_Defined
typedef struct { struct tag_sUnmarshalerMain_VDES *vdes; } Descriptor( sUnmarshalerMain );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SUNMARSHALERMAIN_MAIN           (1)

#endif /* sUnmarshalerMain_TECSGEN_H */
