﻿//==================================================================================================================================//
//!< @file		paPlayerActionImplBase.cpp
//!< @brief		pa::PlayerActionImplBaseクラスの実装
//!< @author	T.Haga
//!< @data		作成日時：2018/01/26	更新履歴：
//==================================================================================================================================//

/* Includes --------------------------------------------------------------------------------------------------- */

#include "paPlayerActionImplBase.h"

namespace pa
{

/* Public Functions ------------------------------------------------------------------------------------------- */

PlayerActionImplBase::PlayerActionImplBase()
	: m_rInputLibrary(sl::IInputDeviceLibrary::Instance())
	, m_SpeedMinVal(0.0f)
	, m_SpeedMaxVal(0.0f)
{}

PlayerActionImplBase::~PlayerActionImplBase()
{}

}	// namespace pa

//==================================================================================================================================//
// END OF FILE
//==================================================================================================================================//
