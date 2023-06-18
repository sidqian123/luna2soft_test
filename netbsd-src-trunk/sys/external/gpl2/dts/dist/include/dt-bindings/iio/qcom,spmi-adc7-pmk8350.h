/*	$NetBSD: qcom,spmi-adc7-pmk8350.h,v 1.1.1.1 2021/11/07 16:49:57 jmcneill Exp $	*/

/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2020 The Linux Foundation. All rights reserved.
 */

#ifndef _DT_BINDINGS_QCOM_SPMI_VADC_PMK8350_H
#define _DT_BINDINGS_QCOM_SPMI_VADC_PMK8350_H

#ifndef PMK8350_SID
#define PMK8350_SID					0
#endif

/* ADC channels for PMK8350_ADC for PMIC7 */
#define PMK8350_ADC7_REF_GND			(PMK8350_SID << 8 | 0x0)
#define PMK8350_ADC7_1P25VREF			(PMK8350_SID << 8 | 0x01)
#define PMK8350_ADC7_VREF_VADC			(PMK8350_SID << 8 | 0x02)
#define PMK8350_ADC7_DIE_TEMP			(PMK8350_SID << 8 | 0x03)

#define PMK8350_ADC7_AMUX_THM1			(PMK8350_SID << 8 | 0x04)
#define PMK8350_ADC7_AMUX_THM2			(PMK8350_SID << 8 | 0x05)
#define PMK8350_ADC7_AMUX_THM3			(PMK8350_SID << 8 | 0x06)
#define PMK8350_ADC7_AMUX_THM4			(PMK8350_SID << 8 | 0x07)
#define PMK8350_ADC7_AMUX_THM5			(PMK8350_SID << 8 | 0x08)

/* 30k pull-up1 */
#define PMK8350_ADC7_AMUX_THM1_30K_PU		(PMK8350_SID << 8 | 0x24)
#define PMK8350_ADC7_AMUX_THM2_30K_PU		(PMK8350_SID << 8 | 0x25)
#define PMK8350_ADC7_AMUX_THM3_30K_PU		(PMK8350_SID << 8 | 0x26)
#define PMK8350_ADC7_AMUX_THM4_30K_PU		(PMK8350_SID << 8 | 0x27)
#define PMK8350_ADC7_AMUX_THM5_30K_PU		(PMK8350_SID << 8 | 0x28)

/* 100k pull-up2 */
#define PMK8350_ADC7_AMUX_THM1_100K_PU		(PMK8350_SID << 8 | 0x44)
#define PMK8350_ADC7_AMUX_THM2_100K_PU		(PMK8350_SID << 8 | 0x45)
#define PMK8350_ADC7_AMUX_THM3_100K_PU		(PMK8350_SID << 8 | 0x46)
#define PMK8350_ADC7_AMUX_THM4_100K_PU		(PMK8350_SID << 8 | 0x47)
#define PMK8350_ADC7_AMUX_THM5_100K_PU		(PMK8350_SID << 8 | 0x48)

/* 400k pull-up3 */
#define PMK8350_ADC7_AMUX_THM1_400K_PU		(PMK8350_SID << 8 | 0x64)
#define PMK8350_ADC7_AMUX_THM2_400K_PU		(PMK8350_SID << 8 | 0x65)
#define PMK8350_ADC7_AMUX_THM3_400K_PU		(PMK8350_SID << 8 | 0x66)
#define PMK8350_ADC7_AMUX_THM4_400K_PU		(PMK8350_SID << 8 | 0x67)
#define PMK8350_ADC7_AMUX_THM5_400K_PU		(PMK8350_SID << 8 | 0x68)

#endif /* _DT_BINDINGS_QCOM_SPMI_VADC_PMK8350_H */