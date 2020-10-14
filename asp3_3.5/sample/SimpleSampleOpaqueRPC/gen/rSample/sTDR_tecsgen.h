/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef sTDR_TECSGEN_H
#define sTDR_TECSGEN_H

/*
 * signature   :  sTDR
 * global name :  sTDR
 * context     :  task
 */

#ifndef TOPPERS_MACRO_ONLY

/* シグニチャディスクリプタ #_SD_# */
struct tag_sTDR_VDES {
    struct tag_sTDR_VMT *VMT;
};

/* シグニチャ関数テーブル #_SFT_# */
struct tag_sTDR_VMT {
    ER             (*reset__T)( const struct tag_sTDR_VDES *edp );
    ER             (*sendSOP__T)( const struct tag_sTDR_VDES *edp, bool_t b_client );
    ER             (*receiveSOP__T)( const struct tag_sTDR_VDES *edp, bool_t b_client );
    ER             (*sendEOP__T)( const struct tag_sTDR_VDES *edp, bool_t b_continue );
    ER             (*receiveEOP__T)( const struct tag_sTDR_VDES *edp, bool_t b_continue );
    ER             (*putInt8__T)( const struct tag_sTDR_VDES *edp, int8_t in );
    ER             (*putInt16__T)( const struct tag_sTDR_VDES *edp, int16_t in );
    ER             (*putInt32__T)( const struct tag_sTDR_VDES *edp, int32_t in );
    ER             (*putInt64__T)( const struct tag_sTDR_VDES *edp, int64_t in );
    ER             (*putInt128__T)( const struct tag_sTDR_VDES *edp, int128_t in );
    ER             (*getInt8__T)( const struct tag_sTDR_VDES *edp, int8_t* out );
    ER             (*getInt16__T)( const struct tag_sTDR_VDES *edp, int16_t* out );
    ER             (*getInt32__T)( const struct tag_sTDR_VDES *edp, int32_t* out );
    ER             (*getInt64__T)( const struct tag_sTDR_VDES *edp, int64_t* out );
    ER             (*getInt128__T)( const struct tag_sTDR_VDES *edp, int128_t* out );
    ER             (*putUInt8__T)( const struct tag_sTDR_VDES *edp, uint8_t in );
    ER             (*putUInt16__T)( const struct tag_sTDR_VDES *edp, uint16_t in );
    ER             (*putUInt32__T)( const struct tag_sTDR_VDES *edp, uint32_t in );
    ER             (*putUInt64__T)( const struct tag_sTDR_VDES *edp, uint64_t in );
    ER             (*putUInt128__T)( const struct tag_sTDR_VDES *edp, uint128_t in );
    ER             (*getUInt8__T)( const struct tag_sTDR_VDES *edp, uint8_t* out );
    ER             (*getUInt16__T)( const struct tag_sTDR_VDES *edp, uint16_t* out );
    ER             (*getUInt32__T)( const struct tag_sTDR_VDES *edp, uint32_t* out );
    ER             (*getUInt64__T)( const struct tag_sTDR_VDES *edp, uint64_t* out );
    ER             (*getUInt128__T)( const struct tag_sTDR_VDES *edp, uint128_t* out );
    ER             (*putChar__T)( const struct tag_sTDR_VDES *edp, char_t in );
    ER             (*getChar__T)( const struct tag_sTDR_VDES *edp, char_t* out );
    ER             (*putBool__T)( const struct tag_sTDR_VDES *edp, bool_t in );
    ER             (*getBool__T)( const struct tag_sTDR_VDES *edp, bool_t* out );
    ER             (*putFloat32__T)( const struct tag_sTDR_VDES *edp, float32_t in );
    ER             (*putDouble64__T)( const struct tag_sTDR_VDES *edp, double64_t in );
    ER             (*getFloat32__T)( const struct tag_sTDR_VDES *edp, float32_t* out );
    ER             (*getDouble64__T)( const struct tag_sTDR_VDES *edp, double64_t* out );
    ER             (*putSChar__T)( const struct tag_sTDR_VDES *edp, schar_t in );
    ER             (*putShort__T)( const struct tag_sTDR_VDES *edp, short_t in );
    ER             (*putInt__T)( const struct tag_sTDR_VDES *edp, int_t in );
    ER             (*putLong__T)( const struct tag_sTDR_VDES *edp, long_t in );
    ER             (*getSChar__T)( const struct tag_sTDR_VDES *edp, schar_t* out );
    ER             (*getShort__T)( const struct tag_sTDR_VDES *edp, short_t* out );
    ER             (*getInt__T)( const struct tag_sTDR_VDES *edp, int_t* out );
    ER             (*getLong__T)( const struct tag_sTDR_VDES *edp, long_t* out );
    ER             (*putUChar__T)( const struct tag_sTDR_VDES *edp, uchar_t in );
    ER             (*putUShort__T)( const struct tag_sTDR_VDES *edp, ushort_t in );
    ER             (*putUInt__T)( const struct tag_sTDR_VDES *edp, uint_t in );
    ER             (*putULong__T)( const struct tag_sTDR_VDES *edp, ulong_t in );
    ER             (*getUChar__T)( const struct tag_sTDR_VDES *edp, unsigned char* out );
    ER             (*getUShort__T)( const struct tag_sTDR_VDES *edp, ushort_t* out );
    ER             (*getUInt__T)( const struct tag_sTDR_VDES *edp, uint_t* out );
    ER             (*getULong__T)( const struct tag_sTDR_VDES *edp, ulong_t* out );
    ER             (*putIntptr__T)( const struct tag_sTDR_VDES *edp, const intptr_t ptr );
    ER             (*getIntptr__T)( const struct tag_sTDR_VDES *edp, intptr_t* ptr );
};

