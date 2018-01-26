﻿//==================================================================================================================================//
//!< @file		paPlayerAction.cpp
//!< @brief		pa::PlayerActionクラスの実装
//!< @author	T.Haga
//!< @data		作成日時：2017/12/05	更新履歴：2017/12/15
//==================================================================================================================================//

/* Includes --------------------------------------------------------------------------------------------------- */

#include <algorithm>
#include "sl/Library/InputDevice/IInputDeviceLibrary/slIInputDeviceLibrary.h"
#include "paPlayerAction.h"
#include "../../../paCustomizeInput.h"
#include "../../../EventManager/paEventManager.h"

namespace pa
{

/* Unnamed Namespace ------------------------------------------------------------------------------------------ */

namespace
{

const float		AttenuationSpeed = 0.02f;		//!< 減衰スピード

}

/* Public Functions ------------------------------------------------------------------------------------------- */

PlayerAction::PlayerAction()
	: m_rInputLibrary(sl::IInputDeviceLibrary::Instance())
{}

void PlayerAction::Initialize()
{
	/** @todo 現在は仮の数値 */
	m_SpeedMaxVal = 4.0f;
	m_SpeedMinVal = 0.0f;
}

void PlayerAction::Update(PlayerParam& rParam)
{
	MoveHorizontally(rParam);
	MoveVertically(rParam);
	Rotate(rParam);

	// 待機状態かどうかのチェックを行う
	if(rParam.m_CurrentHorizontalSpeed == m_SpeedMinVal
		&& rParam.m_CurrentVerticalSpeed == m_SpeedMinVal)
	{
		rParam.m_CurrentState = PLAYER_STATE::WAITING;
		return;
	}
	rParam.m_CurrentState = PLAYER_STATE::MOVING;

	EventManager::Instance().TriggerSynEvent("player_move");
}

void PlayerAction::Finalize()
{
	/** @todo 現状処理なし. すべての実装を終えて処理がなければ削除も検討 */
}

/* Private Functions ------------------------------------------------------------------------------------------ */

void PlayerAction::MoveHorizontally(PlayerParam& rParam)
{
	// 右移動
	if(m_rInputLibrary.CheckCustomizeInputState(RIGHT_MOVE, sl::ON))
	{
		rParam.m_CurrentHorizontalSpeed += rParam.m_IsFacingRight ? rParam.m_Acceleration : AttenuationSpeed;
	}
	else if(m_rInputLibrary.CheckCustomizeInputState(RIGHT_MOVE, sl::OFF)
			&& rParam.m_CurrentHorizontalSpeed != m_SpeedMinVal)
	{
		rParam.m_CurrentHorizontalSpeed += rParam.m_IsFacingRight ? -AttenuationSpeed : 0.0f;
	}

	// 左移動
	if(m_rInputLibrary.CheckCustomizeInputState(LEFT_MOVE, sl::ON))
	{
		rParam.m_CurrentHorizontalSpeed += rParam.m_IsFacingRight ? -AttenuationSpeed : -rParam.m_Acceleration;
	}
	else if(m_rInputLibrary.CheckCustomizeInputState(LEFT_MOVE, sl::OFF)
			&& rParam.m_CurrentHorizontalSpeed != m_SpeedMinVal)
	{
		rParam.m_CurrentHorizontalSpeed += rParam.m_IsFacingRight ? 0.0f : AttenuationSpeed;
	}

	// スピードの最小値と最大値の間に調整する
	if(rParam.m_IsFacingRight)
	{
		if(rParam.m_CurrentHorizontalSpeed < 0.0f)
		{
			rParam.m_CurrentHorizontalSpeed = 0.0f;
		}
		rParam.m_CurrentHorizontalSpeed = std::max<float>(m_SpeedMinVal, std::min<float>(m_SpeedMaxVal, rParam.m_CurrentHorizontalSpeed));
	}
	else 
	{
		if(rParam.m_CurrentHorizontalSpeed > 0.0f)
		{
			rParam.m_CurrentHorizontalSpeed = 0.0f;
		}
		rParam.m_CurrentHorizontalSpeed = std::min<float>(m_SpeedMinVal, std::max<float>(-m_SpeedMaxVal, rParam.m_CurrentHorizontalSpeed));
	}

	rParam.m_Pos.x += rParam.m_CurrentHorizontalSpeed;
}

void PlayerAction::MoveVertically(PlayerParam& rParam)
{
	/** @todo ここは仮処理 */

	/** 仮処理 */
	rParam.m_CurrentVerticalSpeed = m_SpeedMinVal;
	/** 仮処理 */

	// 上移動
	if(m_rInputLibrary.CheckCustomizeInputState(UP_MOVE, sl::ON))
	{
		rParam.m_CurrentVerticalSpeed -= rParam.m_Acceleration;
		rParam.m_Pos.y -= rParam.m_Acceleration * 10;
	}

	// 下移動
	if(m_rInputLibrary.CheckCustomizeInputState(DOWN_MOVE, sl::ON))
	{
		rParam.m_CurrentVerticalSpeed += rParam.m_Acceleration;
		rParam.m_Pos.y += rParam.m_Acceleration * 10;
	}
}

void PlayerAction::Rotate(PlayerParam& rParam)
{
	/** 
	* @todo 回転機能に関してはオミットしている。 
	* ここではボタンがおされたら 反転するだけ 
	*/
	if(m_rInputLibrary.CheckCustomizeInputState(RIGHT_ROTATION, sl::ON))
	{
		rParam.m_IsFacingRight = true;
	}
	else if(m_rInputLibrary.CheckCustomizeInputState(LEFT_ROTATION, sl::ON))
	{
		rParam.m_IsFacingRight = false;
	}
}

}	// namespace pa

//==================================================================================================================================//
// END OF FILE
//==================================================================================================================================//