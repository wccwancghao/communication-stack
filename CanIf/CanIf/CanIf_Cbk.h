/* -------------------------------- Arctic Core ------------------------------
 * Arctic Core - the open source AUTOSAR platform http://arccore.com
 *
 * Copyright (C) 2009  ArcCore AB <contact@arccore.com>
 *
 * This source code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; See <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * -------------------------------- Arctic Core ------------------------------*/








#ifndef CANIF_CBK_H_
#define CANIF_CBK_H_

#include "CanIf_Cfg.h"

#define CANIF_TRANSMIT_CANCELLATION   (STD_OFF) /* This macros is defined to resolve misra warning*/

void CanIf_TxConfirmation( uint32 canTxPduId );
void CanIf_RxIndication( uint8 Hrh, Can_IdType CanId, uint8 CanDlc, const uint8 *CanSduPtr );

#if ( CANIF_TRANSMIT_CANCELLATION == STD_ON )
void CanIf_CancelTxConfirmation( const Can_PduType *PduInfoPtr );
#endif

void CanIf_ControllerBusOff( uint8 Controller );
void CanIf_SetWakeupEvent( uint8 Controller );

/* ArcCore extensions */
void CanIf_Arc_Error( uint8 Controller, Can_Arc_ErrorType Error );

FUNC(void,CANIF_CODE) CanIf_ControllerModeIndication
(
	VAR(CanIf_Arc_ChannelIdType,AUTOMATIC) channel_CanIf_SetControllerMode,
	VAR(
Can_ControllerStateType, AUTOMATIC) ControllerMode
);

#endif /*CANIF_CBK_H_*/
