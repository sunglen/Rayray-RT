/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef sPPAllocator_TECSGEN_H
#define sPPAllocator_TECSGEN_H

/*
 * signature   :  sPPAllocator
 * global name :  sPPAllocator
 * context     :  task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_sPPAllocator_VDES {
    struct tag_sPPAllocator_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_sPPAllocator_VMT {
    ER             (*alloc__T)( const struct tag_sPPAllocator_VDES *edp, uint32_t size, void** ptr );
    ER             (*dealloc__T)( const struct tag_sPPAllocator_VDES *edp, const void* ptr );
    ER             (*dealloc_all__T)( const struct tag_sPPAllocator_VDES *edp );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_sPPAllocator_Defined
#define  Descriptor_of_sPPAllocator_Defined
typedef struct { struct tag_sPPAllocator_VDES *vdes; } Descriptor( sPPAllocator );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_SPPALLOCATOR_ALLOC              (1)
#define	FUNCID_SPPALLOCATOR_DEALLOC            (2)
#define	FUNCID_SPPALLOCATOR_DEALLOC_ALL        (3)

#endif /* sPPAllocator_TECSGEN_H */
