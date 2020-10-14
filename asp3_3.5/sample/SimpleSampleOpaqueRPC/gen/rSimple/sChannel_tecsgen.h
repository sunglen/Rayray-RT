/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef sChannel_TECSGEN_H
#define sChannel_TECSGEN_H

/*
 * signature   :  sChannel
 * global name :  sChannel
 * context     :  task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_sChannel_VDES {
    struct tag_sChannel_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_sChannel_VMT {
    ER             (*send__T)( const struct tag_sChannel_VDES *edp, const int8_t* buf, int16_t size, TMO tmo );
    ER             (*flush__T)( const struct tag_sChannel_VDES *edp, TMO tmo );
    ER_UINT        (*receive__T)( const struct tag_sChannel_VDES *edp, int8_t* buf, int16_t size, TMO tmo );
    ER             (*end_receive__T)( const struct tag_sChannel_VDES *edp );
    ER             (*reset__T)( const struct tag_sChannel_VDES *edp );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_sChannel_Defined
#define  Descriptor_of_sChannel_Defined
typedef struct { struct tag_sChannel_VDES *vdes; } Descriptor( sChannel );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SCHANNEL_SEND                   (1)
#define	FUNCID_SCHANNEL_FLUSH                  (2)
#define	FUNCID_SCHANNEL_RECEIVE                (3)
#define	FUNCID_SCHANNEL_END_RECEIVE            (4)
#define	FUNCID_SCHANNEL_RESET                  (5)

#endif /* sChannel_TECSGEN_H */
