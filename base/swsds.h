/*
* File: swsds.h
* Copyright (c) SWXA 2009
*
*
*/

#ifndef _SW_SDS_H_
#define _SW_SDS_H_ 1

#ifdef __cplusplus
	extern "C"{
#endif

/*数据类型定义*/
typedef char				SGD_CHAR;
typedef char				SGD_INT8;
typedef short				SGD_INT16;
typedef int					SGD_INT32;
typedef long long			SGD_INT64;
typedef unsigned char		SGD_UCHAR;
typedef unsigned char		SGD_UINT8;
typedef unsigned short		SGD_UINT16;
typedef unsigned int		SGD_UINT32;
typedef unsigned long long	SGD_UINT64;
typedef unsigned int		SGD_RV;
typedef void*				SGD_OBJ;
typedef int					SGD_BOOL;
typedef void*				SGD_HANDLE;

/*设备信息*/
typedef struct DeviceInfo_st{
	unsigned char IssuerName[40];
	unsigned char DeviceName[16];
	unsigned char DeviceSerial[16];
	unsigned int  DeviceVersion;
	unsigned int  StandardVersion;
	unsigned int  AsymAlgAbility[2];
	unsigned int  SymAlgAbility;
	unsigned int  HashAlgAbility;
	unsigned int  BufferSize;
} DEVICEINFO;

/*RSA密钥*/
#define RSAref_MAX_BITS    2048
#define RSAref_MAX_LEN     ((RSAref_MAX_BITS + 7) / 8)
#define RSAref_MAX_PBITS   ((RSAref_MAX_BITS + 1) / 2)
#define RSAref_MAX_PLEN    ((RSAref_MAX_PBITS + 7)/ 8)

typedef struct RSArefPublicKey_st
{
	unsigned int  bits;
	unsigned char m[RSAref_MAX_LEN];
	unsigned char e[RSAref_MAX_LEN];
} RSArefPublicKey;

typedef struct RSArefPrivateKey_st
{
	unsigned int  bits;
	unsigned char m[RSAref_MAX_LEN];
	unsigned char e[RSAref_MAX_LEN];
	unsigned char d[RSAref_MAX_LEN];
	unsigned char prime[2][RSAref_MAX_PLEN];
	unsigned char pexp[2][RSAref_MAX_PLEN];
	unsigned char coef[RSAref_MAX_PLEN];
} RSArefPrivateKey;


/*ECC密钥*/
#define ECCref_MAX_BITS			512
#define ECCref_MAX_LEN			((ECCref_MAX_BITS+7) / 8)
#define ECCref_MAX_CIPHER_LEN	136

typedef struct ECCrefPublicKey_st
{
	unsigned int  bits;
	unsigned char x[ECCref_MAX_LEN];
	unsigned char y[ECCref_MAX_LEN];
} ECCrefPublicKey;

typedef struct ECCrefPrivateKey_st
{
    unsigned int  bits;
    unsigned char K[ECCref_MAX_LEN];
} ECCrefPrivateKey;

/*ECC 密文*/
typedef struct ECCCipher_st
{
	unsigned char x[ECCref_MAX_LEN];
	unsigned char y[ECCref_MAX_LEN];
	unsigned char M[32];
	unsigned int  L;
	unsigned char C[1];
} ECCCipher;

/*ECC 签名*/
typedef struct ECCSignature_st
{
	unsigned char r[ECCref_MAX_LEN];
	unsigned char s[ECCref_MAX_LEN];
} ECCSignature;

/*常量定义*/
#define SGD_TRUE		0x00000001
#define SGD_FALSE		0x00000000

/*算法标识*/
#define SGD_SM1_ECB		0x00000101
#define SGD_SM1_CBC		0x00000102
#define SGD_SM1_CFB		0x00000104
#define SGD_SM1_OFB		0x00000108
#define SGD_SM1_MAC		0x00000110
#define SGD_SM1_CTR		0x00000120

#define SGD_SSF33_ECB	0x00000201
#define SGD_SSF33_CBC	0x00000202
#define SGD_SSF33_CFB	0x00000204
#define SGD_SSF33_OFB	0x00000208
#define SGD_SSF33_MAC	0x00000210
#define SGD_SSF33_CTR	0x00000220

#define SGD_AES_ECB		0x00000401
#define SGD_AES_CBC		0x00000402
#define SGD_AES_CFB		0x00000404
#define SGD_AES_OFB		0x00000408
#define SGD_AES_MAC		0x00000410
#define SGD_AES_CTR		0x00000420

#define SGD_3DES_ECB	0x00000801
#define SGD_3DES_CBC	0x00000802
#define SGD_3DES_CFB	0x00000804
#define SGD_3DES_OFB	0x00000808
#define SGD_3DES_MAC	0x00000810
#define SGD_3DES_CTR	0x00000820

#define SGD_SMS4_ECB	0x00002001
#define SGD_SMS4_CBC	0x00002002
#define SGD_SMS4_CFB	0x00002004
#define SGD_SMS4_OFB	0x00002008
#define SGD_SMS4_MAC	0x00002010
#define SGD_SMS4_CTR	0x00002020

#define SGD_DES_ECB		0x00004001
#define SGD_DES_CBC		0x00004002
#define SGD_DES_CFB		0x00004004
#define SGD_DES_OFB		0x00004008
#define SGD_DES_MAC		0x00004010
#define SGD_DES_CTR		0x00004020

#define SGD_RSA			0x00010000
#define SGD_RSA_SIGN	0x00010100
#define SGD_RSA_ENC		0x00010200
#define SGD_SM2_1		0x00020100
#define SGD_SM2_2		0x00020200
#define SGD_SM2_3		0x00020400

#define SGD_SM3			0x00000001
#define SGD_SHA1		0x00000002
#define SGD_SHA256		0x00000004
#define SGD_SHA512		0x00000008
#define SGD_SHA384		0x00000010
#define SGD_SHA224		0x00000020
#define SGD_MD5			0x00000080


/*标准错误码定义*/
#define SDR_OK					0x0						   /*成功*/
#define SDR_BASE				0x01000000
#define SDR_UNKNOWERR			(SDR_BASE + 0x00000001)	   /*未知错误*/
#define SDR_NOTSUPPORT			(SDR_BASE + 0x00000002)	   /*不支持*/
#define SDR_COMMFAIL			(SDR_BASE + 0x00000003)    /*通信错误*/
#define SDR_HARDFAIL			(SDR_BASE + 0x00000004)    /*硬件错误*/
#define SDR_OPENDEVICE			(SDR_BASE + 0x00000005)    /*打开设备错误*/
#define SDR_OPENSESSION			(SDR_BASE + 0x00000006)    /*打开会话句柄错误*/
#define SDR_PARDENY				(SDR_BASE + 0x00000007)    /*权限不满足*/
#define SDR_KEYNOTEXIST			(SDR_BASE + 0x00000008)    /*密钥不存在*/
#define SDR_ALGNOTSUPPORT		(SDR_BASE + 0x00000009)    /*不支持的算法*/
#define SDR_ALGMODNOTSUPPORT	(SDR_BASE + 0x0000000A)    /*不支持的算法模式*/
#define SDR_PKOPERR				(SDR_BASE + 0x0000000B)    /*公钥运算错误*/
#define SDR_SKOPERR				(SDR_BASE + 0x0000000C)    /*私钥运算错误*/
#define SDR_SIGNERR				(SDR_BASE + 0x0000000D)    /*签名错误*/
#define SDR_VERIFYERR			(SDR_BASE + 0x0000000E)    /*验证错误*/
#define SDR_SYMOPERR			(SDR_BASE + 0x0000000F)    /*对称运算错误*/
#define SDR_STEPERR				(SDR_BASE + 0x00000010)    /*步骤错误*/
#define SDR_FILESIZEERR			(SDR_BASE + 0x00000011)    /*文件大小错误或输入数据长度非法*/
#define SDR_FILENOEXIST			(SDR_BASE + 0x00000012)    /*文件不存在*/
#define SDR_FILEOFSERR			(SDR_BASE + 0x00000013)    /*文件操作偏移量错误*/
#define SDR_KEYTYPEERR			(SDR_BASE + 0x00000014)    /*密钥类型错误*/
#define SDR_KEYERR				(SDR_BASE + 0x00000015)    /*密钥错误*/

/*============================================================*/
/*扩展错误码*/
#define SWR_BASE				(SDR_BASE + 0x00010000)	/*自定义错误码基础值*/
#define SWR_INVALID_USER		(SWR_BASE + 0x00000001)	/*无效的用户名*/
#define SWR_INVALID_AUTHENCODE	(SWR_BASE + 0x00000002)	/*无效的授权码*/
#define SWR_PROTOCOL_VER_ERR	(SWR_BASE + 0x00000003)	/*不支持的协议版本*/
#define SWR_INVALID_COMMAND		(SWR_BASE + 0x00000004)	/*错误的命令字*/
#define SWR_INVALID_PARAMETERS	(SWR_BASE + 0x00000005)	/*参数错误或错误的数据包格式*/
#define SWR_FILE_ALREADY_EXIST	(SWR_BASE + 0x00000006)	/*已存在同名文件*/
#define SWR_SYNCH_ERR			(SWR_BASE + 0x00000007)	/*多卡同步错误*/
#define SWR_SYNCH_LOGIN_ERR		(SWR_BASE + 0x00000008)	/*多卡同步后登录错误*/

#define SWR_SOCKET_TIMEOUT		(SWR_BASE + 0x00000100)	/*超时错误*/
#define SWR_CONNECT_ERR			(SWR_BASE + 0x00000101)	/*连接服务器错误*/
#define SWR_SET_SOCKOPT_ERR		(SWR_BASE + 0x00000102)	/*设置Socket参数错误*/
#define SWR_SOCKET_SEND_ERR		(SWR_BASE + 0x00000104)	/*发送LOGINRequest错误*/
#define SWR_SOCKET_RECV_ERR		(SWR_BASE + 0x00000105)	/*发送LOGINRequest错误*/
#define SWR_SOCKET_RECV_0		(SWR_BASE + 0x00000106)	/*发送LOGINRequest错误*/

#define SWR_SEM_TIMEOUT			(SWR_BASE + 0x00000200)	/*超时错误*/
#define SWR_NO_AVAILABLE_HSM	(SWR_BASE + 0x00000201)	/*没有可用的加密机*/
#define SWR_NO_AVAILABLE_CSM	(SWR_BASE + 0x00000202)	/*加密机内没有可用的加密模块*/

#define SWR_CONFIG_ERR			(SWR_BASE + 0x00000301)	/*配置文件错误*/

/*============================================================*/
/*密码卡错误码*/
#define SWR_CARD_BASE					(SDR_BASE + 0x00020000)			/*密码卡错误码*/
#define SWR_CARD_UNKNOWERR				(SWR_CARD_BASE + 0x00000001)	//未知错误
#define SWR_CARD_NOTSUPPORT				(SWR_CARD_BASE + 0x00000002)	//不支持的接口调用
#define SWR_CARD_COMMFAIL				(SWR_CARD_BASE + 0x00000003)	//与设备通信失败
#define SWR_CARD_HARDFAIL				(SWR_CARD_BASE + 0x00000004)	//运算模块无响应
#define SWR_CARD_OPENDEVICE				(SWR_CARD_BASE + 0x00000005)	//打开设备失败
#define SWR_CARD_OPENSESSION			(SWR_CARD_BASE + 0x00000006)	//创建会话失败
#define SWR_CARD_PARDENY				(SWR_CARD_BASE + 0x00000007)	//无私钥使用权限
#define SWR_CARD_KEYNOTEXIST			(SWR_CARD_BASE + 0x00000008)	//不存在的密钥调用
#define SWR_CARD_ALGNOTSUPPORT			(SWR_CARD_BASE + 0x00000009)	//不支持的算法调用
#define SWR_CARD_ALGMODNOTSUPPORT		(SWR_CARD_BASE + 0x00000010)	//不支持的算法调用
#define SWR_CARD_PKOPERR				(SWR_CARD_BASE + 0x00000011)	//公钥运算失败
#define SWR_CARD_SKOPERR				(SWR_CARD_BASE + 0x00000012)	//私钥运算失败
#define SWR_CARD_SIGNERR				(SWR_CARD_BASE + 0x00000013)	//签名运算失败
#define SWR_CARD_VERIFYERR				(SWR_CARD_BASE + 0x00000014)	//验证签名失败
#define SWR_CARD_SYMOPERR				(SWR_CARD_BASE + 0x00000015)	//对称算法运算失败
#define SWR_CARD_STEPERR				(SWR_CARD_BASE + 0x00000016)	//多步运算步骤错误
#define SWR_CARD_FILESIZEERR			(SWR_CARD_BASE + 0x00000017)	//文件长度超出限制
#define SWR_CARD_FILENOEXIST			(SWR_CARD_BASE + 0x00000018)	//指定的文件不存在
#define SWR_CARD_FILEOFSERR				(SWR_CARD_BASE + 0x00000019)	//文件起始位置错误
#define SWR_CARD_KEYTYPEERR				(SWR_CARD_BASE + 0x00000020)	//密钥类型错误
#define SWR_CARD_KEYERR					(SWR_CARD_BASE + 0x00000021)	//密钥错误
#define SWR_CARD_BUFFER_TOO_SMALL		(SWR_CARD_BASE + 0x00000101)	//接收参数的缓存区太小
#define SWR_CARD_DATA_PAD				(SWR_CARD_BASE + 0x00000102)	//数据没有按正确格式填充，或解密得到的脱密数据不符合填充格式
#define SWR_CARD_DATA_SIZE				(SWR_CARD_BASE + 0x00000103)	//明文或密文长度不符合相应的算法要求
#define SWR_CARD_CRYPTO_NOT_INIT		(SWR_CARD_BASE + 0x00000104)	//该错误表明没有为相应的算法调用初始化函数

//01/03/09版密码卡权限管理错误码
#define SWR_CARD_MANAGEMENT_DENY		(SWR_CARD_BASE + 0x00001001)	//管理权限不满足
#define SWR_CARD_OPERATION_DENY			(SWR_CARD_BASE + 0x00001002)	//操作权限不满足
#define SWR_CARD_DEVICE_STATUS_ERR		(SWR_CARD_BASE + 0x00001003)	//当前设备状态不满足现有操作
#define SWR_CARD_LOGIN_ERR				(SWR_CARD_BASE + 0x00001011)	//登录失败
#define SWR_CARD_USERID_ERR				(SWR_CARD_BASE + 0x00001012)	//用户ID数目/号码错误
#define SWR_CARD_PARAMENT_ERR			(SWR_CARD_BASE + 0x00001013)	//参数错误

//05/06版密码卡权限管理错误码
#define SWR_CARD_MANAGEMENT_DENY_05		(SWR_CARD_BASE + 0x00000801)	//管理权限不满足
#define SWR_CARD_OPERATION_DENY_05		(SWR_CARD_BASE + 0x00000802)	//操作权限不满足
#define SWR_CARD_DEVICE_STATUS_ERR_05	(SWR_CARD_BASE + 0x00000803)	//当前设备状态不满足现有操作
#define SWR_CARD_LOGIN_ERR_05			(SWR_CARD_BASE + 0x00000811)	//登录失败
#define SWR_CARD_USERID_ERR_05			(SWR_CARD_BASE + 0x00000812)	//用户ID数目/号码错误
#define SWR_CARD_PARAMENT_ERR_05		(SWR_CARD_BASE + 0x00000813)	//参数错误

/*============================================================*/
/*读卡器错误*/
#define SWR_CARD_READER_BASE				(SDR_BASE + 0x00030000)	//	读卡器类型错误
#define SWR_CARD_READER_PIN_ERROR			(SWR_CARD_READER_BASE + 0x000063CE)  //口令错误
#define SWR_CARD_READER_NO_CARD				(SWR_CARD_READER_BASE + 0x0000FF01)	 //	IC未插入
#define SWR_CARD_READER_CARD_INSERT			(SWR_CARD_READER_BASE + 0x0000FF02)	 //	IC插入方向错误或不到位
#define SWR_CARD_READER_CARD_INSERT_TYPE	(SWR_CARD_READER_BASE + 0x0000FF03)	 //	IC类型错误

/*设备管理类函数*/
// 1.打开设备
SGD_RV SDF_OpenDevice(SGD_HANDLE *phDeviceHandle);
// 2.关闭设备
SGD_RV SDF_CloseDevice(SGD_HANDLE hDeviceHandle);
// 3.创建会话
SGD_RV SDF_OpenSession(SGD_HANDLE hDeviceHandle, SGD_HANDLE *phSessionHandle);
// 4.关闭会话
SGD_RV SDF_CloseSession(SGD_HANDLE hSessionHandle);

#ifdef __cplusplus
}
#endif

