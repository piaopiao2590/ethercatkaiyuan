#ifndef FOEAPP_H
#define FOEAPP_H

#include <QObject>
#include <inttypes.h>
#include "ethercat.h"
#include <QThread>

#pragma pack(1)

typedef struct PACKED
{
   ec_mbxheadert MbxHeader;
   uint8         OpCode;
   uint8         Reserved;
   union
   {
      uint32        Password;
      uint32        PacketNumber;
      uint32        ErrorCode;
   };
   union
   {
      char          FileName[512];
      uint8         Data[512];
      char          ErrorText[512];
   };
} ec_FOEt;
#pragma pack()

class foeApp : public QObject
{
    Q_OBJECT
public:
    explicit foeApp(QObject *parent = nullptr);
    /* FOE 写请求 */
    void ecx_FOEwrite_gxf(ecx_contextt *context, uint16 slave, char *filename, uint32 password, int psize, void *p, int timeout);
    /* FOE 读请求 */
    void ecx_FOEread_gxf(ecx_contextt *context, uint16 slave, char *filename, uint32 password, void *p, int timeout);
    void taskWrite(void);
    void taskRead(void);
    void setFoeinfo(unsigned int size,QString name,uint32 password);
signals:
    /* foe写信号，size：剩余文件大小 */
    void foewrite(unsigned int size);
    void foeread(unsigned int size);

public:
    unsigned short maxsize;
    unsigned int filesize;
    QString filename;
    uint32 password;
    char filebuf[200];

};

#endif // FOEAPP_H
