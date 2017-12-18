﻿//==================================================================================================================================//
//!< @file		paEnergyGauge.h
//!< @brief		pa::EnergyGaugeクラスのヘッダ
//!< @author	T.Haga
//!< @data		作成日時：2017/12/18	更新履歴：
//==================================================================================================================================//

#ifndef PA_ENERGY_GAUGE_H
#define PA_ENERGY_GAUGE_H

#include "../paIUI.h"

namespace pa
{

//===================================================================================//
//!< 電池ゲージクラス
//!< ゲームのプレイ時間をあらわすUI
//===================================================================================//
class EnergyGauge final : public IUI
{

public:
	/** Constructor */
	EnergyGauge();

	/** Destructor */
	virtual ~EnergyGauge();

};	// class EnergyGauge

}	// namespace pa

#endif	// PA_ENERGY_GAUGE_H

//==================================================================================================================================//
// END OF FILE
//==================================================================================================================================//
