/*
 * CAN_APP.h
 *
 *  Created on: 2015?ê12??12è?
 *      Author: chenbo
 */

#ifndef CAN_APP_H_
#define CAN_APP_H_

#define CAN1                ((CAN_TypeDef *) CAN1_BASE)
#define CAN2                ((CAN_TypeDef *) CAN2_BASE)
#define CAN1_BASE           (0 + 0x6400)
#define CAN2_BASE           (0 + 0x6800)

typedef int HAL_StatusTypeDef ;

typedef enum
{
  HAL_CAN_STATE_RESET             = 0x00,  /*!< CAN not yet initialized or disabled */
  HAL_CAN_STATE_READY             = 0x01,  /*!< CAN initialized and ready for use   */
  HAL_CAN_STATE_BUSY              = 0x02,  /*!< CAN process is ongoing              */
  HAL_CAN_STATE_BUSY_TX           = 0x12,  /*!< CAN process is ongoing              */
  HAL_CAN_STATE_BUSY_RX           = 0x22,  /*!< CAN process is ongoing              */
  HAL_CAN_STATE_BUSY_TX_RX        = 0x32,  /*!< CAN process is ongoing              */
  HAL_CAN_STATE_TIMEOUT           = 0x03,  /*!< Timeout state                       */
  HAL_CAN_STATE_ERROR             = 0x04   /*!< CAN error state                     */
}HAL_CAN_StateTypeDef;

typedef struct
{
  volatile  unsigned int               MCR;                 /*!< CAN master control register,         Address offset: 0x00          */
  volatile  unsigned int               MSR;                 /*!< CAN master status register,          Address offset: 0x04          */
  volatile  unsigned int               TSR;                 /*!< CAN transmit status register,        Address offset: 0x08          */
  volatile  unsigned int               RF0R;                /*!< CAN receive FIFO 0 register,         Address offset: 0x0C          */
  volatile  unsigned int               RF1R;                /*!< CAN receive FIFO 1 register,         Address offset: 0x10          */
  volatile  unsigned int               IER;                 /*!< CAN interrupt enable register,       Address offset: 0x14          */
  volatile  unsigned int               ESR;                 /*!< CAN error status register,           Address offset: 0x18          */
  volatile  unsigned int               BTR;                 /*!< CAN bit timing register,             Address offset: 0x1C          */
  unsigned int                         RESERVED0[88];       /*!< Reserved, 0x020 - 0x17F                                            */
  volatile  unsigned int               sTxMailBox[3];       /*!< CAN Tx MailBox,                      Address offset: 0x180 - 0x1AC */
  volatile  unsigned int               sFIFOMailBox[2];     /*!< CAN FIFO MailBox,                    Address offset: 0x1B0 - 0x1CC */
  unsigned int                         RESERVED1[12];       /*!< Reserved, 0x1D0 - 0x1FF                                            */
  volatile  unsigned int               FMR;                 /*!< CAN filter master register,          Address offset: 0x200         */
  volatile  unsigned int               FM1R;                /*!< CAN filter mode register,            Address offset: 0x204         */
  unsigned int                         RESERVED2;           /*!< Reserved, 0x208                                                    */
  volatile  unsigned int               FS1R;                /*!< CAN filter scale register,           Address offset: 0x20C         */
  unsigned int                         RESERVED3;           /*!< Reserved, 0x210                                                    */
  volatile  unsigned int               FFA1R;               /*!< CAN filter FIFO assignment register, Address offset: 0x214         */
  unsigned int                         RESERVED4;           /*!< Reserved, 0x218                                                    */
  volatile  unsigned int               FA1R;                /*!< CAN filter activation register,      Address offset: 0x21C         */
  unsigned int                         RESERVED5[8];        /*!< Reserved, 0x220-0x23F                                              */
  volatile  unsigned int               sFilterRegister[28]; /*!< CAN Filter Register,                 Address offset: 0x240-0x31C   */
} CAN_TypeDef;
/**
  * @brief  CAN init structure definition
  */
