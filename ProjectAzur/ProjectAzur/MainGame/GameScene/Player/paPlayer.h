﻿//==================================================================================================================================//
//!< @file		paPalyer.h
//!< @brief		pa::Playerクラスのヘッダ
//!< @author	T.Haga
//!< @data		作成日時：2017/12/05	更新履歴：
//==================================================================================================================================//

#ifndef PA_PLAYER_H
#define PA_PLAYER_H

#include "../../paIObjectBase.h"

namespace pa
{

//===================================================================================//
//!< ゲームにおけるプレイヤーのクラス
//===================================================================================//
class Player final : public IObjectBase
{

public:
	/** Constructor */
	Player();

	/** Destructor */
	virtual ~Player();

	/** 初期化関数 */
	virtual void Initialize()override;

	/** 更新関数 */
	virtual void Update()override;

	/** 破棄関数 */
	virtual void Finalize()override;

};	// class Player

}	// namespace pa

#endif	// PA_PLAYER_H

//==================================================================================================================================//
// END OF FILE
//==================================================================================================================================//
