/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef sServerChannelOpener_TECSGEN_H
#define sServerChannelOpener_TECSGEN_H

/*
 * signature   :  sServerChannelOpener
 * global name :  sServerChannelOpener
 * context     :  task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_sServerChannelOpener_VDES {
    struct tag_sServerChannelOpener_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_sServerChannelOpener_VMT {
    ER             (*open__T)( const struct tag_sServerChannelOpener_VDES *edp );
    ER             (*close__T)( const struct tag_sServerChannelOpener_VDES *edp );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_sServerChannelOpener_Defined
#define  Descriptor_of_sServerChannelOpener_Defined
typedef struct { struct tag_sServerChannelOpener_VDES *vdes; } Descriptor( sServerChannelOpener );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SSERVERCHANNELOPENER_OPEN       (1)
#define	FUNCID_SSERVERCHANNELOPENER_CLOSE      (2)

#endif /* sServerChannelOpener_TECSGEN_H */