typedef struct
{
  unsigned int Prescaler;  /*!< Specifies the length of a time quantum.
                            This parameter must be a number between Min_Data = 1 and Max_Data = 1024 */
  unsigned int Mode;       /*!< Specifies the CAN operating mode.
                            This parameter can be a value of @ref CAN_operating_mode */
  unsigned int SJW;        /*!< Specifies the maximum number of time quanta
                            the CAN hardware is allowed to lengthen or
                            shorten a bit to perform resynchronization.
                            This parameter can be a value of @ref CAN_synchronisation_jump_width */
  unsigned int BS1;        /*!< Specifies the number of time quanta in Bit Segment 1.
                            This parameter can be a value of @ref CAN_time_quantum_in_bit_segment_1 */
  unsigned int BS2;        /*!< Specifies the number of time quanta in Bit Segment 2.
                            This parameter can be a value of @ref CAN_time_quantum_in_bit_segment_2 */
  unsigned int TTCM;       /*!< Enable or disable the time triggered communication mode.
                            This parameter can be set to ENABLE or DISABLE. */
  unsigned int ABOM;       /*!< Enable or disable the automatic bus-off management.
                            This parameter can be set to ENABLE or DISABLE */
  unsigned int AWUM;       /*!< Enable or disable the automatic wake-up mode.
                            This parameter can be set to ENABLE or DISABLE */
  unsigned int NART;       /*!< Enable or disable the non-automatic retransmission mode.
                            This parameter can be set to ENABLE or DISABLE */
  unsigned int RFLM;       /*!< Enable or disable the receive FIFO Locked mode.
                            This parameter can be set to ENABLE or DISABLE */
  unsigned int TXFP;       /*!< Enable or disable the transmit FIFO priority.
                            This parameter can be set to ENABLE or DISABLE */
}CAN_InitTypeDef;

/**
  * @brief  CAN filter configuration structure definition
  */
typedef struct
{
  unsigned int FilterIdHigh;          /*!< Specifies the filter identification number (MSBs for a 32-bit
                                       configuration, first one for a 16-bit configuration).
                                       This parameter must be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF */
  unsigned int FilterIdLow;           /*!< Specifies the filter identification number (LSBs for a 32-bit
                                       configuration, second one for a 16-bit configuration).
                                       This parameter must be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF */
  unsigned int FilterMaskIdHigh;      /*!< Specifies the filter mask number or identification number,
                                       according to the mode (MSBs for a 32-bit configuration,
                                       first one for a 16-bit configuration).
                                       This parameter must be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF */
  unsigned int FilterMaskIdLow;       /*!< Specifies the filter mask number or identification number,
                                       according to the mode (LSBs for a 32-bit configuration,
                                       second one for a 16-bit configuration).
                                       This parameter must be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF */
  unsigned int FilterFIFOAssignment;  /*!< Specifies the FIFO (0 or 1) which will be assigned to the filter.
                                       This parameter can be a value of @ref CAN_filter_FIFO */
  unsigned int FilterNumber;          /*!< Specifies the filter which will be initialized.
                                       This parameter must be a number between Min_Data = 0 and Max_Data = 27 */
  unsigned int FilterMode;            /*!< Specifies the filter mode to be initialized.
                                       This parameter can be a value of @ref CAN_filter_mode */
  unsigned int FilterScale;           /*!< Specifies the filter scale.
                                       This parameter can be a value of @ref CAN_filter_scale */
  unsigned int FilterActivation;      /*!< Enable or disable the filter.
                                       This parameter can be set to ENABLE or DISABLE. */
  unsigned int BankNumber;            /*!< Select the start slave bank filter
                                       This parameter must be a number between Min_Data = 0 and Max_Data = 28 */
}CAN_FilterConfTypeDef;

typedef struct
{
    unsigned long ID;
    unsigned char IDE;
    unsigned char RTR;
    unsigned char DLC;
    unsigned char Data[8];
}CanRxMsgTypeDef ,CanTxMsgTypeDef,CanFrame_t;

typedef struct
{
  CAN_TypeDef* 				  Instance;
  CAN_InitTypeDef             Init;       /*!< CAN required parameters        */
  CanTxMsgTypeDef*            pTxMsg;     /*!< Pointer to transmit structure  */
  CanRxMsgTypeDef*            pRxMsg;     /*!< Pointer to reception structure */
  volatile  HAL_CAN_StateTypeDef   State;      /*!< CAN communication state        */
  volatile  unsigned int  ErrorCode;  /*!< CAN Error code                 */
}CAN_HandleTypeDef;

#define CAN_INITSTATUS_FAILED       ((unsigned char)0x00)  /*!< CAN initialization failed */
#define CAN_INITSTATUS_SUCCESS      ((unsigned char)0x01)  /*!< CAN initialization OK */
#define CAN_TIMEOUT                 ((unsigned char)0x02)  /*!< CAN initialization OK */

/** @defgroup CAN_transmit_constants
  * @{

  */