/* シグニチャディスクリプタ(動的結合用) #_SDES_# */
#ifndef Descriptor_of_sTDR_Defined
#define  Descriptor_of_sTDR_Defined
typedef struct { struct tag_sTDR_VDES *vdes; } Descriptor( sTDR );
#endif
#endif /* TOPPERS_MACRO_ONLY */

/* function id */
#define	FUNCID_STDR_RESET                      (1)
#define	FUNCID_STDR_SENDSOP                    (2)
#define	FUNCID_STDR_RECEIVESOP                 (3)
#define	FUNCID_STDR_SENDEOP                    (4)
#define	FUNCID_STDR_RECEIVEEOP                 (5)
#define	FUNCID_STDR_PUTINT8                    (6)
#define	FUNCID_STDR_PUTINT16                   (7)
#define	FUNCID_STDR_PUTINT32                   (8)
#define	FUNCID_STDR_PUTINT64                   (9)
#define	FUNCID_STDR_PUTINT128                  (10)
#define	FUNCID_STDR_GETINT8                    (11)
#define	FUNCID_STDR_GETINT16                   (12)
#define	FUNCID_STDR_GETINT32                   (13)
#define	FUNCID_STDR_GETINT64                   (14)
#define	FUNCID_STDR_GETINT128                  (15)
#define	FUNCID_STDR_PUTUINT8                   (16)
#define	FUNCID_STDR_PUTUINT16                  (17)
#define	FUNCID_STDR_PUTUINT32                  (18)
#define	FUNCID_STDR_PUTUINT64                  (19)
#define	FUNCID_STDR_PUTUINT128                 (20)
#define	FUNCID_STDR_GETUINT8                   (21)
#define	FUNCID_STDR_GETUINT16                  (22)
#define	FUNCID_STDR_GETUINT32                  (23)
#define	FUNCID_STDR_GETUINT64                  (24)
#define	FUNCID_STDR_GETUINT128                 (25)
#define	FUNCID_STDR_PUTCHAR                    (26)
#define	FUNCID_STDR_GETCHAR                    (27)
#define	FUNCID_STDR_PUTBOOL                    (28)
#define	FUNCID_STDR_GETBOOL                    (29)
#define	FUNCID_STDR_PUTFLOAT32                 (30)
#define	FUNCID_STDR_PUTDOUBLE64                (31)
#define	FUNCID_STDR_GETFLOAT32                 (32)
#define	FUNCID_STDR_GETDOUBLE64                (33)
#define	FUNCID_STDR_PUTSCHAR                   (34)
#define	FUNCID_STDR_PUTSHORT                   (35)
#define	FUNCID_STDR_PUTINT                     (36)
#define	FUNCID_STDR_PUTLONG                    (37)
#define	FUNCID_STDR_GETSCHAR                   (38)
#define	FUNCID_STDR_GETSHORT                   (39)
#define	FUNCID_STDR_GETINT                     (40)
#define	FUNCID_STDR_GETLONG                    (41)
#define	FUNCID_STDR_PUTUCHAR                   (42)
#define	FUNCID_STDR_PUTUSHORT                  (43)
#define	FUNCID_STDR_PUTUINT                    (44)
#define	FUNCID_STDR_PUTULONG                   (45)
#define	FUNCID_STDR_GETUCHAR                   (46)
#define	FUNCID_STDR_GETUSHORT                  (47)
#define	FUNCID_STDR_GETUINT                    (48)
#define	FUNCID_STDR_GETULONG                   (49)
#define	FUNCID_STDR_PUTINTPTR                  (50)
#define	FUNCID_STDR_GETINTPTR                  (51)

#endif /* sTDR_TECSGEN_H */
