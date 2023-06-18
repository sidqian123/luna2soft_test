/* generated by mkdefs.awk */
#ifndef XPLX_DEFINE
#define XPLX_DEFINE
#define DEVID_XPBUS 0
#define DEVID_TIME 1
#define DEVID_PAM 2
#define DEVID_PCM 3
#define DEVID_PSG 4
#define DEVID_SPK 5
#define DEVID_LPR 6
#define DEVID_FDC 7
#define DEVID_SIO0 8
#define DEVID_SIO1 9
#define PAM_CMD_START 1
#define PAM_CMD_QUERY 2
#define PAM_ENC_PAM2A 1
#define PAM_ENC_PAM2B 2
#define PAM_ENC_PAM3A 3
#define PAM_ENC_PAM3B 4
#define PAM_ENC_PAM1P 5
#define PCM_CMD_START 1
#define PCM_ENC_PCM1 1
#define PCM_ENC_PCM2 2
#define PCM_ENC_PCM3 3
#define SPK_CMD_START 1
#define SPK_CMD_STOP 2
#define SPK_CMD_KEEP 3
#define XPLX_R_OK 1
#define XPLX_R_ERROR_PARAM 254
#define XPLX_R_UNKNOWN_CMD 255
#define USE_INTR 1
/* 0080: 00                DEBUG0::	.DB	0 */
#define DEBUG0 0x0080
/* 0081: 00                DEBUG1::	.DB	0 */
#define DEBUG1 0x0081
/* 0082: 00                DEBUG2::	.DB	0 */
#define DEBUG2 0x0082
/* 0083: 00                DEBUG3::	.DB	0 */
#define DEBUG3 0x0083
/* 0084: 00                DEBUG4::	.DB	0 */
#define DEBUG4 0x0084
/* 0085: 00                DEBUG5::	.DB	0 */
#define DEBUG5 0x0085
/* 0086: 00                DEBUG6::	.DB	0 */
#define DEBUG6 0x0086
/* 0087: 00                DEBUG7::	.DB	0 */
#define DEBUG7 0x0087
/* 0088: 00                DEBUG8::	.DB	0 */
#define DEBUG8 0x0088
/* 0089: 00                DEBUG9::	.DB	0 */
#define DEBUG9 0x0089
/* 008A: 00                DEBUG10::	.DB	0 */
#define DEBUG10 0x008A
/* 00FC:                   XPLX_MAGIC::			; MAGIC */
#define XPLX_MAGIC 0x00FC
/* 0100:                   XPLX_VAR_BASE:: */
#define XPLX_VAR_BASE 0x0100
/* 0100:                   XPBUS_READY:: */
#define XPBUS_READY 0x0100
/* 0101:                   XPBUS_CMD:: */
#define XPBUS_CMD 0x0101
/* 0102:                   XPBUS_RESULT:: */
#define XPBUS_RESULT 0x0102
/* 0103:                   XPBUS_RUN:: */
#define XPBUS_RUN 0x0103
/* 0104:                   XPBUS_STAT_RESET::		; reset count */
#define XPBUS_STAT_RESET 0x0104
/* 0108:                   XPBUS_PRT0_TIMER::		; PRT0 TIMER TLDR (devices dispatch) */
#define XPBUS_PRT0_TIMER 0x0108
/* 010A:                   XPBUS_INTR1_DEV::		; HOSTINTR1 device */
#define XPBUS_INTR1_DEV 0x010A
/* 010C:                   XPBUS_INTR5_DEV::		; HOSTINTR5 device */
#define XPBUS_INTR5_DEV 0x010C
/* 0110:                   TIME_READY:: */
#define TIME_READY 0x0110
/* 0111:                   TIME_CMD:: */
#define TIME_CMD 0x0111
/* 0112:                   TIME_RESULT:: */
#define TIME_RESULT 0x0112
/* 0113:                   TIME_RUN:: */
#define TIME_RUN 0x0113
/* 0114:                   TIME_TIMECOUNTER::		; timecounter (TBD.) */
#define TIME_TIMECOUNTER 0x0114
/* 0120:                   PAM_READY:: */
#define PAM_READY 0x0120
/* 0121:                   PAM_CMD:: */
#define PAM_CMD 0x0121
/* 0122:                   PAM_RESULT:: */
#define PAM_RESULT 0x0122
/* 0123:                   PAM_RUN:: */
#define PAM_RUN 0x0123
/* 0124:                   PAM_ENC:: */
#define PAM_ENC 0x0124
/* 0125:                   PAM_REPT:: */
#define PAM_REPT 0x0125
/* 0126:                   PAM_CYCLE_CLK:: */
#define PAM_CYCLE_CLK 0x0126
/* 0128:                   PAM_REPT_CLK:: */
#define PAM_REPT_CLK 0x0128
/* 0129:                   PAM_REPT_MAX:: */
#define PAM_REPT_MAX 0x0129
/* 012E:                   PAM_STAT_PTR:: */
#define PAM_STAT_PTR 0x012E
/* 0130:                   PCM_READY:: */
#define PCM_READY 0x0130
/* 0131:                   PCM_CMD:: */
#define PCM_CMD 0x0131
/* 0132:                   PCM_RESULT:: */
#define PCM_RESULT 0x0132
/* 0133:                   PCM_RUN:: */
#define PCM_RUN 0x0133
/* 0134:                   PCM_ENC:: */
#define PCM_ENC 0x0134
/* 0136:                   PCM_PRT1_TIMER::			; PRT1 TIMER TLDR (PCM) */
#define PCM_PRT1_TIMER 0x0136
/* 013E:                   PCM_STAT_PTR:: */
#define PCM_STAT_PTR 0x013E
/* 0140:                   PSG_READY:: */
#define PSG_READY 0x0140
/* 0141:                   PSG_CMD:: */
#define PSG_CMD 0x0141
/* 0142:                   PSG_RESULT:: */
#define PSG_RESULT 0x0142
/* 0143:                   PSG_RUN:: */
#define PSG_RUN 0x0143
/* 0150:                   SPK_READY:: */
#define SPK_READY 0x0150
/* 0151:                   SPK_CMD:: */
#define SPK_CMD 0x0151
/* 0152:                   SPK_RESULT:: */
#define SPK_RESULT 0x0152
/* 0153:                   SPK_RUN:: */
#define SPK_RUN 0x0153
/* 0154:                   SPK_VOL:: */
#define SPK_VOL 0x0154
/* 0156:                   SPK_FREQ:: */
#define SPK_FREQ 0x0156
/* 0158:                   SPK_TIME:: */
#define SPK_TIME 0x0158
/* 015A:                   SPK_REMAIN:: */
#define SPK_REMAIN 0x015A
/* 0160:                   LPR_READY:: */
#define LPR_READY 0x0160
/* 0161:                   LPR_CMD:: */
#define LPR_CMD 0x0161
/* 0162:                   LPR_RESULT:: */
#define LPR_RESULT 0x0162
/* 0163:                   LPR_RUN:: */
#define LPR_RUN 0x0163
/* 0170:                   FDC_READY:: */
#define FDC_READY 0x0170
/* 0171:                   FDC_CMD:: */
#define FDC_CMD 0x0171
/* 0172:                   FDC_RESULT:: */
#define FDC_RESULT 0x0172
/* 0173:                   FDC_RUN:: */
#define FDC_RUN 0x0173
/* 0180:                   SIO0_READY:: */
#define SIO0_READY 0x0180
/* 0181:                   SIO0_CMD:: */
#define SIO0_CMD 0x0181
/* 0182:                   SIO0_RESULT:: */
#define SIO0_RESULT 0x0182
/* 0183:                   SIO0_RUN:: */
#define SIO0_RUN 0x0183
/* 0184:                   SIO0_TXCMD:: */
#define SIO0_TXCMD 0x0184
/* 0185:                   SIO0_TXSTAT:: */
#define SIO0_TXSTAT 0x0185
/* 0186:                   SIO0_TX:: */
#define SIO0_TX 0x0186
/* 018A:                   SIO0_RXCMD:: */
#define SIO0_RXCMD 0x018A
/* 018B:                   SIO0_RXSTAT:: */
#define SIO0_RXSTAT 0x018B
/* 018C:                   SIO0_RX:: */
#define SIO0_RX 0x018C
/* 0190:                   SIO1_READY:: */
#define SIO1_READY 0x0190
/* 0191:                   SIO1_CMD:: */
#define SIO1_CMD 0x0191
/* 0192:                   SIO1_RESULT:: */
#define SIO1_RESULT 0x0192
/* 0193:                   SIO1_RUN:: */
#define SIO1_RUN 0x0193
/* 0194:                   SIO1_TXCMD:: */
#define SIO1_TXCMD 0x0194
/* 0195:                   SIO1_TXSTAT:: */
#define SIO1_TXSTAT 0x0195
/* 0196:                   SIO1_TX:: */
#define SIO1_TX 0x0196
/* 019A:                   SIO1_RXCMD:: */
#define SIO1_RXCMD 0x019A
/* 019B:                   SIO1_RXSTAT:: */
#define SIO1_RXSTAT 0x019B
/* 019C:                   SIO1_RX:: */
#define SIO1_RX 0x019C
/* 1000:                   PAM_BUF:: */
#define PAM_BUF 0x1000
/* 1000:                   PCM_BUF:: */
#define PCM_BUF 0x1000
/* 7000:                   PAM_BUF_LEN::	.EQU	$-PAM_BUF */
#define PAM_BUF_LEN 0x7000
/* 7000:                   PCM_BUF_LEN::	.EQU	$-PCM_BUF */
#define PCM_BUF_LEN 0x7000
/* 8000:                   PSG_BUF:: */
#define PSG_BUF 0x8000
/* 1000:                   PSG_BUF_LEN::	.EQU	$-PSG_BUF */
#define PSG_BUF_LEN 0x1000
/* 9000:                   LPR_BUF:: */
#define LPR_BUF 0x9000
/* 1000:                   LPR_BUF_LEN::	.EQU	$-LPR_BUF */
#define LPR_BUF_LEN 0x1000
/* A000:                   FDC_BUF:: */
#define FDC_BUF 0xA000
/* 4000:                   FDC_BUF_LEN::	.EQU	$-FDC_BUF */
#define FDC_BUF_LEN 0x4000
/* 0777:                   XPLX_FIRMWARE_LEN::	.EQU	$ */
#define XPLX_FIRMWARE_LEN 0x0777
#endif /* !XPLX_DEFINE */