#define CAN_TXSTATUS_FAILED         ((unsigned char)0x00)  /*!< CAN transmission failed */
#define CAN_TXSTATUS_OK             ((unsigned char)0x01)  /*!< CAN transmission succeeded */
#define CAN_TXSTATUS_PENDING        ((unsigned char)0x02)  /*!< CAN transmission pending */
#define CAN_TXSTATUS_NOMAILBOX      ((unsigned char)0x04)  /*!< CAN cell did not provide CAN_TxStatus_NoMailBox */

/* Mailboxes definition */
#define CAN_TXMAILBOX_0   ((unsigned char)0x00)
#define CAN_TXMAILBOX_1   ((unsigned char)0x01)
#define CAN_TXMAILBOX_2   ((unsigned char)0x02)
/* Exported functions --------------------------------------------------------*/

/* Initialization/de-initialization functions ***********************************/
HAL_StatusTypeDef HAL_CAN_Init(CAN_HandleTypeDef* hcan);
HAL_StatusTypeDef HAL_CAN_ConfigFilter(CAN_HandleTypeDef* hcan, CAN_FilterConfTypeDef* sFilterConfig);
/* I/O operation functions ******************************************************/
HAL_StatusTypeDef HAL_CAN_Transmit(CAN_HandleTypeDef *hcan, unsigned int Timeout);
HAL_StatusTypeDef HAL_CAN_Transmit_IT(CAN_HandleTypeDef *hcan);
HAL_StatusTypeDef HAL_CAN_Receive(CAN_HandleTypeDef *hcan, unsigned char FIFONumber, unsigned int Timeout);
HAL_StatusTypeDef HAL_CAN_Receive_IT(CAN_HandleTypeDef *hcan, unsigned char FIFONumber);
HAL_StatusTypeDef HAL_CAN_Sleep(CAN_HandleTypeDef *hcan);
HAL_StatusTypeDef HAL_CAN_WakeUp(CAN_HandleTypeDef *hcan);
/* Peripheral State functions ***************************************************/
void HAL_CAN_IRQHandler(CAN_HandleTypeDef* hcan);
unsigned int HAL_CAN_GetError(CAN_HandleTypeDef *hcan);
HAL_CAN_StateTypeDef HAL_CAN_GetState(CAN_HandleTypeDef* hcan);
void HAL_CAN_TxCpltCallback(CAN_HandleTypeDef* hcan);
void HAL_CAN_RxCpltCallback(CAN_HandleTypeDef* hcan);
void HAL_CAN_ErrorCallback(CAN_HandleTypeDef *hcan);

typedef union
{
    CanFrame_t CanFrame;
    struct
    {
        unsigned long SrcAddr:4;
        unsigned long DstAddr:4;
        unsigned long FunCode:3;
        unsigned long resev:5;
        unsigned long rerev1:8;
        unsigned long resev2:8;
        unsigned char IDE;
        unsigned char RTR;
        unsigned char FunCodeLen;
        unsigned char Fundata[8];
    }ProtocalFrame;
}CanAppProtocalFrame_t;

typedef void (*CapHandle_PFUN) (unsigned char FunCode,unsigned char Fundata);
int Hal_CanMsgSend(CanFrame_t *pCanFrame);
int Hal_CanMsgRecive(CanFrame_t *pCanFrame);

#define CAN_SC_ADF_ACK_RST 5000
#define CAN_SC_ADF_PBIT_RST 5001
#define CAN_SC_ADF_QUERY 5002
#define CAN_SC_ADF_MBIT_RST 6001
#define CAN_SC_ADF_SETP 1101
#define CAN_SC_ADF_SETQEC 1102

#define CAN_ADF_SC_ACK 5000
#define CAN_ADF_SC_BIT 5050
#define CAN_ADF_SC_ID 5052
#define CAN_ADF_SC_GETP 1151
#define CAN_ADF_SC_GETQEC 1152
#define CAN_ADF_SC_GETDIR 1153
enum { Idle=0,Begin=0x11,buzy=0xAA,} RqtSt[8];
void CAN_SC1_Frame_Handle(unsigned int FunCode,unsigned char Fundata);           //显控1数据
void CAN_SC2_Frame_Handle(unsigned int FunCode,unsigned char Fundata);           //显控2数据

int CAN_CapFrameHandle(char LocalAddr,
                       CanFrame_t *pCanFrame,
                       CapHandle_PFUN calback);                      //处理接收的数据帧



int CAN_CapFrameSend(unsigned char SrcAddr,
                     unsigned char Dstaddr,
                     unsigned char cmd,
                     unsigned char *pData,
                     unsigned char len);                              //封装发送


#endif /* CAN_APP_H_ */
