/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#include "tSocketClient_tecsgen.h"
#include "tSocketClient_factory.h"

/* 受け口ディスクリプタ型 #_EDT_# */
/* eC0 : omitted by entry port optimize */

/* eOpener : omitted by entry port optimize */

/* 受け口スケルトン関数 #_EPSF_# */
/* eC0 : omitted by entry port optimize */
/* eOpener : omitted by entry port optimize */

/* 受け口スケルトン関数テーブル #_EPSFT_# */
/* eC0 : omitted by entry port optimize */
/* eOpener : omitted by entry port optimize */

/* 呼び口の参照する受け口ディスクリプタ(実際の型と相違した定義) #_CPEPD_# */

/* 呼び口配列 #_CPA_# */

/* 属性・変数の配列 #_AVAI_# */
/* セル INIB #_INIB_# */
tSocketClient_INIB tSocketClient_INIB_tab[] = {
    /* cell: tSocketClient_CB_tab[0]:  ClientChannel id=1 */
    {
        /* entry port #_EP_# */ 
        /* attribute(RO) */ 
        8931,                                    /* portNo */
        "192.168.1.240",                         /* serverAddr */
    },
};

/* セル CB #_CB_# */
struct tag_tSocketClient_CB tSocketClient_CB_tab[] = {
    /* cell: tSocketClient_CB_tab[0]:  ClientChannel id=1 */
    {
        &tSocketClient_INIB_tab[0],              /* _inib */
        /* entry port #_EP_# */ 
        /* var */ 
        0,                                       /* sd */
    },
};

/* 受け口ディスクリプタ #_EPD_# */
/* eC0 : omitted by entry port optimize */
/* eOpener : omitted by entry port optimize */
