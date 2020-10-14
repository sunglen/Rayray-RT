/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#include "tSemaphore_tecsgen.h"
#include "tSemaphore_factory.h"

/* 受け口ディスクリプタ型 #_EDT_# */
/* eSemaphore : omitted by entry port optimize */

/* eiSemaphore : omitted by entry port optimize */

/* 受け口スケルトン関数 #_EPSF_# */
/* eSemaphore : omitted by entry port optimize */
/* eiSemaphore : omitted by entry port optimize */

/* 受け口スケルトン関数テーブル #_EPSFT_# */
/* eSemaphore : omitted by entry port optimize */
/* eiSemaphore : omitted by entry port optimize */

/* 呼び口の参照する受け口ディスクリプタ(実際の型と相違した定義) #_CPEPD_# */

/* 呼び口配列 #_CPA_# */

/* 属性・変数の配列 #_AVAI_# */
/* セル INIB #_INIB_# */
tSemaphore_INIB tSemaphore_INIB_tab[] = {
    /* cell: tSemaphore_CB_tab[0]:  Join_to_through___0Server_Semaphore id=1 */
    {
        /* entry port #_EP_# */ 
        /* attribute(RO) */ 
        0,                                       /* id */
    },
};

/* セル CB #_CB_# */
struct tag_tSemaphore_CB tSemaphore_CB_tab[] = {
    /* cell: tSemaphore_CB_tab[0]:  Join_to_through___0Server_Semaphore id=1 */
    {
        &tSemaphore_INIB_tab[0],                 /* _inib */
        /* entry port #_EP_# */ 
        /* var */ 
        PTHREAD_MUTEX_INITIALIZER,               /* mutex */
    },
};

/* 受け口ディスクリプタ #_EPD_# */
/* eSemaphore : omitted by entry port optimize */
/* eiSemaphore : omitted by entry port optimize */
