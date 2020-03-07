/*
 * conf.h
 *
 *  Created on: Dec 27, 2018
 *      Author: yusaku
 */

#ifndef CONF_H_
#define CONF_H_

#include "stm32f1xx_hal.h"

extern "C"
{
    typedef struct
    {
        uint16_t can_id_cmd;
        uint16_t can_id_vel;
        uint16_t can_id_stat;
        uint16_t can_id_vel2;
        uint16_t can_id_stream;
        double Kp;
        double KiTc;
        double Ke;
        double Kg;
        double Kh;
        double Kr;
        double MaxVel;
        double MaxTrq;
        double AllowRange;
        double Vsup;
        double HomVel;
        double MaxTravel;
        double Kv;
    } ConfStruct;
}

extern ConfStruct confStruct;

void readConf(void);
void writeConf(void);

inline ConfStruct * getConf(void)
{
    return &confStruct;
}

#endif /* CONF_H_ */
