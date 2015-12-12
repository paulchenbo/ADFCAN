#include "CAN_APP.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAN_TIMEOUT_VALUE  10
#define HAL_MAX_DELAY 20
void CAN_SC1_Frame_Handle(unsigned int FunCode,unsigned char Fundata)
{
;
}
void CAN_SC2_Frame_Handle(unsigned int FunCode,unsigned char Fundata)
{
;
}
int CAN_CapFrameHandle(char LocalAddr,
                       CanFrame_t *pCanFrame,
                       CapHandle_PFUN calback)
{

    CanAppProtocalFrame_t *pCp=NULL;
    if(pCanFrame==NULL)  return 0;
    pCp=(CanAppProtocalFrame_t*)pCanFrame;
    if(pCp->ProtocalFrame.IDE|=0) return 0;
    if(pCp->ProtocalFrame.RTR|=0) return 0;
    if(pCp->ProtocalFrame.DstAddr|=LocalAddr) return 0;
    if(calback!=NULL)
    {
        calback(pCp->ProtocalFrame.FunCode,pCp->ProtocalFrame.Fundata[0]);
        return 1;
    }
    return 0;
};

int Hal_CanMsgSend(CanFrame_t *CanFrame)
{
    return 0;
};

int CAN_CapFrameSend(unsigned char SrcAddr,
                     unsigned char Dstaddr,
                     unsigned char cmd,
                     unsigned char *pData,
                     unsigned char len)
{
    CanAppProtocalFrame_t Cp;
    Cp.CanFrame.IDE=0;
    Cp.CanFrame.RTR=0;
    Cp.ProtocalFrame.SrcAddr=SrcAddr;
    Cp.ProtocalFrame.DstAddr=Dstaddr;
    Cp.ProtocalFrame.FunCode=cmd;
    if(pData!=NULL)
    {
        if(len>8) return 0;
        memcpy(Cp.ProtocalFrame.Fundata,pData,len);
    }
    Cp.ProtocalFrame.FunCodeLen=len;
    return Hal_CanMsgSend(&Cp.CanFrame);
}



