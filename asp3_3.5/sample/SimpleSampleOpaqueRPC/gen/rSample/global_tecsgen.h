/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef GLOBAL_TECSGEN_H
#define GLOBAL_TECSGEN_H


/* import_C により import されるヘッダ #_IMP_# */
#include "cygwin_tecs.h"
#include "t_syslog.h"
#include "tecs_rpc.h"
/**/

#ifndef TOPPERS_MACRO_ONLY


#define INITIALIZE_TECS() 
#define INITIALZE_TECSGEN() INITIALIZE_TECS()  /* for backward compatibility */

/* Descriptor for dynamic join */
#define Descriptor( signature_global_name )  DynDesc__ ## signature_global_name
#define is_descriptor_unjoined( desc )  ((desc).vdes==NULL)

#endif /* TOPPERS_MACRO_ONLY */

#define TASK_STATE_0   ((const int)0)
#define TASK_STATE_1   ((const int)1)
#define TDR_SOP_MAGIC1 ((const uint32_t)0x672A)
#define TDR_SOP_MAGIC2 ((const uint32_t)0x561E)
#define TDR_EOP_MAGIC1 ((const uint32_t)0x5A3C)
#define TDR_EOP_MAGIC2 ((const uint32_t)0x6D5E)
#define TDR_SHSOP_MAGIC1 ((const uint32_t)0x98D5)
#define TDR_SHSOP_MAGIC2 ((const uint32_t)0xA9E1)
#define TDR_SHEOP_MAGIC1 ((const uint32_t)0xB5C3)
#define TDR_SHEOP_MAGIC2 ((const uint32_t)0x92A1)
#define RPC_CHANNEL_MAN_SOP_MAGIC ((const uint16_t)0x3141)
#define RPC_CHANNEL_MAN_EOP_MAGIC ((const uint16_t)0x2718)
#define RPCSTATE_CLIENT_GET_SEM ((const int16_t)1)
#define RPCSTATE_CLIENT_SEND_SOP ((const int16_t)2)
#define RPCSTATE_CLIENT_SEND_BODY ((const int16_t)3)
#define RPCSTATE_CLIENT_SEND_EOP ((const int16_t)4)
#define RPCSTATE_CLIENT_EXEC ((const int16_t)5)
#define RPCSTATE_CLIENT_RECV_SOP ((const int16_t)6)
#define RPCSTATE_CLIENT_RECV_BODY ((const int16_t)7)
#define RPCSTATE_CLIENT_RECV_EOP ((const int16_t)8)
#define RPCSTATE_CLIENT_RELEASE_SEM ((const int16_t)9)
#define RPCSTATE_SERVER_GET_SEM ((const int16_t)11)
#define RPCSTATE_SERVER_RECV_SOP ((const int16_t)12)
#define RPCSTATE_SERVER_RECV_BODY ((const int16_t)13)
#define RPCSTATE_SERVER_RECV_EOP ((const int16_t)14)
#define RPCSTATE_SERVER_EXEC ((const int16_t)15)
#define RPCSTATE_SERVER_SEND_SOP ((const int16_t)16)
#define RPCSTATE_SERVER_SEND_BODY ((const int16_t)17)
#define RPCSTATE_SERVER_SEND_EOP ((const int16_t)18)
#define RPCSTATE_SERVER_RELEASE_SEM ((const int16_t)19)
#define SOCKET_DEFAULT_PORT_NO ((const uint16_t)8931)

#endif /* GLOBAL_TECSGEN_H */
