﻿//==================================================================================================================================//
//!< @file		paPlayerCommonDeclaration.h
//!< @brief		Playerクラスに共通する宣言をまとめたファイル
//!< @author	T.Haga
//!< @data		作成日時：2017/12/07	更新履歴：
//==================================================================================================================================//

#ifndef PA_PLAYER_COMMON_DECLARATION_H
#define PA_PLAYER_COMMON_DECLARATION_H

#include <D3DX10.h>

namespace pa
{

//===================================================================================//
//!< プレイヤーの状態の列挙型 
//===================================================================================//
enum class PLAYER_STATE
{
	WAITING,					//!< 待機状態
	MOVING,						//!< 移動状態
};	// enum class PLAYER_STATE

//===================================================================================//
//!< プレイヤーパラメータの構造体
//===================================================================================//
struct PlayerParam
{
	D3DXVECTOR2		m_Pos;						//!< 位置座標
	float			m_Angle;					//!< 角度
	float			m_Acceleration;				//!< 加速度
	PLAYER_STATE	m_CurrentState;				//!< プレイヤーの現在の状態
	bool			m_IsFacingRight;			//!< 右を向いているかどうかのフラグ. true→向いている false→向いていない

	PlayerParam()
		: m_Pos({0.0f, 0.0f})
		, m_Angle(0.0f)
		, m_Acceleration(0.0f)
		, m_CurrentState(PLAYER_STATE::WAITING)
		, m_IsFacingRight(true)
	{}

};	// struct PlayerParam

}	// namespace pa

#endif	// PA_PLAYER_COMMON_DECLARATION_H

//==================================================================================================================================//
// END OF FILE
//==================================================================================================================================//