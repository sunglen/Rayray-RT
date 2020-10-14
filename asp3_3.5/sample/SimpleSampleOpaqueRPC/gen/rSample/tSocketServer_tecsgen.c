/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#include "tSocketServer_tecsgen.h"
#include "tSocketServer_factory.h"

/* 受け口ディスクリプタ型 #_EDT_# */
/* eC1 : omitted by entry port optimize */

/* eOpener : omitted by entry port optimize */

/* 受け口スケルトン関数 #_EPSF_# */
/* eC1 : omitted by entry port optimize */
/* eOpener : omitted by entry port optimize */

/* 受け口スケルトン関数テーブル #_EPSFT_# */
/* eC1 : omitted by entry port optimize */
/* eOpener : omitted by entry port optimize */

/* 呼び口の参照する受け口ディスクリプタ(実際の型と相違した定義) #_CPEPD_# */

/* 呼び口配列 #_CPA_# */

/* 属性・変数の配列 #_AVAI_# */
/* セル INIB #_INIB_# */
tSocketServer_INIB tSocketServer_INIB_tab[] = {
    /* cell: tSocketServer_CB_tab[0]:  Join_to_through___0Server id=1 */
    {
        /* entry port #_EP_# */ 
        /* attribute(RO) */ 
        8931,                                    /* portNo */
    },
};

/* セル CB #_CB_# */
struct tag_tSocketServer_CB tSocketServer_CB_tab[] = {
    /* cell: tSocketServer_CB_tab[0]:  Join_to_through___0Server id=1 */
    {
        &tSocketServer_INIB_tab[0],              /* _inib */
        /* entry port #_EP_# */ 
        /* var */ 
        0,                                       /* sd */
    },
};

/* 受け口ディスクリプタ #_EPD_# */
/* eC1 : omitted by entry port optimize */
/* eOpener : omitted by entry port optimize */