#endif /*#ifndef _SW_SDS_H_*/

#ifndef __SWCSM__
#define __SWCSM__ 1

#ifdef __cplusplus
extern "C"{
#endif

/*密码卡管理函数*/
// 5.初始化设备
SGD_RV  SWCSM_InitDevice(SGD_HANDLE hSessionHandle, SGD_UINT32 uiFlag);
// 6.产生非易失对称密钥
SGD_RV SWMF_GenerateKEK(SGD_HANDLE hSessionHandle, SGD_UINT32 uiKeyNumber, SGD_UINT32 uiKeyLength);
// 7.导入非易失对称密钥
SGD_RV SWMF_InputKEK( SGD_HANDLE hSessionHandle, SGD_UINT32 uiKeyNumber, SGD_UCHAR *pucKey, SGD_UINT32 uiKeyLength);
// 8.销毁非易失对称密钥
SGD_RV SWMF_DeleteKEK(SGD_HANDLE hSessionHandle, SGD_UINT32 uiKeyNumber);
// 9.产生内部RSA密钥对
SGD_RV SWCSM_GenerateRSAKeyPair(SGD_HANDLE hSessionHandle, SGD_UINT32 uiKeyNumber, SGD_UINT32 uiKeyBits);
// 10.导入RSA密钥对
SGD_RV SWCSM_InputRSAKeyPair(SGD_HANDLE hSessionHandle,  SGD_UINT32 uiKeyNumber, RSArefPublicKey*pucPublicKey, RSArefPrivateKey*pucPrivateKey);
// 11.销毁内部RSA密钥对
SGD_RV SWCSM_DestroyRSAKeyPair(SGD_HANDLE hSessionHandle, SGD_UINT32 uiKeyNumber);
// 12.产生内部ECC密钥对
SGD_RV SWCSM_GenerateECCKeyPair(SGD_HANDLE hSessionHandle, SGD_UINT32 uiKeyNumber);
// 13.导入ECC密钥对
SGD_RV SWCSM_ImportECCKeyPair(SGD_HANDLE hSessionHandle, SGD_UINT32 uiKeyNumber, ECCrefPublicKey*pucPublicKey, ECCrefPrivateKey*pucPrivateKey);
// 14.销毁内部ECC密钥对
SGD_RV SWCSM_DestroyECCKeyPair(SGD_HANDLE hSessionHandle, SGD_UINT32 uiKeyNumber);
// 15.获取密码设备内部密钥状态
SGD_RV SDF_GetKeyStatus(SGD_HANDLE hSessionHandle, SGD_UINT32 uiKeyType, SGD_UINT32 *puiKeyStatus, SGD_UINT32 *puiKeyCount);
// 16.备份初始化
SGD_RV SWCSM_BackupInit_NoIC(SGD_HANDLE hSessionHandle, SGD_UINT32 uiAlgorithmID, SGD_UCHAR *passwd, SGD_UINT32 uiPwdLength);
// 17.备份导出RSA密钥对
SGD_RV SWCSM_BackupExportRSAKey(SGD_HANDLE hSessionHandle, SGD_UINT32 uiIndex, SGD_UINT32 *puiKeyBits, SGD_UCHAR *pucKeyData, SGD_UINT32 *puiKeyDataLength);
// 18.备份导出ECC密钥对
SGD_RV SWCSM_BackupExportECCKey(SGD_HANDLE hSessionHandle, SGD_UINT32 uiIndex, SGD_UINT32 *puiKeyBits, SGD_UCHAR *pucKeyData, SGD_UINT32 *puiKeyDataLength);
// 19.备份导出非易失性对称密钥
SGD_RV SWCSM_BackupExportKEK( SGD_HANDLE hSessionHandle, SGD_UINT32 uiIndex, SGD_UCHAR *pucKeyData, SGD_UINT32 *puiKeyDataLength);
// 20.备份结束
SGD_RV SWCSM_BackupFinal(SGD_HANDLE hSessionHandle);
// 21.恢复初始化
SGD_RV SWCSM_RestoreInit_NoIC(SGD_HANDLE hSessionHandle, SGD_UINT32 uiAlgorithmID, SGD_UCHAR *passwd, SGD_UINT32 uiPwdLength);
// 22.恢复导入RSA密钥对
SGD_RV SWCSM_RestoreImportRSAKey(SGD_HANDLE hSessionHandle, SGD_UINT32 uiIndex, SGD_UINT32 uiKeyBits, SGD_UCHAR *pucKeyData, SGD_UINT32 uiKeyDataLength);
// 23.恢复导入ECC密钥对
SGD_RV SWCSM_RestoreImportECCKey(SGD_HANDLE hSessionHandle, SGD_UINT32 uiIndex, SGD_UINT32 uiKeyBits, SGD_UCHAR *pucKeyData, SGD_UINT32 uiKeyDataLength);
// 24.恢复导入非易失性对称密钥
SGD_RV SWCSM_RestoreImportKEK(SGD_HANDLE hSessionHandle, SGD_UINT32 uiIndex, SGD_UCHAR *pucKeyData, SGD_UINT32 uiKeyDataLength);
// 25.恢复结束
SGD_RV SWCSM_RestoreFinal(SGD_HANDLE hSessionHandle);

#ifdef __cplusplus
}
#endif

#endif /*#ifndef __SWCSM__*/